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
  KC_AE, // Danish AE
  KC_OSLH,// Danish OSLASH
  KC_ARNG, // Danish ARING
  KC_LAY // Print layout URL
};

#define KC_ KC_TRNS

// MAC GUI
#define KC_MGA MT(MOD_LGUI, KC_A)
#define KC_MGSC MT(MOD_RGUI, KC_SCLN)
// MAC CTRL
#define KC_MCF MT(MOD_LCTL, KC_F)
#define KC_MCJ MT(MOD_RCTL, KC_J)

// LINUX GUI
#define KC_LGF MT(MOD_LGUI, KC_F)
#define KC_LGJ MT(MOD_RGUI, KC_J)
// LINUX CTRL
#define KC_LCA MT(MOD_LCTL, KC_A)
#define KC_LCSC MT(MOD_RCTL, KC_SCLN)

// ALT
#define KC_ALG MT(MOD_LALT, KC_G)
#define KC_ALH MT(MOD_RALT, KC_H)
// SHIFT
#define KC_STAB MT(MOD_LSFT, KC_TAB)
#define KC_SBSP MT(MOD_RSFT, KC_BSPC)
// UPPER LAYER
#define KC_ULD LT(RAISELEFT, KC_D)
#define KC_ULK LT(RAISERIGHT, KC_K)
// LOWER LAYER
#define KC_LLS LT(LOWERLEFT, KC_S)
#define KC_LLL LT(LOWERRIGHT, KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       ESC, Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , DEL,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      STAB, MGA, LLS, ULD, MCF, ALG,                ALH, MCJ, ULK, LLL,MGSC,SBSP,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , Z  , X  , C  , V  , B  ,                N  , M  ,COMM, DOT,SLSH, ENT,
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
          , LCA,    ,    , LGF,    ,                   , LGJ,    ,    ,LCSC,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
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
          ,    ,    ,    ,    ,    ,                6  , 7  , 8  , 9  , 0  , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , NO , NO , NO , NO , NO ,                NO , NO , NO , NO , NO , NO ,
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
       NO , 1  , 2  , 3  , 4  , 5  ,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , NO , NO , NO , NO , NO ,                NO , NO , NO , NO , NO , NO ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       LOM, NO , NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO , LAY,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,        NO  , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LOWERLEFT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       NO , GRV, DQT, NO ,TILD, NO ,               PLUS,MINS, EQL,LBRC,RBRC, NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,               CIRC,AMPR,ASTR,LPRN,RPRN, NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,BSLS,QUOT,UNDS,PIPE, NO ,               OSLH, AE ,ARNG,LCBR,RCBR, NO ,
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
       NO ,EXLM, AT ,HASH, DLR,PERC,                   ,    ,    ,    ,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,BSLS,QUOT,UNDS,PIPE, NO ,               OSLH, AE ,ARNG,LCBR,RCBR, NO ,
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
        // Toggle between MAC and LINUX layouts
      case KC_LAY:
        SEND_STRING("http://www.keyboard-layout-editor.com/#/gists/02e24edc4a606f3bd42e12cd3ae656c5"SS_TAP(X_ENTER));
        return false;
        break;
      case KC_LOM:
        layer_state = layer_state_is(LINUX) ? (1UL << MAC) : (1UL << MAC) | (1UL << LINUX);
        default_layer_set(layer_state);
        layer_state_set(layer_state);
        eeconfig_update_default_layer(layer_state);
        return false;
        break;
    }
  }
  return true;
}
