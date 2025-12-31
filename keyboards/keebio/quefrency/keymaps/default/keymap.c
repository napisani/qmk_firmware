// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
#    include "rgblight.h"
#endif

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
 * S simlayer rules:
 * - Holding `S` alone types `s` on release.
 * - Holding `S` while tapping H/J/K/L sends Ctrl+H/J/K/L.
 * Mode toggle:
 * - Hold the `1` key for ≥5s to toggle between modified logic and stock behavior.
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

static bool     modifications_enabled = true;
static bool     hold1_active          = false;
static bool     hold1_toggled         = false;
static uint16_t hold1_timer           = 0;

static bool caps_held            = false;
static bool caps_arrow_active[4] = {false, false, false, false};
static bool s_held               = false;
static bool s_used               = false;

#ifdef RGBLIGHT_ENABLE
static bool     indicator_active       = false;
static uint16_t indicator_timer        = 0;
static bool     indicator_prev_enabled = false;
static uint8_t  indicator_prev_mode    = 0;
static uint16_t indicator_prev_hue     = 0;
static uint8_t  indicator_prev_sat     = 0;
static uint8_t  indicator_prev_val     = 0;
#endif

static void flash_indicator(bool enabled) {
#ifdef RGBLIGHT_ENABLE
    indicator_prev_enabled = rgblight_is_enabled();
    indicator_prev_mode    = rgblight_get_mode();
    indicator_prev_hue     = rgblight_get_hue();
    indicator_prev_sat     = rgblight_get_sat();
    indicator_prev_val     = rgblight_get_val();

    if (!indicator_prev_enabled) {
        rgblight_enable_noeeprom();
    }
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    if (enabled) {
        rgblight_sethsv_noeeprom(85, 255, 255);
    } else {
        rgblight_sethsv_noeeprom(0, 255, 255);
    }

    indicator_active = true;
    indicator_timer  = timer_read();
#else
    (void)enabled;
#endif
}

static void reset_indicator_if_needed(void) {
#ifdef RGBLIGHT_ENABLE
    if (!indicator_active) {
        return;
    }
    if (timer_elapsed(indicator_timer) > 200) {
        if (!indicator_prev_enabled) {
            rgblight_disable_noeeprom();
        } else {
            rgblight_mode_noeeprom(indicator_prev_mode);
            rgblight_sethsv_noeeprom(indicator_prev_hue, indicator_prev_sat, indicator_prev_val);
        }
        indicator_active = false;
    }
#endif
}

static void release_caps_arrows(void) {
    if (caps_arrow_active[0]) {
        unregister_code(KC_LEFT);
        caps_arrow_active[0] = false;
    }
    if (caps_arrow_active[1]) {
        unregister_code(KC_DOWN);
        caps_arrow_active[1] = false;
    }
    if (caps_arrow_active[2]) {
        unregister_code(KC_UP);
        caps_arrow_active[2] = false;
    }
    if (caps_arrow_active[3]) {
        unregister_code(KC_RIGHT);
        caps_arrow_active[3] = false;
    }
}

static void apply_modifications_enabled(bool enabled) {
    if (modifications_enabled == enabled) {
        return;
    }

    bool send_s_on_release = (s_held && !s_used && !enabled);

    modifications_enabled = enabled;

    caps_held = false;
    s_held    = false;
    s_used    = false;
    release_caps_arrows();

    if (!enabled) {
        if (send_s_on_release) {
            tap_code(KC_S);
        }
        layer_off(_LA_SYM);
        layer_off(_LD_ARROW);
        layer_off(_LL_SYM);
        layer_off(_LN_NUM);
        layer_off(_LS_CTRL);
    }

    flash_indicator(enabled);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool mods_active = modifications_enabled;

    switch (keycode) {
        case KC_1:
            if (record->event.pressed) {
                hold1_active  = true;
                hold1_toggled = false;
                hold1_timer   = timer_read();
            } else {
                if (!hold1_toggled) {
                    tap_code(KC_1);
                }
                hold1_active = false;
            }
            return false;

        case CAPS_ESC:
            if (!mods_active) {
                if (record->event.pressed) {
                    tap_code(KC_CAPS);
                }
                return false;
            }
            if (record->event.pressed) {
                caps_held = true;
            } else {
                caps_held = false;
            }
            return true;

        case A_SYM:
            if (!mods_active) {
                if (record->event.pressed) {
                    register_code(KC_A);
                } else {
                    unregister_code(KC_A);
                }
                return false;
            }
            break;

        case D_ARROWS:
            if (!mods_active) {
                if (record->event.pressed) {
                    register_code(KC_D);
                } else {
                    unregister_code(KC_D);
                }
                return false;
            }
            break;

        case L_SYM:
            if (!mods_active) {
                if (record->event.pressed) {
                    register_code(KC_L);
                } else {
                    unregister_code(KC_L);
                }
                return false;
            }
            break;

        case N_NUM:
            if (!mods_active) {
                if (record->event.pressed) {
                    register_code(KC_N);
                } else {
                    unregister_code(KC_N);
                }
                return false;
            }
            break;

        case KC_S:
            if (!mods_active) {
                return true;
            }
            if (record->event.pressed) {
                s_held = true;
                s_used = false;
            } else {
                if (!s_used) {
                    tap_code(KC_S);
                }
                s_held = false;
            }
            return false;

        case KC_H:
        case KC_J:
        case KC_K:
        case KC_L: {
            if (!mods_active) {
                return true;
            }
            int      idx        = 0;
            uint16_t arrow_code = KC_LEFT;
            if (keycode == KC_J) {
                idx        = 1;
                arrow_code = KC_DOWN;
            } else if (keycode == KC_K) {
                idx        = 2;
                arrow_code = KC_UP;
            } else if (keycode == KC_L) {
                idx        = 3;
                arrow_code = KC_RIGHT;
            }
            if (caps_held) {
                if (record->event.pressed) {
                    register_code(arrow_code);
                    caps_arrow_active[idx] = true;
                } else if (caps_arrow_active[idx]) {
                    unregister_code(arrow_code);
                    caps_arrow_active[idx] = false;
                }
                return false;
            }
            if (s_held && record->event.pressed) {
                tap_code16(C(keycode));
                s_used = true;
                return false;
            }
            break;
        }
        default:
            break;
    }

    if (!mods_active) {
        return true;
    }

    if (caps_held && keycode >= KC_A && keycode <= KC_Z && keycode != KC_H && keycode != KC_J && keycode != KC_K && keycode != KC_L) {
        if (record->event.pressed) {
            tap_code16(C(keycode));
        }
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    if (hold1_active && !hold1_toggled && timer_elapsed(hold1_timer) >= 5000) {
        hold1_toggled = true;
        apply_modifications_enabled(!modifications_enabled);
    }

    reset_indicator_if_needed();
}
