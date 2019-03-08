# Henré's Ergodox EZ QMK layout

## Design tenets

### Universality

This keymap strives for maximal compatibility with software across Windows, Linux, and macOS, including GUI programs, CLI tools, and games of all types.

The main point to consider in terms of macOS compatibility is the use of Super as primary shortcut modifier, a key which in other OSes we don't use nearly as often.

Games come in a few different types. We can classify a game as time-sensitive (e.g. a fighting game or FPS, where you want your inputs to be recognised instantaneously) or non-time-sensitive (e.g. MTGA, where you're not concerned with zero-latency inputs). Many QMK features introduce an output delay; for instance, dual-mode keys emit their primary keycode on key _up_, which necessarily means the output is delayed relative to normal keys which emit their keycode on key down.

Furthermore, games come in three flavours with respect to their manner of reading keyboard input:

1. "Button" games, where each key is simply treated as a unique input. Most fighting games and FPSes fall into this category; Overwatch doesn't see a difference between Shift and Space.
2. "Modifier" or "GUI" games, where modifier keys like Shift are recognised as such, and where it is possible to bind a modified keypress to an action. Many MOBAs fall into this category; League of Legends allows you to bind Q to one action and Ctrl-Q to another. Something important to remember here is that some of these games allow you to modify a **mouse click**; so while it might be tempting to use advanced QMK modifier features, bear in mind that many of these do not work with the mouse.
3. "Hybrid" games, where actions can be bound to a modifier alone (e.g. Ctrl to crouch), or to a modified keypress (e.g. Ctrl-Q to self-target ability 1). These games do recognise modifiers as different keys, but are willing to let them be used as non-modifiers if configured as such.

It's useful then to try to design our layout such that we have comfortable access to plentiful "button" keys for games that follow that philosophy, as well as at least some modifiers for "modifier" games (bearing in mind that KB+M games leave only the left hand on the keyboard), and in both cases ensuring that "hybrid" games are also well-supported.

### Rebalance finger load

The thumb is the best finger! It's nimble, strong, and opposable. It's an outrage that the standard keyboard layout has a single key shared between both thumbs. Let's try to place much more load on the thumbs, so that we can lighten the load elsewhere — especially for the pinkies.

## Features

### Thumbs

Holding a key with the thumb while hitting other keys with the other fingers is much more ergonomic than the standard pattern of holding a modifier down with the pinky. To this end, we put Shift — probably the most commonly-used modifier — on a thumb key, removing that responsibility from the pinkies and simultaneously opening up a pinky key for a different purpose. We also have Alt on a thumb key, as it is frequently used on all OSes, often in a typing context, and also affords us another usable modifier for "modifier" and "hybrid" games.

Thumbs are also nimble and strong, so common keys like Space are assigned to thumbs as well.

Thumbs are actually really great for dual-mode keys (primary mode because the thumb is nimble, and secondary mode because the thumb is opposable), but time-sensitive games do not support these, which would mean our best fingers go unused, which is simply unacceptable. In a future revision, we might implement a gaming layer, so that we can have the best of both worlds. Or perhaps use these on the right thumb only! (The right thumb is rarely used for games, even considering games that use both hands on the keyboard.)

### Tmux layer

Tmux is an extremely useful tool for anyone who uses the terminal, but its commands are lengthy: any command must be prefixed by Ctrl-B. This layout features a Tmux layer, where every keypress is prefixed by Ctrl-B, allowing you to input multiple commands in sequence without having to hit the prefix key every time.

The Tmux layer does have some annoying edge case bugs (e.g. not playing well with keys that are themselves on other layers); this is largely due to us using the layer mechanism for what is not really conceptually a layer, and will be fixed in a later revision.

### Vim arrows

We have arrow keys on a layer on ESDF, for familiarity, but we also have them on HJKL.

### Brackets of all flavours

Parentheses, brackets, and braces are all available on a layer, near home row in a symmetrical pattern.

### Game-specific layers

The layout supports layers designed for specific games, typically ones that don't natively allow remapping the keyboard (and whose mappings make assumptions about physical keyboard layout that are not borne out by the Ergodox). These are easily accessed by hitting the leader key followed by an abbreviation of the game's name, thereby precluding the need to remember which game is on which numbered layer.
