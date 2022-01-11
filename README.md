# FALTY_LedControllerArtNet_v0

Welcome to the FALTY code page on Github. 

**Introduction**

FALTY is the project name of the ledcontroller I'm developing as part of my IT Studies at Fontys University of Applied Sciences. It is a small led controller, 
able to receive ArtNet and transmit it to WS28xx LED Strips. 

**Hardware**

Below you'll find a list of hardware used within this project:
- Teensy 4.1 microcontroller
- Teensy 4.1 Ethernet break-out board
- WS2815 programmable LED-strips*.

*the software uses the WS2812B protocol from the FASTLED Library, so any WS-series type that is supported by FastLED, should be compatible.

**Library's used within**
- Art-Net library from Natcl
- NativeEthernet library included in Teensyduino
- SPI library included in Teensyduino
- FastLED

**Current state and future additions**

This is the first version (v0) of this software. At this moment it is able to receive a pre-defined Art-net universe, and capture DMX-data from predefined channels. At the moment, everything is configured to receive four DMX channels which control in order: Intensity, color1, color2, color3. 

So what is still to come?
- Better FPS rate. At this moment you can see the LED's change one after another.
- Individual control of each LED in terms of colour selection.
- Intensity control per connected LED strip
- Parameter control/acces trough a web-based userinterface


**Thanks**
Thank you for taking an interest in my project. It is really appreciated. Also: suggestions and comments are more than welcome!
