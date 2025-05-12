#pragma once

#include "HID-Project.h"
#include "HID-Settings.h"

#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   64

#define KEY_LAYER_UP 0xE8
#define KEY_LAYER_DOWN 0xE9

#define _4X6_MATRIX_
//#define _6X6_MATRIX_ 
//#define _5X12_MATRIX_
#define _6X14_MATRIX_
//#define _6X18_MATRIX_

#define COLS2ROWS // Remove for ROWS2COL diode configuration
#define LEFT_SIDE // define keyboard side firmware (define LEFT_SIDE for one side Keyboard)


#ifdef LEFT_SIDE

#define ENCODER_A MEDIA_VOL_UP
#define ENCODER_B MEDIA_VOL_DOWN 

#endif

extern unsigned char keyConfig[3][4][6]; 