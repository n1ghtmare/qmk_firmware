# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [VitePress](https://vitepress.dev/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls).

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.

## Installation

To install (on Arch), run:

```zsh
$ sudo pacman -S qmk
```

Then clone this repo (this guide assuesm `~/Dev-Config/`), and run:

```zsh
$ qmk setup -H ~/Dev-Config/qmk_firmware
```

## Flashing the Sofle

In order to flash the sofle, disconnect the keyboard from the computer, then detach the TRRS cable between the halves. Then connect one half first, and run:

```zsh
$ qmk flash -kb sofle/rev1 -km n1ghtmare
```

When asked to reset your controller press the reset button next to the OLED screen (bottom right).

## Flashing the Sofle Choc

In order to flash the sofle choc, disconnect the keyboard from the computer, then detach the TRRS cable between the halves. Then connect the left half first, and double press the button below the OLED screens. This will cause the half to appear as a USB storage device on the system, if you're on Linux do:

```zsh
$ lsblk -f
```
Find the newly attached device (in this example it's `/dev/sdd1`), then mount it to a folder of your choosing:

```
$ sudo mount /dev/sdd1 ~/Mount/soflechoc
```

Go to the qmk folder (in this case it's `~/Dev-Config/qmk_firmware/`), and switch to the `choc2` branch. You might need to run:

```zsh
$ qmk clean --all
```

Now compile the firmware using the following command:

```zsh
$ qmk compile -kb sofle_choc -km n1ghtmare -e CONVERT_TO=promicro_rp2040
```

Once the compile is done, a new file will appear in the qmk folder. Copy that file to the folder the USB flash device was mounted to (in this case `~/Mount/soflechoc/`). Disconnect the half, connect the other one, mount it and copy the same file to it.
