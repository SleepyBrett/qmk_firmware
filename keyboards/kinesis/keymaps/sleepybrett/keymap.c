#include "kinesis.h"

#define _QWERTY 0 // Base qwerty
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  ADJUST,
  KC_KUC,
  KC_KUCS,
  KC_KUCB,
  KC_KUCH,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_AJST ADJUST
#define KC_LOWR LOWER
#define KC_RASE RAISE

// For my Phoenix window manager config
// https://github.com/kasper/phoenix/
#define KC_X1 LALT(LCTL(KC_1))
#define KC_X2 LALT(LCTL(KC_2))
#define KC_X3 LALT(LCTL(KC_3))
#define KC_X4 LALT(LCTL(KC_4))
#define KC_X5 LALT(LCTL(KC_5))
#define KC_X6 LALT(LCTL(KC_6))
#define KC_X7 LALT(LCTL(KC_7))
#define KC_X8 LALT(LCTL(KC_8))
#define KC_X9 LALT(LCTL(KC_9))
#define KC_XLFT LALT(LCTL(KC_LEFT))
#define KC_XRHT LALT(LCTL(KC_RGHT))

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | RAISE  |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   |  \|  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | GUI  | Alt  |         | Ctrl | GUI  |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_RASE,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSPO,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_BSLS,KC_LEFT,KC_RGHT,
			                     KC_LGUI,KC_LALT,
                                   KC_HOME,
                   KC_BSPC,KC_DEL ,KC_END ,
          KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0,DEBUG,
	        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	        KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	        KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	        KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSPC,
		              KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
                  KC_RCTL,KC_RGUI,
                  KC_PGUP,
                  KC_PGDN,KC_ENTER ,KC_SPC
    ),

[_RAISE] = KEYMAP(
          _______, _______,_______,_______,_______,_______,_______,_______,_______,
           KC_F1 ,KC_F2   ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,
          KC_CAPS, KC_KUCS,KC_KUCB,KC_KUCH,KC_KUC ,_______,
          _______, _______,_______,_______,_______,_______,
          _______, _______,_______,_______,_______,_______,
                   KC_ESC ,KC_INSERT,KC_XLFT,KC_XRHT,
                   _______, _______,
                            _______,
            _______,_______,_______,
           _______,_______,_______,_______,_______,_______,_______,_______,_______,
            KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12,
           _______, KC_X7 , KC_X8 , KC_X9 ,_______,_______,
           _______, KC_X4 , KC_X5 , KC_X6 ,_______,_______,
           _______, KC_X1 , KC_X2 , KC_X3 ,_______,_______,
                   KC_VOLU,KC_VOLD,KC_MUTE,KC_MPLY,
                   _______,_______,
                   _______,
                   _______,_______,_______
    )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  case KC_KUC:
    if (!record->event.pressed) {
      SEND_STRING("--context ");
    }
    return false;
    break;
  case KC_KUCS:
    if (!record->event.pressed) {
      SEND_STRING("--context steel");
    }
    return false;
    break;
  case KC_KUCB:
    if (!record->event.pressed) {
      SEND_STRING("--context barcelona");
    }
    return false;
    break;
  case KC_KUCH:
    if (!record->event.pressed) {
      SEND_STRING("--context hydrogen");
    }
    return false;
    break;
  } 
  return true;
}

void led_set_user(uint8_t usb_led) {

}
