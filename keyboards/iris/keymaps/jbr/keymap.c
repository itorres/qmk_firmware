#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

enum iris_layers {
  DEFAULT = 0,
  LINUX,
  MAC,
  RAISELEFT,
  RAISERIGHT,
  LOWERLEFT,
  LOWERRIGHT
};

enum iris_keycodes {
  KC_AE = SAFE_RANGE, // Danish AE
  KC_OSLH,            // Danish OSLASH
  KC_ARNG,            // Danish ARING
  KC_CHKM,            // Change keymap
  KC_LAY              // Print layout URL
};

#define KC_ KC_TRNS

// MAC GUI
#define KC_MZM MT(MOD_LGUI, KC_Z)
#define KC_MSLM MT(MOD_RGUI, KC_SLSH)
// MAC CTRL
#define KC_MVM MT(MOD_LCTL, KC_V)
#define KC_MMM MT(MOD_RCTL, KC_M)

// LINUX GUI
#define KC_MVL MT(MOD_LGUI, KC_V)
#define KC_MML MT(MOD_RGUI, KC_M)
// LINUX CTRL
#define KC_MZL MT(MOD_LCTL, KC_Z)
#define KC_MSLL MT(MOD_RCTL, KC_SLSH)

// ALT
#define KC_ALB MT(MOD_LALT, KC_B)
#define KC_ALN MT(MOD_RALT, KC_N)
// SHIFT
#define KC_SSPC MT(MOD_LSFT, KC_SPC)
#define KC_SENT MT(MOD_RSFT, KC_ENT)
// UPPER LAYER
#define KC_ULC LT(RAISELEFT, KC_C)
#define KC_ULCO LT(RAISERIGHT, KC_COMM)
// LOWER LAYER
#define KC_LLX LT(LOWERLEFT, KC_X)
#define KC_LLDO LT(LOWERRIGHT, KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       TAB, Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , DEL,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       ESC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,BSPC,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      BSLS, NO , LLX, ULC, NO , ALB,                ALN, NO ,ULCO,LLDO, NO ,MINS,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      HOME,PGDN,PGUP, END, NO ,SENT, NO ,      NO ,SSPC, NO ,LEFT,DOWN, UP ,RGHT,
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
          , MZL,    ,    , MVL,    ,                   , MML,    ,    ,MSLL,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,    ,            ,    ,
   //                   `----+----+----'       `----+----+----'
  ),
  [MAC] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
          ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          , MZM,    ,    , MVM,    ,                   , MMM,    ,    ,MSLM,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,    ,            ,    ,
   //                   `----+----+----'       `----+----+----'
  ),
  [RAISELEFT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       NO , GRV, AT ,TILD, NO , NO ,                NO ,PLUS, EQL,LBRC,RBRC,ARNG,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,EXLM, DQT,HASH, DLR,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,OSLH,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,    ,    ,    ,    ,    ,                NO , NO , NO ,LCBR,RCBR, AE ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      MRWD,MSTP,MPLY,MFFD, NO ,   ,  NO ,      NO , NO , NO ,MUTE,VOLD,VOLU, NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,         NO , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [RAISERIGHT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       NO , GRV, AT ,TILD, NO , NO ,                NO ,PLUS, EQL,LBRC,RBRC,ARNG,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,EXLM, DQT,HASH, DLR,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,OSLH,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , NO ,QUOT, NO , NO , NO ,                   ,    ,    ,    ,    , AE ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      MRWD,MSTP,MPLY,MFFD, NO , NO,  NO ,      NO ,    , NO ,MUTE,VOLD,VOLU, NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,         NO , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LOWERLEFT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 , F10, F11, F12,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,    ,    ,    ,    ,    ,                NO , NO , NO , NO , NO , NO ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      CHKM, NO , NO , NO , NO ,    , NO ,      NO , NO , NO , NO , NO , NO , LAY ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,        NO  , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LOWERRIGHT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 , F10, F11, F12,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , NO , NO , NO , NO , NO ,                   ,    ,    ,    ,    , NO ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      CHKM, NO , NO , NO , NO , NO , NO ,      NO ,    , NO , NO , NO , NO , NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,        NO  , NO , NO
   //                   `----+----+----'       `----+----+----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Fetch keymap from eeprom
  uint8_t keymap = eeconfig_read_keymap();

  if (record->event.pressed) {
    switch (keycode) {
      case KC_AE:
        keymap == LINUX ? SEND_STRING(SS_RALT("z")) : SEND_STRING(SS_RALT("\""));
        return false;
      case KC_OSLH:
        keymap == LINUX ? SEND_STRING(SS_RALT("l")) : SEND_STRING(SS_RALT("o"));
        return false;
      case KC_ARNG:
        keymap == LINUX ? SEND_STRING(SS_RALT("w")) : SEND_STRING(SS_RALT("a"));
        return false;
      case KC_LAY:
        // Show keyboard layout in new tab in browser
        if (keymap == LINUX) {
          SEND_STRING(SS_LCTRL("t")"http://www.keyboard-layout-editor.com/#/gists/a5b0ab213362103dcd2cda16c42f0a0e"SS_TAP(X_ENTER));
        } else {
          SEND_STRING(SS_LGUI("t")"http://www.keyboard-layout-editor.com/#/gists/a5b0ab213362103dcd2cda16c42f0a0e"SS_TAP(X_ENTER));
        }
        return false;
      case KC_CHKM:
        layer_off(keymap);
        keymap = keymap == LINUX ? MAC : LINUX;
        eeconfig_update_keymap(keymap);
        layer_on(keymap);
        return false;
    }
  }
  return true;
}

void matrix_init_user(void) {
  // Fetch keymap from eeprom
  uint8_t keymap = eeconfig_read_keymap();
  // If keymap has never been set, write default keymap to eeprom
  if (keymap == 0) {
    keymap = LINUX;
    eeconfig_update_keymap(keymap);
  }
  // Turn on keymap from eeprom
  layer_on(keymap);
}
