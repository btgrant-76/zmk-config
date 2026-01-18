#!/usr/bin/env sh

OPTIONS="chiffre jlwffre corne corne_left corne_right"

#if [ $# -ne 1 ]; then
#  echo "Usage: $0 {chiffre|jlwffre|corne|corne_left|corne_right}"
#  exit 1
#fi

# TODO optional clean flag to add -p
# TODO add the option to flash? really only useful for Le Chiffre STM

CONFIG="/Users/brian.grant/projects/personal/zmk-firmware/zmk-config/config/"
MODULES="/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-leader-key/"

case "$1" in
  chiffre)
    BOARD="le_chiffre_stm32"
    BUILD_DIR=$BOARD
    MODULES="$MODULES;/Users/brian.grant/projects/personal/zmk-firmware/zmk-configs/le-chiffre-stm32-zmk-config"
    echo "Building Le Chiffre STM..."
    ;;
  jlwffre)
    BOARD="le_jlwffre"
    BUILD_DIR=$BOARD
    MODULES="$MODULES;/Users/brian.grant/projects/personal/zmk-firmware/zmk-modules/zmk-config-jlw/"
    echo "Building le jlwffre..."
    ;;
  corne-left)
    BOARD="nice_nano_v2"
    BUILD_DIR="corne_left"
    SHIELD="-DSHIELD=corne_left"
    echo "Building Corne left side..."
    ;;
  corne-right)
    BOARD="nice_nano_v2"
    BUILD_DIR="corne_right"
    SHIELD="-DSHIELD=corne_right"
    echo "Building Corne right side..."
    ;;
  corne)
    ./build.sh corne-left "$2"
    BOARD="nice_nano_v2"
    BUILD_DIR="corne_right"
    SHIELD="-DSHIELD=corne_right"
    echo "Building Corne right side..."
    ;;
  *)
    echo "Error: Invalid option '$1'. Valid options are: $OPTIONS"
    exit 1
    ;;
esac

echo "running 'west build -b $BOARD \
-d ./build/$BUILD_DIR \
"$2" -- \
-DZMK_CONFIG=$CONFIG \
$SHIELD \
-DZMK_EXTRA_MODULES=\"$MODULES\"'"

west build -b $BOARD \
-d ./build/$BUILD_DIR \
"$2" -- \
-DZMK_CONFIG=$CONFIG \
$SHIELD \
-DZMK_EXTRA_MODULES="$MODULES"
