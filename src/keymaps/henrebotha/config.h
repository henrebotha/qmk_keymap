#define LEADER_TIMEOUT 2000
#define ONESHOT_TAP_TOGGLE 3
// Affects behaviour of CTL_T(ESC) down, T down, CTL_T(ESC) up, T up
// i.e. releasing the mod-tap key before releasing the other key.
//
// With I_M_T_I: emits Esc, T
// Without:      emits Ctrl-T
#undef IGNORE_MOD_TAP_INTERRUPT
