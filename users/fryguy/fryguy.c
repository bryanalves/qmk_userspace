#include "fryguy.h"

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

void write_host_led_state(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

void write_rgb_state(void) {
    static char rgbStatusLine[26] = {0};
    snprintf(rgbStatusLine, sizeof(rgbStatusLine), "%d %d/%d/%d/%d", rgblight_get_mode(), rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), rgb_matrix_get_speed());
    oled_write_ln(rgbStatusLine, false);
}

void write_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_HMOD:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_QWERTY_MODS)) {
                    layer_off(_QWERTY_MODS);
                }
                else {
                    layer_on(_QWERTY_MODS);
                }
            }

            return false;

        case FWD_CFG:
        case REV_CFG:
            if (record->event.pressed) {
                switch (get_mods() | get_oneshot_mods()) {
#if defined(RGB_MATRIX_ENABLE)
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
#endif // RGB_MATRIX_ENABLE
                    default:
                        break;
                }
            }

            return false;
    }

    return true;
}
