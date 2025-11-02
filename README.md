# ZMK Firmware

## Builds

### Le Chiffre STM32

```shell
west build -p -b le_chiffre_stm32 \
    -d ./build/le-chiffre-stm32 -- \
    -DZMK_CONFIG=/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/le-chiffre-stm32-zmk-config/config/ \
    -DZMK_EXTRA_MODULES="/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-leader-key/;/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/le-chiffre-stm32-zmk-config"
    
west build -p -b le_chiffre_stm32 -- \
    -DZMK_CONFIG=/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/le-chiffre-stm32-zmk-config/config/ \
    -DZMK_EXTRA_MODULES=/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-leader-key
```

### Le Jlwffre

```shell
west build -p -b le_jlwffre \
    -d ./build/le-jlwffre -- \
    -DZMK_CONFIG=/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/jlw-zmk-config/config \
    -DZMK_EXTRA_MODULES="/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-config-jlw/;/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-leader-key/"


west build -p -b "le_jlwffre" -- \
   -DZMK_CONFIG=/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/jlw-zmk-config/config \
   -DZMK_EXTRA_MODULES="/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-config-jlw/;/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-leader-key/"
```


## TODOs

- [ ] align [Caps Word Behavior](https://zmk.dev/docs/keymaps/behaviors/caps-word) to what I'm using in QMK
- [ ] Review macro configurations     
- [ ] reorganize this project around a `zmk-config` folder
- [ ] update the "build scripts" above to use `-d` to specify a unique output location for each 
- [ ] implement any missing leader key sequences/macros
    -  new browser tab, you jerk

### Active

- [ ] move notes/TODOs out of the individual `.keymap` files
```md
/* TODO read up on the different fields/options
- wait-ms
- tap-ms
- what other configuration options are available
*/
// TODO can the presses in macro_press and _release be consolidated in a single item?
  
/*
  TODO
   - [ ] try to set up #defines for bigger keycodes like BACK, FWD, etc.
   - [ ] config encoder https://zmk.dev/docs/features/encoders
   - [ ] implement mod morphs (key overrides) https://zmk.dev/docs/keymaps/behaviors/mod-morph
   - [ ] format everything nicely https://zmk.dev/docs/development/contributing/documentation#formatting-and-linting-your-changes
   - troubleshooting
     - [ ] is there a wait time before a layer hold can effect the hold?
     - [ ] for tap-holds like HRM, I can double-tap-and-hold to get the tap action to repeat, but that doesn't work with layer holds
 */
       
       // TODO make aliases of more of the complex key-presses
    on &mt:  // TODO there's some tuning needed here:  when I do quick layer hold-and-release sequences, it seems like it chooses the tap action over hold


    C L sequence:  /* FIXME this needs to be updated to hold for a short period to overcome the macOS delay that's required.
         does QMK address this autmatically? Or is there something configured in Karabiner that's not being applied to the BLE Chiffre?
     */


    sensor-bindings = <&inc_dec_kp LG(RBKT) LG(LBKT)>; // TODO why can't I use BACK and FWD here? look into this option:  https://zmk.dev/docs/keymaps/behaviors/sensor-rotate#variable-sensor-rotation


        mse { // 5 // TODO mouse emu isn't going to work on STM at all. Remove this and move base references to fun and med instead?

re:  mse layer SCRL_* keys:   // TODO try out other options for scrolling


st.require-prior-idle-ms = <125>; // TODO try removing this or lowering it
```
- [ ] [troubleshoot pair-related macros](./macro-troubleshooting.md) what's happening with the bracket inserts?
    - [ ] sync up the contents of the two keymaps and flash before testing
    - Notes
        - is this an issue with any of the other macros?
        - is it an issue outside the IntelliJ editor?
    - [ ] go through all macros on both boards and see which ones freak out and which ones are fine
      - boards
          - Le Chiffre
              - works
              - fails
          - Le Jlwffre
              - works
              - fails
      - [ ] raise a question about what I'm observing in ZMK help


### Done
