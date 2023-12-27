AUDIO_ENABLE = no
AUTO_SHIFT_ENABLE = no
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = no
GRAVE_ESC_ENABLE = no
#LEADER_ENABLE = yes
LTO_ENABLE = yes
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = yes
#MOUSEKEY_ENABLE = no
MUSIC_ENABLE = no
NKRO_ENABLE = no
OLED_ENABLE= yes
# OLED_DRIVER = SSD1306
RGBLIGHT_ENABLE = yes
SLEEP_LED_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no

# BCAT_OLED_PET = luna
# SPLIT_TRANSPORT = mirror
# WPM_ENABLE = yes
#SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
#DYNAMIC_TAPPING_TERM_ENABLE = yes


# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/logo_reader.c \
        # ./lib/layer_state_reader.c \
        # ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
