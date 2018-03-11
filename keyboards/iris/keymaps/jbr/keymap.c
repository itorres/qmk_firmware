#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

enum iris_layers {
  MAC = 0,
  LINUX,
  RAISE
};

enum iris_keycodes {
  KC_LOM = SAFE_RANGE,
};

#define KC_LOSL RALT(KC_L)
#define KC_LAE  RALT(KC_Z)
#define KC_LARG RALT(KC_W)

#define KC_MOSL RALT(KC_O)
#define KC_MAE  RALT(KC_QUOT)
#define KC_MARG RALT(KC_A)

#define KC_OSFT OSM(MOD_LSFT)
#define KC_OGUI OSM(MOD_LGUI)
#define KC_OALT OSM(MOD_RALT)
#define KC_OCTL OSM(MOD_LCTL)
#define KC_ORAI OSL(RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC] = KC_KEYMAP(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      HOME,PGDN,PGUP,END ,MUTE,MPLY,               VOLD,VOLU,LEFT,DOWN,UP  ,RGHT,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB ,Q   ,W   ,E   ,R   ,T   ,               Y   ,U   ,I   ,O   ,P   ,MARG,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ESC ,A   ,S   ,D   ,F   ,G   ,               H   ,J   ,K   ,L   ,MAE ,MOSL,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      NO  ,Z   ,X   ,C   ,V   ,B   ,OCTL,     OGUI,N   ,M   ,COMM,DOT ,SCLN,SLSH,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                         OALT,OSFT,BSPC,        SPC ,ORAI,ENT
   //                   `----+----+----'       `----+----+----'
  ),
  [LINUX] = KC_KEYMAP(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,TRNS,TRNS,LARG,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,TRNS,LAE ,LOSL,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,OGUI,     OCTL,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                         TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS
   //                   `----+----+----'       `----+----+----'
  ),
  [RAISE] = KC_KEYMAP(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1  ,F2  ,F3  ,F4  ,F5  , F6 ,               F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      DQUO,EXLM,AT  ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,PLUS,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      QUOT,1   ,2   ,3   ,4   ,5   ,               6   ,7   ,8   ,9   ,0   ,MINS,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      GRV ,TILD,BSLS,PIPE,UNDS,LOM ,TRNS,     TRNS,NO  ,LCBR,RCBR,LBRC,RBRC,EQL ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                         TRNS,NO  ,DEL ,        NO  ,TRNS,NO
   //                   `----+----+----'       `----+----+----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint32_t layer_state;

  switch (keycode) {
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
