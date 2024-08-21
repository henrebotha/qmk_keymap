#define LEADER_TIMEOUT 300
// Restart the leader key timeout on each keypress
#define LEADER_PER_KEY_TIMING
#define ONESHOT_TAP_TOGGLE 3
// Affects behaviour of CTL_T(ESC) down, T down, CTL_T(ESC) up, T up
// i.e. releasing the mod-tap key before releasing the other key.
//
// With H_O_O_K_P: emits Ctrl-T
// Without:        emits Esc, T
#define HOLD_ON_OTHER_KEY_PRESS
// Retro tap seems to have caused my Tmux layer key to emit spurious nonsense
// when held. Otherwise I'd like to have it on, so that e.g. a long press of
// CTL_T(KC_ESCAPE) still emits Esc. Oh well!
#undef RETRO_TAPPING
#define QUICK_TAP_TERM_PER_KEY

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#undef DRIVER_ADDR_1
#undef DRIVER_ADDR_2
#undef DRIVER_COUNT
#undef DRIVER_1_LED_TOTAL
#undef DRIVER_2_LED_TOTAL
#undef DRIVER_LED_TOTAL
#undef RGB_MATRIX_SKIP_FRAMES

#define MIDI_ADVANCED
