## About

This project allow you to hook up a Fanatec Shifter and Handbrake to your PC using USB.

Out of the box they will only work if you connect them to a Fanatec wheel or pedal base. This mod allows you to
connect and use them with any wheel and pedals that you like. 

## Usage

1. Flash the teensy with the [latest firmware](TODO LINK).
2. Print the [3d case](TODO LINK)
3. Assemble the case using the schematic below

[TODO schematic]



## BOM

* 1x Teensy LC
* 2x RJ22 female connector
* 1x USB-A -> Mini USB cable
* 1x Enclosure
* Some wires



## Donation

If this project helps you to save some cost and want to help further development of this and other projects, you can give me a cup of coffee :) 

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://paypal.me/MarijnKoesen)


## Compile errors

If you get compile errors, edit `teensy/avr/cores/teensy3/usb_desc.h` in the seensy library, on OSX it can be
located in `/Applications/Arduino.app/Contents/Java/hardware/teensy/avr/cores/teensy3/usb_desc.h` or similar.

Change the line below `#elif defined(USB_HID)` and change:

```
#define MANUFACTURER_NAME {'T','e','e','n','s','y','d','u','i','n','o'}
#define MANUFACTURER_NAME_LEN 11
#define PRODUCT_NAME      {'K','e','y','b','o','a','r','d','/','M','o','u','s','e','/','J','o','y','s','t','i','c','k'}
#define PRODUCT_NAME_LEN  23
```

to:

```
#define MANUFACTURER_NAME  {'F', 'a', 'n', 'a', 't', 'e', 'c'}
#define MANUFACTURER_NAME_LEN 7
#define PRODUCT_NAME    {'S', 'h', 'i', 'f', 't', 'e', 'r', ' ', '&', ' ', 'H', 'a', 'n', 'd',  'b', 'r', 'a', 'k', 'e'}
#define PRODUCT_NAME_LEN  19
```

## Resources

* https://www.fanatec.com/eu-en/pedals-accessories/pedal-shifter-cable-2-0m-ps-2-rj11-eu.html
* https://www.pjrc.com/teensy/td_joystick.html
* http://www.hamaluik.com/posts/making-a-custom-teensy3-hid-joystick/
* http://www.pbase.com/cdyckes/image/121768077
