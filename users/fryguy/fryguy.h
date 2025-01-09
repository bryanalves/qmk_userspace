#pragma once

#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _QWERTY_MODS,
    _FUNC1,
    _FUNC2,
};

enum custom_keycodes {
    KC_HMOD = SAFE_RANGE,
    KC_DBG,
    FWD_CFG,  // turn encoder while holding mod combinations to adjust features
    REV_CFG,  // e.g. RGB settings, haptic frequency, click frequency, base layer
};

#define KC_____ KC_TRNS

#define KCM_G_A MT(MOD_LGUI, KC_A)
#define KCM_A_S MT(MOD_LALT, KC_S)
#define KCM_C_D MT(MOD_LCTL, KC_D)
#define KCM_S_F MT(MOD_LSFT, KC_F)

#define KCM_S_J MT(MOD_RSFT, KC_J)
#define KCM_C_K MT(MOD_RCTL, KC_K)
#define KCM_A_L MT(MOD_RALT, KC_L)
#define KCM_G_SC MT(MOD_RGUI, KC_SCLN)

#define KCM_S_Z MT(MOD_LSFT, KC_Z)
#define KCM_S_SL MT(MOD_LSFT, KC_SLSH)

#define KCM_C_ESC CTL_T(KC_ESC)

#define KCM_ZOOMU C(KC_EQL)
#define KCM_ZOOMD C(KC_MINUS)
#define KCM_ZOOMR C(KC_0)

#define QWERTY_LEFT1 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5
#define QWERTY_LEFT2 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T
#define QWERTY_LEFT3 KCM_C_ESC, KC_A, KC_S, KC_D, KC_F, KC_G
#define QWERTY_LEFT4 KC_LSFT, KCM_S_Z, KC_X, KC_C, KC_V, KC_B

#define QWERTY_RIGHT1 KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC
#define QWERTY_RIGHT2 KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS
#define QWERTY_RIGHT3 KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
#define QWERTY_RIGHT4 KC_N, KC_M, KC_COMM, KC_DOT, KCM_S_SL, KC_RSFT

#define BASE_LTHUMB4 KC_LALT, KC_LGUI, MO(_FUNC1), KC_ENT
#define BASE_RTHUMB4 KC_SPC, MO(_FUNC2), KC_BSPC, KC_RCTL

#define FUNC1_LEFT1 KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define FUNC1_LEFT2 _______, _______, _______, KC_END, _______, _______
#define FUNC1_LEFT3 _______, KC_HOME, _______, _______, _______,  _______
#define FUNC1_LEFT4 _______, _______, KC_DEL,  _______, S(KC_INS), _______

#define FUNC1_RIGHT1 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12
#define FUNC1_RIGHT2 KC_HOME, KC_END,  KC_INS, _______, KC_MINUS, KC_EQL
#define FUNC1_RIGHT3 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______
#define FUNC1_RIGHT4 KC_PGUP, KC_PGDN, _______, _______, _______, _______

#define HMOD_LEFT _______, KCM_G_A, KCM_A_S, KCM_C_D, KCM_S_F, _______
#define HMOD_RIGHT _______, KCM_S_J, KCM_C_K, KCM_A_L, KCM_G_SC, _______

#define FUNC2_LEFT1 QK_BOOT,   UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, _______
#define FUNC2_LEFT2 QK_REBOOT, UG_NEXT, UG_HUED, UG_SATD, UG_VALD, _______
#define FUNC2_LEFT3 _______, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, _______
#define FUNC2_LEFT4 _______, RM_NEXT, RM_HUED, RM_SATD, RM_VALD, _______

#define FUNC2_RIGHT1 _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUSE
#define FUNC2_RIGHT2 TRANSPARENT_ROW
#define FUNC2_RIGHT3 TRANSPARENT_ROW
#define FUNC2_RIGHT4 _______, KC_MUTE, _______, _______, _______, _______
#define FUNC2_LEFT_T KC_DBG, _______, _______, _______
#define FUNC2_RIGHT_T KC_HMOD, _______, _______, _______

#define TRANSPARENT_ROW _______, _______, _______, _______, _______, _______
#define TRANSPARENT_THUMB4 _______, _______, _______, _______

const void write_layer_state(void);
const void write_mods_state(void);
const void write_host_led_state(void);
const void write_rgb_state(void);
const void write_qmk_logo(void);

//PDF(layer)
//TG(layer)
