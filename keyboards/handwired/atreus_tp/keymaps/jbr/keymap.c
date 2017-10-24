// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus_tp.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NORM  0
#define _SHIFT 1
#define _SYM   2
#define _FUNC  3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NORM] = {
  {KC_Q,             KC_W,        KC_E,    KC_R,    KC_T,      KC_TRNS,       KC_Y,            KC_U,     KC_I,          KC_O,     KC_P             },
  {KC_A,             KC_S,        KC_D,    KC_F,    KC_G,      KC_TRNS,       KC_H,            KC_J,     KC_K,          KC_L,     KC_QUOTE         },
  {KC_Z,             KC_X,        KC_C,    KC_V,    KC_B,      ALT_T(KC_ESC), KC_N,            KC_M,     KC_COMM,       KC_DOT,   KC_SLSH          },
  {LT(_SHIFT, TO(_SYM)),       KC_GRV,KC_LCTL, KC_TAB, KC_SPC,    GUI_T(KC_ESC), KC_BSPC,         KC_ENT,   KC_NONUS_HASH, KC_MINUS, MO(_SHIFT)              }
},
[_SHIFT] = {
//insert shifted keys here for more control
  {S(KC_Q),             S(KC_W),        S(KC_E),    S(KC_R),    S(KC_T),      KC_TRNS,       S(KC_Y),            S(KC_U),     S(KC_I),          S(KC_O),     S(KC_P)             },
  {S(KC_A),             S(KC_S),        S(KC_D),    S(KC_F),    S(KC_G),      KC_TRNS,       S(KC_H),            S(KC_J),     S(KC_K),          S(KC_L),     S(KC_QUOTE)         },
  {S(KC_Z),             S(KC_X),        S(KC_C),    S(KC_V),    S(KC_B),      KC_TRNS,       S(KC_N),            S(KC_M),     S(KC_COMM),       S(KC_DOT),   S(KC_SLSH)          },
  {KC_TRNS,             S(KC_NONUS_BSLASH), KC_TRNS,KC_TAB,     KC_SPC,       KC_TRNS,       KC_DELETE,          KC_ENT,      S(KC_NONUS_HASH), S(KC_MINUS), KC_TRNS             }
},
[_SYM] = {
  {KC_EXLM,          KC_AT,       KC_HASH, KC_DLR,  KC_PERC,   KC_TRNS,       KC_NONUS_BSLASH, KC_7,     KC_8,          KC_9,     KC_PLUS          },
  {KC_CIRC,          KC_AMPR,     KC_ASTR, KC_LPRN, KC_RPRN,   KC_TRNS,       KC_COLN,         KC_4,     KC_5,          KC_6,     KC_PEQL          },
  {KC_LBRACKET,      KC_RBRACKET, KC_LCBR, KC_RCBR, KC_SCOLON, KC_TRNS,       KC_DOT,          KC_1,     KC_2,          KC_3,     KC_NO            },
  {KC_TRNS,         KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,       KC_BSPC,         KC_TRNS,  KC_0,          KC_NO,    TO(_NORM)        }
},
[_FUNC] = {
  {BL_INC,           KC_HOME,     KC_UP,   KC_END,  KC_PGUP,   KC_TRNS,       KC_VOLU,        KC_F7,    KC_F8,         KC_F9,    KC_F10           },
  {BL_DEC,           KC_LEFT,     KC_DOWN, KC_RGHT, KC_PGDN,   KC_TRNS,       KC_VOLD,        KC_F4,    KC_F5,         KC_F6,    KC_F11           },
  {RESET,            RGB_HUI,     KC_MRWD, KC_MPLY, KC_MRWD,   KC_TRNS,       KC_MUTE,        KC_F1,    KC_F2,         KC_F3,    KC_F12           },
  {TO(_NORM),        RGB_HUD,     KC_TRNS, RGB_SAI, RGB_SAD,   KC_TRNS,       RGB_VAI,        RGB_VAD,  RGB_MOD,       RGB_TOG,  TO(_FUNC)        }
}};

