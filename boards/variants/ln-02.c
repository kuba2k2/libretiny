/* This file was auto-generated from ln-02.json using boardgen */

#include <Arduino.h>

#ifdef LT_VARIANT_INCLUDE
#include LT_VARIANT_INCLUDE
#endif

// clang-format off
PinInfo lt_arduino_pin_info_list[PINS_COUNT] = {
	// D0: P11, SD_D1, I2C0_SCL, I2C0_SDA
	{PA_11, PIN_I2C | PIN_IRQ | PIN_GPIO,            PIN_NONE, 0},
	// D1: P19, ADC5, I2C0_SCL, I2C0_SDA
	{PB_3,  PIN_I2C | PIN_IRQ | PIN_GPIO,            PIN_NONE, 0},
	// D2: P3, UART1_RX, I2C0_SCL, I2C0_SDA
	{PA_3,  PIN_UART | PIN_I2C | PIN_GPIO,           PIN_NONE, 0},
	// D3: P24, UART0_RX, I2C0_SCL, I2C0_SDA
	{PB_8,  PIN_UART | PIN_I2C | PIN_IRQ | PIN_GPIO, PIN_NONE, 0},
	// D4: P2, UART1_TX, I2C0_SCL, I2C0_SDA
	{PA_2,  PIN_UART | PIN_I2C | PIN_GPIO,           PIN_NONE, 0},
	// D5: P25, UART0_TX, I2C0_SCL, I2C0_SDA
	{PB_9,  PIN_UART | PIN_I2C | PIN_GPIO,           PIN_NONE, 0},
	// D6: P1, ADC3, SWDIO, I2C0_SCL, I2C0_SDA
	{PA_1,  PIN_SWD | PIN_I2C | PIN_ADC | PIN_GPIO,  PIN_NONE, 0},
	// D7: P0, ADC2, I2C0_SCL, I2C0_SDA
	{PA_0,  PIN_I2C | PIN_ADC | PIN_GPIO,            PIN_NONE, 0},
};

PinInfo *lt_arduino_pin_gpio_map[] = {
	[0]  = &(lt_arduino_pin_info_list[7]), // PA_0 (D7)
	[1]  = &(lt_arduino_pin_info_list[6]), // PA_1 (D6)
	[2]  = &(lt_arduino_pin_info_list[4]), // PA_2 (D4)
	[3]  = &(lt_arduino_pin_info_list[2]), // PA_3 (D2)
	[11] = &(lt_arduino_pin_info_list[0]), // PA_11 (D0)
	[19] = &(lt_arduino_pin_info_list[1]), // PB_3 (D1)
	[24] = &(lt_arduino_pin_info_list[3]), // PB_8 (D3)
	[25] = &(lt_arduino_pin_info_list[5]), // PB_9 (D5)
};
// clang-format on