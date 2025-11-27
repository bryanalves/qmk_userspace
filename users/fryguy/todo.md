rgb.h
--

/// RGB Matrix (https://docs.qmk.fm/features/rgb_matrix)
extern const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3];
extern rgb_config_t rgb_matrix_config;
extern const int left_shift_index;

// clang-format off
#define BLACK { HSV_BLACK }
#define BHITE { 128, 60, 255 } // Bluer white if white ends up being pink
#define BLUE  { HSV_BLUE }
#define CYAN  { HSV_CYAN }
#define GREEN { HSV_GREEN }
#define MAGNT { HSV_MAGENTA }
#define ORANG { HSV_ORANGE }
#define RED   { HSV_RED }
#define WHITE { HSV_WHITE }
#define YELLW { HSV_YELLOW }
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };

        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    // if (rawhid_state.rgb_control) return false;
    // if (keyboard_config.disable_layer_led) return false;
    set_layer_color(biton32(layer_state));

    // Caps indicator
    // uprintf("Caps Lock: %s\n", host_keyboard_led_state().caps_lock ? "on" : "off");
    // uprintf("Caps Word: %s\n", is_caps_word_on() ? "on" : "off");
#ifdef CAPS_WORD_ENABLE
    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
        rgb_matrix_set_color(left_shift_index, RGB_WHITE);
    }
#endif

    // Leader indicator
    // if (leader_sequence_active()) {
    //     rgb_matrix_set_color(40, RGB_GREEN);
    // }

    return true;
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_BASE] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, YELLW,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , ORANG,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        BHITE, CYAN ,
    },

    [LAYER_LINUX] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, BLUE ,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , ORANG,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        BHITE, CYAN ,
    },

    [LAYER_GAME] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        CYAN , BLUE , CYAN , MAGNT, CYAN , CYAN ,
        CYAN , BLUE , MAGNT, MAGNT, MAGNT, CYAN ,
        CYAN , BLUE , CYAN , CYAN , CYAN , CYAN ,
        CYAN , MAGNT,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , GREEN,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        BHITE, CYAN ,
    },

    [LAYER_DWARF] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , MAGNT,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        CYAN , CYAN , CYAN , CYAN , CYAN , ORANG,
        CYAN , CYAN , CYAN , CYAN , CYAN , CYAN ,
        CYAN , CYAN , CYAN , CYAN , CYAN , BLUE ,
        BHITE, CYAN ,
    },

    [LAYER_SYM] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        BLUE , ORANG, ORANG, ORANG, ORANG, ORANG,
        MAGNT, GREEN,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        ORANG, ORANG, ORANG, ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG, ORANG, ORANG, ORANG,
        ORANG, ORANG, ORANG, ORANG, ORANG, BLUE ,
        ORANG, CYAN ,
    },

    [LAYER_NAV] = {
        // Left
        BLUE , MAGNT, MAGNT, MAGNT, MAGNT, MAGNT,
        BLUE , BHITE, BHITE, BHITE, RED  , RED  ,
        BLUE , BHITE, BHITE, BHITE, CYAN , BLACK,
        BLUE , BLUE , BLUE , BLUE , BHITE, BLACK,
        MAGNT, YELLW,

        // Right
        MAGNT, MAGNT, MAGNT, MAGNT, MAGNT, BLUE ,
        BLACK, BLACK, YELLW, BLACK, BLACK, BLACK,
        GREEN, GREEN, GREEN, GREEN, BLACK, BLACK,
        YELLW, YELLW, YELLW, YELLW, BHITE, BLUE ,
        BLUE , BHITE,
    },

    [LAYER_NUM] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, GREEN,

        // Right
        GREEN, GREEN, GREEN, GREEN, GREEN, BLUE ,
        ORANG, GREEN, GREEN, GREEN, ORANG, BHITE,
        ORANG, GREEN, GREEN, GREEN, ORANG, ORANG,
        ORANG, GREEN, GREEN, GREEN, ORANG, BLUE ,
        CYAN , CYAN ,
    },

    [LAYER_MOUSE] = {
        // Left
        BLUE , GREEN, GREEN, GREEN, GREEN, GREEN,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        BLUE , CYAN , CYAN , CYAN , CYAN , CYAN ,
        MAGNT, YELLW,

        // Right
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        ORANG, ORANG, GREEN, ORANG, ORANG, YELLW,
        MAGNT, GREEN, GREEN, GREEN, MAGNT, YELLW,
        BLACK, MAGNT, MAGNT, MAGNT, BLACK, BHITE,
        YELLW, MAGNT,
    },
};

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow same hand holds
    switch (tap_hold_keycode) {
        case HM_Z:
            switch (other_keycode) {
                case KC_Y:
                    return false;
            }
            break;
        case HM_NSPC:
        case FN_QUOT:
            return true;
        case NU_A:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LGUI:
                case KC_LSFT:
                case MY_MEH:
                    return true;
                case KC_Y:
                case KC_P:
                case KC_H:
                case KC_L:
                case SY_SCLN:
                case KC_N:
                case NV_SLSH:
                    return false;
            }
            break;
        case NU_D:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LSFT:
                case MY_MEH:
                case NV_SLSH:
                    return true;
                case KC_LGUI:
                    // Prioritize LGUI in Linux
                    if (layer_state_is(LAYER_BASE)) return true;
            }
            break;
        case SY_F:
            switch (other_keycode) {
                case KC_E: // allow for chords in different hands, like =>
                case KC_LALT:
                case KC_LGUI:
                case MY_MEH:
                    return true;
            }
            break;
        case SY_SCLN:
            switch (other_keycode) {
                case KC_U:
                case KC_I:
                case KC_H:
                case KC_J:
                case KC_K:
                case KC_N:
                case KC_M:
                case KC_COMM:
                case KC_MINS:
                    return true;
            }
            break;
        case NV_SLSH:
            switch (other_keycode) {
                case KC_LALT:
                case KC_LCTL:
                case KC_LGUI:
                case KC_LSFT:
                case MY_MEH:
                case KC_H:
                case KC_J:
                case KC_K:
                case KC_L:
                    return true;
            }
    }

    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}
