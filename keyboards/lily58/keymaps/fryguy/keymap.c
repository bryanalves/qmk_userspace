#include QMK_KEYBOARD_H
#include <stdio.h>

bool dbg = false;
int RGB_current_mode;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

#define HSV_MINE 10, 255, 103

#ifdef RGBLIGHT_LAYERS
// const rgblight_segment_t PROGMEM _shift_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//   {3, 1, HSV_RED},
//   {13, 1, HSV_RED}
// );


const rgblight_segment_t PROGMEM _qwerty_layer[]   = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_MINE} );
const rgblight_segment_t PROGMEM _hmod_layer[]     = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_MINE} );
const rgblight_segment_t PROGMEM _func1_layer[]    = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_BLUE} );
const rgblight_segment_t PROGMEM _func2_layer[]    = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_PINK} );

const rgblight_segment_t PROGMEM _shift_layer[]    = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_RED} );
const rgblight_segment_t PROGMEM _ctrl_layer[]     = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_GREEN} );
const rgblight_segment_t PROGMEM _alt_layer[]      = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_GOLDENROD} );
const rgblight_segment_t PROGMEM _super_layer[]    = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_CORAL} );

const rgblight_segment_t PROGMEM _capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 24, HSV_MAGENTA} );

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  _qwerty_layer,
  _hmod_layer,
  _func1_layer,
  _func2_layer,
  _shift_layer,
  _ctrl_layer,
  _alt_layer,
  _super_layer,
  _capslock_layer
);

#endif

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

// ├─┬

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,---------------------------------------------------------.                   .----------------------------------------------------------.
           KC_GRV,   KC_1,   KC_2,   KC_3,    KC_4,       KC_5,                           KC_6,    KC_7,     KC_8,   KC_9,    KC_0,   KC_BSPC,\
  //,------------+-------+-------+-------+-------+------------/                   /-----------+--------+---------+-------+--------+----------/
           KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,       KC_T,                           KC_Y,    KC_U,     KC_I,   KC_O,    KC_P,   KC_BSLS,\
  //,------------+-------+-------+-------+-------+------------/                   /-----------+--------+---------+-------+--------+----------/
          KCC_ESC,   KC_A,   KC_S,   KC_D,   KC_F,        KC_G,                           KC_H,    KC_J,     KC_K,   KC_L, KC_SCLN,   KC_QUOT,\
  //,------------+-------+-------+-------+-------+------------+--------/  /-------/-----------+--------+---------+-------+--------+----------/
          KC_LSFT,KCM_S_Z,   KC_X,   KC_C,    KC_V,       KC_B, KC_LBRC,   KC_RBRC,       KC_N,    KC_M,  KC_COMM, KC_DOT, KCM_S_SL,   KC_RSFT,\
  //,------------+-------+-------+-------+-------+------------+--------/  /-------.-----------+--------+---------+-------+--------+-----------/
                                  KC_LALT, KC_LGUI, MO(_FUNC1),  KC_ENT,    KC_SPC, MO(_FUNC2), KC_BSPC, KC_RCTL \
                                //,------------------------------------,  ,---------------------------------------,
  ),

  [_QWERTY_MODS] = LAYOUT( \
  //,---------------------------------------------------.                    .----------------------------------------------------.
    KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,                     KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+--------+--------/                    /-------+--------+--------+--------+--------+--------/
    KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,                     KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+--------+--------/                    /-------+--------+--------+--------+--------+--------/
    KC_____, KCM_G_A, KCM_A_S, KCM_C_D, KCM_S_F, KC_____,                     KC_____, KCM_S_J, KCM_C_K, KCM_A_L, KCM_G_SC, KC_____,\
  //,------+--------+--------+--------+--------+--------+--------/  /-------/-------+--------+--------+--------+--------+---------/
    KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,   KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+--------+--------+--------/  /-------/-------+--------+--------+--------+--------+---------/
                              KC_____, KC_____, KC_____, KC_____,   KC_____, KC_____, KC_____, KC_____ \
                            //,----------------------------------,  ,-----------------------------------,
),

  [_FUNC1] = LAYOUT( \
  //,-----------------------------------------------------.                    .-----------------------------------------------------.
     KC_F11,   KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,\
  //,------+--------+--------+--------+----------+--------/                    /--------+--------+--------+--------+--------+--------/
    KC_____, KC_____, KC_____,  KC_END,   KC_____, KC_____,                      KC_HOME,  KC_END,  KC_INS, KC_____,KC_MINUS,  KC_EQL,\
  //,------+--------+--------+--------+----------+--------/                    /--------+--------+--------+--------+--------+--------/
    KC_____, KC_HOME, KC_____, KC_____,   KC_____, KC_____,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_____, KC_____,\
  //,------+--------+--------+--------+----------+--------+--------/   /-------/--------+--------+--------+--------+--------+--------/
    KC_____, KC_____,  KC_DEL, KC_____, S(KC_INS), KC_____, KC_PGUP,    KC_PGDN, KC_PGUP, KC_PGDN, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+----------+--------+--------/   /-------/--------+--------+--------+--------+--------+--------/
                               KC_____,   KC_____, KC_____, KC_____,    KC_____, KC_____, KC_____, KC_____ \
                             //,-----------------------------------,   ,-----------------------------------,
  ),

  [_FUNC2] = LAYOUT( \
  //,----------------------------------------------------.                    .-----------------------------------------------------.
      QK_BOOT, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_____,                      KC_____, KC_____, KC_____, KC_PSCR, KC_SCRL, KC_PAUSE,\
  //,-------+--------+--------+--------+--------+--------/                    /--------+--------+--------+--------+--------+--------/
     QK_REBOOT, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_____,                      KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_____, KC_____,\
  //,-------+--------+--------+--------+--------+--------/                    /--------+--------+--------+--------+--------+--------/
     KC_____, KC_____,  KC_____, KC_____, KC_____, KC_____,                      KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_____, KC_____,\
  //,-------+--------+--------+--------+--------+--------+--------/   /-------/--------+-------+--------+--------+--------+---------/
     KC_____, KC_____,  KC_____, KC_____, KC_____,  KC_____, KC_VOLD,    KC_VOLU, KC_____, KC_MUTE, KC_____, KC_____, KC_____, KC_____,\
  //,-------+--------+--------+--------+--------+--------+--------/   /-------/--------+--------+--------+--------+--------+--------/
                          KC_DBG, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1,    KC_HMOD, KC_____, KC_____, KC_____ \
                              //,---------------------------------,   ,-----------------------------------,
  ),

};

#ifdef OLED_ENABLE

const char *read_layer_state(void);
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

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_LAYERS
  rgblight_layers = _rgb_layers;
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
  for (int i = _QWERTY; i <=  _FUNC2; i++) {
    rgblight_set_layer_state(i, layer_state_cmp(state, i));
  }
#endif
  return state;
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_LAYERS
  rgblight_set_layer_state(8, led_state.caps_lock);
#endif
  return true;
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
}

void matrix_scan_user(void) {
#ifdef RGBLIGHT_LAYERS
  uint8_t mods = mod_config(get_mods());
  rgblight_set_layer_state(4, mods & MOD_MASK_SHIFT);
  rgblight_set_layer_state(5, mods & MOD_MASK_CTRL);
  rgblight_set_layer_state(6, mods & MOD_MASK_ALT);
  rgblight_set_layer_state(7, mods & MOD_MASK_GUI);
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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}
