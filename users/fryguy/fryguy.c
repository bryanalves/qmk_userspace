#include "fryguy.h"

void write_layer_state(void) {
    switch (layer_state) {
        case _QWERTY_MODS:
           oled_write_ln_P(PSTR("Layer: Default"), false);
           break;

        case 1 << _QWERTY:
            oled_write_ln_P(PSTR("Layer: Qwerty"), false);
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
    snprintf(rgbStatusLine, sizeof(rgbStatusLine), "%d %d/%d/%d/%d", rgblight_get_mode(), rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), rgblight_get_speed());
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
