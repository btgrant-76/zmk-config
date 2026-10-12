# Build commands for Docker

## Le Jlwffre

```shell
west build -b le_jlwffre -d ./build/le_jlwffre -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-config-jlw/"
```

## Corne

### corne-right

```shell
west build -b nice_nano_v2 -d ./build/corne_right -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DSHIELD=corne_right \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/"
```

### corne-left

```shell
west build -b nice_nano_v2 -d ./build/corne_left -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config/ \
  -DSHIELD=corne_left \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/"
```

---

## TODO Le Chiffre STM

## TODO AdeptBLE

## Forager

### forager-right

```shell
west build -d ./build/forager_right -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="forager_right rgbled_adapter" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;"\
"/workspaces/zmk-modules/forager-zmk-module/;"\
"/workspaces/zmk-modules/zmk-rgbled-widget/"
```

### forager-left

```shell
west build -d ./build/forager_left -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="forager_left rgbled_adapter" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;"\
"/workspaces/zmk-modules/forager-zmk-module/;"\
"/workspaces/zmk-modules/zmk-rgbled-widget/"
```

## Occultation

### occultation-left

```shell
west build -d ./build/occultation_left -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="occultation_left" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-config-occultation/"
```

### occultation-right

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

### totem-right

```shell
west build -d ./build/totem_right -b seeeduino_xiao_ble -- \
  -DZMK_CONFIG=/workspaces/zmk-config/config \
  -DSHIELD="totem_right" \
  -DZMK_EXTRA_MODULES="/workspaces/zmk-modules/zmk-leader-key/;/workspaces/zmk-modules/zmk-keyboard-totem/"
```
