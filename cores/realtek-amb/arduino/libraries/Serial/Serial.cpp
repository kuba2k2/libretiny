/* Copyright (c) Kuba Szczodrzyński 2022-07-03. */

#include "Serial.h"

#include <Arduino.h>
#include <sdk_private.h>

#if HAS_SERIAL0
SerialClass Serial0(UART0_DEV, UART0_IRQ, PIN_SERIAL0_RX, PIN_SERIAL0_TX);
#endif
#if HAS_SERIAL1
SerialClass Serial1(UART1_DEV, UART1_IRQ, PIN_SERIAL1_RX, PIN_SERIAL1_TX);
#endif
#if HAS_SERIAL2
SerialClass Serial2(UART2_DEV, UART_LOG_IRQ, PIN_SERIAL2_RX, PIN_SERIAL2_TX);
#endif

SerialClass::SerialClass(void *uart, uint8_t irq, pin_size_t rx, pin_size_t tx) {
	data.uart = uart;
	data.buf  = NULL;
	this->irq = irq;
	this->rx  = rx;
	this->tx  = tx;
}

#if LT_AUTO_DOWNLOAD_REBOOT
static uint8_t adrState = 0;

// clang-format off
// Family ID, big-endian
static const uint8_t adrCmd[] = {
	0x55, 0xAA,
	(FAMILY >> 24) & 0xFF,
	(FAMILY >> 16) & 0xFF,
	(FAMILY >> 8) & 0xFF,
	(FAMILY >> 0) & 0xFF
};

// clang-format on

static void adrParse(uint8_t c) {
	adrState = (adrState + 1) * (c == adrCmd[adrState]);
	if (adrState == 6) {
		LT_I("Auto download mode: rebooting");
		LT.restartDownloadMode();
	}
}
#endif

static uint32_t callback(void *param) {
	SerialData *data   = (SerialData *)param;
	UART_TypeDef *uart = (UART_TypeDef *)data->uart;

	uint32_t intcr	= uart->DLH_INTCR;
	uart->DLH_INTCR = 0;

	uint8_t c;
	while (UART_Readable(uart)) {
		UART_CharGet(uart, &c);
#if LT_AUTO_DOWNLOAD_REBOOT && defined(PIN_SERIAL2_RX)
		// parse UART protocol commands on UART2
		if (uart == UART2_DEV)
			adrParse(c);
#endif
		data->buf->store_char(c);
	}

	uart->DLH_INTCR = intcr;
	return 0;
}

void SerialClass::begin(unsigned long baudrate, uint16_t config) {
	// RUART_WLS_7BITS / RUART_WLS_8BITS
	uint8_t dataWidth = (config & SERIAL_DATA_MASK) == SERIAL_DATA_8;
	// RUART_PARITY_DISABLE / RUART_PARITY_ENABLE
	uint8_t parity = (config & SERIAL_PARITY_MASK) != SERIAL_PARITY_NONE;
	// RUART_ODD_PARITY / RUART_EVEN_PARITY
	uint8_t parityType = (config & SERIAL_PARITY_MASK) == SERIAL_PARITY_EVEN;
	// RUART_STOP_BIT_1 / RUART_STOP_BIT_2
	uint8_t stopBits = (config & SERIAL_STOP_BIT_MASK) == SERIAL_STOP_BIT_2;

	switch ((uint32_t)data.uart) {
		case UART0_REG_BASE:
			RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
			break;
		case UART1_REG_BASE:
			RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE);
			break;
	}

	Pinmux_Config(pinInfo(this->rx)->gpio, PINMUX_FUNCTION_UART);
	Pinmux_Config(pinInfo(this->tx)->gpio, PINMUX_FUNCTION_UART);
	PAD_PullCtrl(pinInfo(this->rx)->gpio, GPIO_PuPd_UP);

	UART_InitTypeDef cfg;
	UART_StructInit(&cfg);
	cfg.WordLen	   = dataWidth;
	cfg.Parity	   = parity;
	cfg.ParityType = parityType;
	cfg.StopBit	   = stopBits;
	UART_Init((UART_TypeDef *)data.uart, &cfg);
	UART_SetBaud((UART_TypeDef *)data.uart, baudrate);

	if (data.buf) {
		data.buf->clear();
	} else {
		data.buf = new RingBuffer();
	}

	VECTOR_IrqUnRegister(this->irq);
	VECTOR_IrqRegister(callback, this->irq, (uint32_t)&data, 10);
	VECTOR_IrqEn(this->irq, 10);

	UART_RxCmd((UART_TypeDef *)data.uart, ENABLE);
	UART_INTConfig((UART_TypeDef *)data.uart, RUART_IER_ERBI, ENABLE);
}

void SerialClass::end() {
	if (data.uart == UART2_DEV) {
		// restore command line mode
		DIAG_UartReInit((IRQ_FUN)UartLogIrqHandle);
	}
	delete data.buf;
}

int SerialClass::available() {
	return data.buf->available();
}

int SerialClass::peek() {
	return data.buf->peek();
}

int SerialClass::read() {
	return data.buf->read_char();
}

void SerialClass::flush() {
	UART_WaitBusy((UART_TypeDef *)data.uart, 10);
}

size_t SerialClass::write(uint8_t c) {
	while (UART_Writable((UART_TypeDef *)data.uart) == 0) {}
	UART_CharPut((UART_TypeDef *)data.uart, c);
	return 1;
}
