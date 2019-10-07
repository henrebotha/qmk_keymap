// v1.5.4

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"
#include "version.h"

#include "keymap_german.h"
#include "keymap_nordic.h"

#define PERMISSIVE_HOLD

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  KC_TASK,
};

enum layers {
  LAYER_HOME = 0,
  LAYER_GAMING,
  LAYER_FUNCTION,
  LAYER_TMUX,
  LAYER_GS_GGX2,
  LAYER_GS_SCB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // home layer
  [LAYER_HOME] = LAYOUT_ergodox_pretty(
    KC_GRAVE,         KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   TG(1),    RESET,    KC_6,    KC_7,    KC_8,      KC_9,     KC_0,     KC_BSPACE,
    KC_TAB,           KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   _______,  _______,  KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,     KC_BSLASH,
    CTL_T(KC_ESCAPE), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,     KC_J,     KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,
    KC_LGUI,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_MINUS, KC_EQUAL, KC_N,    KC_M,    KC_COMMA,  KC_DOT,   KC_SLASH, KC_RGUI,
    KC_HYPR,          KC_TASK, KC_LEAD, OSL(3), OSL(2), OSL(2), OSL(3),   KC_LEAD,  _______, KC_HYPR,

    KC_MUTE,   KC_VOLU,  KC_MPRV, KC_MNXT,
    KC_VOLD,   KC_MPLY,
    KC_LSHIFT, KC_SPACE, KC_LALT, KC_RALT, KC_ENTER, KC_RSHIFT
  ),

  // gaming layer (to be completed)
  [LAYER_GAMING] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, TO(0),   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    _______, _______, _______, _______,
    _______, _______,
    _______, _______, _______, _______, _______, _______
  ),

  // function layer
  [LAYER_FUNCTION] = LAYOUT_ergodox_pretty(
    KC_ESCAPE, KC_F1,     KC_F2,   KC_F3,   KC_F4,       KC_F5,   _______, _______, KC_F6,   KC_F7,       KC_F8,    KC_F9,   KC_F10,  KC_DELETE,
    _______,   KC_PGUP,   KC_HOME, KC_UP,   KC_END,      _______, _______, _______, _______, _______,     _______,  KC_F11,  KC_F12,  KC_INSERT,
    _______,   KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RIGHT,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,    KC_QUOTE, _______,
    _______,   _______,   _______, KC_LPRN, KC_LBRACKET, KC_LCBR, _______, _______, KC_RCBR, KC_RBRACKET, KC_RPRN,  _______, _______, _______,
    _______,   _______,   _______, _______, TO(0),       TO(0),   _______, _______, _______, _______,

    _______, _______, _______, _______,
    _______, _______,
    _______, _______, _______, _______, _______, _______
  ),

  // tmux layer — inherits mappings from layer zero, see process_record_user
  [LAYER_TMUX] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, TO(0),   _______, _______, TO(0),   _______, _______, _______,

    _______, _______, _______, _______,
    _______, _______,
    _______, _______, _______, _______, _______, _______
  ),

  // game-specific layer
  [LAYER_GS_GGX2] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_A,    KC_S,    KC_D,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, TO(0),   _______, _______, _______, _______, TO(0),   _______, _______,

    _______, _______, _______, _______,
    _______, _______,
    KC_W,    _______, _______, _______, _______, _______
  ),

  // game-specific layer
  [LAYER_GS_SCB] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_UP,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, KC_Z,    KC_X,    _______, _______, _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, TO(0),   _______, _______,  _______, _______, TO(0),   _______, _______,

    _______, _______, _______, _______,
    _______, _______,
    _______, _______, _______, _______, _______, _______
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
};

LEADER_EXTERNS();

bool kc_task_release_after_500 = false;
uint16_t kc_task_release_time;

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Guilty Gear XX Accent Core Plus R, aka the final GG X2
    SEQ_FOUR_KEYS(KC_G, KC_G, KC_X, KC_2) {
      layer_on(LAYER_GS_GGX2);
    }

    // Super Crate Box
    SEQ_THREE_KEYS(KC_S, KC_C, KC_B) {
      layer_on(LAYER_GS_SCB);
    }
  }

  if (kc_task_release_after_500) {
    // If this operation is slow, it will only affect performance for 500 ms
    // after a KC_TASK press. The rest of the time, the conditional will prevent
    // any performance cost.
    if (timer_elapsed(kc_task_release_time) > 500) {
       unregister_code(KC_LALT);
       kc_task_release_after_500 = false;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // Only prefix on keydown
    if (biton32(layer_state) == LAYER_TMUX) {
      if (keycode >= KC_A && keycode <= KC_UP) {
        tap_code16(C(KC_B));
        return true;
      }
    }
    switch(keycode) {
      case KC_TASK:
        kc_task_release_after_500 = false;
        register_code(KC_LALT);
        tap_code(KC_TAB);
        return false;
    }
  } else {
    switch(keycode) {
      case KC_TASK:
        kc_task_release_after_500 = true;
        kc_task_release_time = timer_read();
        return false;
    }
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
