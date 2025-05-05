#pragma once
// Arduino Due Keyboard with Pin Definitions

// Reserved Pins
const int usb_pins[2] = {12, 13};  // USB Pins (D− and D+)
const int i2c_pins[2] = {20, 21};  // I2C Pins (SCL and SDA)
const int encoder_pins[2] = {
    22, // Encoder 1 A Pin
    23  // Encoder 1 B Pin
}; // Encoder Pins (A and B)

const int underglow_pin = 28; // Underglow Right (RGB)

// Layout Definitions

#if defined(_6X6_MATRIX_)
    // 6x6 Matrix Layout
    const int rows[6] = {
        30,   // Row 1
        31,   // Row 2
        32,   // Row 3
        33,   // Row 4
        34,   // Row 5
        35    // Row 6
    };

    const int lines[6] = {
        36,   // Column 1
        37,   // Column 2
        38,   // Column 3
        39,   // Column 4
        40,   // Column 5
        41    // Column 6
    };

#elif defined(_5X12_MATRIX_)
    // 5x12 Matrix Layout
    const int rows[5] = {
        30,   // Row 1
        31,   // Row 2
        32,   // Row 3
        33,   // Row 4
        34    // Row 5
    };

    const int lines[12] = {
        36,   // Column 1
        37,   // Column 2
        38,   // Column 3
        39,   // Column 4
        40,   // Column 5
        41,   // Column 6
        42,   // Column 7
        43,   // Column 8
        44,   // Column 9
        45,   // Column 10
        46,   // Column 11
        47    // Column 12
    };

#elif defined(_6X14_MATRIX_)
    // 6x14 Matrix Layout
    const int rows[6] = {
        30,   // Row 1
        31,   // Row 2
        32,   // Row 3
        33,   // Row 4
        34,   // Row 5
        35    // Row 6
    };

    const int lines[14] = {
        36,   // Column 1
        37,   // Column 2
        38,   // Column 3
        39,   // Column 4
        40,   // Column 5
        41,   // Column 6
        42,   // Column 7
        43,   // Column 8
        44,   // Column 9
        45,   // Column 10
        46,   // Column 11
        47,   // Column 12
        48,   // Column 13
        49    // Column 14
    };

#elif defined(_6X18_MATRIX_)
    // 6x18 Matrix Layout
    const int rows[6] = {
        30,   // Row 1
        31,   // Row 2
        32,   // Row 3
        33,   // Row 4
        34,   // Row 5
        35    // Row 6
    };

    const int lines[18] = {
        36,   // Column 1
        37,   // Column 2
        38,   // Column 3
        39,   // Column 4
        40,   // Column 5
        41,   // Column 6
        42,   // Column 7
        43,   // Column 8
        44,   // Column 9
        45,   // Column 10
        46,   // Column 11
        47,   // Column 12
        48,   // Column 13
        49,   // Column 14
        50,   // Column 15
        51,   // Column 16
        52,   // Column 17
        53    // Column 18
    };

#else
    #error "No valid keyboard layout defined! Define a valid keyboard layout such as _6X6_MATRIX_, _5X12_MATRIX_, _6X14_MATRIX_, _6X18_MATRIX_, or _SPLIT_6X6_MATRIX_"
#endif
