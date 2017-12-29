#include "atreus_tp.h"

enum states {
  NORM = 0,
  SHIFT,
  SYM,
  FUNC
};

enum {
  TD_SYM = 0,
  TD_FUNC = 1
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPPLE_TAP = 5,
  ABORT = 99
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [NORM] = {
    {KC_Q,       KC_W,    KC_E,     KC_R,    KC_T,    KC_TRNS,        KC_Y,     KC_U,    KC_I,           KC_O,      KC_P},
    {KC_A,       KC_S,    KC_D,     KC_F,    KC_G,    KC_TRNS,        KC_H,     KC_J,    KC_K,           KC_L,      KC_QUOTE},
    {KC_Z,       KC_X,    KC_C,     KC_V,    KC_B,    ALT_T(KC_ESC),  KC_N,     KC_M,    KC_COMM,        KC_DOT,    KC_SLSH},
    {TD(TD_FUNC),  KC_GRV,  OSM(MOD_LCTL),  KC_TAB,  KC_SPC,  GUI_T(KC_ESC),    KC_ENT,  KC_BSPC, KC_NONUS_HASH,  KC_MINUS, TD(TD_SYM)}
  },
  [SHIFT] = {
    {S(KC_Q),  S(KC_W),             S(KC_E),  S(KC_R),  S(KC_T),  KC_TRNS,  S(KC_Y),    S(KC_U),  S(KC_I),           S(KC_O),      S(KC_P)},
    {S(KC_A),  S(KC_S),             S(KC_D),  S(KC_F),  S(KC_G),  KC_TRNS,  S(KC_H),    S(KC_J),  S(KC_K),           S(KC_L),      S(KC_QUOTE)},
    {S(KC_Z),  S(KC_X),             S(KC_C),  S(KC_V),  S(KC_B),  KC_TRNS,  S(KC_N),    S(KC_M),  S(KC_COMM),        S(KC_DOT),    S(KC_SLSH)},
    {KC_TRNS, S(KC_NONUS_BSLASH),  KC_TRNS,  KC_TAB,   KC_SPC,   KC_TRNS,   KC_ENT,   KC_DELETE,  S(KC_NONUS_HASH),  S(KC_MINUS),  KC_TRNS}
  },
  [SYM] = {
    {KC_EXLM,      KC_AT,        KC_HASH,  KC_DLR,   KC_PERC,    KC_TRNS,  KC_NONUS_BSLASH,  KC_7,     KC_8,  KC_9,   KC_PLUS},
    {KC_CIRC,      KC_AMPR,      KC_ASTR,  KC_LPRN,  KC_RPRN,    KC_TRNS,  KC_COLN,          KC_4,     KC_5,  KC_6,   KC_PEQL},
    {KC_LBRACKET,  KC_RBRACKET,  KC_LCBR,  KC_RCBR,  KC_SCOLON,  KC_TRNS,  KC_DOT,           KC_1,     KC_2,  KC_3,   KC_NO},
    {TO(NORM), LGUI(LALT(KC_EJCT)), KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,          KC_BSPC,   KC_0,  KC_NO, KC_TRNS}
  },
  [FUNC] = {
    {BL_INC,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_TRNS,  KC_VOLU,  KC_F7,    KC_F8,    KC_F9,    KC_F10},
    {BL_DEC,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  KC_TRNS,  KC_VOLD,  KC_F4,    KC_F5,    KC_F6,    KC_F11},
    {RESET,    RGB_HUI,  KC_MRWD,  KC_MPLY,  KC_MRWD,  KC_TRNS,  KC_MUTE,  KC_F1,    KC_F2,    KC_F3,    KC_F12},
    {KC_TRNS,  RGB_HUD,  KC_TRNS,  RGB_SAI,  RGB_SAD,  KC_TRNS,  RGB_VAI,  RGB_VAD,  RGB_MOD,  RGB_TOG,  TO(NORM)}
  }
};

static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || state->pressed==0) {
      return SINGLE_TAP;
    }
    else {
      return SINGLE_HOLD;
    }
  }
  else if (state->count == 2) {
    if (state->interrupted || state->pressed==0) {
      return DOUBLE_TAP;
    }
    else {
      return DOUBLE_HOLD;
    }
  }
  else if (state->count == 3) {
    if (state->interrupted || state->pressed==0) {
      return TRIPPLE_TAP;
    }
  }
  return 6;
}

void td_sym_finished(qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      if (layer_state_is(SYM)) {
        layer_off(SYM);
        xtap_state.state = ABORT;
      }
      else {
        set_oneshot_layer(SHIFT, ONESHOT_START);
      }
      break;
    case SINGLE_HOLD:
      layer_on(SHIFT);
      break;
    case DOUBLE_TAP:
      set_oneshot_layer(SYM, ONESHOT_START);
      break;
    case DOUBLE_HOLD:
    case TRIPPLE_TAP:
      layer_on(SYM);
      break;
  }
}

void td_func_finished(qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      if (layer_state_is(FUNC)) {
        layer_off(FUNC);
        xtap_state.state = ABORT;
      }
      else {
        set_oneshot_layer(SHIFT, ONESHOT_START);
      }
      break;
    case SINGLE_HOLD:
      layer_on(SHIFT);
      break;
    case DOUBLE_TAP:
      set_oneshot_layer(FUNC, ONESHOT_START);
      break;
    case DOUBLE_HOLD:
    case TRIPPLE_TAP:
      layer_on(FUNC);
      break;
  }
}

void td_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:
    case DOUBLE_TAP:
      clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;
    case SINGLE_HOLD:
    case DOUBLE_HOLD:
      layer_off(SHIFT);
      layer_off(SYM);
      layer_off(FUNC);
      break;
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SYM]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_sym_finished, td_reset),
  [TD_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_func_finished, td_reset)
};

