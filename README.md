# ZMK Firmware

## Builds

### Le Chiffre STM32

```shell
west build -p -b le_chiffre_stm32 \
    -d ./build/le-chiffre-stm32 -- \
    -DZMK_CONFIG=/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/le-chiffre-stm32-zmk-config/config/ \
    -DZMK_EXTRA_MODULES="/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-leader-key/;/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/le-chiffre-stm32-zmk-config"
    

west flash -d ./build/le-chiffre-stm32
```

### Le Jlwffre

```shell
west build -p -b le_jlwffre \
    -d ./build/le-jlwffre -- \
    -DZMK_CONFIG=/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/jlw-zmk-config/config \
    -DZMK_EXTRA_MODULES="/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-config-jlw/;/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-leader-key/"
```

## TODOs

- [ ] format everything nicely https://zmk.dev/docs/development/contributing/documentation#formatting-and-linting-your-changes
- [ ] why can't I use BACK and FWD here? `sensor-bindings = <&inc_dec_kp LG(RBKT) LG(LBKT)>;`
  - read the ZMK encoder docs
  - look into this option:  https://zmk.dev/docs/keymaps/behaviors/sensor-rotate#variable-sensor-rotation
- [ ] mouse emu isn't going to work on STM at all. Remove this and move base references to fun and med instead?
- [ ] re:  mse layer SCRL_* keys: try out other options for scrolling
- [ ] can values like `quick-tap-ms = <220>;` be consolidated somewhere? 
    - can it be `#define QUICK_TAP_MS 220` and then `quick-tap-ms = <QUICK_TAP_MS>;`?
- [ ] use this approach to rename layers:  [Layer Behaviors](https://zmk.dev/docs/keymaps/behaviors/layers#defines-to-refer-to-layers)
- [ ] I shouldn't have to [change the `status` fields in `le_chiffre_stm32.dts` in order to enable the encoder](https://github.com/petejohanson/le-chiffre-stm32-zmk-config/commit/ef42fbbdff2ecf1a71faac5307f86ff84200190d). What't the correct way to do this from the keymap/config side?
  - I could try to *disable* the encoder from within the `.keymap` file to see if that works. That might help me to identify if I'm putting the override in the right place.

### Active

- [ ] [troubleshoot pair-related macros](./macro-troubleshooting.md) 


### Done
 - [x] is there a wait time before a layer hold can effect the hold?
   - there's some tuning needed here:  when I do quick layer hold-and-release sequences, it seems like it chooses the tap action over hold
   - `tapping-term-ms = <145>`;
 - [x] for tap-holds like HRM, I can double-tap-and-hold to get the tap action to repeat, but that doesn't work with layer holds
     - `quick-tap-ms = <220>;`
- [x] move notes/TODOs out of the individual `.keymap` files
- [x] reorganize this project around a `zmk-config` folder
- [x] align [Caps Word Behavior](https://zmk.dev/docs/keymaps/behaviors/caps-word) to what I'm using in QMK
    - unfortunately, there are basically no configuration options here, so it looks like I'm stuck with what's available
- [x] fix the caplock leader macro
    - this needs to be updated to hold for a short period to overcome the macOS delay that's required. does QMK address this automatically? Or is there something configured in Karabiner that's not being applied to the BLE Chiffre?
- [x] update the "build scripts" above to use `-d` to specify a unique output location for each
- [x] implement any missing leader key sequences/macros
    -  new browser tab, you jerk
- [x] on `st`/`shift_tap`, try removing or reducing `require-prior-idle-ms = <125>;` this or lowering it
- [x] config encoder https://zmk.dev/docs/features/encoders
- [x] implement mod morphs (key overrides) https://zmk.dev/docs/keymaps/behaviors/mod-morph
- [x] can the presses in macro_press and _release be consolidated in a single item?
- [x] try to set up `#define`s for bigger keycodes like BACK, FWD, etc.
- [x] Review [macro configuration options](https://zmk.dev/docs/keymaps/behaviors/macros#macro-controls)
    - `wait-ms`:  time between execution of bindings; default is `15`
    - `tap-ms`:  the amount of time bindings will be "held"; default is `30`
    - [x] for most macros, I can probably eliminate both `wait-ms` and `tap-ms` entirely
    - [x] for QMK macros where I have introduced a pause, try [using `macro_wait_time`](https://zmk.dev/docs/keymaps/behaviors/macros#wait-time) 
- [x] make aliases of more of the complex key-presses
- [x] why doesn't the encoder rotation work on the STM PCB? Try moving `encoder` and `sensors` to where `chosen` is.
    - [x] I think I found one of the above options in Sporkus's ZMK config repo. I could check there again to see if the state of any of his files are different from mine.
    - [ ] ~~if I don't find anything useful in Sporkus's repo, ask on the ZMK Discord~~

I tried this:
```
{
    chosen {
        zmk,matrix_transform = &transform_with_encoder;
    };
    
    encoder {
        status = "okay";
    };

    sensors {
        status = "okay";
    };
};
```

... this ...
```
/ {
    chosen {
        zmk,matrix_transform = &transform_with_encoder;
    };
};

&encoder {
    status = "okay";
};

&sensors {
    status = "okay";
};
```
... and I tried enabling both in the `le_chiffre_stm32.dts` file.

```
encoder: encoder {
    compatible = "alps,ec11";
    label = "ENCODER";
    a-gpios = <&gpiob 4 (GPIO_ACTIVE_HIGH | GPIO_PULL_UP)>;
    b-gpios = <&gpiob 5 (GPIO_ACTIVE_HIGH | GPIO_PULL_UP)>;
steps = <30>;
    /* status = "disabled"; */
    status = "okay";
};

sensors: sensors {
    compatible = "zmk,keymap-sensors";
    /* status = "disabled"; */
    status = "okay";
    sensors = <&encoder>;

triggers-per-rotation = <15>;
};
```
