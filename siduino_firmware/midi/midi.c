
#define F_CPU 16000000UL

#include <avr/io.h>

#include <util/delay.h>
#include <avr/interrupt.h>

#define USART_BAUDRATE 31250 
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 


/*


    0xnc, 0xkk, 0xvv

    n   is the command (note on (0x9) or off(0x8))
    c   is the channel (1 to 16)
    kk  is the key number (0 to 127, where middle C is key number 60)
    vv  is the striking velocity (0 to 127)


	//CASIO  CT650 

	0x90 - note on channel 0 

	0x60 - key channel 0   
	0x40 - velocity channel 0

	0x60 - key channel 0  
	0x00 - velocity zero is same as off 

*/

/***************************************************************************/

//VERY short delay to let the SID registers sync up 
void SIDdelay() 
{
  unsigned char i;
  for(i=0;i<255;i++) {
      __asm("nop\n\t");
      //PORTC ^= CLK_PIN; //XOR the system clock when not loading data to chip      
  }  
}


void delay() 
{
  unsigned char i;
  for(i=0;i<200;i++) {
     SIDdelay();
  }
}

void longdelay() 
{
  unsigned char j;
 
  for(j=0;j<15;j++) {
      delay();
  }
 
}


/***************************************************************************/

void sweep(void)
{
    int x = 0;
    for (x=30;x<100;x++) // Loop forever 
    { 
        while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
        UDR0 = x;

        while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
        UDR0 = 0x40;
        
        longdelay();
    }

    for (x=100;x>30;x--) // Loop forever 
    { 
        while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
        UDR0 = x;

        while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
        UDR0 = 0x40;
        
        longdelay();
    }
}

/***************************************************************************/


void pattern1(void)
{
    int x = 0;
 
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x24;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();
 
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x34;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();

    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x48;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();

    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x32;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();
 
}

/***************************************************************************/

void pattern2(void)
{
    int x = 0;
 
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x28;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();
 
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x17;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();

    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x38;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();

    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x42;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;
    longdelay();
 
}

void sillysong(void)
{
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x90;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x32;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;

    int z = 0;
    for (z=0;z<6;z++)    
    {
        pattern1();
    } 
    for (z=0;z<6;z++)    
    {
        pattern2();
    } 

}


void polyphonic()
{
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x90;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x32;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;

    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x90;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x42;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x40;

    longdelay();

    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x80;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x42;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x00;


    longdelay();

    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x80;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x32;
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; 
    UDR0 = 0x00;

    delay();


}
/***************************************************************************/


int main (void) 
{ 

   DDRC = 0xff;
    
   UCSR0B = (1 << RXEN0) | (1 << TXEN0);   // Turn on the transmission and reception circuitry 
   UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); // Use 8-bit character sizes 

   UBRR0H = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
   UBRR0L = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 


   for (;;) // Loop forever 
   { 

       //polyphonic();
       
       sillysong();
   }    

   return 1;
}

