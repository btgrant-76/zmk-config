// Home row mods macro
#define HRML(k1,k2,k3,k4) &hrml LCTRL k1  &hrml LALT k2  &gui_hrml LGUI k3  &hrml LSHFT k4
#define HRMR(k1,k2,k3,k4) &hrmr RSHFT k1  &hrmr RGUI k2  &hrmr LALT k3  &hrmr RCTRL k4
#define HRMR3(k1,k2,k3) &hrmr RSHFT k1  &hrmr RGUI k2  &hrmr LALT k3

#define BACK &kp LG(LBKT)
#define FWD &kp LG(RBKT)
#define MISS_CTL &kp LC(UP)

/* base */
#define Z_HYPR &htl LC(LA(LG(LSHFT))) Z
#define Z_SHIFT &htl LSHFT Z
#define E_HYPR &htl LC(LA(LG(LSHFT))) E
#define SLS_HYPR &htr LC(LA(LG(LSHFT))) FSLH
#define SLS_SHIFT &htr LSHFT FSLH
#define I_HYPR &htr LC(LA(LG(LSHFT))) I
#define B_MEH &htl LC(LA(LSHFT)) B
#define N_MEH &htr LC(LA(LSHFT)) N

/* macros */
#define UNDO_  &kp LG(Z)
#define CUT_   &kp LG(X)
#define COPY_  &kp LG(C)
#define PASTE_ &kp LG(V)
#define REDO_  &kp LS(LG(Z))

#define TAB_LFT &kp LS(LG(LBKT))
#define TAB_RGT &kp LS(LG(RBKT))
