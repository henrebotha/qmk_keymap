// v1.3.1
//
// TODO:
// * Make Tmux layer respect Shift. E.g. `/` shouldn't send `C-?`, it should
//   send `C-/`.

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
  TMUX_0,
  TMUX_1,
  TMUX_2,
  TMUX_3,
  TMUX_4,
  TMUX_5,
  TMUX_6,
  TMUX_7,
  TMUX_8,
  TMUX_9,
  TMUX_A,
  TMUX_C,
  TMUX_D,
  TMUX_H,
  TMUX_J,
  TMUX_K,
  TMUX_L,
  TMUX_S,
  TMUX_W,
  TMUX_Z,
  TMUX_CL,
  TMUX_HL,
  TMUX_ML,
  TMUX_MR,
  TMUX_SH,
  TMUX_SV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // home layer
  [0] = KEYMAP(
      KC_GRAVE,         KC_1,     KC_2,    KC_3,     KC_4,      KC_5,             TG(1),
      KC_TAB,           KC_Q,     KC_W,    KC_E,     KC_R,      KC_T,             LCTL(KC_B),
      CTL_T(KC_ESCAPE), KC_A,     KC_S,    KC_D,     KC_F,      KC_G,
      KC_LGUI,          KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,             KC_MINUS,
      OSL(2),           KC_TRNS,  KC_TRNS, OSL(3),   OSL(2),

      KC_MUTE,          KC_VOLU,
      KC_VOLD,
      KC_LSHIFT,        KC_SPACE, KC_LALT,

      RESET,            KC_6,     KC_7,    KC_8,     KC_9,      KC_0,             KC_BSPACE,
      KC_TRNS,          KC_Y,     KC_U,    KC_I,     KC_O,      KC_P,             KC_BSLASH,
      KC_H,             KC_J,     KC_K,    KC_L,     KC_SCOLON, KC_QUOTE,
      KC_EQUAL,         KC_N,     KC_M,    KC_COMMA, KC_DOT,    KC_SLASH,         KC_RGUI,
      OSL(2),           OSL(3),   KC_TRNS, KC_TRNS,  OSL(2),

      KC_MPRV,          KC_MNXT,
      KC_MPLY,
      KC_RALT,          KC_ENTER, KC_RSHIFT
  ),

  // gaming layer (to be completed)
  [1] = KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // function layer
  [2] = KEYMAP(
      KC_ESCAPE, KC_F1,     KC_F2,       KC_F3,    KC_F4,       KC_F5,   KC_TRNS,
      KC_TRNS,   KC_PGUP,   KC_HOME,     KC_UP,    KC_END,      KC_TRNS, KC_TRNS,
      KC_TRNS,   KC_PGDOWN, KC_LEFT,     KC_DOWN,  KC_RIGHT,    KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_LPRN,  KC_LBRACKET, KC_LCBR, KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,

      KC_TRNS,   KC_TRNS,
      KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,

      KC_TRNS,   KC_F6,     KC_F7,       KC_F8,    KC_F9,       KC_F10,  KC_DELETE,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_F11,      KC_F12,  KC_INSERT,
      KC_LEFT,   KC_DOWN,   KC_UP,       KC_RIGHT, KC_QUOTE,    KC_TRNS,
      KC_TRNS,   KC_RCBR,   KC_RBRACKET, KC_RPRN,  KC_TRNS,     KC_TRNS, KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,

      KC_TRNS,   KC_TRNS,
      KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

  // tmux layer
  [3] = KEYMAP(
      KC_TRNS, TMUX_1,  TMUX_2,  TMUX_3,  TMUX_4,  TMUX_5,     KC_TRNS,
      KC_TRNS, KC_TRNS, TMUX_W,  KC_TRNS, KC_TRNS, KC_TRNS,    TMUX_ML,
      KC_TRNS, TMUX_A,  TMUX_S,  TMUX_D,  KC_TRNS, KC_TRNS,
      KC_TRNS, TMUX_Z,  KC_TRNS, TMUX_C,  KC_TRNS, LCTL(KC_B), TMUX_SH,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, TMUX_6,  TMUX_7,  TMUX_8,  TMUX_9,  TMUX_0,     KC_TRNS,
      TMUX_MR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    TMUX_SV,
               TMUX_H,  TMUX_J,  TMUX_K,  TMUX_L,  TMUX_CL,    KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_HL,    KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,

      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case TMUX_0:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "0");
      }
      break;
    case TMUX_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "1");
      }
      break;
    case TMUX_2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "2");
      }
      break;
    case TMUX_3:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "3");
      }
      break;
    case TMUX_4:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "4");
      }
      break;
    case TMUX_5:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "5");
      }
      break;
    case TMUX_6:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "6");
      }
      break;
    case TMUX_7:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "7");
      }
      break;
    case TMUX_8:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "8");
      }
      break;
    case TMUX_9:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "9");
      }
      break;
    case TMUX_A:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "a");
      }
      break;
    case TMUX_C:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "c");
      }
      break;
    case TMUX_D:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "d");
      }
      break;
    case TMUX_H:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "h");
      }
      break;
    case TMUX_J:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "j");
      }
      break;
    case TMUX_K:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "k");
      }
      break;
    case TMUX_L:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "l");
      }
      break;
    case TMUX_S:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "s");
      }
      break;
    case TMUX_W:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "W");
      }
      break;
    case TMUX_Z:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "z");
      }
      break;
    case TMUX_CL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") ":");
      }
      break;
    case TMUX_HL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "?");
      }
      break;
    case TMUX_ML:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "{");
      }
      break;
    case TMUX_MR:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "}");
      }
      break;
    case TMUX_SH:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "-");
      }
      break;
    case TMUX_SV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b") "|");
      }
      break;
    case CTL_T(KC_ESCAPE):
      if (record->event.pressed) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      }
      break;
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
