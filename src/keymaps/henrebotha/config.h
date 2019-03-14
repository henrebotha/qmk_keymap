#define LEADER_TIMEOUT 2000
#define ONESHOT_TAP_TOGGLE 3
// Affects behaviour of CTL_T(ESC) down, T down, CTL_T(ESC) up, T up
// i.e. releasing the mod-tap key before releasing the other key.
//
// With I_M_T_I: emits Esc, T
// Without:      emits Ctrl-T
#undef IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#undef DRIVER_ADDR_1
#undef DRIVER_ADDR_2
#undef DRIVER_COUNT
#undef DRIVER_1_LED_TOTAL
#undef DRIVER_2_LED_TOTAL
#undef DRIVER_LED_TOTAL
#undef RGB_MATRIX_SKIP_FRAMES
