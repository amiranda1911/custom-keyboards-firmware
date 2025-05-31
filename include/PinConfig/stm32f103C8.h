// STM32 Keyboard with Pin Definitions

// Reserved Pins
const int usb_pins[2] = {PA11, PA12};  // USB Pins (D− and D+)
const int i2c_pins[2] = {PB6, PB7};    // I2C Pins (SCL and SDA)
const int encoder_pins[4] = {
    PB4, // Encoder 1 A Pin
    PB5, // Encoder 1 B Pin
}; // Encoder Pins (A and B)

const int underglow_pin = PA8;  // Underglow Left (RGB)



// Layout Definitions

#if defined(_4X6_MATRIX_)
    // 6x6 Matrix Layout
    const int pinRows[6] = {
        PC14,   // Row 1
        PC15,   // Row 2
        PA0,    // Row 3
        PA1,    // Row 4
    };

    const int pinCols[6] = {
        PB12,   // Column 6
        PB13,   // Column 5
        PB14,   // Column 4
        PB15,   // Column 3
        PA8,    // Column 2
        PA9     // Column 1
    };

const int ledRows[4] = {
    PB0,   // Led Row 1
    PB1,  // Led Row 2
    PB10,   // Led Row 3
    PB11   // Led Row 4
};

const int ledCols[6] = {
    PA7,   // Led Column 1
    PA6,   // Led Column 2
    PA5,   // Led Column 3
    PA4,  // Led Column 4
    PA3,  // Led Column 5
    PA2   // Led Column 6 (livre e seguro)
};



#elif defined(_6X6_MATRIX_)
    // 6x6 Matrix Layout
    const int pinRows[6] = {
        PC14,   // Row 1
        PC15,   // Row 2
        PA0,    // Row 3
        PA1,    // Row 4
        PA2,    // Row 5
        PA3     // Row 6
    };

    const int pinCols[6] = {
        PA9,    // Column 1
        PA8,    // Column 2
        PB15,   // Column 3
        PB14,   // Column 4
        PB13,   // Column 5
        PB12    // Column 6
    };

#elif defined(_5X12_MATRIX_)
    // 5x12 Matrix Layout
    const int pinRows[5] = {
        PC14,   // Row 1
        PC15,   // Row 2
        PA0,    // Row 3
        PA1,    // Row 4
        PA2     // Row 5
    };

    const int pinCols[12] = {
        PA9,    // Column 1
        PA8,    // Column 2
        PB15,   // Column 3
        PB14,   // Column 4
        PB13,   // Column 5
        PB12,   // Column 6
        PA5,    // Column 7
        PA6,    // Column 8
        PA7,    // Column 9
        PB0,    // Column 10
        PB1,    // Column 11
        PB2     // Column 12
    };

#elif defined(_6X14_MATRIX_)
    // 6x14 Matrix Layout
    const int pinRows[6] = {
        PC14,   // Row 1
        PC15,   // Row 2
        PA0,    // Row 3
        PA1,    // Row 4
        PA2,    // Row 5
        PA3     // Row 6
    };

    const int pinCols[14] = {
        PA9,    // Column 1
        PA8,    // Column 2
        PB15,   // Column 3
        PB14,   // Column 4
        PB13,   // Column 5
        PB12,   // Column 6
        PA5,    // Column 7
        PA6,    // Column 8
        PA7,    // Column 9
        PB0,    // Column 10
        PB1,    // Column 11
        PB2,    // Column 12
        PB3,    // Column 13
        PB4     // Column 14
    };

#elif defined(_6X18_MATRIX_)
    // 6x18 Matrix Layout
    const int pinRows[6] = {
        PC14,   // Row 1
        PC15,   // Row 2
        PA0,    // Row 3
        PA1,    // Row 4
        PA2,    // Row 5
        PA3     // Row 6
    };

    const int pinCols[18] = {
        PA9,    // Column 1
        PA8,    // Column 2
        PB15,   // Column 3
        PB14,   // Column 4
        PB13,   // Column 5
        PB12,   // Column 6
        PA5,    // Column 7
        PA6,    // Column 8
        PA7,    // Column 9
        PB0,    // Column 10
        PB1,    // Column 11
        PB2,    // Column 12
        PB3,    // Column 13
        PB4,    // Column 14
        PB5,    // Column 15
        PB6,    // Column 16
        PB7,    // Column 17
        PB8     // Column 18
    };

#else
    #error "No valid keyboard layout defined! Define a valid keyboard layout such as _6X6_MATRIX_, _5X12_MATRIX_, _6X14_MATRIX_, _6X18_MATRIX_, or _SPLIT_6X6_MATRIX_"
#endif