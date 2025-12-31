// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layer {
    _BASE,
    _FN1,
    _LA_SYM,
    _LD_ARROW,
    _LL_SYM,
    _LN_NUM,
    _LS_CTRL,
};

#define CAPS_ESC LT(_LS_CTRL, KC_ESC)
#define A_SYM LT(_LA_SYM, KC_A)
#define D_ARROWS LT(_LD_ARROW, KC_D)
#define L_SYM LT(_LL_SYM, KC_L)
#define N_NUM LT(_LN_NUM, KC_N)

/*
 * Caps layer rules:
 * - Tapping `CAPS_ESC` emits Escape.
 * - Holding `CAPS_ESC` engages `_LS_CTRL`; letter keys send Ctrl+letter except H/J/K/L.
 * - With `_LS_CTRL` active, H/J/K/L send arrow keys without Ctrl for Vim-style motion.
 * Thumb rules:
 * - Both split space bar keys send Space (no Backspace on the right thumb).
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_BASE] = LAYOUT_65_with_macro(KC_F1, KC_F2, QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_DEL, KC_BSPC, KC_HOME, KC_F3, KC_F4, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, KC_F5, KC_F6, CAPS_ESC, A_SYM, KC_S, D_ARROWS, KC_F, KC_G, KC_H, KC_J, KC_K, L_SYM, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, KC_F7, KC_F8, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, N_NUM, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, KC_F9, KC_F10, KC_LCTL, KC_LALT, KC_LGUI, MO(_FN1), KC_SPC, MO(_FN1), KC_SPC, KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT),

                                                              [_FN1] = LAYOUT_65_with_macro(_______, _______, QK_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_BSPC, _______, _______, _______, UG_TOGG, UG_NEXT, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

                                                              [_LA_SYM] = LAYOUT_65_with_macro(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, S(KC_9), KC_QUOT, S(KC_QUOT), S(KC_0), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, S(KC_LBRC), KC_COMM, KC_DOT, S(KC_RBRC), KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, S(KC_COMM), S(KC_7), _______, S(KC_8), S(KC_DOT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

                                                              [_LD_ARROW] = LAYOUT_65_with_macro(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

                                                              [_LL_SYM] = LAYOUT_65_with_macro(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0, S(KC_6), S(KC_4), S(KC_EQL), S(KC_GRV), _______, KC_MINS, S(KC_MINS), _______, _______, _______, _______, _______, _______, _______, _______, _______, S(KC_2), _______, _______, S(KC_SCLN), KC_SLSH, S(KC_SLSH), KC_EQL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, S(KC_1), _______, S(KC_5), S(KC_BSLS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

                                                              [_LN_NUM] = LAYOUT_65_with_macro(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

                                                              [_LS_CTRL] = LAYOUT_65_with_macro(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};


static bool caps_held = false;
static bool caps_arrow_active[4] = {false, false, false, false};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAPS_ESC:
            if (record->event.pressed) {
                caps_held = true;
            } else {
                caps_held = false;
            }
            return true;
        case KC_H:
        case KC_J:
        case KC_K:
        case KC_L: {
            int idx = 0;
            uint16_t arrow_code = KC_LEFT;
            if (keycode == KC_J) {
                idx = 1;
                arrow_code = KC_DOWN;
            } else if (keycode == KC_K) {
                idx = 2;
                arrow_code = KC_UP;
            } else if (keycode == KC_L) {
                idx = 3;
                arrow_code = KC_RIGHT;
            }
            if (record->event.pressed) {
                if (caps_held) {
                    register_code(arrow_code);
                    caps_arrow_active[idx] = true;
                    return false;
                }
            } else if (caps_arrow_active[idx]) {
                unregister_code(arrow_code);
                caps_arrow_active[idx] = false;
                return false;
            }
            break;
        }
        default:
            break;
    }

    if (caps_held && keycode >= KC_A && keycode <= KC_Z && keycode != KC_H && keycode != KC_J && keycode != KC_K && keycode != KC_L) {
        if (record->event.pressed) {
            tap_code16(C(keycode));
        }
        return false;
    }

    return true;
}
