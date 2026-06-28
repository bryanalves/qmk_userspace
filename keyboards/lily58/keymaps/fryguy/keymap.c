#include <stdio.h>

#include "fryguy.h"
#include "combo.h"

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
