/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "quantum.h"

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// Define constants for RGB matrix indices
#define TILDE_IDX 0
#define CAPS_IDX 32
#define FN_IDX 68
#define MEDIA_START 7
#define MEDIA_END 12
#define FUN_START 1
#define FUN_END 12

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_72(
        QK_GESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,   KC_BSPC,           KC_INS,  RM_NEXT,
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,           KC_END,  KC_DEL,
        TG(_FN3), KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           KC_ENT,            KC_HOME, KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,           KC_RSFT,           KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                             KC_SPC,                             KC_RCMD,  KC_RCTL, MO(_FN1), KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_72(
        QK_GESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,   KC_BSPC,           KC_INS,  RM_NEXT,
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,           KC_END,  KC_DEL,
        TG(_FN3), KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           KC_ENT,            KC_HOME, KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,           KC_RSFT,           KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RALT,  KC_RCTL, MO(_FN2), KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_72(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU,  _______,           _______, RM_TOGG,
        RM_TOGG, RM_NEXT,  RM_VALU,  RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, _______,  _______, _______,  _______,           _______, _______,
        _______, RM_PREV,  RM_VALD,  RM_HUED, RM_SATD, RM_SPDD, _______, _______, _______, _______, _______,  _______,           _______,           _______, _______,
        _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,           _______,           _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______, _______,  _______,  _______, _______, _______),

    [_FN2] = LAYOUT_ansi_72(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU,  _______,           _______, RM_TOGG,
        RM_TOGG, RM_NEXT,  RM_VALU,  RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, _______,  _______, _______,  _______,           _______, _______,
        _______, RM_PREV,  RM_VALD,  RM_HUED, RM_SATD, RM_SPDD, _______, _______, _______, _______, _______,  _______,           _______,           _______, _______,
        _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,           _______,           _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______, _______,  _______,  _______, _______, _______),

    [_FN3] = LAYOUT_ansi_72(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,   _______,           _______, _______,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_R,    _______, _______, _______, _______, _______,  _______, _______,  _______,           _______, _______,
        _______, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    _______, _______, _______, _______, _______,  _______,           _______,           _______, _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,           _______,           _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______, _______,  _______,  _______, _______, _______)
};

// Helper function to set RGB color for a range of keys
void set_rgb_color_range(uint8_t start, uint8_t end, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = start; i <= end; i++) {
        rgb_matrix_set_color(i, r, g, b);
    }
}

void color_fun_row(bool light) {
    if (light) {
        set_rgb_color_range(FUN_START, FUN_END, 127, 32, 153);
    } else {
        set_rgb_color_range(FUN_START, FUN_END, 0, 0, 0);
    }
}

void color_tilde(bool light) {
    rgb_matrix_set_color(TILDE_IDX, light ? 255 : 0, 0, 0);
}

bool fun_toggled = false;
void handle_fun_toggle(void) {
    fun_toggled = !fun_toggled;
    color_fun_row(fun_toggled);
    color_tilde(fun_toggled);
}

void color_media_row(bool light) {
    uint8_t color = light ? 255 : 0;
    for (uint8_t i = MEDIA_START; i <= MEDIA_END; i++) {
        if (i == 8) {
            rgb_matrix_set_color(i, color, 0, 0);
        } else if (i == 10) {
            rgb_matrix_set_color(i, 0, 0, color);
        } else {
            rgb_matrix_set_color(i, 0, color, 0);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // handle functional toggle
        case TG(_FN3):
            if (record->event.pressed) {
                handle_fun_toggle();
            }
            return true;
        // handle windows media hold
        case MO(_FN2):
            bool pressed = record->event.pressed;

            color_tilde(pressed);
            color_media_row(pressed);

            return true;
        default:
            return true;
    }
}

void color_caps(bool light) {
    rgb_matrix_set_color(FN_IDX, light ? 255 : 0, light ? 255 : 0, light ? 255 : 0);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    color_caps(host_keyboard_led_state().caps_lock);
    return false;
}
