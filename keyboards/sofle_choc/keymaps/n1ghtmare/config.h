/* Copyright 2022 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// Plug USB into the left half of the keyboard
// see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
#define MASTER_LEFT
// #define EE_HANDS //Use this if EEPROM setting is desired instead

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
#define SPLIT_USB_DETECT

// NKRO Settings
#ifdef NKRO_ENABLE
	#define FORCE_NKRO //Force NKRO if enabled.
#endif

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT		//Save 244 bytes (-244).
#define NO_RESET				//Save 40 bytes (-40).
#define LAYER_STATE_8BIT		//For less than 8 bits worth of layers.

// Communication between sides
#define SOFT_SERIAL_PIN D2

#ifdef RGB_MATRIX_ENABLE

#define RGB_DISABLE_WHEN_USB_SUSPENDED     // turn off effects when suspended
#define SPLIT_TRANSPORT_MIRROR             // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100  // limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash.
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_BREATHING

// Animations
// Uncomment any that you want to try. Limited by
// space on the microcontroller. The defines below mirror
// the order they animations will cycle through.

// These modes don’t require any additional defines
// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_BAND_SAT
// #define ENABLE_RGB_MATRIX_BAND_VAL
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define ENABLE_RGB_MATRIX_HUE_BREATHING
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #define ENABLE_RGB_MATRIX_PIXEL_RAIN

// These modes require the RGB_MATRIX_FRAMEBUFFER_EFFECTS define
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

// These modes require the RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES define
#define RGB_MATRIX_KEYPRESSES
// #define RGB_MATRIX_KEYRELEASES
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif

// OLED settings
#ifdef OLED_ENABLE
	#define OLED_TIMEOUT 80000			//80000 = 80secs, 120000 = 2mins in ms.
	#define OLED_BRIGHTNESS 90			//Default is 100.
	#define SPLIT_OLED_ENABLE			//Synx on/off OLED state between halves (+100).
	#ifdef WPM_ENABLE
		#define SPLIT_WPM_ENABLE			//Enable WPM across split keyboards (+106-268).
	#endif
	#define OLED_LOGO					//Enable to print snakey custom logo on slave side (+108).
	//#define SNEAK_DISABLE				//Disable snakey keyboard pet sneak animation to save space (-132).
	//#define OLED_NO_SLAVE				//Disable snakey minimal keyboard pet slave OLED rendering (-160).
	//#define OLED_NO_MASTER				//Disable snakey minimal keyboard pet master OLED rendering and render status on the slave (+96).
	#ifdef OLED_NO_MASTER
		#define SPLIT_LAYER_STATE_ENABLE	//Keep on master to save space (+142).
		#define SPLIT_LED_STATE_ENABLE		//Keep on master to save space (+112).
		#undef SPLIT_OLED_ENABLE			//Do not sync OLED state with one OLED only (+100).
	#endif
	//#define SPLIT_MODS_ENABLE			//Keep on master to save space (+138).
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN D3
    #define RGBLED_NUM 29
    #define RGB_MATRIX_LED_COUNT 58
    #define RGB_MATRIX_SPLIT { 29, 29 }

	#define RGBLIGHT_SLEEP //Turn off LEDs when computer sleeping (+72)

    #define RGBLIGHT_EFFECT_RAINBOW_MOOD

	#define RGBLIGHT_LIMIT_VAL 120 //Power draw may still exceed the USB limitations of 0.6A at max brightness with white colour with this setting.
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17

    // TODO: This has been ported from the non-choc version which has additional LEDs for underglow (needs to be fixed?)
	/* #define LED_LAYOUT( \
		L00,	L01,	L02,	L03,	L04,	L05,		 L06,	L07,	L08,	L09,	L10,	L11, \
		L12,	L13,	L14,	L15,	L16,	L17,		 L18,	L19,	L20,	L21,	L22,	L23, \
		L24,	L25,	L26,	L27,	L28,	L29,		 L30,	L31,	L32,	L33,	L34,	L35, \
		L36,	L37,	L38,	L39,	L40,	L41,		 L42,	L43,	L44,	L45,	L46,	L47, \
		                L48,	L49,	L50,	L51,	     L54,	L55,	L56,	L57, \
                                                L52,         L53	) \
    { \
		L54,	L47,	L46,	L37,	L36,	L26,		 L00,	L10,	L11,	L20,	L21,	L28, \
		L53,	L48,	L45,	L38,	L35,	L27,		 L01,	L09,	L12,	L19,	L22,	L27, \
		L52,	L49,	L44,	L39,	L34,	L28,		 L02,	L08,	L13,	L18,	L23,	L26, \
		L51,	L50,	L43,	L40,	L33,	L30,		 L03,	L07,	L14,	L17,	L24,	L25, \
		                L42,	L41,	L32,	L31,	     L05,	L06,	L15,	L16, \
                                                L29,         L04	\
    }
	//RGB LED logical order map
	#define RGBLIGHT_LED_MAP LED_LAYOUT( \
54, 47, 46, 37, 36,  26,      0, 10, 11, 20, 21, 28, \
53, 48, 45, 38, 35,  27,      1, 9,  12, 19, 22, 27, \
52, 49, 44, 39, 34,  28,      2, 8,  13, 18, 23, 26, \
51, 50, 43, 40, 33,  30,      3, 7,  14, 17, 24, 25, \
        42, 41, 32,  31,      5, 6,  15, 16,         \
                     29,      4 ) */
#endif

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5 // Specify a optional status led by GPIO number which blinks when entering the bootloader
