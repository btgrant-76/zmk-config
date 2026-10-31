# Build commands for Docker

## AdeptBLE

```shell
west build -b seeeduino_xiao_ble -d ./build/AdeptBLE -p auto -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DSHIELD="AdeptBLE" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-config-adeptble;/workspaces/zmk-modules/zmk-pmw3610-driver"
```

## Corne

### right

```shell
west build -b nice_nano_v2 -d ./build/corne_right -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DSHIELD=corne_right \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/"
```

### left

```shell
west build -b nice_nano_v2 -d ./build/corne_left -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DSHIELD=corne_left \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/"
```

## Forager

### right

```shell
west build -d ./build/forager_right -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="forager_right rgbled_adapter" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;"\
"/workspaces/zmk-modules/forager-zmk-module/;"\
"/workspaces/zmk-modules/zmk-rgbled-widget/"
```

### left

```shell
west build -d ./build/forager_left -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="forager_left rgbled_adapter" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;"\
"/workspaces/zmk-modules/forager-zmk-module/;"\
"/workspaces/zmk-modules/zmk-rgbled-widget/"
```

## Le Chiffre STM

```shell
west build -b le_chiffre_stm32 -d ./build/le_chiffre_stm32 -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/le-chiffre-stm32-zmk-config"
```

## Le Jlwffre

```shell
west build -b le_jlwffre -d ./build/le_jlwffre -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-config-jlw/"
```

## Occultation

### left

```shell
west build -d ./build/occultation_left -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="occultation_left" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-config-occultation/"
```

### right

```shell
west build -d ./build/occultation_right -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="occultation_right" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-config-occultation/"
```

## TOTEM

### totem-left

```shell
west build -d ./build/totem_left -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="totem_left" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-keyboard-totem/"
```

### right

```shell
west build -d ./build/totem_right -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="totem_right" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-keyboard-totem/"
```

## TODOs

- [ ] add a rename step after the build commits so every output isn't named `zmk.uf2` or `zmk.bin` but instead is
      named after the keyboard and side. This will make it easier to flash the correct firmware to the correct board.
