#!/usr/bin/env bash

# 1. Copy my files into their appropriate locations inside QMK
mkdir -p qmk_firmware/keyboards/ergodox_ez/keymaps/henrebotha
cp src/keymaps/henrebotha/config.h qmk_firmware/keyboards/ergodox_ez/keymaps/henrebotha/
cp src/keymaps/henrebotha/keymap.c qmk_firmware/keyboards/ergodox_ez/keymaps/henrebotha/
cp src/keymaps/henrebotha/rules.mk qmk_firmware/keyboards/ergodox_ez/keymaps/henrebotha/
cp src/keymaps/overrides/config.h qmk_firmware/keyboards/ergodox_ez/

# 2. Run string replacement to tweak EZ defaults (alternative to copying overrides dir)

# 3. Make clean
cd qmk_firmware
make ergodox_ez:henrebotha:clean

# 4. Make teensy build
make ergodox_ez:henrebotha

# 5. Clean up
cp -r .build ../.build
git clean -f -d
git checkout -- .
