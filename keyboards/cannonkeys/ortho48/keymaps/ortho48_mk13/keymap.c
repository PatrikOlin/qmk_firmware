/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#include "./../../../../../quantum/keymap_extras/keymap_swedish.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _______ KC_TRNS
#define LEADER_TIMEOUT 200
#define LEADER_PER_KEY_TIMING

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_K) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      SEND_STRING(SS_LCTRL(SS_LSFT("t")));
    }
    SEQ_ONE_KEY(KC_L){
        SEND_STRING(SS_LCTRL(SS_LSFT("l")));
    }
    // Note: This is not an array, you don't need to put any commas
    // or semicolons between sequences.
    SEQ_TWO_KEYS(KC_N, KC_T) {
      // When I press KC_LEAD and then N followed by T, this sends CTRL + T
      SEND_STRING(SS_LCTRL("t"));
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ?  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ctrl |  OS  | Alt  | Bksp |Raise |  Spc | Lead |Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_QUES, KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, TT(_RAISE),   KC_SPC,  KC_LEAD,  TT(_LOWER),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   <  |   >  |   *  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  /   |  (   |   )  |   '  |      |      |   -  |   {  |   }  |   +  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   \  |  {   |   }  |   "  |      |      |   _  |   [  |   ]  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RST  |      |  [   |   ]  |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    NO_TILD, KC_EXLM, NO_AT,   KC_HASH, NO_DLR,  KC_PERC, NO_CIRC, NO_AMPR,    NO_LESS,   NO_GRTR,   NO_ASTR, KC_BSPC,
    KC_DEL,  NO_SLSH,   NO_LPRN,   NO_RPRN,  NO_APOS,   NO_GRV,   _______,   NO_MINS,    NO_LCBR_MAC, NO_RCBR_MAC, NO_PLUS, NO_PIPE,
    KC_TRNS, NO_BSLS,   NO_LCBR, NO_RCBR,   NO_QUO2,  _______,  _______,  NO_UNDS, NO_LBRC, NO_RBRC, NO_EQL, S(KC_NUBS),
    RESET,   _______, NO_LBRC, NO_RBRC, KC_TRNS, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   7  |   8  |   9  |   -  |      |      |  F9  |  F10 |  F11 |  F12 | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |      |      |  F5  |  F6  |  F7  |  F8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   *  |      |      |  F1  |  F2  |  F3  |  F4  | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |      |   ,  |      |             |      | Next | Vol- | Vol+ | PgDn |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_7,    KC_8,    KC_9,    KC_KP_MINUS,    _______,    _______,    KC_F9,  KC_F10, KC_F11, KC_F12,    KC_BSPC,
    _______, KC_4,    KC_5,    KC_6,    KC_KP_PLUS,     _______,    _______,    KC_F5,  KC_F6,  KC_F7,  KC_F8,  _______,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_KP_ASTERISK, _______,    _______,    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_PGUP,
    RGB_TOG, KC_0,    _______, KC_COMM, KC_TRNS,    _______,    _______,    KC_TRNS, KC_MPLY, KC_VOLD, KC_VOLU, KC_PGDN
),
};
