/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

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
#include "unicode.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    //             ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., .......,
    C_S_T(KC_EQL), KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    LCTL(KC_EQL),  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_DEL,
    LALT(KC_X),    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,
                   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    TT(2),   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,         KC_RSFT, KC_BSPC,
                   KC_LGUI,          KC_LALT, KC_BSPC, TT(1),   KC_SPC,                    KC_RALT,                                             KC_CALC),

  [1] = LAYOUT(
    //             ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., .......,
    RGB_TOG,       VLK_TOG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   RESET,
    RGB_MOD,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
    RGB_RMOD,      KC_LCTL,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,                     KC_NO,
                   KC_LSFT, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,
                   KC_TRNS,          KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_RALT,                                              KC_TRNS),

  [2] = LAYOUT( // greek/math layer
    //             ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., ......., .......,
    KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,         KC_NO,   KC_NO,   KC_NO,   SIGMA,   KC_NO,   TAU,     UPSLN,   KC_NO,   IOTA,    THETA,   PSI,     KC_NO,   KC_NO,            KC_NO,
    KC_NO,         KC_NO,   ALPHA,   KC_NO,   DELTA,   KC_NO,   GAMMA,   ETA,     KC_NO,   KAPPA,   LAMBD,   KC_NO,   KC_NO,                     KC_NO,
                   KC_LSFT, ZETA,    CHI,     KC_NO,   KC_NO,   KC_TRNS, BETA,    NU,      GMU,     X(LSEQ), X(GREQ), KC_NO,            KC_NO,   KC_NO,
                   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,                                                KC_NO)
};

void matrix_init_user(void) {
  // use wincompose for unicode input
  set_unicode_input_mode(UC_WINC);
}
