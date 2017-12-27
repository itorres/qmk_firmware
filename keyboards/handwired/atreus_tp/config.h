/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0x1209
#define PRODUCT_ID      0xA1E5
#define DEVICE_VER      0x0009
#define MANUFACTURER    Technomancy
#define PRODUCT         Atreus_tp
#define DESCRIPTION     q.m.k. keyboard firmware for Atreus

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 11

// Change this to how you wired your keyboard
// COLS: Left to right, ROWS: Top to bottom
#define MATRIX_ROW_PINS { F7, F6, F5, F4 }
#define MATRIX_COL_PINS { B6, B5, B4, B3, B2, B1, D4, D3, D2, D1, D0 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
//#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#ifdef PS2_USE_INT
#define PS2_CLOCK_PORT  PORTE
#define PS2_CLOCK_PIN   PINE
#define PS2_CLOCK_DDR   DDRE
#define PS2_CLOCK_BIT   6
#define PS2_DATA_PORT   PORTD
#define PS2_DATA_PIN    PIND
#define PS2_DATA_DDR    DDRD
#define PS2_DATA_BIT    7

#define PS2_INT_INIT()  do {    \
    EICRB |= ((1<<ISC61) |      \
              (0<<ISC60));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT6);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT6);        \
} while (0)
#define PS2_INT_VECT INT6_vect
#define PS2_MOUSE_DEBUG_HID
#define PS2_MOUSE_DEBUG_RAW
#endif

#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y
#define PS2_MOUSE_INVERT_H
#define PS2_MOUSE_INVERT_V
#define PS2_MOUSE_SCROLL_DIVISOR_V 2
#define PS2_MOUSE_SCROLL_DIVISOR_H 2

#define RGB_DI_PIN C6
#define RGBLED_NUM 3
#define RGBLIGHT_ANIMATIONS

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
