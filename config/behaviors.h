#define QUICK_TT 220

// settings ported from QMK
#define QMK_TT 145
#define QMK_SFT_TT 105

// ported from urob's ZMK config
#define TT_UROB 280
#define QTT_UROB 175
#define REQ_P_IDLE_UROB 150

/ {
    behaviors {
        /* TAP HOLDS BEGIN */
       // in use
        lt: layer_tap { // this overrides the built-in layer-tap configuration https://zmk.dev/docs/keymaps/behaviors/hold-tap#custom-hold-tap-examples
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <TT_UROB>;
            quick-tap-ms = <QTT_UROB>;
            bindings = <&mo>, <&kp>;
        };

        // used by MEH and HYPR tap-holds
        // TODO would ht and st work better with hold-trigger-key-positions?
        ht: hold_tap {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <TT_UROB>;
//            flavor = "tap-preferred"; // FIXME if I go back to this for HRM, I changed this from balanced
//            tapping-term-ms = <QMK_TT>;
            quick-tap-ms = <QUICK_TT>;
//            require-prior-idle-ms = <125>;
            bindings = <&kp>, <&kp>;
        };
        /* not in use
        st: shift_tap {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <QMK_SFT_TT>;
            quick-tap-ms = <QUICK_TT>;
            bindings = <&kp>, <&kp>;
        };
        */

        hrml: home_row_mods_left_hand { // based on urob's settings
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <TT_UROB>;
//            tapping-term-ms = <QMK_TT>;
            quick-tap-ms = <QTT_UROB>;
//            require-prior-idle-ms = <REQ_P_IDLE_UROB >;
            bindings = <&kp>, <&kp>;
            hold-trigger-key-positions = <KEYS_R THUMBS>;
            hold-trigger-on-release; // recommended for use with HRM https://zmk.dev/docs/keymaps/behaviors/hold-tap#positional-hold-tap-and-hold-trigger-key-positions
        };
        hrmr: home_row_mods_right_hand { // based on urob's settings
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <TT_UROB>;
//            tapping-term-ms = <QMK_TT>;
            quick-tap-ms = <QTT_UROB>;
//            require-prior-idle-ms = <REQ_P_IDLE_UROB >;
            bindings = <&kp>, <&kp>;
            hold-trigger-key-positions = <KEYS_L THUMBS>;
            hold-trigger-on-release; // recommended for use with HRM https://zmk.dev/docs/keymaps/behaviors/hold-tap#positional-hold-tap-and-hold-trigger-key-positions
        };

        /* replaced by urob's settings above
        sftl: home_row_mod_shift_left_hand {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <TT_UROB>;
//            tapping-term-ms = <QMK_SFT_TT>;
            quick-tap-ms = <QTT_UROB>;
//            require-prior-idle-ms = <REQ_P_IDLE_UROB >;
            bindings = <&kp>, <&kp>;
            hold-trigger-key-positions = <KEYS_R THUMBS>;
            hold-trigger-on-release;
        };
        sftr: home_row_mod_shift_right_hand {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
//            flavor = "tap-preferred";
            flavor = "tap-preferred";
            tapping-term-ms = <TT_UROB>;
//            tapping-term-ms = <QMK_SFT_TT>;
            quick-tap-ms = <QTT_UROB>;
//            require-prior-idle-ms = <REQ_P_IDLE_UROB >;
            bindings = <&kp>, <&kp>;
            hold-trigger-key-positions = <KEYS_L THUMBS>;
            hold-trigger-on-release;
        };
        */
        /* TAP HOLDS END */


        /* MOD-MORPHS BEGIN */
        z_esc: z_to_esc {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <Z_HYPR>, <&kp ESC>;
            mods = <(MOD_RCTL)>;
        };
        sls_ent: slash_to_enter {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <SLS_HYPR>, <&kp RETURN>;
            mods = <(MOD_LCTL)>;
        };
        cma_lbkt: comma_to_left_bracket { // this does not work :(
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp LPAR>, <&kp RPAR>;
            mods = <(MOD_LALT|MOD_RALT)>;
        };
        cma_lprn: comma_left_paren {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&cma_lbkt>;
            mods = <(MOD_LCTL|MOD_RCTL)>;
        };
        lbkt_par: left_bracket_to_paren {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp LBKT>, <&kp LPAR>;
            mods = <(MOD_LCTL|MOD_RCTL)>;
        };
        rbkt_par: right_bracket_to_paren {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp RBKT>, <&kp RPAR>;
            mods = <(MOD_LCTL|MOD_RCTL)>;
        };
        dot_rprn: dot_right_paren {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp RPAR>;
            mods = <(MOD_LCTL)>;
        };

        /** NUMPAD MORPHS BEGIN **/
        grv_slsh: grave_to_slash {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp GRAVE>, <&kp FSLH>;
            mods = <(MOD_LCTL)>;
        };
        mins_space: minus_to_space {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp MINUS>, <&kp SPACE>;
            mods = <(MOD_LCTL)>;
        };
        semi_quot: semicolon_to_quote {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp SEMI>, <&kp SQT>;
            mods = <(MOD_LCTL)>;
        };
        three_dot: three_to_dot {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp N3>, <&kp DOT>;
            mods = <(MOD_LCTL)>;
        };
        two_comma: two_to_comma {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp N2>, <&kp COMMA>;
            mods = <(MOD_LCTL)>;
        };
        zero_space: zero_to_space {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp N0>, <&kp SPACE>;
            mods = <(MOD_LCTL)>;
        };
        bslsh_enter: bslsh_to_enter {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp BSLH>, <&kp RETURN>;
            mods = <(MOD_LCTL)>;
        };
        /** NUMPAD MORPHS END **/
        /* MOD-MORPHS END */

        leader: leader {
            compatible = "zmk,behavior-leader-key";
            #binding-cells = <0>;

            // vim
            vim_write_ls       { sequence = <V W>; bindings = <&vim_w>; };
            vim_write_quit_ls  { sequence = <V Q>; bindings = <&vim_wq>; };

            // parens
            parens_ls               { sequence = <P A>; bindings = <&pair LPAR RPAR>; };
            parens_ins_ls           { sequence = <P I>; bindings = <&pair_insert LPAR RPAR>; };
            /* ZMK 0.4 memory savings */
            parens_semi_ls          { sequence = <P S A>; bindings = <&pair_w_semi LPAR RPAR>; };
            parens_semi_ins_ls      { sequence = <P S I>; bindings = <&pair_insert_w_semi LPAR RPAR>; };
            /**/

            // brackets
            bracket_ls              { sequence = <B A>; bindings = <&pair LBKT RBKT>; };
            bracket_ins_ls          { sequence = <B I>; bindings = <&pair_insert LBKT RBKT>; };
            /* ZMK 0.4 memory savings */
            bracket_semi_ls         { sequence = <B S A>; bindings = <&pair_w_semi LBKT RBKT>; };
            bracket_semi_ins_ls     { sequence = <B S I>; bindings = <&pair_insert_w_semi LBKT RBKT>; };
            /**/

            // curly braces
            curly_brace_ls          { sequence = <C A>; bindings = <&pair LBRC RBRC>; };
            curly_brace_ins_ls      { sequence = <C I>; bindings = <&pair_insert LBRC RBRC>; };
            /* ZMK 0.4 memory savings */
            curly_brace_semi_ls     { sequence = <C S A>; bindings = <&pair_w_semi LBRC RBRC>; };
            curly_brace_semi_ins_ls { sequence = <C S I>; bindings = <&pair_insert_w_semi LBRC RBRC>; };
            /**/

            // back-tick/grave
            grave_ins_ls            { sequence = <G I>; bindings = <&pair_insert GRAVE GRAVE>; };
            code_fence_ls           { sequence = <C F>; bindings = <&code_fence>; };

            // quotes
            quote_ins_ls            { sequence = <Q I>;   bindings = <&pair_insert SQT SQT>; };
            dquote_ins_ls           { sequence = <D Q I>; bindings = <&pair_insert DQT DQT>; };

            // HTML tags
            /* ZMK 0.4 memory savings */
            tag_open_in_ls          { sequence = <T O>; bindings = <&tag_open_insert>; };
            tag_close_in_ls         { sequence = <T C>; bindings = <&tag_close_insert>; };
            tag_void_in_ls          { sequence = <T V>; bindings = <&tag_void_insert>; };
            /**/

            // others
            /* ZMK 0.4 memory savings */
            updir_ls                { sequence = <U D>; bindings = <&up_dir>; };
            /**/
            js_log_ls               { sequence = <L O G>; bindings = <&js_log>; };
            js_af_ls                { sequence = <A F>; bindings = <&js_arr_fun>; };
            caps_lock_ls            { sequence = <C L>; bindings = <&macos_caps>; };
            new_browser_window_ls   { sequence = <N>; bindings = <&new_browser_window>; };
        };

        combos {
            compatible = "zmk,combos";
            combo_fun_layer {
                timeout-ms = <50>;
                key-positions = <30 31>;
                bindings = <&mo 4>;
                layers = <0>;
            };
            combo_sym_layer {
                timeout-ms = <50>;
                // key-positions = <33 34>; // jlwffre
                key-positions = <32 33>; // STM Chiffre
                bindings = <&mo 1>;
                layers = <0>;
            };
        };
    };


    macros {
        up_dir: up_dir {
            #binding-cells = <0>;
            compatible = "zmk,behavior-macro";
            bindings = <&kp DOT &kp DOT &kp FSLH>;
        };
        code_fence: code_fence {
            #binding-cells = <0>;
            compatible = "zmk,behavior-macro";
            bindings = <&kp GRAVE &kp GRAVE &kp GRAVE &kp RETURN &kp RETURN &kp GRAVE &kp GRAVE &kp GRAVE &kp UP &kp UP>; // TODO UP UP or UP LEFT?
        };
        vim_w: vim_write {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&kp ESC &kp COLON &kp W &kp ENTER>;
        };
        vim_wq: vim_write_and_quit {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&kp ESC &kp COLON &kp W &kp Q &kp ENTER>;
        };
        log_out: log_out {
            #binding-cells = <0>;
            compatible = "zmk,behavior-macro";
            wait-ms = <40>;
            tap-ms = <40>;
            bindings =
                <&macro_press   &kp LCTRL &kp LGUI>,
                <&macro_tap     &kp Q>,
                <&macro_release &kp LCTRL &kp LGUI>;
        };
        scrn2clp: scrn2clp {
            #binding-cells = <0>;
            compatible = "zmk,behavior-macro";
            bindings =
                <&macro_press   &kp LGUI &kp LCTRL &kp LSHFT>,
                <&macro_tap     &kp N4>,
                <&macro_release &kp LGUI &kp LCTRL &kp LSHFT>;
        };
        scrn2fl: scrn2fl {
            #binding-cells = <0>;
            compatible = "zmk,behavior-macro";
            bindings =
                <&macro_press   &kp LGUI &kp LSHFT>,
                <&macro_tap     &kp N4>,
                <&macro_release &kp LGUI &kp LSHFT>;
        };
        pair: pair {
            compatible = "zmk,behavior-macro-two-param";
            #binding-cells = <2>;
            bindings = <&macro_param_1to1>,
                       <&kp MACRO_PLACEHOLDER>,
                       <&macro_param_2to1>,
                       <&kp MACRO_PLACEHOLDER>;
        };
        pair_insert: pair_insert {
            compatible = "zmk,behavior-macro-two-param";
            #binding-cells = <2>;
            bindings = <&macro_param_1to1>,
                       <&kp MACRO_PLACEHOLDER>,
                       <&macro_param_2to1>,
                       <&kp MACRO_PLACEHOLDER>,
                       <&kp LEFT>;
        };
        /* ZMK 0.4 memory savings */
        pair_w_semi: pair_w_semi {
            compatible = "zmk,behavior-macro-two-param";
            #binding-cells = <2>;
            bindings = <&macro_param_1to1>,
                       <&kp MACRO_PLACEHOLDER>,
                       <&macro_param_2to1>,
                       <&kp MACRO_PLACEHOLDER>,
                       <&kp SEMI>;
        };
        pair_insert_w_semi: pair_insert_w_semi {
            compatible = "zmk,behavior-macro-two-param";
            #binding-cells = <2>;
            bindings = <&macro_param_1to1>,
                       <&kp MACRO_PLACEHOLDER>,
                       <&macro_param_2to1>,
                       <&kp MACRO_PLACEHOLDER>,
                       <&kp SEMI>,
                       <&kp LEFT>,
                       <&kp LEFT>;
        };
        /**/
        js_log: javascript_console_log {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = < &kp C &kp O &kp N &kp S &kp O &kp L &kp E &kp DOT
                         &kp L &kp O &kp G &kp LPAR &kp SQT &kp SQT &kp RPAR &kp SEMI
                         &kp LEFT &kp LEFT &kp LEFT>;
        };
        js_arr_fun: javascript_arrow_function {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&kp EQUAL &kp GT &kp SPC &kp LBRC  &kp RBRC
                        &kp LEFT>;
        };
        /* ZMK 0.4 memory savings */
        tag_open_insert:  html_tag_open_insert {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&kp LT &kp GT &kp LEFT>;
        };
        tag_close_insert: html_tag_close_insert {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&kp LT &kp FSLH &kp GT &kp LEFT>;
        };
        tag_void_insert: html_tag_void_insert {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&kp LT &kp SPACE &kp FSLH &kp GT &kp LEFT &kp LEFT &kp LEFT>;
        };
        /**/
        new_browser_window: new_browser_window {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            wait-ms = <400>;
            bindings = <&kp LG(N)>,
                       <&macro_wait_time 40>,
                       <&kp LG(T) &kp LG(LBRC) &kp LG(W)>;
        };
        macos_caps: macos_caps_lock {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            tap-ms = <200>; // macOS requires that capslock be held briefly in order to activate
            bindings = <&kp CAPS>;
        };
    };
};
