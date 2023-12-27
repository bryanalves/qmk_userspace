/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/*
 * QUICK_TAP_TERM 0

*/
#pragma once

#undef MANUFACTURER
#define MANUFACTURER "Bryan"
#undef PRODUCT
#define PRODUCT "Lily58"

#define MASTER_LEFT

#define TAPPING_TERM 175
#define TAPPING_TOGGLE 2
#define TAPPING_FORCE_HOLD_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY
#define DYNAMIC_TAPPING_TERM_INCREMENT 10
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define COMBO_COUNT 1
#define COMBO_TERM 60

#undef RGBLED_NUM
#define RGBLED_NUM 24
#define RGBLED_SPLIT { 12, 12 }

#define RGBLIGHT_SLEEP

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
