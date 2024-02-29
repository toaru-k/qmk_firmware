// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


// Layers
enum layers {
    base = 0,
    symbols ,
    function,
};



// Additional Keycodes
// Shortcuts
#define UNDO    LGUI(KC_Z)
#define REDO    SGUI(KC_Z)
#define LOG     SGUI(KC_V)


// Screen Control
#define L_Scrn  C(KC_LEFT)
#define R_Scrn  C(KC_RGHT)


// Layer Control
#define Ls_LSPC MO(symbols )
#define Ls_RSPC LM(symbols , MOD_LSFT)
#define Lf_TAB  LT(function, KC_TAB  )
#define Lf_ENT  LT(function, KC_ENT  )


// Original Keycodes
enum custom_keycodes {
    KC_EN = SAFE_RANGE,
    LGUI_EN,
    RGUI_JP,
};


static bool jp_mode        = false;
static bool unpressed_flag = false;
static uint16_t pressed_time[5];


// Customizing Keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case Ls_LSPC:
        if (record->event.pressed) {
            pressed_time[0] = timer_read();
            unpressed_flag = true;
        } else if (timer_elapsed(pressed_time[0]) < TAPPING_TERM && unpressed_flag) {
            tap_code(KC_SPC);
            unpressed_flag = false;
        }

        return true;

    case Ls_RSPC:
        if (record->event.pressed) {
            pressed_time[1] = timer_read();
            unpressed_flag = true;
        } else if (timer_elapsed(pressed_time[1]) < TAPPING_TERM && unpressed_flag) {
            unregister_code(KC_LSFT);
            tap_code(KC_SPC);
            register_code(KC_LSFT);
            unpressed_flag = false;
        }

        return true;

    case LGUI_EN:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            pressed_time[2] = timer_read();
            unpressed_flag = true;
        } else {
            unregister_code(KC_LGUI);

             if (timer_elapsed(pressed_time[2]) < TAPPING_TERM && unpressed_flag) {
                tap_code(KC_LNG2);
                unpressed_flag = false;
                jp_mode        = false;
            }
        }

        return false;

    case RGUI_JP:
        if (record->event.pressed) {
            register_code(KC_RGUI);
            pressed_time[3] = timer_read();
            unpressed_flag = true;
        } else {
            unregister_code(KC_RGUI);

             if (timer_elapsed(pressed_time[3]) < TAPPING_TERM && unpressed_flag) {
                tap_code(KC_LNG1);
                unpressed_flag = false;
                jp_mode        = true;
            }
        }

        return false;

    case KC_EN:
        if (record->event.pressed) {
            if (jp_mode) {
                tap_code(KC_LNG2);
            }
            pressed_time[4] = timer_read();
            unpressed_flag = true;
        } else {
            if (timer_elapsed(pressed_time[4]) < TAPPING_TERM && unpressed_flag) {
                tap_code(KC_SPC);
                unpressed_flag = false;
            }
            if (jp_mode) {
                tap_code(KC_LNG1);
            }
        }

        return false;
    
    default:
        if (unpressed_flag) {
            unpressed_flag = false;
        }

        return true;
    }
};


// Key Maps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [base] = LAYOUT(
        KC_ESC , KC_Q, KC_W, KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O  , KC_P, KC_BSPC, KC_DEL ,
        Lf_TAB , KC_A, KC_S, KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L  ,    Lf_ENT    , KC_HOME,
        KC_LSFT, KC_Z, KC_X, KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT,    KC_RSFT   , KC_END ,
                             KC_LCTL, LGUI_EN, Ls_LSPC,     Ls_RSPC, RGUI_JP, KC_RALT
    ),
    [symbols] = LAYOUT(
        KC_MUTE, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   ,  KC_0, _______, _______,
        KC_TAB , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,     KC_SCLN, KC_QUOT, KC_GRV , KC_SLSH,     KC_ENT    , XXXXXXX,
        KC_ENT , KC_BSPC, KC_DEL , LOG    , L_Scrn , R_Scrn ,     XXXXXXX, XXXXXXX, KC_COMM, KC_DOT ,     XXXXXXX   , XXXXXXX,
                                   _______, KC_LGUI, KC_EN  ,     KC_EN  , KC_RGUI, _______
    ),
    [function] = LAYOUT(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12 ,
        KC_TAB , KC_ENT , KC_DEL , KC_BSPC, XXXXXXX, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,    _______    , KC_WH_D,
        KC_LSFT, L_Scrn , KC_MCTL, R_Scrn , LOG    , XXXXXXX,     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,    KC_RSFT    , KC_WH_U,
                                   _______, _______, KC_SPC ,     KC_SPC , _______, _______
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [base    ] = { ENCODER_CCW_CW( KC_LEFT, KC_RGHT ) },
    [symbols ] = { ENCODER_CCW_CW( KC_VOLD, KC_VOLU ) },
    [function] = { ENCODER_CCW_CW( UNDO   , REDO    ) },
};