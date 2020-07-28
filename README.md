# Realtek RTL8188SU/RTL8191SU/RTL8192SU driver

## Introduction

This is "a" driver repository for the WIP rtl8192su for any interested developer.

To build the driver you will need to have a recent and compatible kernel source.
Currently, only kernels built from the latest wireless-testing.git are supported.
If you want to know more about wireless-testing.git then visit our
[wireless wiki's Git-Guide](http://wireless.kernel.org/en/developers/Documentation/git-guide).

## Contact

If you have any questions, reports or patches, you should write to <linux-wireless@vger.kernel.org>.

## Building the driver

just use the Makefile:

`make`

and then

`make load`

to load the module.

## PSP Xlink mode

This driver has been patched to support promiscious mode.
This has been removed in newer kernel versions though, so you might need to patch your kernel with these patches:
- https://gist.github.com/codedwrench/fa9304a399c7253eba821de0fceea3e5
