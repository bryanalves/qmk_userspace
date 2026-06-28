// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "fryguy.h"
#include "combo.h"

#define LAYOUT_EXPAND(...) LAYOUT(__VA_ARGS__)

#define TRANSPARENT_ENC _______, _______

#define LAYER_MODS \
    QWERTY_LEFT1, KCM_ZOOMR, KCM_ZOOMR, QWERTY_RIGHT1,\
    QWERTY_LEFT2,                       QWERTY_RIGHT2,\
    HMOD_LEFT,                          HMOD_RIGHT,\
    QWERTY_LEFT4, KC_LBRC, KC_RBRC,     QWERTY_RIGHT4,\
    BASE_LTHUMB4,                       BASE_RTHUMB4

#define LAYER_QWERTY \
    TRANSPARENT_ROW,    TRANSPARENT_ENC,  TRANSPARENT_ROW,\
    TRANSPARENT_ROW,                      QWERTY_RIGHT2,\
    TRANSPARENT_ROW,                      QWERTY_RIGHT3,\
    TRANSPARENT_ROW,    _______, _______, TRANSPARENT_ROW,\
    TRANSPARENT_THUMB4,                   TRANSPARENT_THUMB4

#define LAYER_FUNC1 \
    FUNC1_LEFT1, TRANSPARENT_ENC,  FUNC1_RIGHT1,\
    FUNC1_LEFT2,                   FUNC1_RIGHT2,\
    FUNC1_LEFT3,                   FUNC1_RIGHT3,\
    FUNC1_LEFT4, KC_PGUP, KC_PGDN, FUNC1_RIGHT4,\
    TRANSPARENT_THUMB4,            TRANSPARENT_THUMB4

#define LAYER_FUNC2 \
    FUNC2_LEFT1, TRANSPARENT_ENC,  FUNC2_RIGHT1,\
    FUNC2_LEFT2,                   FUNC2_RIGHT2,\
    FUNC2_LEFT3,                   FUNC2_RIGHT3,\
    FUNC2_LEFT4, KC_VOLD, KC_VOLU, FUNC2_RIGHT4,\
    FUNC2_LEFT_T,                  FUNC2_RIGHT_T

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY_MODS] = LAYOUT_EXPAND(LAYER_MODS),
  [_QWERTY] = LAYOUT_EXPAND(LAYER_QWERTY),
  [_FUNC1] = LAYOUT_EXPAND(LAYER_FUNC1),
  [_FUNC2] = LAYOUT_EXPAND(LAYER_FUNC2)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R', 'R',
                  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
    );


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY_MODS] = { ENCODER_CCW_CW(KCM_ZOOMU, KCM_ZOOMD), ENCODER_CCW_CW(KCM_ZOOMU, KCM_ZOOMD) },
    [_QWERTY] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FUNC1] = { ENCODER_CCW_CW(FWD_CFG, REV_CFG), ENCODER_CCW_CW(FWD_CFG, REV_CFG) },
    [_FUNC2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FWD_CFG:
        case REV_CFG:
            if (record->event.pressed) {
                switch (get_mods() | get_oneshot_mods()) {
                    case MOD_BIT(KC_LGUI):
                        keycode == FWD_CFG ? rgb_matrix_increase_hue() : rgb_matrix_decrease_hue();
                        break;
                    case MOD_BIT(KC_LALT):
                        keycode == FWD_CFG ? rgb_matrix_increase_sat() : rgb_matrix_decrease_sat();
                        break;
                    case MOD_BIT(KC_LCTL):
                        keycode == FWD_CFG ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
                        break;
                    case MOD_BIT(KC_LSFT):
                        keycode == FWD_CFG ? rgb_matrix_increase_speed() : rgb_matrix_decrease_speed();
                        break;
                    case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL):
                        keycode == FWD_CFG ? rgb_matrix_step() : rgb_matrix_step_reverse();
                        break;
                    default:
                        break;
                }
            }

            return false;
    }

    return true;
}
