#include "keymap_common.h"

#define FN_LAYER_ALT KEYMAP(SHIFT(KC_1), KC_UP,       SHIFT(KC_2),    SHIFT(KC_LBRC), SHIFT(KC_RBRC),                 SHIFT(KC_3), KC_7,   KC_8,   KC_9, SHIFT(KC_8), \
                            KC_LEFT,     KC_DOWN,     KC_RIGHT,       KC_LBRC,        KC_RBRC,                        SHIFT(KC_4), KC_4,   KC_5,   KC_6, SHIFT(KC_EQUAL), \
                            SHIFT(KC_6), SHIFT(KC_7), SHIFT(KC_BSLS), SHIFT(KC_9),    SHIFT(KC_0),                    SHIFT(KC_5), KC_1,   KC_2,   KC_3, KC_BSLS, \
                            KC_FN1,      KC_GRAVE,    KC_LGUI,        KC_LSFT,        KC_DEL,         KC_FN4, KC_FN5, KC_SPC,      KC_FN0, KC_DOT, KC_0, KC_EQUAL)

#define LAYER_TWO_ALT KEYMAP(KC_HOME, KC_UP,           KC_END,   KC_NO,   KC_PGUP,                 KC_F13,  KC_F7,  KC_F8, KC_F9, KC_F10, \
                             KC_LEFT, KC_DOWN,         KC_RIGHT, KC_NO,   KC_PGDN,                 KC_F14,  KC_F4,  KC_F5, KC_F6, KC_F11, \
                             KC_MUTE, KC_VOLD,         KC_VOLU,  KC_NO,   KC_NO,                   KC_F15,  KC_F1,  KC_F2, KC_F3, KC_F12, \
                             KC_NO,   SHIFT(KC_GRAVE), KC_LGUI,  KC_LSFT, KC_BSPC, KC_FN4, KC_FN5, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_FN3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P, \
         KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, \
         KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,                    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_FN4, KC_FN5, KC_SPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT), \
  /* 1: punctuation and numbers and arrow keys */
  FN_LAYER_ALT,                                     \
  /* 2: arrows and function keys and volume keys */
  LAYER_TWO_ALT
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC), // CRTL key when held, ESC when tapped
  [5] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT) // ALT key when held, ENTER when tapped
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
