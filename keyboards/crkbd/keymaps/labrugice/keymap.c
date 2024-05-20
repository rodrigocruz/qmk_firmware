/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

enum combos {
    JK_ESC,
    DF_TAB,
    KL_BSPC
};

enum custom_keycodes {
    ARR_ONE = SAFE_RANGE,
    ARR_TWO,
    D_DOT,
    ALFRED,
    SOURCE,
    THINGS,
};

const uint16_t PROGMEM jk_combo[] = { HOME_J, HOME_K, COMBO_END };
const uint16_t PROGMEM df_combo[] = { HOME_D, HOME_F, COMBO_END };
const uint16_t PROGMEM kl_combo[] = { HOME_K, HOME_L, COMBO_END };

combo_t key_combos[] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [DF_TAB] = COMBO(df_combo, KC_TAB),
    [KL_BSPC] = COMBO(kl_combo, KC_BSPC),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case ARR_ONE:  // Arrow macro, types ->.
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;

        case ARR_TWO:  // Arrow macro, types =>.
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;

        case D_DOT:  // Double-dot macro, types ::
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
        case ALFRED:  // ALFRED macro, types ~
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_SPC);
                unregister_code(KC_LALT);
            }
            return false;
        case SOURCE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
             }
        return false;
            case THINGS:
                if (record->event.pressed) {
                    register_code(KC_LSFT);
                    register_code(KC_LGUI);
                    tap_code(KC_N);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LGUI);
                }
            return false;
    }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN, THINGS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SOURCE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  ALFRED,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_COLN,   MO(1),  LSFT_T(KC_SPC),     RCTL_T(KC_ENT),   MO(2), KC_QUOT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT,  KC_DLR,  KC_EQL, KC_UNDS,                      KC_CIRC, KC_PERC, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN,  KC_EQL,                      KC_HASH, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,   D_DOT, ARR_TWO, ARR_ONE, KC_MINS,                      KC_UNDS, KC_MINS, KC_PPLS, KC_AMPR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, XXXXXXX,   KC_F1,   KC_F2, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
