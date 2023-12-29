#include QMK_KEYBOARD_H
#include <stdio.h>

bool dbg = false;
int RGB_current_mode;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

#define HSV_MINE 10, 255, 103

enum layer_number {
    _QWERTY = 0,
    _QWERTY_MODS,
    _FUNC1,
    _FUNC2,
};

enum combos {
    CMB_DEL
};

enum custom_keycodes {
    KC_HMOD = SAFE_RANGE,
    KC_DBG,
};

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

#define KCC_ESC CTL_T(KC_ESC)

#define KC_____ KC_TRNS

const uint16_t PROGMEM del_combo[] = {KC_0, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CMB_DEL] = COMBO(del_combo, KC_DEL)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
         KC_GRV,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                              KC_6,      KC_7,      KC_8,      KC_9,      KC_0,   KC_BSPC,\
         KC_TAB,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                              KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,   KC_BSLS,\
        KCC_ESC,      KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                              KC_H,      KC_J,      KC_K,      KC_L,   KC_SCLN,   KC_QUOT,\
        KC_LSFT,   KCM_S_Z,      KC_X,      KC_C,      KC_V,      KC_B,   KC_LBRC,     KC_RBRC,      KC_N,      KC_M,   KC_COMM,    KC_DOT,  KCM_S_SL,   KC_RSFT,\
                                       KC_LALT,   KC_LGUI,MO(_FUNC1),    KC_ENT,          KC_SPC,MO(_FUNC2),   KC_BSPC,   KC_RCTL                                \
    ),

  [_QWERTY_MODS] = LAYOUT( \
        KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,                           KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,\
        KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,                           KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,\
        KC_____,   KCM_G_A,   KCM_A_S,   KCM_C_D,   KCM_S_F,   KC_____,                           KC_____,   KCM_S_J,   KCM_C_K,   KCM_A_L,  KCM_G_SC,   KC_____,\
        KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,     KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,\
                                       KC_____,   KC_____,   KC_____,   KC_____,         KC_____,   KC_____,   KC_____,   KC_____                                \
    ),

  [_FUNC1] = LAYOUT( \
         KC_F11,     KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                             KC_F6,     KC_F7,     KC_F8,     KC_F9,    KC_F10,    KC_F12,\
        KC_____,   KC_____,   KC_____,    KC_END,   KC_____,   KC_____,                           KC_HOME,    KC_END,    KC_INS,   KC_____,  KC_MINUS,    KC_EQL,\
        KC_____,   KC_HOME,   KC_____,   KC_____,   KC_____,   KC_____,                           KC_LEFT,   KC_DOWN,     KC_UP,  KC_RIGHT,   KC_____,   KC_____,\
        KC_____,   KC_____,    KC_DEL,   KC_____, S(KC_INS),   KC_____,   KC_PGUP,     KC_PGDN,   KC_PGUP,   KC_PGDN,   KC_____,   KC_____,   KC_____,   KC_____,\
                                       KC_____,   KC_____,   KC_____,   KC_____,         KC_____,   KC_____,   KC_____,   KC_____                                \
    ),

  [_FUNC2] = LAYOUT( \
        QK_BOOT,   RGB_TOG,   RGB_HUI,   RGB_SAI,   RGB_VAI,   KC_____,                           KC_____,   KC_____,   KC_____,   KC_PSCR,   KC_SCRL,  KC_PAUSE,\
      QK_REBOOT,   RGB_MOD,   RGB_HUD,   RGB_SAD,   RGB_VAD,   KC_____,                           KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,\
        KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,                           KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,\
        KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_____,   KC_VOLD,     KC_VOLU,   KC_____,   KC_MUTE,   KC_____,   KC_____,   KC_____,   KC_____,\
                                        KC_DBG,   KC_____,   KC_____,   KC_____,         KC_HMOD,   KC_____,   KC_____,   KC_____                                \
    ),
};

#ifdef OLED_ENABLE

const char *read_rgb_info(void);
const char *read_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;

    return rotation;
}

void write_layer_state(void) {
    switch (layer_state) {
        case _QWERTY:
           oled_write_ln_P(PSTR("Layer: Default"), false);
           break;

        case 1 << _QWERTY_MODS:
            oled_write_ln_P(PSTR("Layer: H-Mods"), false);
            break;

        case 1 << _FUNC1:
        case (1 << _FUNC1) + (1 << _QWERTY_MODS):
            oled_write_ln_P(PSTR("Layer: Func1"), false);
            break;

        case 1 << _FUNC2:
        case (1 << _FUNC2) + (1 << _QWERTY_MODS):
            oled_write_ln_P(PSTR("Layer: Func2"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Layer: Undefined"), false);
    }
}

void write_mods_state(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    bool    ctrl = mods & MOD_MASK_CTRL;
    bool    shft = mods & MOD_MASK_SHIFT;
    bool    alt  = mods & MOD_MASK_ALT;
    bool    gui  = mods & MOD_MASK_GUI;

    oled_write_P(ctrl ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P(shft ? PSTR("SHIFT ") : PSTR("      "), false);
    oled_write_P(alt ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_ln_P(gui ? PSTR("GUI ") : PSTR("    "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (dbg) {
            write_layer_state();
            write_mods_state();
            oled_write_ln(read_rgb_info(), false);
        } else {
            oled_write(read_logo(), false);
        }
    } else {
        oled_write(read_logo(), false);
    }

    return false;
}

void suspend_power_down_user(void) {
    oled_clear();
    oled_off();
}

#endif // OLED_ENABLE

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            // Toggle homerow mods, regardless of the current layout.
            case KC_HMOD:
                if (IS_LAYER_ON(_QWERTY_MODS)) {
                    layer_off(_QWERTY_MODS);
                }
                else {
                    layer_on(_QWERTY_MODS);
                }

                return false;

            case KC_DBG:
                dbg = !dbg;
                oled_clear();
                return false;
        }
    }

    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}
