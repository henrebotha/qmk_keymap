#!/usr/bin/env bash
KEYBOARD=ergodox_ez
KEYMAP=henrebotha
QMK_DIR=qmk_firmware

set -e

# 0. Clean
rm -rf .build

# 1. Copy my files into their appropriate locations inside QMK
mkdir -p $QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP
ln -i -s "$(pwd)"/src/keymaps/$KEYMAP/config.h "$(pwd)"/$QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP/config.h
ln -i -s "$(pwd)"/src/keymaps/$KEYMAP/keymap.c "$(pwd)"/$QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP/keymap.c
ln -i -s "$(pwd)"/src/keymaps/$KEYMAP/rules.mk "$(pwd)"/$QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP/rules.mk
# cp -r src/keymaps/overrides/ $QMK_DIR/keyboards/$KEYBOARD

# 2. Run string replacement to tweak EZ defaults (this is an alternative to
# copying the overrides dir)

# 3. Clean
cd $QMK_DIR
qmk clean --all

# 4. Compile
qmk compile -kb ergodox_ez -km henrebotha

# 5. Clean up
cp -r .build ../.build
git clean -f -d
git checkout -- .
