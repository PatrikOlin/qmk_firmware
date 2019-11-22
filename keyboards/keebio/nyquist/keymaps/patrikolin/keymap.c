#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/keymap_swedish.h"


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  LESS,
  GREATER,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_LGUI,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_QUES, KC_SFTENT , \
  KC_LCTL,  KC_LGUI, KC_LALT, KC_BSPC, TT(_LOWER),   KC_SPC,  KC_LEAD,  TT(_RAISE),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
    KC_F1, KC_F2, KC_F3,   KC_F4, KC_F5,  KC_F6,  KC_F7, KC_F8,   KC_F9,    KC_F10, KC_F11, KC_F12, \
    SE_TILD, KC_EXLM, SE_AT,   KC_HASH, SE_DLR,  KC_PERC,  SE_AMPR, SE_CIRC,   KC_GRV,    S(KC_GRV), SE_ASTR, KC_BSPC, \
    KC_DEL,  SE_SLSH,   SE_LPRN,   SE_RPRN,   SE_APOS,   SE_GRV,   _______,   SE_MINS,    SE_LCBR_MAC,    SE_RCBR_MAC, SE_PLUS, SE_PIPE,\
    _______, SE_BSLS,   SE_LCBR,   SE_RCBR,   SE_QUO2,  _______,  _______,  SE_UNDS, SE_LBRC, SE_RBRC, SE_EQL,  S(KC_NUBS),
    _______,   _______, SE_LBRC, SE_RBRC, KC_TRNS, _______, _______, KC_TRNS,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
    KC_F1, KC_F2, KC_F3,   KC_F4, KC_F5,  KC_F6,  KC_F7, KC_F8,   KC_F9,    KC_F10, KC_F11, RESET, \
  KC_GRV,  KC_F9,    KC_F10,    KC_F11,    KC_F12,    _______,    _______, SE_ASTR,   KC_7,    KC_8,    KC_9,        KC_BSPC, \
  KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,   _______,   SE_PLUS,   KC_4,    KC_5,    KC_6,        KC_BSLS, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  _______,  _______,  SE_MINS,  KC_1,     KC_2,    KC_3,     _______, \
  _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_0, _______, _______, _______ \
),

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_T) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      SEND_STRING(SS_LGUI(SS_LSFT("t")));
    }
    SEQ_ONE_KEY(KC_V) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      SEND_STRING(SS_LCTRL("v"));
    }
    SEQ_ONE_KEY(KC_LEFT) {
      register_code(KC_LGUI);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      unregister_code(KC_LGUI);
    }
    SEQ_ONE_KEY(KC_RGHT) {
      register_code(KC_LGUI);
      register_code(KC_RGHT);
      unregister_code(KC_RGHT);
      unregister_code(KC_LGUI);
    }
    SEQ_ONE_KEY(KC_UP) {
      register_code(KC_LGUI);
      register_code(KC_UP);
      unregister_code(KC_UP);
      unregister_code(KC_LGUI);
    }
    SEQ_ONE_KEY(KC_COMM) {
      register_code(KC_LGUI);
      register_code(KC_1);
      unregister_code(KC_1);
      unregister_code(KC_LGUI);
    }
    SEQ_ONE_KEY(KC_DOT) {
      register_code(KC_LGUI);
      register_code(KC_2);
      unregister_code(KC_2);
      unregister_code(KC_LGUI);
    }
    SEQ_ONE_KEY(SE_QUES) {
      register_code(KC_LGUI);
      register_code(KC_3);
      unregister_code(KC_3);
      unregister_code(KC_LGUI);
    }
    // Note: This is not an array, you don't need to put any commas
    // or semicolons between sequences.
    SEQ_TWO_KEYS(KC_N, KC_T) {
      // When I press KC_LEAD and then N followed by T, this sends CTRL + T
      SEND_STRING(SS_LGUI("t"));
    }
  }
}

