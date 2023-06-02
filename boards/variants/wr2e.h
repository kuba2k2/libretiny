/* This file was auto-generated from wr2e.json using boardgen */

#pragma once

// clang-format off

// Pins
// ----
#define PINS_COUNT         8  // Total GPIO count
#define NUM_DIGITAL_PINS   7  // Digital inputs/outputs
#define NUM_ANALOG_INPUTS  2  // ADC inputs
#define NUM_ANALOG_OUTPUTS 5  // PWM & DAC outputs
#define PINS_GPIO_MAX      41 // Last usable GPIO number

// Wire Interfaces
// ---------------
#define PIN_WIRE1_SCL 18u // PA_18
#define PIN_WIRE1_SDA 23u // PA_23

// Serial ports
// ------------
#define PIN_SERIAL0_CTS 19u // PA_19
#define PIN_SERIAL0_RX  18u // PA_18
#define PIN_SERIAL0_TX  23u // PA_23

// Pin function macros
// -------------------
#define PIN_ADC1  19u // PA_19
#define PIN_ADC2  41u // AD_2
#define PIN_CS0   19u // PA_19
#define PIN_CS1   19u // PA_19
#define PIN_CTS0  19u // PA_19
#define PIN_MOSI0 23u // PA_23
#define PIN_MOSI1 23u // PA_23
#define PIN_PA05  5u  // PA_5
#define PIN_PA12  12u // PA_12
#define PIN_PA14  14u // PA_14
#define PIN_PA15  15u // PA_15
#define PIN_PA18  18u // PA_18
#define PIN_PA19  19u // PA_19
#define PIN_PA23  23u // PA_23
#define PIN_PWM0  14u // PA_14
#define PIN_PWM1  15u // PA_15
#define PIN_PWM3  12u // PA_12
#define PIN_PWM4  5u  // PA_5
#define PIN_RX0   18u // PA_18
#define PIN_SCK0  18u // PA_18
#define PIN_SCK1  18u // PA_18
#define PIN_SCL1  18u // PA_18
#define PIN_SDA0  19u // PA_19
#define PIN_SDA1  23u // PA_23
#define PIN_TX0   23u // PA_23

// Port availability
// -----------------
#define HAS_SERIAL0             1
#define HAS_WIRE1               1
#define SERIAL_INTERFACES_COUNT 1
#define WIRE_INTERFACES_COUNT   1

// Arduino pin names
// -----------------
#define PIN_D0 12u // PA_12
#define PIN_D1 19u // PA_19
#define PIN_D2 5u  // PA_5
#define PIN_D3 18u // PA_18
#define PIN_D4 23u // PA_23
#define PIN_D5 14u // PA_14
#define PIN_D6 15u // PA_15
#define PIN_A0 19u // PA_19
#define PIN_A1 41u // AD_2

// Static pin names
// ----------------
static const unsigned char A0 = PIN_A0;
static const unsigned char A1 = PIN_A1;
static const unsigned char D0 = PIN_D0;
static const unsigned char D1 = PIN_D1;
static const unsigned char D2 = PIN_D2;
static const unsigned char D3 = PIN_D3;
static const unsigned char D4 = PIN_D4;
static const unsigned char D5 = PIN_D5;
static const unsigned char D6 = PIN_D6;
