#pragma once

#include <Arduino.h>


#include <U8g2lib.h>
#include <Wire.h>

#include "Configuration.h"

#if defined(ARDUINO_ARCH_STM32)
    
    #pragma message "compile for STM32"
    #define EEPROM_START_ADDR 0x0801FC00
    #include <Keyboard.h>
    #include "Keys.h"
    #if defined(ARDUINO_BLUEPILL_F103C8)
        #include "PinConfig/stm32f103C8.h"
    #else
        #error "MCU not compatible"
    #endif
#elif defined(__AVR__)
    #include "HID-Project.h"
    #include "HID-Settings.h"
    #if defined(__AVR_ATmega32U4__)
        #include "PinConfig/atmega32u4.h"
    #elif defined(ARDUINO_ARCH_SAM)
        #include "PinConfig/at91sam3x8e.h" 
    #else
        #error "MCU not compatible"
    #endif
#endif


