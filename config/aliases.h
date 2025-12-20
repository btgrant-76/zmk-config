// Home row mods macro
#define HRML(k1,k2,k3,k4) &hrml LCTRL k1  &hrml LALT k2  &hrml LGUI k3  &hrml LSHFT k4
#define HRMR(k1,k2,k3,k4) &hrmr RSHFT k1  &hrmr RGUI k2  &hrmr LALT k3  &hrmr RCTRL k4

#define BACK &kp LG(LBKT)
#define FWD &kp LG(RBKT)
#define MISS_CTL &kp LC(UP)

/* base */
#define Z_HYPR &ht LC(LA(LG(LSHFT))) Z
#define SLS_HYPR &ht LC(LA(LG(LSHFT))) FSLH
#define B_MEH &ht LC(LA(LSHFT)) B
#define N_MEH &ht LC(LA(LSHFT)) N

/* macros */
#define UNDO_  &kp LG(Z)
#define CUT_   &kp LG(X)
#define COPY_  &kp LG(C)
#define PASTE_ &kp LG(V)
#define REDO_  &kp LS(LG(Z))

#define TAB_LFT &kp LS(LG(LBKT))
#define TAB_RGT &kp LS(LG(RBKT))
