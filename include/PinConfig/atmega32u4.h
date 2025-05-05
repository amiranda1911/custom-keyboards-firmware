#pragma once
#include <Arduino.h>
// Arduino Leonardo Keyboard with Pin Definitions

// Reserved Pins

const int i2c_pins[2] = { SCL, SDA };    // I2C Pins (SCL and SDA)
const int encoder_pins[2] = {
    0, // Encoder 1 A Pin
    1  // Encoder 1 B Pin
}; // Encoder Pins (A and B)

// Underglow Pins (opcional, LED underglow control)
const int underglow_pin = 4;  // Underglow Left (RGB)

// Layout Definitions

#if defined(_6X6_MATRIX_)
    // 6x6 Matrix Layout
    const int rows[6] = {
        5,   // Row 1
        6,   // Row 2
        7,   // Row 3
        8,   // Row 4
        9,   // Row 5
        10   // Row 6
    };

    const int lines[6] = {
        11,   // Column 1
        12,   // Column 2
        13,   // Column 3
        A0,   // Column 4
        A1,   // Column 5
        A2    // Column 6
    };

#elif defined(_5X12_MATRIX_)
    // 5x12 Matrix Layout
    const int rows[5] = {
        5,    // Row 1
        6,    // Row 2
        7,    // Row 3
        8,    // Row 4
        9     // Row 5
    };

    const int lines[12] = {
        10,   // Column 1
        11,   // Column 2
        12,   // Column 3
        13,   // Column 4
        A0,   // Column 5
        A1,   // Column 6
        A2,   // Column 7
        A3,   // Column 8
        A4,   // Column 9
        A5,   // Column 10
        2,    // Column 11
        3     // Column 12
    };

#elif defined(_6X14_MATRIX_)
    // 6x14 Matrix Layout
    const int rows[6] = {
        4,    // Row 1
        5,    // Row 2
        6,    // Row 3
        7,    // Row 4
        8,    // Row 5
        9     // Row 6
    };

    const int lines[14] = {
        10,   // Column 1
        11,   // Column 2
        12,   // Column 3
        13,   // Column 4
        A0,   // Column 5
        A1,   // Column 6
        A2,   // Column 7
        A3,   // Column 8
        A4,   // Column 9
        A5,   // Column 10
        2,    // Column 11
        3,    // Column 12
        0,    // Column 13 (RX)
        1     // Column 14 (TX)
    };

#elif defined(_6X18_MATRIX_)
    // 6x18 Matrix Layout
    const int rows[6] = {
        4,    // Row 1
        5,    // Row 2
        6,    // Row 3
        7,    // Row 4
        8,    // Row 5
        9     // Row 6
    };

    const int lines[18] = {
        10,   // Column 1
        11,   // Column 2
        12,   // Column 3
        13,   // Column 4
        A0,   // Column 5
        A1,   // Column 6
        A2,   // Column 7
        A3,   // Column 8
        A4,   // Column 9
        A5,   // Column 10
        2,    // Column 11
        3,    // Column 12
        0,    // Column 13
        1,    // Column 14
        14,   // Column 15 (usar com cuidado)
        15,   // Column 16 (usar com cuidado)
        16,   // Column 17 (usar com cuidado)
        17    // Column 18 (usar com cuidado)
    };


#else
    #error "No valid keyboard layout defined! Define a valid keyboard layout such as _6X6_MATRIX_, _5X12_MATRIX_, _6X14_MATRIX_, _6X18_MATRIX_, or _SPLIT_6X6_MATRIX_"
#endif
