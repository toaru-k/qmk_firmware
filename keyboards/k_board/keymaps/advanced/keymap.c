// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum layers {
    base = 0,
    num_sym,
    function,
    keypad
};


// Additional Keycodes
// Modifires
#define LGUI_   LGUI_T(KC_LNG2)
#define RGUI_   RGUI_T(KC_LNG1)
#define ALT_Z   LALT_T(KC_Z   )
// #define CTL_DOT RCTL_T(KC_DOT ) 

// Shortcuts
#define UNDO    LGUI(KC_Z)
#define REDO    SGUI(KC_Z)
#define LOG     SGUI(KC_V)

// Screen Control
#define L_Scrn  C(KC_LEFT)
#define R_Scrn  C(KC_RGHT)

// Layer Control
#define LT1_SPC LT(num_sym , KC_SPC)
#define LT2_TAB LT(function, KC_TAB)
#define LT2_ENT LT(function, KC_ENT)
#define DF0     DF(base  )
#define DF3     DF(keypad)

// Commbos
const uint16_t PROGMEM caps_combo[] = { KC_LSFT, KC_RSFT, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO( caps_combo, KC_CAPS ),
};



// Key Maps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [base] = LAYOUT(
        KC_ESC , KC_Q , KC_W, KC_E   , KC_R , KC_T   , KC_Y   , KC_U , KC_I   , KC_O  , KC_P, KC_BSPC, KC_DEL ,
        LT2_TAB, KC_A , KC_S, KC_D   , KC_F , KC_G   , KC_H   , KC_J , KC_K   , KC_L  ,    LT2_ENT   , KC_WH_D,
        KC_LSFT, ALT_Z, KC_X, KC_C   , KC_V , KC_B   , KC_N   , KC_M , KC_COMM, KC_DOT,    KC_RSFT   , KC_WH_U,
                              KC_LCTL, LGUI_, LT1_SPC, LT1_SPC, RGUI_, KC_RALT
    ),
    [num_sym] = LAYOUT(
        KC_MUTE, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0, _______, _______,
        KC_TAB , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_GRV , KC_SLSH,    KC_ENT    , KC_HOME,
        _______, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,    _______   , KC_END ,
                                   _______, KC_LGUI, KC_SPC , KC_SPC , KC_RGUI, _______
    ),
    [function] = LAYOUT(
        KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12 ,
        _______, KC_LPAD, KC_MCTL, KC_BSPC, KC_ENT , XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,    _______    , XXXXXXX,
        DF3    , KC_MPRV, KC_MPLY, KC_MNXT, LOG    , XXXXXXX, L_Scrn , R_Scrn , XXXXXXX, XXXXXXX,      DF3      , XXXXXXX,
                                   _______, _______, _______, _______, _______, _______
    ),
    [keypad] = LAYOUT(
        _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_P7, KC_P8  , KC_P9  , XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,
        _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_PEQL, KC_P4, KC_P5  , KC_P6  , XXXXXXX,     KC_PENT     , XXXXXXX,
        DF0    , KC_PERC, KC_AMPR, KC_PIPE, KC_CIRC, KC_EXLM, KC_P1, KC_P2  , KC_P3  , XXXXXXX,     KC_NUM      , XXXXXXX,
                                   KC_LGUI, KC_LCTL, KC_LALT, KC_P0, KC_PDOT, KC_PCMM
    )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [base    ] = { ENCODER_CCW_CW( KC_LEFT, KC_RGHT ) },
    [num_sym ] = { ENCODER_CCW_CW( KC_VOLD, KC_VOLU ) },
    [function] = { ENCODER_CCW_CW( UNDO   , REDO    ) },
    [keypad  ] = { ENCODER_CCW_CW( XXXXXXX, XXXXXXX ) }
};