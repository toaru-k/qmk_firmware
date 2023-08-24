// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC , KC_Q, KC_W, KC_E   , KC_R   , KC_T  , KC_Y  , KC_U   , KC_I   , KC_O  , KC_P, KC_BSPC, XXXXXXX,
        KC_TAB , KC_A, KC_S, KC_D   , KC_F   , KC_G  , KC_H  , KC_J   , KC_K   , KC_L  ,    KC_ENT    , XXXXXXX,
        KC_LSFT, KC_Z, KC_X, KC_C   , KC_V   , KC_B  , KC_N  , KC_M   , KC_COMM, KC_DOT,    KC_RSFT   , XXXXXXX,
                             KC_LCTL, KC_LGUI, KC_SPC, KC_SPC, KC_RGUI, KC_RALT
    ),
    [1] = LAYOUT(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0, _______, XXXXXXX,
        _______, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_GRV , KC_SLSH,    _______   , XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _______   , XXXXXXX,
                                   _______, _______, XXXXXXX, XXXXXXX, _______, _______
    ),
    [2] = LAYOUT(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12 ,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT,    _______    , XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _______    , XXXXXXX,
                                   _______, _______, XXXXXXX, XXXXXXX, _______, _______
    ),
    [3] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _______      , XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _______      , XXXXXXX,
                                   _______, _______, XXXXXXX, XXXXXXX, _______, _______
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW( XXXXXXX, XXXXXXX ) },
    [1] = { ENCODER_CCW_CW( XXXXXXX, XXXXXXX ) },
    [2] = { ENCODER_CCW_CW(	XXXXXXX, XXXXXXX ) },
    [3] = { ENCODER_CCW_CW(	XXXXXXX, XXXXXXX ) }
};