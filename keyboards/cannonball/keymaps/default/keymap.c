// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    Cursol = 0,
    Editor,
    Browser,
    Youtube
    // Shortcuts
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Cursol] = LAYOUT(
        KC_ENT, GUI_T(KC_LNG2), KC_LSFT, CTL_T(KC_LNG1),
                KC_HOME, KC_UP  , KC_END , KC_NO,
        KC_ESC, KC_LEFT, KC_DOWN, KC_RGHT,
        // LEVER
       DF(Browser), DF(Cursol), DF(Editor)
    ),
    [Editor] = LAYOUT(
        KC_ENT , KC_LSFT, KC_LGUI, KC_LALT   ,
                 KC_LNG2, G(KC_F), KC_LNG1   , KC_NO,
        G(KC_X), G(KC_C), G(KC_V), S(G(KC_V)),
        // LEVER
        _______, _______, _______
    ),
    [Browser] = LAYOUT(
        G(KC_T), KC_MPRV, KC_MPLY, KC_MNXT,
                 KC_NO  , KC_LGUI, KC_NO  , KC_MUTE,
        G(KC_W), KC_BTN4, KC_BTN3, KC_BTN5,
        // LEVER
        _______, _______, _______
    ),
    // [Shortcuts] = LAYOUT(
    //     _______, _______, _______, _______,
    //              _______, _______, _______, _______,
    //     _______, _______, _______, _______,
    //     // LEVER
    //     KC_NO, KC_NO, KC_NO
    // )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [Cursol ] = { ENCODER_CCW_CW(S(KC_TAB), KC_TAB    ), ENCODER_CCW_CW(KC_WH_U  , KC_WH_D     ), ENCODER_CCW_CW(KC_WH_L    , KC_WH_R  ) },
    [Editor ] = { ENCODER_CCW_CW(G(KC_Z  ), S(G(KC_Z))), ENCODER_CCW_CW(KC_WH_U  , KC_WH_D     ), ENCODER_CCW_CW(KC_BSPC    , KC_DEL   ) },
    [Browser] = { ENCODER_CCW_CW(KC_VOLD  , KC_VOLU   ), ENCODER_CCW_CW(C(KC_TAB), S(C(KC_TAB))), ENCODER_CCW_CW(G(KC_MINUS), G(KC_EQL)) },
    // [Shortcuts] =  { ENCODER_CCW_CW(_______  , _______   ), ENCODER_CCW_CW(_______     , _______  ), ENCODER_CCW_CW(_______  , _______    ) },
};