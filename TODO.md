# To do

## Bug in task switcher

The very first press of `SW_TASK` (or maybe the first after `SW_T_M`) never does the timeout/release action.

I checked the logic pretty carefully, writing out the variables at each step etc. It seems correct to me. One thing to check is whether the timeout const is maybe the wrong type; does the problem disappear if I just inline 500?

## Add Unicode support

It turns out that [there are ways to change the target OS for Unicode support at runtime](https://docs.qmk.fm/#/feature_unicode), and it's even remembered across power cycles.

## Improve build process

My current system relies on a script that essentially copies my code into the right place in QMK, then runs the QMK build process, and finally exfiltrates the output. It works well, but it's a bit of a kludge, and I would prefer to have something that is a bit smoother.

### Migrate to external userspace

[This is now supported](https://docs.qmk.fm/newbs_external_userspace), though it annoyingly still works pretty much like my kludgy way.

GitHub Actions have first-class support with this feature.

### Copy Kevin's build process

[The way Kevin is doing it](https://github.com/amurani/lily58-keymap/blob/main/README.md#setup) seems a lot more sensible to me tbh. Would allow Vim to find C header files, for example, since everything is actually in the right place. I think I can fork QMK, add my map as a submodule to QMK, and then easily pull QMK whenever I want.

How would this work out?

#### Current system
My repo declares which QMK version it works with. QMK is unpolluted. I can at any time build using the same version of QMK; or I can decide to pull QMK, which itself is a change that will be declared in my repo.

#### Kevin's system
QMK is not aware of my repo. My repo does not know which QMK version is surrounding it. QMK is polluted by the submodule. Updating requires maintaining a long-running fork?

## Implement releases

That way, I can get any firmware version I need even when I'm not on a PC with dev access. Maybe use GitHub Actions?
