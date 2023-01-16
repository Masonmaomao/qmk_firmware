
#include "mason_testpad.h"
#include "config.h"
#include <Stdio.h>
#include <stdbool.h>

/* Define a Structure to Read and Store the EEprom Status
typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

user_config_t user_config;
*/
/* Read out the EEprom config value, Config the RGBligth as the Satus stored in the EEprom
void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Set default layer, if enabled
  if (user_config.rgb_layer_change) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom_cyan();
    rgblight_mode_noeeprom(1);
  }
}
*/
/* RGB underglow changes ONLY if the value was enabled
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_magenta(); rgblight_mode_noeeprom(1); }
        break;
    case _LOWER:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_red(); rgblight_mode_noeeprom(1); }
        break;
    case _PLOVER:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_green(); rgblight_mode_noeeprom(1); }
        break;
    case _ADJUST:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_white(); rgblight_mode_noeeprom(1); }
        break;
    default: //  for any other layers, or the default layer
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_cyan(); rgblight_mode_noeeprom(1); }
        break;
    }
  return state;
}
*/

/* Specify default values for EEprom when it being reseted
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FOO:
      if (record->event.pressed) {
        // Do something when pressed
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case KC_ENTER:
        // Play a tone when enter is pressed
        if (record->event.pressed) {
            PLAY_SONG(tone_qwerty);
        }
        return true; // Let QMK send the enter press/release events
    case RGB_LYR:  // This allows me to use underglow as layer indication, or as normal
        if (record->event.pressed) {
            user_config.rgb_layer_change ^= 1; // Toggles the status
            eeconfig_update_user(user_config.raw); // Writes the new status to EEPROM
            if (user_config.rgb_layer_change) { // if layer state indication is enabled,
                layer_state_set(layer_state);   // then immediately update the layer color
            }
        }
        return false;
    case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT: // For any of the RGB codes (see quantum_keycodes.h, L400 for reference)
        if (record->event.pressed) { //This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
            if (user_config.rgb_layer_change) {        // only if this is enabled
                user_config.rgb_layer_change = false;  // disable it, and
                eeconfig_update_user(user_config.raw); // write the setings to EEPROM
            }
        }
        return true; break;
    default:
      return true; // Process all other keycodes normally
  }
}
*/
/* Specify default values for EEprom when it being reseted
void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.rgb_layer_change = true; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv_cyan();  // Set it to CYAN by default
  rgblight_mode(1); // set to solid by default
}
*/



/* Caps Lock indicator */
#ifdef RGBLIGHT_ENABLE

// Light LEDs 35 to 35 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {35, 1, HSV_RED},       // Light the 35th LED
);
// Now define the array of capslock layer
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
);
// Enable the LED layers
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}
// Active the Capslock Layer when the Capslock toggled on
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
#endif

/* Keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*

    Keymap
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011,
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109,       K111,
	K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,
	K300, K301, K302,                   K306,                   K310, K311

    */

    /* Base Layer */
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P, KC_BSLS,
	    KC_TAB,  KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,          KC_ENT,
	    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_RSFT, MO(1),
	    KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,                    KC_RALT, KC_CAPS
    ),

    /* RGB Layer */
    [1] = LAYOUT(
        RGB_TOG,  RGB_MODE_FORWARD,    RGB_MODE_REVERSE,    RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,    RGB_SPI,    RGB_SPD, KC_NO,
	    RGB_MODE_PLAIN,  RGB_MODE_BREATHE,    RGB_MODE_RAINBOW,    RGB_MODE_SWIRL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,          KC_NO,
	    BL_TOGG, BL_STEP,    BL_INC,    BL_DEC, BL_BRTG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(0),
	    KC_NO, KC_NO, KC_NO,               KC_NO,                    KC_NO, KC_NO
    ),

};
