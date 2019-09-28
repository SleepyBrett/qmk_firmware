/* Copyright 2019 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define L_MAC  0
#define L_PC   1
#define L_GAME 2
#define L_HIGH 3
#define L_LOW  4
#define L_ADJ  5

enum custom_keycodes {
  MAC = SAFE_RANGE,
  LOWER,
  RAISE,
  PC,
  GAME,
  ADJUST,
};

#define KC_LOW  LOWER
#define KC_RSE  RAISE
#define KC_MAC  MAC
#define KC_PC   PC
#define KC_GAME GAME

// 0 = mac, 1 = pc, 2 = game, 3 = raise, 4 = low
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_MAC] = LAYOUT( \
        KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL, KC_GRV, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,          \
        KC_LOW, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME,                  \
        KC_LSPO, KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, KC_UP,   KC_END,         \
        KC_LCTL, KC_LALT, KC_LGUI,                KC_BSPC, KC_RSE, KC_SPC,         KC_RALT, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT                   \
    ),
[L_PC] = LAYOUT( \
        KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL, KC_GRV, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,          \
        KC_LOW, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME,                  \
        KC_LSPO, KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, KC_UP,   KC_END,         \
        KC_LCTL, KC_LGUI, KC_LALT,                KC_BSPC, KC_RSE, KC_SPC,         KC_RALT, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT                   \
    ),
[L_GAME] = LAYOUT( \
        KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL, KC_GRV, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,          \
        KC_LOW, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME,                  \
        KC_LSFT, KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,         \
        KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC, KC_RSE, KC_BSPC,         KC_RALT, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT                   \
    ),

[L_HIGH] = LAYOUT( \
        KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_ESC, KC_MUTE, \
        KC_CAPS, KC_MAC, KC_PC, KC_GAME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, RGB_TOG, KC_VOLU,          \
        KC_LOW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,                   \
        KC_TRNS, KC_TRNS, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_RSE, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR                     \
    ),
[L_LOW] = LAYOUT( \
        KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_ESC, KC_MUTE, \
        KC_CAPS, KC_MAC, KC_PC, KC_GAME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, RGB_TOG, KC_VOLU,          \
        KC_LOW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,                   \
        KC_TRNS, KC_TRNS, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_RSE, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR                     \
    ),
[L_ADJ] = LAYOUT( \
        KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_ESC, KC_MUTE, \
        KC_CAPS, KC_MAC, KC_PC, KC_GAME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, RGB_TOG, KC_VOLU,          \
        KC_LOW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,                   \
        KC_TRNS, KC_TRNS, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_RSE, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR                     \
    ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<L_MAC);
      }
      return false;
      break;
    case PC:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<L_PC);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<L_GAME);
      }
      return false;
      break;


    case LOWER:
      if (record->event.pressed) {
        layer_on(L_LOW);
        update_tri_layer(L_LOW, L_HIGH, L_ADJ);
      } else {
        layer_off(L_LOW);
        update_tri_layer(L_LOW, L_HIGH, L_ADJ);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(L_HIGH);
        update_tri_layer(L_LOW, L_HIGH, L_ADJ);
      } else {
        layer_off(L_HIGH);
        update_tri_layer(L_LOW, L_HIGH, L_ADJ);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
