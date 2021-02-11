
#define __SFR_OFFSET 0     // Needed to keep io.h from adding an incorrect offset to our port addresses
#include <avr/io.h>


#define LO(x) ((x) & 0xFF) 
#define HI(x) ((x)>>8) 

#define accum r16

.global main               // Main entry point


//-----------------------

main:
   // ldi      accum, 0xff     
   // sts      DDRC,  accum   

   ldi      accum, 0xff  
   out      DDRC,  accum

   // Put our stack at the top of internal SRAM
   ldi      accum, HI(RAMEND)
   out      SPH,   accum
   ldi      accum, LO(RAMEND)
   out      SPL,   accum

   rjmp    blink_leds


//-----------------------
predelay:
    push r16
    ldi r16, 255
delay:
    dec r16
    brne delay
    pop r16
    ret 

//-----------------------
prelongdelay:
    push r16
    ldi r16, 255
longdelay:
    rcall predelay
    dec r16
    brne longdelay
    pop r16
    ret 

//-----------------------
prelongerdelay:
    push r16
    ldi r16, 2
longerdelay:
    rcall prelongdelay
    dec r16
    brne longerdelay
    pop r16
    ret 


//-----------------------

blink_leds:
    //
    ldi r16, 0x08
    out PORTC,r16
    rcall prelongerdelay
    ldi r16, 0x00
    out PORTC,r16
 
    //
    ldi r16, 0x10
    out PORTC,r16
    rcall prelongerdelay

    ldi r16, 0x00
    out PORTC,r16

    //
    ldi r16, 0x20
    out PORTC,r16
    rcall prelongerdelay

    ldi r16, 0x00
    out PORTC,r16

    rjmp blink_leds





