#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// #define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 


#define F_CPU 16000000      // 16MHz 
#define BAUD 31250          // 31.250 KBaud is Baud Rate or Bit Rate
#define MYUBRR 31           // UART Baud Rate Register (UBRR) = (F_CPU/16/BAUD)-1


int set_PORTC_bit(unsigned int, unsigned int);
void USART_Init(unsigned int);
unsigned char USART_ReceiveByte(void);
void USART_TransmitByte(unsigned char);
void delay_ms(uint16_t x); // general purpose delay



void print_byte( uint8_t data){
   uint8_t i = 0;

   for (i=0; i<=7; i++) {
       //if ( !!(data & (1 << ii)) ){  // LSB
       if ( !!(data & (1 << (7 - i))) ){  // MSB
           PORTC = 0x08; //OFF
       }else{
           PORTC = 0x00; //ON
       }
       delay_ms(200);
    }
}




int main(void)
{
    
    USART_Init(MYUBRR);

    //DDRB = 0b11101111;    //PB4 = MISO 
    DDRC = 0xFF;            //this sets all bits/pins on Port C as outputs    
    //DDRD = 0b00111110;    //PORTD (RX on PD0)
        
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
      

    //PORTC = 0x08;

    print_byte(0xaa);

    for(;;)
    {
       
        uint8_t byte = USART_ReceiveByte();
        if( byte !=0 )
        {
            print_byte(byte);
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
