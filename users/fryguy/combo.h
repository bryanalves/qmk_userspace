enum combos {
    CMB_DEL,
    CMB_CAPS,
};

const uint16_t PROGMEM del_combo[] = {KC_0, KC_BSPC, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};

combo_t key_combos[] = {
    [CMB_DEL] = COMBO(del_combo, KC_DEL),
    [CMB_CAPS] = COMBO(caps_combo, KC_CAPS)
};
