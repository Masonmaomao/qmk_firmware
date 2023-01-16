# MCU name
MCU = STM32F072
# BootLoader name
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
ENCODER_ENABLE = no
BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration/ESC_Pressed when USB cable inserted
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no        # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
KEY_LOCK_ENABLE = no
# BACKLIGHT_ENABLE = yes	   # Pre-Key LED
# BACKLIGHT_DRIVER = pwm
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
# WS2812_DRIVER = PWM
OLED_DRIVER_ENABLE = no
AUTO_SHIFT_ENABLE = yes
VELOCIKEY_ENABLE = yes
