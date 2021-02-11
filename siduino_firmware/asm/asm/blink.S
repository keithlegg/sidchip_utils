
#define __SFR_OFFSET 0     // Needed to keep io.h from adding an incorrect offset to our port addresses

#include <avr/io.h>



#define LO(x) ((x) & 0xFF) 
#define HI(x) ((x)>>8) 

#define accum r16

#define temp r17
#define overflows r18

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

   rjmp    blink


 

reset: 
   ldi temp,  0x05
   out TCCR0B, temp      ; set the Clock Selector Bits CS00, CS01, CS02 to 101
                         ; this puts Timer Counter0, TCNT0 in to FCPU/1024 mode
                         ; so it ticks at the CPU freq/1024
   ldi temp, 0b00000001
   sts TIMSK0, temp      ; set the Timer Overflow Interrupt Enable (TOIE0) bit 
                         ; of the Timer Interrupt Mask Register (TIMSK0)

   sei                   ; enable global interrupts -- equivalent to "sbi SREG, I"

   clr temp
   out TCNT0, temp       ; initialize the Timer/Counter to 0

   sbi DDRC, 4           ; set   to output

//------------------------------------------------


blink:
   sbi PORTC, 4          ; turn on LED on  
   rcall delay           ; delay will be 1/2 second
   cbi PORTC, 4          ; turn off LED on  
   rcall delay           ; delay will be 1/2 second
   rjmp blink            ; loop back to the start
  
delay:
   clr overflows         ; set overflows to 0 
   sec_count:
     cpi overflows,30    ; compare number of overflows and 30
   brne sec_count        ; branch to back to sec_count if not equal 
   ret                   ; if 30 overflows have occured return to blink

overflow_handler: 
   inc overflows         ; add 1 to the overflows variable
   cpi overflows, 61     ; compare with 61
   //brne PC+2             ; Program Counter + 2 (skip next line) if not equal
   breq .+2                ; above line fixed 
   clr overflows         ; if 61 overflows occured reset the counter to zero
   reti                  ; return from interrupt




