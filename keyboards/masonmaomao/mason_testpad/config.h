// Copyright 2022 Masonmaomao (@Masonmaomao)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Layer States*/
#define LAYER_STATE_8BIT

/*
USB Device descriptor parameter
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0002
#define MANUFACTURER Binary_Design
#define PRODUCT Mason_TestPad
*/

/* key matrix set */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/*
Rows: Top to Bottom; Columns: Left to Right
#define MATRIX_ROW_PINS { A14, B3, A10, A8 }
#define MATRIX_COL_PINS { A6, A4, A2, A0, A15, A13, B7, A9, A7, A5, A3, A1 }
*/

/*
Dioder Direction
#define DIODE_DIRECTION ROW2COL
*/

/* Debounce Setting*/
#define DEBOUNCE 5

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DI_PIN B0
#    define RGBLED_NUM 40
#    define RGB_MATRIX_LED_COUNT RGBLED_NUM

    /* RGB Driver*/
#    define WS2812_PWM_DRIVER PWMD3                     // The PB0 I/O of STM32F072 uses the TIM3_CH3, so the PWM_Driver would be: PWMD3.
#    define WS2812_PWM_CHANNEL 3                        // The PB0 I/O of STM32F072 uses the TIM3_CH3, so the PWM_Channel would be: 3.
#    define WS2812_PWM_PAL_MODE 1                       // Pin "alternate function", TIM3_CH3 on PB0 located in AF1. so the PAL_MODE woule be: 1.
#    define WS2812_DMA_STREAM STM32_DMA1_STREAM2        // Based on the STM32F071 ref_manual, the DMA Stream and Channel for TIM3_UP, located in DMA1 Stream2, Channel3.
#    define WS2812_DMA_CHANNEL 3                        // Based on the STM32F071 ref_manual, the DMA Channel for TIM3_UP, located in DMA Channel 3.
#    define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM3_UP      // Define a TIM Pheripherial for the PWM

    /* RGB Effects*/
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_KEYRELEASES
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN

/* RGB Behavior */
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 175
#    define RGBLIGHT_VAL_STEP 10
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    define RGB_MATRIX_CENTER { 112, 32 }

/* RGB Layer Overwrite, the Capslock Layer still can work even when the RGB Lighting turned off */
#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
/* Use the same Lightness as the current RGB light setting for the Capslock LED */
#    define RGBLIGHT_LAYERS_RETAIN_VAL

#endif

/*
#ifdef BACKLIGHT_ENABLE

 Backlight Config
#define BACKLIGHT_PIN B4
#define BACKLIGHT_PWM_DRIVER PWMD4
#define BACKLIGHT_PWM_CHANNEL 3         // Need to check the datasheet
#define BACKLIGHT_PAL_MODE 1            // Need to check the datasheet

#endif
*/
/*
 * Feature disable options

 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
