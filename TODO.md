# To do

## Fix commits

I forgot to update my version comment a few times.

## Fix Tmux key

Turns out that the Tmux key code doesn't work with mod-tap mods. Specifically, TMUX Shift-\ sends \, instead of Ctrl-B |. If I do Shift-Tmux-\, though, it works. It also works if I hold TMUX down throughout.

## Add Unicode support

It turns out that [there are ways to change the target OS for Unicode support at runtime](https://docs.qmk.fm/#/feature_unicode), and it's even remembered across power cycles.

## Copy Kevin's build process

[The way Kevin is doing it](https://github.com/amurani/lily58-keymap/blob/main/README.md#setup) seems a lot more sensible to me tbh. Would allow Vim to find C header files, for example, since everything is actually in the right place. I think I can fork QMK, add my map as a submodule to QMK, and then easily pull QMK whenever I want.

## Implement releases

That way, I can get any firmware version I need even when I'm not on a PC with dev access. Maybe use GitHub Actions?
