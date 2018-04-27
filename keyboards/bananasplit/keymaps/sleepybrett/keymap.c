#include "bananasplit.h"

/*
-------------------------------------------------------------------------------------------
| K00 | K01 | K02 | K03 | K04 | K05 | K06 | K07 | K08 | K09 | K0A | K0B | K0C | K0D | K2D |
-------------------------------------------------------------------------------------------
|  K10   | K11 | K12 | K13 | K14 | K15 | K16 | K17 | K18 | K19 | K1A | K1B | K1C |  K1D   |
-------------------------------------------------------------------------------------------
|   K20   | K21 | K22 | K23 | K24 | K25 | K26 | K27 | K28 | K29 | K2A | K2B |     K2C     |
-------------------------------------------------------------------------------------------
|     K30     | K32 | K33 | K34 | K35 | K36 | K37 | K38 | K39 | K3A | K3B |   K3C   | K3D |
-------------------------------------------------------------------------------------------
|  K40  |  K41  |  K42  |     K44     |  K45  |     K46     | K48 | K49 | K4A | K4B | K4C |
-------------------------------------------------------------------------------------------
*/
#define KEYMAP_BRETT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K2D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42,      K44, K45, K46,      K48, K49, K4A, K4B, K4C  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D }, \
    { K30, KC_NO,    K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D }, \
    { K40, K41, K42, KC_NO,    K44, K45, K46, KC_NO,    K48, K49, K4A, K4B, K4C, KC_NO }  \
}

#define DEFAULT_LAYER 0
#define LAYER_GAME    1
#define LAYER_LOW     2
#define LAYER_HIGH    3
#define LAYER_ADJ     4

#define KC_LOW  LOWER
#define KC_RASE RAISE
#define KC_ADJ  ADJUST

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP_BRETT( \
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,       KC_5,   KC_6,     KC_7,     KC_8,   KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_DEL, KC_ESC, \
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,       KC_T,   KC_Y,     KC_U,     KC_I,   KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_LOW,   KC_A,   KC_S,     KC_D,     KC_F,       KC_G,   KC_H,     KC_J,     KC_K,   KC_L,     KC_SCLN,  KC_QUOT, KC_ENT, \
    KC_LSPO,            KC_Z,     KC_X,     KC_C,       KC_V,   KC_B,     KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, KC_RSPC, KC_UP, \
    KC_LCTL,  KC_LALT,  KC_LGUI,            KC_BSPC,    KC_RASE,KC_SPC,         KC_RGUI,KC_RALT,  KC_LEFT,  KC_RIGHT,KC_DOWN \
  ),

  [1] = KEYMAP_BRETT( \
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,       KC_5,   KC_6,     KC_7,     KC_8,   KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_DEL, KC_GRV, \
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,       KC_T,   KC_Y,     KC_U,     KC_I,   KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_LOW,   KC_A,   KC_S,     KC_D,     KC_F,       KC_G,   KC_H,     KC_J,     KC_K,   KC_L,     KC_SCLN,  KC_QUOT, KC_ENT, \
    KC_LSFT,            KC_Z,     KC_X,     KC_C,       KC_V,   KC_B,     KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, KC_UP, \
    KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,    KC_RASE,KC_BSPC,         KC_RALT,KC_RGUI,  KC_LEFT,  KC_RIGHT,KC_DOWN \
  ),

  [2] = KEYMAP_BRETT( \
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_INS, _______, \
    KC_CAPS,  QWERTY,   GAME,     _______,  _______,    _______, _______, _______, _______, _______,  _______,  _______, _______, _______, \
    _______,  _______,  _______,  _______,  _______,    _______, _______, _______, _______, _______,  _______,  _______, _______, \
    _______,            _______,  _______,  _______,    _______, _______, _______, KC_MUTE, KC_VOLD,  KC_VOLU,  KC_MPLY, _______, KC_PGUP, \
    _______,  _______,  _______,            _______,    _______, _______,          _______, _______,  KC_HOME,  KC_END,  KC_PGDN  \
  ),

  [3] = KEYMAP_BRETT( \
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_INS, _______, \
    KC_CAPS,  QWERTY,   GAME,     _______,  _______,    _______, _______, _______, _______, _______,  _______,  _______, _______, _______, \
    _______,  _______,  _______,  _______,  _______,    _______, _______, _______, _______, _______,  _______,  _______, _______, \
    _______,            _______,  _______,  _______,    _______, _______, _______, KC_MUTE, KC_VOLD,  KC_VOLU,  KC_MPLY, _______, KC_PGUP, \
    _______,  _______,  _______,            _______,    _______, _______,          _______, _______,  KC_HOME,  KC_END,  KC_PGDN  \
  ),

  [4] = KEYMAP_BRETT( \
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_INS, _______, \
    KC_CAPS,  QWERTY,   GAME,     _______,  _______,    _______, _______, _______, _______, _______,  _______,  _______, _______, _______, \
    _______,  _______,  _______,  _______,  _______,    _______, _______, _______, _______, _______,  _______,  _______, _______, \
    _______,            _______,  _______,  _______,    _______, _______, _______, KC_MUTE, KC_VOLD,  KC_VOLU,  KC_MPLY, _______, KC_PGUP, \
    _______,  _______,  _______,            _______,    _______, _______,          _______, _______,  KC_HOME,  KC_END,  KC_PGDN  \
  ),

};

const uint16_t PROGMEM fn_actions[] = {
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<0);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<1);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(2);
        update_tri_layer(2, 3, 4);
      } else {
        layer_off(2);
        update_tri_layer(2, 3, 4);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(3);
        update_tri_layer(2, 3, 4);
      } else {
        layer_off(3);
        update_tri_layer(2, 3, 4);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(4);
      } else {
        layer_off(4);
      }
      return false;
      break;
  }
  return true;
}