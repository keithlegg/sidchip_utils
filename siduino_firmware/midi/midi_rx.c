#include <avr/io.h>
#include <avr/interrupt.h>

// #define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 


#define F_CPU 16000000      // 16MHz 
#define BAUD 31250          // 31.250 KBaud is Baud Rate or Bit Rate
#define MYUBRR 31           // UART Baud Rate Register (UBRR) = (F_CPU/16/BAUD)-1


#define PWM_PIN 0x04 //PORTC
#define RW_PIN 0x02  //PORTC
#define CS_PIN 0x01  //PORTC

int set_PORTC_bit(unsigned int, unsigned int);
void USART_Init(unsigned int);
unsigned char USART_ReceiveByte(void);
void USART_TransmitByte(unsigned char);
void delay_ms(uint16_t x); // general purpose delay

#define sbi(a, b) (a) |= (1 << (b))
#define cbi(a, b) (a) &= ~(1 << (b))


/*
//draw a byte with two pins to look at with logic analyzer
void blink_byte_msb(uint8_t data)
{
    uint8_t i = 0;
    for (i=0; i<=7; i++) 
    {
        PORTB ^= _BV(3);   
        //if ( !!(data & (1 << ii)) ){  // LSB
        if ( !!(data & (1 << (7 - i))) ){  // MSB
            PORTC = 0x08; //ON
            sbi(PORTB, 4); 
        }else{
            PORTC = 0x00; //OFF
            cbi(PORTB, 4); 
        }
        PORTB ^= _BV(3);   
        delay_ms(10);
    }

    cbi(PORTB, 4); //leave data "off" 

}
*/

//draw a byte with two pins to look at with logic analyzer
void blink_byte_lsb(uint8_t data)
{
    uint8_t i = 0;
    for (i=0; i<=7; i++) 
    {
        PORTB ^= _BV(3);   
        //if ( !!(data & (1 << ii)) ){  // LSB
        if ( !!(data & (1 << (7 - i))) ){  // MSB
            PORTC = 0x08; //ON
            sbi(PORTB, 4); 
        }else{
            PORTC = 0x00; //OFF
            cbi(PORTB, 4); 
        }
        PORTB ^= _BV(3);   
        delay_ms(10);
    }

    cbi(PORTB, 4); //leave data "off" 

}





/************************************************************/
/************************************************************/
// interrupt section 
 
//use interrupt to setup SID clock pin as an audio source  
void enable_audio_isr()
{
    TCCR1B |= (1 << WGM12 ) ;  // Configure timer 1 for CTC mode
    TIMSK1 |= (1 << OCIE1A ) ; // Enable CTC interrupt
    sei();       //Enable global interrupts
    OCR1A = 0;    // Set CTC compare value - use to set tone of sound/delay 
    TCCR1A |= (1 << COM1A0);   // Toggle OC1A on Compare Match.
    
    TCCR1B |= (1 << CS10);     // clock on 
    TCCR1B |= (1 << CS12);     // clock on 

}

ISR ( TIMER1_COMPA_vect )
{
    PORTC ^= PWM_PIN; //XOR the system clock when not loading data to chip      
}


 
/************************************************************/
/************************************************************/



int main(void)
{
    
    USART_Init(MYUBRR);

    //DDRB = 0b11101111;    //PB4 = MISO 


    DDRC = 0xff;

        
    //Startup Test Sequence
    // PORTC = 0b0001;
    // delay_ms(800);
    // PORTC = 0b0011;
    // delay_ms(800);
    // PORTC = 0b0111;
    // delay_ms(800);
    // PORTC = 0b1111;
    // delay_ms(1600);
    // PORTC = 0b0000;
      

    //blink_byte_lsb(0xff);
     blink_byte_lsb(0xaa);
    // blink_byte_lsb(0x55);
    // blink_byte_lsb(0xf0);
    // blink_byte_lsb(0x0f);

    //enable_audio_isr();

    
    for(;;)
    {
       
        uint8_t byte = USART_ReceiveByte();
        if( byte !=0 )
        {
            PORTC = 0x10; //ON
            delay_ms(1);
            PORTC = 0x00; //OFF

            // blink_byte_lsb(byte);
            // PORTB = 0x00;
            // PORTC = 0x00;
            // delay_ms(20);
            
            if(byte==0x90)
            {
                // blink_byte_lsb(0xf0);

            }   
            
            //OCR1A = (uint8_t) byte/3;

            /*
            //AUDIO OUT TEST 
            if(byte==0x24)
            {
                OCR1A = 10;
            } 
            if(byte==0x25)
            {
                OCR1A = 9;
            } 

            if(byte==0x26)
            {
                OCR1A = 8;
            } 
            if(byte==0x27)
            {
                OCR1A = 7;
            } 
            if(byte==0x28)
            {
                OCR1A = 6;                
            }  
            */

            //BLINK OUT TEST 
            if(byte==0x24)
            {
                blink_byte_lsb(0x0f);
            } 
            if(byte==0x25)
            {
                blink_byte_lsb(0x0f);
            } 

            if(byte==0x26)
            {
                blink_byte_lsb(0xaa);
            } 
            if(byte==0x27)
            {
                blink_byte_lsb(0xaa);
            } 
            if(byte==0x28)
            {
                blink_byte_lsb(0x55);
            }  

        }
      
    }
  


    return 0;   /* never reached */
}


int set_PORTC_bit(unsigned int position, unsigned int value)      
{                                                                 

    // Function sets or clears the PORTC bit in position 'position'
    // either high or low (1 or 0) to match 'value'.
    
    // Leaves all other bits  unchanged.
    if (value == 0)
    {
        PORTC &= ~(1 << position);      // Set bit # 'position' low
    }
    else
    {
        PORTC |= (1 << position);       // Set bit # 'position' high
    }
    return 1;
}



void USART_Init(unsigned int ubrr_value)   //Initializes the Universal A/Synchonous Receiver/Transmitter
{
    
    //UBRR0 = (unsigned char) ubrr_value;                  
    //Sets the Baud/Bit rate
    
    UBRR0L = (unsigned char) ubrr_value;
    //Load lower 8-bits of the baud rate value  
    //into the low byte of the register
    
    UBRR0H = (unsigned char) (ubrr_value >> 8);            
    // Load upper 8-bits of the baud rate value 
    //into the high byte of the register
        
    UCSR0C |=  (1 << UCSZ01) | (1 << UCSZ00) ;                  
    
    /*
    //Note: MIDI uses 1 start bit, 8 data bits, and 1 stop bit, so 10 bits total per message
    //Set data frame format: asynchronous mode,no parity, 1 stop bit, 8 bit size
    
    //UCSR0C |= (0<<UMSEL00)|(0<<UMSEL01)|(0<<UPM01)|(0<<UPM00)|(0<<USBS0)|(0<<UCSZ02)|(1<<UCSZ01)|(1<<UCSZ00); 
    */
       
    UCSR0B = ( (1<<RXEN0) | (1<<TXEN0) );           //Enable The receiver and  transmitter
    
    
}


unsigned char USART_ReceiveByte( void ){            
    
    //This function is used to read the available data from USART. 
        
    while( !(UCSR0A & (1<<RXC0)) )          //Wait until data is available
        
        //Do nothing until data have been recieved and is ready to be read 
        //from UDR (wait until data is received)
        
        ;//(Do nothing)
    
    
    //Now USART has received data from host
    //and is available as a buffer
    
    return UDR0;
}



void USART_TransmitByte(unsigned char OutByte){       
    //This fuction writes the given byte to the
    // USART which then transmits it via TX line.

    //Wait until the transmitter is ready
    
    while( !(UCSR0A & (1<<UDRE0)) )               
        
        // Do nothing while waiting for the transmit buffer to empty
    
        ;//(Do nothing)
    
    //Now write the data to the USART buffer
    
    UDR0 = OutByte;
}


//General short delays
void delay_ms(uint16_t x)
{
    uint8_t y, z;
    for ( ; x > 0 ; x--){
        for ( y = 0 ; y < 80 ; y++){
            for ( z = 0 ; z < 40 ; z++){
                asm volatile ("nop");
            }
        }
    }
}
