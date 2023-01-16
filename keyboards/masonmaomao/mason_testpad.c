
#include "mason_testpad.h"

/* Define Per-Key RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#    define XX NO_LED
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11},
        {22, 21, 20, 19, 18, 17, 16, 15, 14, 13, XX, 12},
        {23, XX, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33},
        {39, 38, 37, XX, XX, XX, 36, XX, XX, XX, 35, 34},
    },

    {
        // LED Index to Physical Position
        /* Cal. the Phical Position of the RGB based on the RGB Matrix
                x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
                y =  64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
        */
        {0, 0},     {20, 0},    {41, 0},    {61, 0},    {81, 0},    {102, 0},   {122, 0},   {143, 0},  {163, 0},   {183, 0},  {204, 0},  {224, 0},              // 12 RGB LEDs for row0
        {224, 21},  {188, 21},  {168, 32},  {148, 32},  {127, 32},  {107, 32},  {87, 32},   {66, 32},  {46, 32},   {25, 32},  {5, 32},                          // 11 RGB LEDs for row1
        {15, 43},   {36, 43},   {56, 43},   {76, 43},   {97, 43},   {117, 43},  {137, 43},  {158, 43}, {178, 43},  {204, 43}, {224, 43},                        // 11 RGB LEDs for row3
        {224, 64},  {199, 64},  {173, 64},  {46, 64},   {25, 64},   {5, 64},                                                                                    // 6  RGB LEDs for row4
    },

    {
        // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4
    }
    };

#endif

#ifdef RGB_DISABLE_WHEN_USB_SUSPENDED
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif
