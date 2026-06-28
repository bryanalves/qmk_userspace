SRC += fryguy.c
AUDIO_ENABLE = no
AUTO_SHIFT_ENABLE = no
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = yes
COMBO_ENABLE = yes
# COMMAND_ENABLE = no
CONSOLE_ENABLE = yes
EXTRAKEY_ENABLE = no
GRAVE_ESC_ENABLE = no
# LEADER_ENABLE = yes
LTO_ENABLE = yes
# MAGIC_ENABLE = no
MUSIC_ENABLE = no
# NKRO_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
OS_DETECTION_ENABLE = no


#ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  # Include my fancy rgb functions source here
  #SRC += cool_rgb_stuff.c
#endif
