#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

enum iris_layers {
  MAC = 0,
  LINUX,
  RAISELEFT,
  RAISERIGHT,
  LOWERLEFT,
  LOWERRIGHT
};

enum iris_keycodes {
  KC_LOM = SAFE_RANGE, // Switch default layer between MAC og LINUX
  KC_LST, // Print layer state
  KC_AE, // Danish AE
  KC_OSLH,// Danish OSLASH
  KC_ARNG, // Danish ARING
  KC_LAY // Print layout URL
};

#define KC_ KC_TRNS

// MAC GUI
#define KC_MGZ MT(MOD_LGUI, KC_Z)
#define KC_MGSH MT(MOD_RGUI, KC_SLSH)
// MAC CTRL
#define KC_MCV MT(MOD_LCTL, KC_V)
#define KC_MCM MT(MOD_RCTL, KC_M)

// LINUX GUI
#define KC_LGV MT(MOD_LGUI, KC_V)
#define KC_LGM MT(MOD_RGUI, KC_M)
// LINUX CTRL
#define KC_LCZ MT(MOD_LCTL, KC_Z)
#define KC_LCSH MT(MOD_RCTL, KC_SLSH)

// ALT
#define KC_ALB MT(MOD_LALT, KC_B)
#define KC_ALN MT(MOD_RALT, KC_N)
// SHIFT
#define KC_SNO KC_LSFT
#define KC_SENT MT(MOD_RSFT, KC_ENT)
// UPPER LAYER
#define KC_ULC LT(RAISELEFT, KC_C)
#define KC_ULCO LT(RAISERIGHT, KC_COMM)
// LOWER LAYER
#define KC_LLX LT(LOWERLEFT, KC_X)
#define KC_LLDO LT(LOWERRIGHT, KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       ESC, Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , DEL,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       TAB, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,BSPC,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       SNO, MGZ, LLX, ULC, MCV, ALB,                ALN, MCM,ULCO,LLDO,MGSH,SENT,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      HOME,PGDN,PGUP, END, NO ,SPC , NO ,      NO , SPC, NO ,LEFT,DOWN, UP ,RGHT,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,         NO , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LINUX] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
          ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          , LCZ,    ,    , LGV,    ,                   , LGM,    ,    ,LCSH,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,    ,            ,    ,
   //                   `----+----+----'       `----+----+----'
  ),
  [RAISELEFT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 , F10, F11, F12,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,                NO , NO , NO , NO , NO , NO ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       LOM, NO , NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO , LAY,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,        NO  , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [RAISERIGHT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 , F10, F11, F12,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , NO , NO , NO , NO , NO ,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       LOM, LST, NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO , LAY,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,        NO  , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LOWERLEFT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       NO , GRV, DQT, NO ,TILD, NO ,               PLUS,MINS, EQL,LBRC,RBRC, NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,EXLM, AT ,HASH, DLR,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN, NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,               OSLH, AE ,ARNG,LCBR,RCBR, NO ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      MRWD,MSTP,MPLY,MFFD, NO , NO,  NO ,      NO , NO , NO ,MUTE,VOLD,VOLU, NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,         NO , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LOWERRIGHT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       NO , GRV, DQT, NO ,TILD, NO ,               PLUS,MINS, EQL,LBRC,RBRC, NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,EXLM, AT ,HASH, DLR,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN, NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,BSLS,QUOT,UNDS,PIPE, NO ,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      MRWD,MSTP,MPLY,MFFD, NO , NO,  NO ,      NO , NO , NO ,MUTE,VOLD,VOLU, NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,         NO , NO , NO
   //                   `----+----+----'       `----+----+----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint32_t layer_state;

  // Use current layer to send correct keycode for Danish letters
  if (record->event.pressed) {
    switch (keycode) {
      case KC_AE:
        layer_state_is(LINUX) ? SEND_STRING(SS_RALT("z")) : SEND_STRING(SS_RALT("\""));
        return false;
        break;
      case KC_OSLH:
        layer_state_is(LINUX) ? SEND_STRING(SS_RALT("l")) : SEND_STRING(SS_RALT("o"));
        return false;
        break;
      case KC_ARNG:
        layer_state_is(LINUX) ? SEND_STRING(SS_RALT("w")) : SEND_STRING(SS_RALT("a"));
        return false;
        break;
        // Show keyboard layout in new tab in browser
      case KC_LAY:
        if(layer_state_is(LINUX)) {
          SEND_STRING(SS_LCTRL("t")"http://www.keyboard-layout-editor.com/#/gists/02e24edc4a606f3bd42e12cd3ae656c5"SS_TAP(X_ENTER));
        } else {
          SEND_STRING(SS_LGUI("t")"http://www.keyboard-layout-editor.com/#/gists/02e24edc4a606f3bd42e12cd3ae656c5"SS_TAP(X_ENTER));
        }
        return false;
        break;
      case KC_LOM:
        // Toggle between MAC and LINUX layouts
        layer_state = layer_state_is(LINUX) ? (1UL << MAC) : (1UL << MAC) | (1UL << LINUX);
        default_layer_set(layer_state);
        layer_state_set(layer_state);
        eeconfig_update_default_layer(layer_state);
        return false;
        break;
        // Print which OS layer is on
      case KC_LST:
        layer_state_is(LINUX) ? SEND_STRING("LINUX") : SEND_STRING("MAC");
        return false;
        break;
    }
  }
  return true;
}
