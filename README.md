# Personal QMK Layouts

## Purpose
Currently, QMK [stores all keymaps in the same repository](https://github.com/qmk/qmk_firmware/issues/1120) as the firmware code. This makes it difficult to work with a keymap as the entire QMK source code needs to be stored along with the keymap in order to get the latest updates. This repository tries to make this process slightly easier by keeping the QMK firmware as a git submodule and keeping the custom keymaps at the root of the repository.
The build script then handles the task of moving the keymaps into the correct location in the QMK firmware and building the firmware hex file.  