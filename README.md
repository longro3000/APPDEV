# my readme file
Raspberry PI acoustic sensor project

This project will turn a raspberry Pi 3 into a acoustic sensor

1.Configuration

1.1 Hardware Configuration

A raspberry Pi 3 is recommended. If a older version of Pi is used. correspongding configuration might be changed.

the Pi is mounted with a USB sound card, and plugged in a microphone.

It is recommended to have Ethernet connection for your Pi.

1.2 Software Configuration

the USB sound card has to be set as default audio device. to do so, you need to modify two file with following contents.

.......

if you are using Raspbian Jessie, you have to roll back alsa-utils to an early version.

.......


