// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "fryguy.h"

#define LAYOUT_EXPAND(...) LAYOUT(__VA_ARGS__)

#define TRANSPARENT_ENC _______, _______

#define LAYER_QWERTY \
    QWERTY_LEFT1, KCM_ZOOMR, KCM_ZOOMR, QWERTY_RIGHT1,\
    QWERTY_LEFT2,                       QWERTY_RIGHT2,\
    QWERTY_LEFT3,                       QWERTY_RIGHT3,\
    QWERTY_LEFT4, KC_LBRC,   KC_RBRC,   QWERTY_RIGHT4,\
    BASE_LTHUMB4,                       BASE_RTHUMB4

#define LAYER_MODS \
    TRANSPARENT_ROW, TRANSPARENT_ENC,   TRANSPARENT_ROW,\
    TRANSPARENT_ROW,                    TRANSPARENT_ROW,\
    HMOD_LEFT,                          HMOD_RIGHT,\
    TRANSPARENT_ROW,  _______, _______, TRANSPARENT_ROW,\
    TRANSPARENT_THUMB4,                 TRANSPARENT_THUMB4

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
  [_QWERTY] = LAYOUT_EXPAND(LAYER_QWERTY),
  [_QWERTY_MODS] = LAYOUT_EXPAND(LAYER_MODS),
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KCM_ZOOMU, KCM_ZOOMD), ENCODER_CCW_CW(KCM_ZOOMU, KCM_ZOOMD) },
    [_QWERTY_MODS] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FUNC1] = { ENCODER_CCW_CW(FWD_CFG, REV_CFG), ENCODER_CCW_CW(FWD_CFG, REV_CFG) },
    [_FUNC2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif // ENCODER_MAP_ENABLE

#if defined(COMBO_ENABLE)
#    include "combo.h"
#endif

#ifdef OLED_ENABLE

bool is_oled_enabled = true;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
    if (!is_oled_enabled) {
        oled_off();
        return false;
    } else  {
        oled_on();
    }

    write_layer_state();
    write_mods_state();
    write_host_led_state();
    write_rgb_state();

   return false;
}

void housekeeping_task_user(void) {
    is_oled_enabled = (bool)((last_input_activity_elapsed()) < 20000);
}

#endif // OLED_ENABLE
