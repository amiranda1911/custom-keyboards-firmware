#include "Configuration.h"

unsigned char layersCount = 3;


#ifdef LEFT_SIDE

unsigned char keyConfig[3][4][6] = 
{
    //layer 0
    {
      {KEY_ESC,   KEY_Q,  KEY_W,  KEY_E,    KEY_R,    KEY_T}, 
      {KEY_TAB,   KEY_A,  KEY_S,  KEY_D,    KEY_F,    KEY_G},
      {KEY_LEFT_SHIFT,  KEY_Z,  KEY_X,  KEY_C,    KEY_V,    KEY_B},
      {     KEY_LEFT_CTRL , KEY_LEFT_ALT, KEY_LEFT_GUI, KEY_LAYER_UP, KEY_ENTER, MEDIA_VOL_MUTE}
    },
    //layer 1
    {
      {HID_KEYBOARD_GRAVE_ACCENT_AND_TILDE, KEY_1,  KEY_2,  KEY_3,    KEY_4,    KEY_5}, 
      {KEY_ESC,   KEY_Q,  KEY_W,  KEY_E,    KEY_R,    KEY_T}, 
      {KEY_TAB,   KEY_A,  KEY_S,  KEY_D,    KEY_F,    KEY_G},
      {     KEY_LEFT_CTRL , KEY_LEFT_ALT, KEY_LEFT_GUI, KEY_LAYER_UP, KEY_ENTER, MEDIA_VOL_MUTE}
    },
    //layer 2
    {
      {KEY_F1,    KEY_F2,  KEY_F3,    KEY_F4,    KEY_F5, KEY_F6}, 
      {KEY_ESC,   KEY_Q,  KEY_W,  KEY_E,    KEY_R,    KEY_T}, 
      {KEY_TAB,   KEY_A,  KEY_S,  KEY_D,    KEY_F,    KEY_G},
      {     KEY_LEFT_CTRL , KEY_LEFT_ALT, KEY_LEFT_GUI, KEY_LAYER_UP, KEY_ENTER, MEDIA_VOL_MUTE}
    }
  };

#else


extern unsigned char keyConfig[4][6]  = {
  KEY_6,    KEY_7,    KEY_8,    KEY_9,    KEY_0,  KEY_BACKSPACE,
  KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,  KEY_ENTER,
  KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SEMICOLON,  KEY_QUOTE,
  0x00,     KEY_N,    KEY_M,    KEY_COMMA, KEY_PERIOD, KEY_SLASH,  KEY_RIGHT_SHIFT,
  KEY_SPACE,  0xE9, KEY_RIGHT_GUI, KEY_RIGHT_ALT, KEY_RIGHT_CTRL
};

#endif

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Entr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
