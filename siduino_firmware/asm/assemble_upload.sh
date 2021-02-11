#!/bin/bash


# 324 WORKS!!
# avr-gcc -Wall -Os -DF_CPU=20000000UL -mmcu=atmega324p -o vga.o vga.S
# avr-objcopy -j .text -j .data -O ihex vga.o vga.hex
# avrdude -V -c usbtiny -p atmega324p -b 19200 -U flash:w:vga.hex

# 164 WORKS!!!
# avr-gcc -Wall -Os -DF_CPU=20000000UL -mmcu=atmega164p -o vga.o vga.S
# avr-objcopy -j .text -j .data -O ihex vga.o vga.hex
# avrdude -V -c usbtiny -p atmega164p -b 19200 -U flash:w:vga.hex



PROG_MMCU=atmega328p
PROGRAMMER=usbtiny
PORT=usb

#defaults for mega128
LOW_FUSE=0xc1
HIGH_FUSE=0x99
EXT_FUSE=0xfd


#ASSEMBLE AND UPLOAD
avr-gcc -Wall -Os -DF_CPU=16000000UL -mmcu=atmega328p  -o sidfirmware.o ./asm/blink.S 2>&1

#avr-gcc -Wall -Os -DF_CPU=16000000UL -mmcu=atmega328p  -o sidfirmware.o ./asm/siduino.S 2>&1
avr-objcopy -j .text -j .data -O ihex sidfirmware.o sidfirmware.hex
avrdude -V -c usbtiny -p atmega328p -b 19200 -U flash:w:sidfirmware.hex
#avrdude -P $(PORT) -v -p $(PROG_MMCU) -c $(PROGRAMMER) -U lfuse:w:$(LOW_FUSE):m -U hfuse:w:$(HIGH_FUSE):m -U efuse:w:$(EXT_FUSE):m


# #CLEAN UP NOW
# rm -f *.o
# rm -f *.hex

