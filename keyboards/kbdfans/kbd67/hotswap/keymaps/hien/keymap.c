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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

enum layers_keymap {
  _QWERTY = 0,
  _FUNCTION,
  _NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|  \|Num  |
   * |-----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BSPC|Del  |
   * |-----------------------------------------------------------------|
   * |Fn   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter   |PgUp |
   * |-----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn |
   * |-----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN |||||Lef|Dow|Right|
   * `----------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT(
  KC_ESC,        KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, TG(_NUMPAD), \
  KC_TAB,        KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL,  \
  MO(_FUNCTION), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGUP, \
  KC_LSFT,       KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   KC_PGDN, \
  KC_LCTL,       KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT,   MO(_FUNCTION),           KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap Fn Layer.
   * ,----------------------------------------------------------------.
   * |    |F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |Prnt|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |       |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |Rst |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |    |||||   |   |    |
   * `----------------------------------------------------------------'
   */

[_FUNCTION] = LAYOUT(
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,  KC_PSCR, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, RESET, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,                   KC_TRNS,  KC_TRNS, KC_TRNS),

  /* Numpad Layer.
   * ,----------------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |  /|  *|  -|  =|   |   |     |
   * |-----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |  7|  8|  9|  +|   | BSPC|     |
   * |-----------------------------------------------------------------|
   * |       |   |   |   |   |   |   |   |  4|  5|  6| + | Enter |     |
   * |-----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |  1|  2|  3|      |   |     |
   * |-----------------------------------------------------------------|
   * |    |    |    |                       |   0| . |||||   |   |     |
   * `----------------------------------------------------------------'`
   */
[_NUMPAD] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,   KC_PPLS, KC_TRNS, KC_BSPC,          KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,   KC_PPLS,          KC_ENT,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,   KC_TRNS,                   KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_0,    KC_DOT,                   KC_TRNS, KC_TRNS, KC_TRNS),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
