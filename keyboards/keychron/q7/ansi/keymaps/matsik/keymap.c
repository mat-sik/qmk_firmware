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

// Define key indecies
#define TILDE_IDX 0
#define CAPS_IDX 32
#define FN_IDX 68
#define MEDIA_START 7
#define MEDIA_END 9
#define VOLUME_START 10
#define VOLUME_END 12
#define FUN_START 1
#define FUN_END 12

// Define colors
#define _RGB_BLACK (rgb_t){0, 0, 0}
#define _RGB_WHITE (rgb_t){255, 255, 255}
#define _RGB_PURPLE (rgb_t){145, 5, 250}
#define _RGB_RED (rgb_t){255, 0, 0}
#define _RGB_GREEN (rgb_t){0, 255, 213}
#define _RGB_BLUE (rgb_t){0, 190, 255}

// Define other
#define KEY_LIGHT_UP_TIME 5000

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
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    _______, _______, _______, _______, _______,  _______, _______,  _______,           _______, _______,
        _______, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    _______, _______, _______, _______, _______,  _______,           _______,           _______, _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,           _______,           _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______, _______,  _______,  _______, _______, _______)
};

void set_rgb_color_range(uint8_t start, uint8_t end, rgb_t rgb) {
    for (uint8_t led_idx = start; led_idx <= end; led_idx++) {
        rgb_matrix_set_color(led_idx, rgb.r, rgb.g, rgb.b);
    }
}

void color_func(rgb_t rgb) {
    set_rgb_color_range(FUN_START, FUN_END, rgb);
}

void color_tilde(rgb_t rgb) {
    rgb_matrix_set_color(TILDE_IDX, rgb.r, rgb.g, rgb.b);
}

void color_media(rgb_t rgb) {
    set_rgb_color_range(MEDIA_START, MEDIA_END, rgb);
}

void color_volume(rgb_t rgb) {
    set_rgb_color_range(VOLUME_START, VOLUME_END, rgb);
}

void color_caps(rgb_t rgb) {
    rgb_matrix_set_color(FN_IDX, rgb.r, rgb.g, rgb.b);
}

void handle_caps_coloring(bool shouldColor) {
    rgb_t caps_color = _RGB_BLACK;
    if (shouldColor) {
        caps_color = _RGB_GREEN;
    }
    color_caps(caps_color);
}

void light_up_media_volume(void) {
    color_tilde(_RGB_RED);
    color_media(_RGB_GREEN);
    color_volume(_RGB_PURPLE);
}

void light_down_media_volume(void) {
    color_tilde(_RGB_BLACK);
    color_media(_RGB_BLACK);
    color_volume(_RGB_BLACK);
}

void light_up_func(void) {
    color_tilde(_RGB_RED);
    color_func(_RGB_PURPLE);
}

void light_down_func(void) {
    color_tilde(_RGB_BLACK);
    color_func(_RGB_BLACK);
}

typedef struct {
    uint16_t turn_off_time;
    uint8_t pressed_times;
} key_status_t;

uint16_t get_next_turn_off_time(void) {
    uint16_t current_time = timer_read();
    return current_time + KEY_LIGHT_UP_TIME;
}

bool should_turn_off(key_status_t key_status) {
    uint16_t current_time = timer_read();
    return current_time > key_status.turn_off_time;
}

static key_status_t key_statuses[MATRIX_ROWS * MATRIX_COLS] = {0};

bool is_protected_key(uint8_t led_idx, uint8_t current_layer) {
    bool is_protected_key = false;
    if (led_idx == FN_IDX) {
        return true;
    }

    if (current_layer == _FN2) {
        is_protected_key = (led_idx >= MEDIA_START && led_idx <= MEDIA_END) ||
                          (led_idx >= VOLUME_START && led_idx <= VOLUME_END) ||
                          (led_idx == TILDE_IDX);
    } else if (current_layer == _FN3) {
        is_protected_key = (led_idx >= FUN_START && led_idx <= FUN_END) ||
                          (led_idx == TILDE_IDX);
    }
    return is_protected_key;
}

static const rgb_t colors_per_press[] = {
    _RGB_GREEN,
    _RGB_WHITE
};

void handle_key_effect(uint8_t current_layer) {
    for (uint8_t led_idx = 0; led_idx < MATRIX_ROWS * MATRIX_COLS; led_idx++) {
        if (is_protected_key(led_idx, current_layer)) {
            continue;
        }

        uint8_t pressed_times = key_statuses[led_idx].pressed_times;

        rgb_t color;
        if (should_turn_off(key_statuses[led_idx])) {
            key_statuses[led_idx].turn_off_time = 0;
            key_statuses[led_idx].pressed_times = 0;
            color = _RGB_BLACK;
        } else {
            uint8_t idx = pressed_times > 1 ? 1 : 0;
            color = colors_per_press[idx];
        }

        rgb_matrix_set_color(led_idx, color.r, color.g, color.b);
    }
}

void handle_layer_coloring(uint8_t current_layer) {
    switch(current_layer) {
        case _FN2: // handle media, volume hold
            light_down_func();
            light_up_media_volume();

            break;
        case _FN3: // handle functional toggle
            light_down_media_volume();
            light_up_func();

            break;
        default: // clear the lights
            light_down_func();
            light_down_media_volume();

            break;
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    handle_caps_coloring(host_keyboard_led_state().caps_lock);

    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);

    handle_layer_coloring(current_layer);

    handle_key_effect(current_layer);

    return false;
}

static const uint8_t led_map[MATRIX_ROWS][MATRIX_COLS] = {
    // Row 0
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15},
    // Row 1
    { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
    // Row 2
    { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 44, 45, 46 },
    // Row
    { 47, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 58, 59, 60 },
    // Row 4
    { 61, 62, 63, 64, 64, 64, 64, 64, 64, 65, 66, 67, 68, 69, 70, 71 }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t led_idx = led_map[record->event.key.row][record->event.key.col];

    if (record->event.pressed) {
        key_statuses[led_idx].turn_off_time = get_next_turn_off_time();
        key_statuses[led_idx].pressed_times += 1;
    }

    return true;
}
