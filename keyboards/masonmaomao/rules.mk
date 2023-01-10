# MCU name
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
MCU = STM32F072

# Bootloader selection
BOOTLOADER = stm32-dfu
=======
=======
>>>>>>> 62c7ae0a69 (Add initial rules.mk)
=======
>>>>>>> 92a127c1fb (Add initial rules.mk)
=======
>>>>>>> 4b812ebaea (Add initial rules.mk)
=======
>>>>>>> 7db44193cc (Add initial rules.mk)
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 909bb8056e (Add initial rules.mk)
=======
>>>>>>> 62c7ae0a69 (Add initial rules.mk)
=======
>>>>>>> 92a127c1fb (Add initial rules.mk)
=======
>>>>>>> 4b812ebaea (Add initial rules.mk)
=======
>>>>>>> 7db44193cc (Add initial rules.mk)

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGBMATIX_ENABLE = yes       # Enable keyboard RGB Matrix
RGB_MATRIX_DRIVER = pwm     # Define the RGB Driver mode as pwm
AUDIO_ENABLE = no           # Audio output

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
=======
=======
>>>>>>> 62c7ae0a69 (Add initial rules.mk)
=======
>>>>>>> 92a127c1fb (Add initial rules.mk)
=======
>>>>>>> 4b812ebaea (Add initial rules.mk)
=======
>>>>>>> 7db44193cc (Add initial rules.mk)
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 909bb8056e (Add initial rules.mk)
=======
>>>>>>> 62c7ae0a69 (Add initial rules.mk)
=======
>>>>>>> 92a127c1fb (Add initial rules.mk)
=======
>>>>>>> 4b812ebaea (Add initial rules.mk)
=======
>>>>>>> 7db44193cc (Add initial rules.mk)
