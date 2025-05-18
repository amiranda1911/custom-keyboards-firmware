// STM32 Keyboard with Pin Definitions

// Reserved Pins
const int usb_pins[2] = {PA11, PA12};  // USB Pins (D− and D+)
const int i2c_pins[2] = {PB6, PB7};    // I2C Pins (SCL and SDA)
const int encoder_l_pins[4] = {
    PB4, // Encoder 1 A Pin
    PB5, // Encoder 1 B Pin
}; // Encoder Pins (A and B)

const int underglow_pin = PA_8;  // Underglow Left (RGB)



// Layout Definitions

#if defined(_4X6_MATRIX_)
    // 6x6 Matrix Layout
    const int rows[6] = {
        PC_14,   // Row 1
        PC_15,   // Row 2
        PA_0,    // Row 3
        PA_1,    // Row 4
    };

    const int lines[6] = {
        PA_9,    // Column 1
        PA_8,    // Column 2
        PB_15,   // Column 3
        PB_14,   // Column 4
        PB_13,   // Column 5
        PB_12    // Column 6
    };

#if defined(_6X6_MATRIX_)
    // 6x6 Matrix Layout
    const int rows[6] = {
        PC_14,   // Row 1
        PC_15,   // Row 2
        PA_0,    // Row 3
        PA_1,    // Row 4
        PA_2,    // Row 5
        PA_3     // Row 6
    };

    const int lines[6] = {
        PA_9,    // Column 1
        PA_8,    // Column 2
        PB_15,   // Column 3
        PB_14,   // Column 4
        PB_13,   // Column 5
        PB_12    // Column 6
    };

#elif defined(_5X12_MATRIX_)
    // 5x12 Matrix Layout
    const int rows[5] = {
        PC_14,   // Row 1
        PC_15,   // Row 2
        PA_0,    // Row 3
        PA_1,    // Row 4
        PA_2     // Row 5
    };

    const int lines[12] = {
        PA_9,    // Column 1
        PA_8,    // Column 2
        PB_15,   // Column 3
        PB_14,   // Column 4
        PB_13,   // Column 5
        PB_12,   // Column 6
        PA_5,    // Column 7
        PA_6,    // Column 8
        PA_7,    // Column 9
        PB_0,    // Column 10
        PB_1,    // Column 11
        PB_2     // Column 12
    };

#elif defined(_6X14_MATRIX_)
    // 6x14 Matrix Layout
    const int rows[6] = {
        PC_14,   // Row 1
        PC_15,   // Row 2
        PA_0,    // Row 3
        PA_1,    // Row 4
        PA_2,    // Row 5
        PA_3     // Row 6
    };

    const int lines[14] = {
        PA_9,    // Column 1
        PA_8,    // Column 2
        PB_15,   // Column 3
        PB_14,   // Column 4
        PB_13,   // Column 5
        PB_12,   // Column 6
        PA_5,    // Column 7
        PA_6,    // Column 8
        PA_7,    // Column 9
        PB_0,    // Column 10
        PB_1,    // Column 11
        PB_2,    // Column 12
        PB_3,    // Column 13
        PB_4     // Column 14
    };

#elif defined(_6X18_MATRIX_)
    // 6x18 Matrix Layout
    const int rows[6] = {
        PC_14,   // Row 1
        PC_15,   // Row 2
        PA_0,    // Row 3
        PA_1,    // Row 4
        PA_2,    // Row 5
        PA_3     // Row 6
    };

    const int lines[18] = {
        PA_9,    // Column 1
        PA_8,    // Column 2
        PB_15,   // Column 3
        PB_14,   // Column 4
        PB_13,   // Column 5
        PB_12,   // Column 6
        PA_5,    // Column 7
        PA_6,    // Column 8
        PA_7,    // Column 9
        PB_0,    // Column 10
        PB_1,    // Column 11
        PB_2,    // Column 12
        PB_3,    // Column 13
        PB_4,    // Column 14
        PB_5,    // Column 15
        PB_6,    // Column 16
        PB_7,    // Column 17
        PB_8     // Column 18
    };

#else
    #error "No valid keyboard layout defined! Define a valid keyboard layout such as _6X6_MATRIX_, _5X12_MATRIX_, _6X14_MATRIX_, _6X18_MATRIX_, or _SPLIT_6X6_MATRIX_"
#endif