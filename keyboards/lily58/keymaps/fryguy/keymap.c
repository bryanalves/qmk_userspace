#include <stdio.h>

#include "fryguy.h"

#define LAYOUT_EXPAND(...) LAYOUT(__VA_ARGS__)

#define LAYER_QWERTY \
    QWERTY_LEFT1,                    QWERTY_RIGHT1,\
    QWERTY_LEFT2,                    QWERTY_RIGHT2,\
    QWERTY_LEFT3,                    QWERTY_RIGHT3,\
    QWERTY_LEFT4, KC_LBRC,  KC_RBRC, QWERTY_RIGHT4,\
    BASE_LTHUMB4,                    BASE_RTHUMB4

#define LAYER_MODS \
    TRANSPARENT_ROW,                    TRANSPARENT_ROW,\
    TRANSPARENT_ROW,                    TRANSPARENT_ROW,\
    HMOD_LEFT,                          HMOD_RIGHT,\
    TRANSPARENT_ROW,  _______, _______, TRANSPARENT_ROW,\
    TRANSPARENT_THUMB4,                 TRANSPARENT_THUMB4

#define LAYER_FUNC1 \
    FUNC1_LEFT1,                   FUNC1_RIGHT1,\
    FUNC1_LEFT2,                   FUNC1_RIGHT2,\
    FUNC1_LEFT3,                   FUNC1_RIGHT3,\
    FUNC1_LEFT4, KC_PGUP, KC_PGDN, FUNC1_RIGHT4,\
    TRANSPARENT_THUMB4,            TRANSPARENT_THUMB4

#define LAYER_FUNC2 \
    FUNC2_LEFT1,                   FUNC2_RIGHT1,\
    FUNC2_LEFT2,                   FUNC2_RIGHT2,\
    FUNC2_LEFT3,                   FUNC2_RIGHT3,\
    FUNC2_LEFT4, KC_VOLD, KC_VOLU, FUNC2_RIGHT4,\
    FUNC2_LEFT_T,                  FUNC2_RIGHT_T

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_EXPAND(LAYER_QWERTY),
  [_QWERTY_MODS] = LAYOUT_EXPAND(LAYER_MODS),
  [_FUNC1] = LAYOUT_EXPAND(LAYER_FUNC1),
  [_FUNC2] = LAYOUT_EXPAND(LAYER_FUNC2),
};

#if defined(COMBO_ENABLE)
#    include "combo.h"
#endif

#ifdef OLED_ENABLE

void write_logo(void) {
    static char logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};

    oled_write(logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;

    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        write_layer_state();
        write_mods_state();
        write_rgb_state();
    } else {
        write_logo();
    }

    return false;
}

void suspend_power_down_user(void) {
    oled_clear();
    oled_off();
}

#endif // OLED_ENABLE
