#include "sweet16.h"

#define _______ KC_TRNS

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_4x4(
        _______,       KC_UP,      _______,    _______, 
        KC_LEFT,       KC_DOWN,       KC_RGHT,    _______, 
        _______,       KC_DOWN,    _______,    KC_ENT, 
        _______,       _______,    _______,    KC_SPC
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboads.com");
            }
            return false;
            break;
    }
    return true;
}