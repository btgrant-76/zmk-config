#define BASE_1_LEFT        &kp Q         &kp W        &kp E      &kp R      &kp T
#define BASE_1_RIGHT       &kp Y         &kp U        &kp I      &kp O      &kp P
#define BASE_2_LEFT        HRML(A,       S,           D,         F)         &kp G
#define BASE_2_RIGHT       &kp H         HRMR3(J,     K,         L)         &qot_smi
#define BASE_3_LEFT        &z_esc        &kp X        &kp C      &kp V      B_MEH
#define BASE_3_RIGHT       N_MEH         &kp M        &cma_lprn  &dot_rprn  &sls_ent

#define BASE_2_THUMB_LEFT  &lt 5 TAB     &lt 2 BSPC
#define BASE_2_THUMB_RIGHT &lt 3 SPACE   &lt 5 DEL

#define BASE_3_THUMB_LEFT  &lt 4 TAB     &lt 2 BSPC   &lt 5 ESC
#define BASE_3_THUMB_RIGHT &lt 5 RETURN  &lt 3 SPACE  &lt 1 DEL

#define MED_1_LEFT         &none      &none        &none        &none      &none
#define MED_1_RIGHT        &none      &none        &none        &none      &none
#define MED_2_LEFT         &kp C_PREV &kp C_VOL_DN &kp C_VOL_UP &kp C_NEXT &none
#define MED_2_RIGHT        &none      &none        &none        &none      &none
#define MED_3_LEFT         &none      &none        &none        &none      &none
#define MED_3_RIGHT        &none      &none        &none        &none      &none

#define MED_2_THUMB_LEFT   &kp C_MUTE &kp C_PP
#define MED_2_THUMB_RIGHT  &none      &none

#define MED_3_THUMB_LEFT   &kp C_MUTE &kp C_PP     &none
#define MED_3_THUMB_RIGHT  &none      &none        &none


#define NUM_1_LEFT         UNDO_         CUT_      COPY_       PASTE_       REDO_
#define NUM_1_RIGHT        &lbkt_par     &kp N7    &kp N8      &kp N9       &rbkt_par
#define NUM_2_LEFT         &kp LCTRL     &kp LALT  &kp LGUI    &kp LSHFT    &caps_word
#define NUM_2_RIGHT        &kp EQUAL     &kp N4    &kp N5      &kp N6       &semi_quot
#define NUM_3_LEFT         &kp ESC       &none     &leader     &key_repeat  &none
#define NUM_3_RIGHT        &bslsh_enter  &kp N1    &two_comma  &three_dot   &grv_slsh

#define NUM_2_THUMB_LEFT   &kp BSPC      &trans
#define NUM_2_THUMB_RIGHT  &mins_space   &zero_space

#define NUM_3_THUMB_LEFT   &kp DEL       &none        &kp BSPC
#define NUM_3_THUMB_RIGHT  &mins_space   &zero_space  &kp DOT


#define NAV_1_LEFT         TAB_LFT    BACK       FWD        TAB_RGT      &up_dir
#define NAV_1_RIGHT        REDO_      PASTE_     COPY_      CUT_         UNDO_
#define NAV_2_LEFT         &kp LCTRL  &kp LALT   &kp LGUI   &kp LSHFT    &kp CAPS
#define NAV_2_RIGHT        &kp LEFT   &kp DOWN   &kp UP     &kp RIGHT    &kp SEMI
#define NAV_3_LEFT         &none      &none      &none      &key_repeat  &none
#define NAV_3_RIGHT        &kp HOME   &kp PG_DN  &kp PG_UP  &kp END      &kp RETURN

#define NAV_2_THUMB_LEFT   &none      &kp N
#define NAV_2_THUMB_RIGHT  &none      &none

#define NAV_3_THUMB_LEFT   &none      &kp BSPC   &kp ENTER
#define NAV_3_THUMB_RIGHT  &none      &none      &none


#define FUN_1_LEFT         &log_out  &none     &scrn2clp  &scrn2fl   &none
#define FUN_1_RIGHT        &none     &kp F7    &kp F8     &kp F9     &kp F12
#define FUN_2_LEFT         &kp LCTL  &kp LALT  &kp LGUI   &kp LSHFT  &kp C_BRI_UP
#define FUN_2_RIGHT        &none     &kp F4    &kp F5     &kp F6     &kp F11
#define FUN_3_LEFT         &none     &none     &none      &none      &kp C_BRI_DN
#define FUN_3_RIGHT        &none     &kp F1    &kp F2     &kp F3     &kp F10

#define FUN_2_THUMB_LEFT   &none     &mo 5
#define FUN_2_THUMB_RIGHT  &mo 6     &none

#define FUN_3_THUMB_LEFT   &none     &mo 5     &none
#define FUN_3_THUMB_RIGHT  &none     &mo 6     &none


#define MSE_1_LEFT         UNDO_           CUT_            COPY_         PASTE_           REDO_
#define MSE_1_RIGHT        &none           &none           &none         &none            &none
#define MSE_2_LEFT         &mkp MB5        &mkp MB3        &mkp MB1      &mkp MB2         &none
#define MSE_2_RIGHT        &mmv MOVE_LEFT  &mmv MOVE_DOWN  &mmv MOVE_UP  &mmv MOVE_RIGHT  &none
#define MSE_3_LEFT         &kp ESC         &kp LCTRL       &kp LALT      &kp LGUI         &kp LSHFT
#define MSE_3_RIGHT        &msc SCRL_LEFT  &msc SCRL_DOWN  &msc SCRL_UP  &msc SCRL_RIGHT  &none

#define MSE_2_THUMB_LEFT   &none           &none
#define MSE_2_THUMB_RIGHT  &none           &none

#define MSE_3_THUMB_LEFT   &kp ESC         &none           &none
#define MSE_3_THUMB_RIGHT  &none           &none           &none


#define ADD_1_LEFT         &bt BT_CLR  &bt BT_SEL 0  &bt BT_SEL 1  &bt BT_SEL 2  &none
#define ADD_1_RIGHT        REDO_       PASTE_        COPY_         CUT_          UNDO_
#define ADD_2_LEFT         &none       &none         &none         &none         &none
#define ADD_2_RIGHT        &none       &none         &none         &none         &none
#define ADD_3_LEFT         &none       &none         &none         &none         &bootloader
#define ADD_3_RIGHT        &none       &none         &none         &none         &none

#define ADD_2_THUMB_LEFT   &trans      &trans
#define ADD_2_THUMB_RIGHT  &trans      &trans

#define ADD_3_THUMB_LEFT   &none       &none         &none
#define ADD_3_THUMB_RIGHT  &none       &none         &none
