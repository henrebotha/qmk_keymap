#!/usr/bin/env bash
KEYBOARD=crkbd/rev1
KEYMAP=bpruitt-goddard
QMK_DIR=qmk_firmware

set -e

# 0. Clean
rm -rf .build

# 1. Copy my files into their appropriate locations inside QMK
mkdir -p $QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP
cp -r keymaps/$KEYMAP $QMK_DIR/keyboards/$KEYBOARD/keymaps/

# 2. Compile
cd $QMK_DIR
util/docker_build.sh $KEYBOARD:$KEYMAP

# 3. Clean up
mkdir ../.build
cp -r .build/*.hex ../.build
git clean -f -d
git checkout -- .
