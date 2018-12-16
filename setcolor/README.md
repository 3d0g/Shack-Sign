
# setcolor

Simple python script to send a 24 bit RGB color number (in decimal) to a Shack Sign running the Arduino Shack_Sign4.ino project.

Syntax: python setcolor.py (color) <br>
(color) is a decimal representation of 24 bits, 8 for the intensity of each color, Red, Green, and Blue. So, a full-bright Blue would be 0b000000000000000011111111, or 255 decimal. Green would be 0b000000001111111100000000, or 65280. Finally, Red would be 0b111111110000000000000000 or 16711680.

# Build Notes

This script relies on the Digispark USB driver (if your OS needs one). If you've already set up your Arduino IDE for Digispark programming, you've probably already installed any needed drivers. setcolor will also return an error if it cannot find a Shack Sign plugged in.

If you're on a Mac, there's just under a million ways to install the pyusb and libusb libraries. Just about all of them won't work right with the 'built in' python in OSX because nobody can agree on where libraries should actually be installed. I found Homebrew the most sucessful tool for getting python dependencies right with OSX. YMMV. https://brew.sh/

Remember the USB interface is software, derived from V-USB. It's very limited and can be quirky. The Digistump Wiki and Forums can be immensely helpful in troubleshooting. http://digistump.com/wiki/digispark/tutorials/digiusb

Note the Arduino DigiUSB library must be tweaked - by default it uses half(!) the RAM for a ring buffer, leaving insufficient RAM for the rest of the Shack Sign code and NeoPixel library. Hunt down DigiUSB.h in your Arduino folders and set RING_BUFFER_SIZE to 64. Then Shack_Sign4.ino will run properly. Also note the DigiUSB and NeoPixel libraries are not small! This very simple project consumes 85% of the available code space on the Shack Sign processor. If your project gets more complex, you may have to get creative with space. There's a Digistump provided WS2811 (NeoPixel) library that is quite space efficient but also very low-level and not as friendly to use as the Adafruit library. Finally, note the newer (and recommended) DigiCDC USB library does NOT work with recent OSX versions. El Capitan saw a complete rewrite of USB code wich made it extremely hostile to V-USB and derivatives.  
