/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "quantum/keymap_extras/keymap_swedish.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _MACOS,
  _SANE,
  _LOWERMAC,
  _RAISEMAC,
  _LOWER,
  _RAISE,
  _ENCODERADJUST,
  _ADJUST,
  _ADJUSTMAC
};

enum planck_keycodes {
  MACOS = SAFE_RANGE,
  SANE,
  BACKLIT,
  EXT_PLV,
  ADJ_TOGGLE,
    DYNAMIC_MACRO_RANGE,
};

 #include "dynamic_macro.h"

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define LOWERMAC MO(_LOWERMAC)
#define RAISEMAC MO(_RAISEMAC)
#define ENCADJ TG(_ENCODERADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Macos
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
[_MACOS] = LAYOUT_planck_grid(
  ENCADJ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  SFT_T(KC_ESC), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_QUES, KC_SFTENT , \
  KC_LGUI,  KC_LCTRL, KC_LALT, KC_BSPC, LOWERMAC,   KC_SPC,  ENCADJ,  RAISEMAC,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* SANE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SANE] = LAYOUT_planck_grid(
  ENCADJ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  SFT_T(KC_ESC), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_QUES, KC_SFTENT , \
  KC_LCTRL,  KC_LGUI, KC_LALT, KC_BSPC, LOWER,   KC_SPC,  KC_LEAD,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWERMAC] = LAYOUT_planck_grid(
    KC_LALT, KC_EXLM, SE_AT,   KC_HASH, SE_DLR,  KC_PERC,  SE_AMPR, SE_CIRC,  SE_ASTR,  KC_GRV, S(KC_GRV), KC_BSPC, \
    KC_DEL,  SE_SLSH,   SE_LPRN,   SE_RPRN,   SE_APOS,   SE_GRV,   SE_TILD,   SE_MINS,    SE_LCBR_MAC,    SE_RCBR_MAC, SE_PLUS, SE_PIPE,\
    _______, SE_BSLS_MAC,   SE_LCBR,   SE_RCBR,   SE_QUO2,  _______,  _______,  SE_UNDS, SE_LBRC, SE_RBRC, SE_EQL,  SE_TILD,
    _______,   _______, SE_LBRC, SE_RBRC, KC_TRNS, _______, _______, KC_TRNS,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISEMAC] = LAYOUT_planck_grid(
    KC_GRV,  KC_F9,    KC_F10,    KC_F11,    KC_F12,    _______,    _______, SE_ASTR,   KC_7,    KC_8,    KC_9,        KC_BSPC, \
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,   _______,   SE_PLUS,   KC_4,    KC_5,    KC_6,        KC_BSLS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  _______,  _______,  SE_MINS,  KC_1,     KC_2,    KC_3,     _______, \
    _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_0, _______, _______, _______ \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_LALT, KC_EXLM,   SE_AT,    KC_HASH, SE_DLR,  KC_PERC,  SE_AMPR, SE_CIRC,   KC_GRV,    SE_LESS, SE_GRTR, KC_BSPC, \
    KC_DEL,  SE_SLSH,   SE_LPRN,   SE_RPRN,   SE_APOS,   SE_GRV,   SE_TILD,   SE_MINS,    SE_LCBR,    SE_RCBR, SE_PLUS, SE_PIPE,\
    _______, SE_BSLS,   SE_LCBR,   SE_RCBR,   SE_QUO2,  _______,  _______,  SE_UNDS, SE_LBRC, SE_RBRC, SE_EQL,  SE_TILD,
    KC_LCTRL,   _______, SE_LBRC, SE_RBRC, KC_TRNS, _______, _______, KC_TRNS,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_F9,    KC_F10,    KC_F11,    KC_F12,    _______,    _______, SE_ASTR,   KC_7,    KC_8,    KC_9,        KC_BSPC, \
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,   _______,   SE_PLUS,   KC_4,    KC_5,    KC_6,        KC_BSLS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  _______,  _______,  SE_MINS,  KC_1,     KC_2,    KC_3,     _______, \
    KC_LCTRL, _______, KC_LALT, _______, KC_TRNS, _______, _______, KC_TRNS, KC_0, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AU_clc|MUSmod|Aud on|Audoff|AGnorm|AGswap|MACOS | SANE |      |Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, CK_TOGG, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, MACOS,  SANE,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP,
    CK_RST,  CK_DOWN, CK_UP, _______, _______, _______, _______, _______, _______,  DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AU_clc|MUSmod|Aud on|Audoff|AGnorm|AGswap|MACOS | SANE |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Muson|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUSTMAC] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, CK_TOGG, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, MACOS,  SANE,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP,
    CK_RST,  CK_DOWN, CK_UP, _______, _______, _______, _______, _______, _______,  DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, _______

),
[_ENCODERADJUST] = LAYOUT_planck_grid(
    ENCADJ, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, ENCADJ, _______, _______, _______, _______,  _______

)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float ode_to_joy[][2]      = SONG(ODE_TO_JOY);
  float planck_sound[][2]    = SONG(PLANCK_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    state = update_tri_layer_state(state, _LOWERMAC, _RAISEMAC, _ADJUSTMAC);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
  switch (keycode) {
    case ENCADJ:
        if(record->event.pressed) {
            adjust_encoder_speed = !adjust_encoder_speed;
        }
        return false;
        break;
    case MACOS:
      if (record->event.pressed) {
        stop_all_notes();
        PLAY_SONG(ode_to_joy);
        set_single_persistent_default_layer(_MACOS);
      }
      return false;
      break;
    case SANE:
      if (record->event.pressed) {
        stop_all_notes();
        PLAY_SONG(planck_sound);
        set_single_persistent_default_layer(_SANE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
bool adjust_encoder_speed = false;
uint8_t scroll_speed = 1;
uint8_t x;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else if (adjust_encoder_speed == true)) {
      if (clockwise && scroll_speed < 5) {
          scroll_speed++;
      } else {
        if(scroll_speed > 1) {
          scroll_speed--;
        }
      }
    }
    else if (IS_LAYER_ON(_RAISEMAC)) {
            if (clockwise) {
                register_code(KC_LGUI);
                tap_code(KC_Y);
                unregister_code(KC_LGUI);
            } else {
                register_code(KC_LGUI);
                tap_code(KC_Z);
                unregister_code(KC_LGUI);
            }
    } else if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                register_code(KC_LCTRL);
                tap_code(KC_Y);
                unregister_code(KC_LCTRL);
            } else {
                register_code(KC_LCTRL);
                tap_code(KC_Z);
                unregister_code(KC_LCTRL);
            }
    } else if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_LOWERMAC)) {
            if (clockwise) {
                tap_code(KC_AUDIO_VOL_DOWN);
            } else {
                tap_code(KC_AUDIO_VOL_UP);
            }
    } else if (IS_LAYER_ON(_ADJUST) || IS_LAYER_ON(_ADJUSTMAC)) {
            if (clockwise) {
                tap_code16(CK_UP);
            } else {
                tap_code16(CK_DOWN);
            }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
          for (x = 0; x < scroll_speed; x++) {
            tap_code(KC_MS_WH_DOWN);
          }
        #else
            tap_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
         for (x = 0; x < scroll_speed; x++) {
            tap_code(KC_MS_WH_UP);
         }
        #else
            tap_code(KC_PGUP);
        #endif
        }
    }
  }

void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {

    if (IS_LAYER_ON(_MACOS)) {
        LEADER_DICTIONARY() {
            leading = false;
            leader_end();
            // Replace the sequences below with your own sequences.
            SEQ_ONE_KEY(KC_SPC) {
            // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
            SEND_STRING("macos");
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
    } else {
        LEADER_DICTIONARY() {
            leading = false;
            leader_end();
            // Replace the sequences below with your own sequences.
            SEQ_ONE_KEY(KC_SPC) {
            // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
            SEND_STRING("inte macos");
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

  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

