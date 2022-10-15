# CB2L Wi-Fi Module

*by Tuya Inc.*

[Product page](https://developer.tuya.com/en/docs/iot/cb2l-module-datasheet?id=Kai2eku1m3pyl)

- [General info](../../docs/platform/beken-72xx/README.md)
- [Flashing guide](../../docs/platform/beken-72xx/flashing.md)
- [BkWriter v1.6.0](https://images.tuyacn.com/smart/bk_writer1.60/bk_writer1.60.exe)

Parameter    | Value
-------------|------------------------------------------
Board code   | `cb2l`
MCU          | BK7231N
Manufacturer | Beken
Series       | BK72XX
Frequency    | 120 MHz
Flash size   | 2 MiB
RAM size     | 256 KiB
Voltage      | 3.0V - 3.6V
I/O          | 9x GPIO, 5x PWM, 2x UART
Wi-Fi        | 802.11 b/g/n
Bluetooth    | BLE v5.1
FCC ID       | [2ANDL-CB2L](https://fccid.io/2ANDL-CB2L)

## Usage

**Board code:** `cb2l`

In `platformio.ini`:

```ini
[env:cb2l]
platform = libretuya
board = cb2l
framework = arduino
```

## Pinout

![Pinout](pinout_cb2l.svg)

## Arduino Core pin mapping

No. | Pin | UART     | I²C      | SPI | PWM  | Other
----|-----|----------|----------|-----|------|------
D0  | P8  |          |          |     | PWM2 |
D1  | P7  |          |          |     | PWM1 |
D2  | P6  |          |          |     | PWM0 |
D3  | P26 |          |          |     | PWM5 |
D4  | P24 |          |          |     | PWM4 |
D5  | P10 | UART1_RX |          |     |      |
D6  | P0  | UART2_TX | I2C2_SCL |     |      |
D7  | P11 | UART1_TX |          |     |      |
D8  | P21 |          | I2C1_SDA |     |      | TMS

## Flash memory map

Flash size: 2 MiB / 2,097,152 B / 0x200000

Hex values are in bytes.

Name            | Start    | Length             | End
----------------|----------|--------------------|---------
Bootloader      | 0x000000 | 68 KiB / 0x11000   | 0x011000
App Image       | 0x011000 | 1.1 MiB / 0x119000 | 0x12A000
OTA Image       | 0x12A000 | 664 KiB / 0xA6000  | 0x1D0000
Calibration     | 0x1D0000 | 4 KiB / 0x1000     | 0x1D1000
Network Data    | 0x1D1000 | 4 KiB / 0x1000     | 0x1D2000
TLV Store       | 0x1D2000 | 4 KiB / 0x1000     | 0x1D3000
Key-Value Store | 0x1D3000 | 32 KiB / 0x8000    | 0x1DB000
User Data       | 0x1DB000 | 148 KiB / 0x25000  | 0x200000

Bootloader and app partitions contain CRC16 sums every 32 bytes. That results in the actual flash offsets/sizes not aligned to sector boundaries. To simplify calculations, the values shown in the table (extracted from bootloader's partition table) were aligned to 4096 bytes.
