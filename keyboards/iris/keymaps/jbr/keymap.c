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
  KC_ARNG // Danish ARING
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
// UPPER LAYER
#define KC_ULD LT(RAISELEFT, KC_D)
#define KC_ULK LT(RAISERIGHT, KC_K)
// LOWER LAYER
#define KC_LLS LT(LOWERLEFT, KC_S)
#define KC_LLL LT(LOWERRIGHT, KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       TAB, Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       ESC, MGA, LLS, ULD, MCF, ALG,                ALH, MCJ, ULK, LLL,MGSC, ENT,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      LSFT, Z  , X  , C  , V  , B  ,                N  , M  ,COMM, DOT,SLSH,RSFT,
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
       NO ,EXLM, AT ,HASH, DLR,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN, DEL,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO ,    ,    ,    ,    ,    ,                6  , 7  , 8  , 9  , 0  , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          , DQT,QUOT, GRV,TILD,PIPE,               PLUS,MINS, EQL,UNDS,BSLS,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       NO , NO , NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO , NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,        NO  , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [RAISERIGHT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       NO ,EXLM, AT ,HASH, DLR,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN, DEL,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       NO , 1  , 2  , 3  , 4  , 5  ,                   ,    ,    ,    ,    , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          , DQT,QUOT, GRV,TILD,PIPE,               PLUS,MINS, EQL,UNDS,BSLS,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       NO , NO , NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO , NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,        NO  , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LOWERLEFT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 , F10, F11, F12,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       LOM,    ,    ,    ,    ,    ,                NO , NO , NO ,LCBR,RCBR, NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          , NO , NO , NO , NO , NO ,                AE ,OSLH,ARNG,LBRC,RBRC,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      MRWD,MSTP,MPLY,MFFD, NO , NO,  NO ,      NO , NO , NO ,MUTE,VOLD,VOLU, NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,         NO , NO , NO
   //                   `----+----+----'       `----+----+----'
  ),
  [LOWERRIGHT] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 , F10, F11, F12,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       LOM, NO , NO , NO , NO , NO ,                   ,    ,    ,    ,    , NO ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          , NO , NO , NO , NO , NO ,                AE ,OSLH,ARNG,LBRC,RBRC,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      MRWD,MSTP,MPLY,MFFD, NO , NO,  NO ,      NO , NO , NO ,MUTE,VOLD,VOLU, NO ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          NO , NO , NO ,         NO , NO , NO
   //                   `----+----+----'       `----+----+----'
  )
};

#define KC_LOSL RALT(KC_L)
#define KC_LAE  RALT(KC_Z)
#define KC_LARG RALT(KC_W)

#define KC_MOSL RALT(KC_O)
#define KC_MAE  RALT(KC_QUOT)
#define KC_MARG RALT(KC_A)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint32_t layer_state;

  // Use current layer to send correct keycode for Danish letters
  switch (keycode) {
    case KC_AE:
      if (record->event.pressed) {
        register_code(KC_RALT);
        layer_state_is(LINUX) ? register_code(KC_Z) : register_code(KC_QUOT);
      } else {
        unregister_code(KC_RALT);
        layer_state_is(LINUX) ? unregister_code(KC_Z) : unregister_code(KC_QUOT);
      }
      return false;
      break;
    case KC_OSLH:
      if (record->event.pressed) {
        register_code(KC_RALT);
        layer_state_is(LINUX) ? register_code(KC_L) : register_code(KC_O);
      } else {
        unregister_code(KC_RALT);
        layer_state_is(LINUX) ? unregister_code(KC_L) : unregister_code(KC_O);
      }
      return false;
      break;
    case KC_ARNG:
      if (record->event.pressed) {
        register_code(KC_RALT);
        layer_state_is(LINUX) ? register_code(KC_W) : register_code(KC_A);
      } else {
        unregister_code(KC_RALT);
        layer_state_is(LINUX) ? unregister_code(KC_W) : unregister_code(KC_A);
      }
      return false;
      break;
    // Toggle between MAC and LINUX layouts
    case KC_LOM:
      if (record->event.pressed) {
        if(layer_state_is(LINUX)) {
          layer_state = (1UL << MAC);
        }
        else {
          layer_state = (1UL << MAC) | (1UL << LINUX);
        }
        default_layer_set(layer_state);
        layer_state_set(layer_state);
        eeconfig_update_default_layer(layer_state);
      }
      return false;
      break;
  }
  return true;
}
