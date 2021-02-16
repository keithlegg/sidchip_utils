#ifndef SIDCTRL_H

#define F_CPU 16000000UL

#include <avr/io.h>

#include <util/delay.h>
#include <avr/interrupt.h>



//#include <avr/wdt.h> //watchdog for reset cmd
//#include <avr/sfr_defs.h>


/**************************/

//UART STUFF
#define FOSC 16000000UL

//these are affected by xtal and fuse settings! 
#define BAUD 57600
//#define BAUD 115200
//these are affected by xtal and fuse settings!

#define MYUBRR FOSC/16/BAUD-1

/**************************/

#define BIT_ON 0x30
#define BIT_OFF 0x31

//#define LED_PIN 0x05 //PORTC  //not used yet 
#define CLK_PIN 0x04 //PORTC
#define RW_PIN 0x02  //PORTC
#define CS_PIN 0x01  //PORTC

/**************************/

void SIDdelay();
void delay();
void longdelay();

void wrSID(uint8_t addr, uint8_t data);
void poke(uint16_t addr, uint16_t value);

void sid_clear_registers();
void init_SID_bus();
void enable_timer_isr();


/*****************/

void USART_Init( unsigned int ubrr);

uint8_t USART_receive(void);
void USART_Transmit( unsigned char data );

void print_byte( uint8_t data);
void echo_uart();
void break_connection();





#endif 