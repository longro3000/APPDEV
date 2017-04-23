
https://github.com/longro3000/APPDEV

=================================================================================

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

pcm.!default {
  type plug
  slave {
    pcm "hw:1,0"
  }
}
ctl.!default {
    type hw
    card 1
}

you need to put these command above to 2 file which opened by command :

"sudo nano /etc/asound.conf"

and

"nano .asoundrc"

.......

if you are using Raspbian Jessie, you have to roll back alsa-utils to an early version.

to downgrade you need to.

step 1 .Use “sudo nano /etc/apt/sources.list” command and add the last line.

deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
# Uncomment line below then 'apt-get update' to enable 'apt-get source'
#deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi
deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi

step 2.	Run “sudo apt-get update”.

step 3.	Run “sudo aptitude versions alsa-utils” to check if version 1.0.25 of alsa-util is available.

step 4. Run “sudo apt-get install alsa-utils=1.0.25-4” to downgrade.

===============================================================================

2.Installation

libcurl must be installed in your raspberry Pi.to do so you need to.

step 1. Use command “ls /usr/include/curl” to identify that /usr/include/curl/ folder exists or not.

step 2.	If the folder doesn’t exist. Run “sudo apt-get update” to update the application list.

step 3.	Run “sudo apt-get install libcurl3” to install the libcurl3.

step 4.	Run “sudo apt-get install libcurl4-openssl-dev” to install the development API of libcurl4.

=================================================================================

3.File contents

3.1 Programs

comm.c : program used to send data to server for web based display.

main.c : main program of the project.

makefile : control file of the whole project.

screen.c : program to set up screen display like screen color, clear screen ,i.e.

wave.c : program to generate signal waves on the screen.

sound.php : php program to write signal captured into a txt file.

sound.html : html program to display signal captured on web browser.

........

3.2 Library

comm.h : define server.

screen.h : define display settings

wave.h : define debug mode

============================================================================

4.Operating

Use "make" command to start program.

use "./sound.a" command to start capturing ascoustic waves.

press "Ctrl + C" to stop capturing signal.

if you want to create a test tone file , press "1" ,

if not , press "0".

if you want to see the ascoustic waves in web based display . click on "sound.html".

use "make clean" command to reset the sound.a file for reuseing the program.

============================================================================

5.TroubleShooting

use "nano wave.h" to access to "wave.h" library.

remove '//' before "#define DEBUG" to turn on debug mode.
 
===============================================================================================

6.copyright and licensing information

Application Development,2016, BY GC@vamk.fi.

===============================================================================================
