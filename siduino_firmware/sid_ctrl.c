#include "sid_ctrl.h"

volatile bool running = false;

//volatile unsigned long timenow = 0; //test 

/*

AVR 328p Pin Mapping : low 3 bits of PORTC:


 CLK -PC2 0x04 - data read when high 
 RW - PC1 0x02 - RW stays low (DDR -> SID reads data)
 CS - PC0 0x01 - data read when low
 RGBLED - PC4,PC5,PC6

 Address bus = portb
 Data bus= PortD

  /////////////////////////////////////////////////////////////

                o-o-TX-RX-RST-o-o    
                  ------------
              pd1 | MMduino  |
              pd0 |          |             
              rst |          |rst           -
              gnd |          |Vcc           -
              pd2 |          |pc3           -
              pd3 |          |pc2-adc3      - SID CLK/02 
              pd4 |          |pc1-adc2      - SID RW (ALWAYS LOW!) 
              pd5 |          |pc0-adc1      - SID CS
              pd6 |          |pb5-adc0      - 
              pd7 |          |pb4-sck  -d13 - SIDADDR4
 SIDADDR0     pb0 |          |pb3-mosi -d11 - SIDADDR3
 SIDADDR1     pb1 |          |pb2-cs   -d10 - SIDADDR2
                   ----------
  /////////////////////////////////////////////////////////////
 SID-ADR-Table:

     VALUE    ATTACK    DECAY/RELEASE
   +-------+----------+---------------+
   |   0   |    2 ms  |      6 ms     |
   |   1   |    8 ms  |     24 ms     |
   |   2   |   16 ms  |     48 ms     |
   |   3   |   24 ms  |     72 ms     |
   |   4   |   38 ms  |    114 ms     |
   |   5   |   56 ms  |    168 ms     |
   |   6   |   68 ms  |    204 ms     |
   |   7   |   80 ms  |    240 ms     |
   |   8   |  100 ms  |    300 ms     |
   |   9   |  240 ms  |    720 ms     |
   |   10  |  500 ms  |    1.5 s      |
   |   11  |  800 ms  |    2.4 s      |
   |   12  |    1 s   |      3 s      |
   |   13  |    3 s   |      9 s      |
   |   14  |    5 s   |     15 s      |
   |   15  |    8 s   |     24 s      |
   +-------+----------+---------------+

  /////////////////////////////////////////////////////////////
   SID-Maths:

    Frequency:
    ----------

     To calculate the frequency corresponding to the 16-bit value in
     $D400+$D401, $D407+$D408, $D40E+$D40F use the following formula:

      Freq = 16Bit-Value * Phi2 / 16777216 Hz

     where Phi2 is the system-clock, 985248 Hz for PAL-systems,
     1022727 Hz for NTSC-systems.

     A good approximation for both systems is the formula:

      Freq = 16Bit-Value / 17.03

    Pulse-Width:
    ------------

     To calculate the pulse width (in %) corresponding to the 12-bit value in
     $D402+$D403, $D409+$D40A, $D410+$D411 use the following formula:

      PulseWidth = (16Bit-Value / 40.96) %


  /////////////////////////////////////////////////////////////
  //FROM // http://www.oxyron.de/html/registers_sid.html
  ------------------------------------------------------------------------------------------------
                      7         6         5         4         3        2         1         0     
   ------------------------------------------------------------------------------------------------
  $D400 (W) FREQLO1                          Channel 1 Frequency Low-Byte
  $D401 (W) FREQHI1                          Channel 1 Frequency High-Byte
  $D402 (W) PWLO1                            Channel 1 Pulse Width (PW7-0)
  $D403 (W) PWHI1                     UNUSED              |       Channel 1 Pulse Width (PW11-8)
  $D404 (W) CR1     NOISE  |   PULSE  |   SAW  |   TRI    |  TEST  |  RING  |   SYNC  |   GATE
  $D405 (W) AD1             Channel 1 Attack              |       Channel 1 Decay
  $D406 (W) SR1             Channel 1 Sustain             |       Channel 1 Release
  $D407 (W) FREQLO2                          Channel 2 Frequency Low-Byte
  $D408 (W) FREQHI2                          Channel 2 Frequency High-Byte
  $D409 (W) PWLO2                            Channel 2 Pulse Width (PW7-0)
  $D40A (W) PWHI2                     UNUSED              |       Channel 2 Pulse Width (PW11-8)
  $D40B (W) CR2     NOISE  |   PULSE  |   SAW  |   TRI    |  TEST  |  RING  |   SYNC  |   GATE
  $D40C (W) AD2             Channel 2 Attack              |       Channel 2 Decay
  $D40D (W) SR2             Channel 2 Sustain             |       Channel 2 Release
  $D40E (W) FREQLO3                         Channel 3 Frequency Low-Byte
  $D40F (W) FREQHI3                         Channel 3 Frequency High-Byte
  $D410 (W) PWLO3                           Channel 3 Pulse Width (PW7-0)
  $D411 (W) PWHI3     unused                              | Channel 3 Pulse Width (PW11-8)
  $D412 (W) CR3     NOISE  |   PULSE  |   SAW  |   TRI    | TEST   |   RING |   SYNC  |   GATE
  $D413 (W) AD3              Channel 3 Attack             |       Channel 3 Decay
  $D414 (W) SR3              Channel 3 Sustain            |       Channel 3 Release
  $D415 (W) FCLO             unused                       |       Filter Cutoff Low (FC2-FC0)
  $D416 (W) FCHI      Filter Cutoff High (FC10-FC3)
  $D417 (W) Res/Filt  Filter Resonance  Filt Ex   Filt 3  Filt 2                           Filt 1
  $D418 (W) Mode/Vol  Ch3Off    HighPass  BandPass  LoPass|             Volume
  $D419 (R) POTX                        Potentiometer X
  $D41A (R) POTY                        Potentiometer Y
  $D41B (R) OSC3                        Channel 3 Oscillator
  $D41C (R) ENV3                        Channel 3 Envelope
  ------------------------------------------------------------------------------------------------

*/

/***********************/

// RGB PINS 
// PORTC = 0x08;
// PORTC = 0x10;
// PORTC = 0x20;


//VERY short delay to let the SID registers sync up 
void SIDdelay() 
{
  unsigned char i;
  for(i=0;i<10;i++) {
     __asm("nop\n\t");
  }
}

void delay() 
{
  unsigned char i;
  for(i=0;i<100;i++) {
     SIDdelay();
  }
}

void longdelay() 
{
  unsigned char i;
  unsigned char j;

  for(i=0;i<255;i++) {
    for(j=0;j<10;j++) {
       delay();
    }
  }
}

/***********************/
void init_SID_bus()
{

   //SID ADDRESS PINS - BOTTOM 5 PINS 
   DDRB = 0x1f;  
   //CONTROL BUS      -  BOTTOM 6 PINS 
   DDRC = 0x3f;       // 00111111  (5,4,3-RGB / 2,1,0-CTRL) 
   // 8 bit DATA BUS   
   DDRD = 0xff;

   //clear initial pin states
   PORTB = 0x00;
   PORTC = 0x00;
   PORTD = 0x00;
  
   PORTC |= (CS_PIN); //CS high  
   PORTC &= ~RW_PIN;  //RW LOW (SID reads data)
          
}


/***********************/
/*
void wrSID(uint8_t addr, uint8_t data)
{
   running = true;
   
   //WIRING =  pc0 CS, pc1 RW, pc2 CLK

   PORTC &= ~CLK_PIN;  //clock low   
   PORTC &= ~RW_PIN;   // RW low
   SIDdelay();

   PORTB = addr;       //set Addr 
   PORTD = data;       //set Data
   SIDdelay();
   
   PORTC |= CLK_PIN;   // clock high  
   PORTC &= ~(CS_PIN); // CS low - Activate 

   SIDdelay();
   
   PORTC &= ~CLK_PIN; // clock low 

   PORTC |= (CS_PIN); // CS high- (deactive)
   PORTC |= RW_PIN;   // RW high

   running = false;

}
*/

/***********************/
//original - may or may not work 
void wrSID(uint8_t addr, uint8_t data)
{
   //data gets written to chip when clock is high and RW/CS are LOW (active high)  
   running = true;
   //WIRING =  pc0 CS, pc1 RW, pc2 CLK
   PORTC |= CLK_PIN;   //clock high  
   PORTC &= ~(CS_PIN); //CS low - Activate  - dont think this is needed 
   SIDdelay();
   PORTC &= ~CLK_PIN;  //clock low   
   PORTC |= (CS_PIN);  // CS high- (deactive)
   PORTB = addr;       //set Addr 
   PORTD = data;       //set Data
   SIDdelay();
   PORTC |= CLK_PIN;   // clock high  
   PORTC &= ~(CS_PIN); // CS low - Activate 
   PORTC &= ~RW_PIN;   // RW low
   SIDdelay();
   PORTC &= ~CLK_PIN; // clock low 
   PORTC |= (CS_PIN); // CS high- (deactive)
   PORTC |= RW_PIN;   // RW high
   running = false;
}


/***********************/
void sid_clear_registers(){
  // Clear all 29 SID registers 
  //REM 20 FOR L = 0 TO 24: POKE S+L,0: NEXT

   wrSID(0b00000000 , 0b00000000 );
   wrSID(0b00000001 , 0b00000000 );
   wrSID(0b00000010 , 0b00000000 );
   wrSID(0b00000011 , 0b00000000 );
   wrSID(0b00000100 , 0b00000000 );
   wrSID(0b00000101 , 0b00000000 );
   wrSID(0b00000110 , 0b00000000 );
   wrSID(0b00000111 , 0b00000000 );      
   wrSID(0b00001000 , 0b00000000 );
   wrSID(0b00001001 , 0b00000000 ); 
   wrSID(0b00001010 , 0b00000000 ); 
   wrSID(0b00001011 , 0b00000000 ); 
   wrSID(0b00001100 , 0b00000000 ); 
   wrSID(0b00001101 , 0b00000000 ); 
   wrSID(0b00001110 , 0b00000000 ); 
   wrSID(0b00001111 , 0b00000000 ); 
   wrSID(0b00010000 , 0b00000000 ); 
   wrSID(0b00010001 , 0b00000000 ); 
   wrSID(0b00010010 , 0b00000000 ); 
   wrSID(0b00010011 , 0b00000000 ); 
   wrSID(0b00010100 , 0b00000000 ); 
   wrSID(0b00010101 , 0b00000000 ); 
   wrSID(0b00010110 , 0b00000000 ); 
   wrSID(0b00010111 , 0b00000000 ); 
   wrSID(0b00011000 , 0b00000000 ); 
   //no need to set the other registers they are read not write

}




/***********************/
void enable_timer_isr()
{
    TCCR1B |= (1 << WGM12 ) ;  // Configure timer 1 for CTC mode
    TIMSK1 |= (1 << OCIE1A ) ; // Enable CTC interrupt
    sei();     //Enable global interrupts
    
    //not sure where to set this 70 was defualt - as low as 48?
    //OCR1A = 70;// Set CTC compare value - controls "system-C64" clock speed via ISR
    OCR1A = 50;

    TCCR1B |= (1 << CS10 )  ;  // NO prescalar (faster)
}



/***********************/
/***********************/
//UART STUFF


// page 183 of datasheet
void USART_Init( unsigned int ubrr)
{
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    /*Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

uint8_t USART_receive(void)
{
    while (!(UCSR0A & (1 << RXC0))) {/*Busy wait.*/}
    return UDR0;
}

void USART_Transmit( unsigned char data )
{
  while ( !( UCSR0A & (1<<UDRE0)) );
  UDR0 = data;
}

void print_byte( uint8_t data){
   uint8_t i = 0;

   for (i=0; i<=7; i++) {
       //if ( !!(data & (1 << ii)) ){  // LSB
       if ( !!(data & (1 << (7 - i))) ){  // MSB
           USART_Transmit( BIT_OFF );
       }else{
           USART_Transmit( BIT_ON );
       }
    }
    
    USART_Transmit( 0xa ); //0xa = new line  
    USART_Transmit( 0xd ); //0xd = carriage return
}



void echo_uart(){
     uint8_t buf = USART_receive();
     print_byte(buf);
}

void break_connection(){
    PORTD = 0x00;    //clear port  (LEDS) 
    USART_Transmit( 0x45 ); //E
    USART_Transmit( 0x78 ); //x
    USART_Transmit( 0x69 ); //i
    USART_Transmit( 0x54 ); //T

}







/***********************/
/***********************/


ISR ( TIMER1_COMPA_vect )
{
    if (!running)
    {
        PORTC ^= CLK_PIN; //XOR the system clock when not loading data to chip      
    }
    //timenow++;
}

