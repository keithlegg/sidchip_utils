
/*
  **************************************
 
    THIS CODE PUT ON HOLD 
    THE SIDUINO BOARD CANT WRITE?READ SEIRAL DATA WHILE PLAYING
    THIS WAS FROM ANOTHER PROTOTYPE THAT IS DEFUNCT AT THE MOMENT  

  **************************************
*/





void listen_oneByte()
{
    while(1)
    { 
         //echo_uart();
         ////////////////
         // DEMO OF SOUND AND SERIAL XFER 
         
         PORTC &= ~(0x32);;  //led 1 off      
         uint8_t byte = USART_receive();
         PORTC |= (0x32);  //led1 on 

         if (byte==0x61){ //a
             USART_Transmit( 0x61 );
             sweep_freqency_v1();
         }

         else if(byte==0x62){ //b
             USART_Transmit( 0x62 );
             play_spacechip();
         }

         //letter C - two more bytes coming!
         else if(byte==0x63){ //c
             listen_twoBytes();
             USART_Transmit( 0x63 );
         }

         //letter E - send back echo!
         else if(byte==0x65){ //e
             echo_twochars();
         }

         else if(byte==0x7a){
               
               USART_Transmit(0x41); //z -  for full demo
               voice1_scale();

               USART_Transmit(0x42);
               play_spacechip();

               USART_Transmit(0x43); 
               sweep_pulse_width();

               USART_Transmit(0x44);
               sweep_freqency_v1();

               USART_Transmit(0x45);       
               voice2_scale();
         }
         else if(byte==0x79){ //y - quiet
             sid_clear_registers();
         }
         else if(byte==0x78){ //x - speak now - DEBUG 
             setup_sid_voices();   
             wrSID(0b00000001, 0b000101000);    // 54273, 40  -Set inital frequency
             wrSID(0b00000101, 0b00001001 );    // 54277      -Set Attack/Decay voice 1
             wrSID(0b00000110, 0b10000000 );    // 54278      -Set Sustain/Release voice 1
             //*************
             wrSID(0b00000100, 0b00010001 );    // 54276,17   -V1 Triangle waveform and Gate bits 
         }
         else if(byte==0x77){ //w

             //wrSID(0b00011000, 0b00001111 );  // 54296,16  Set maximum Volume
             wrSID(0b00000001, 0b000101000);    // 54273, 40  -Set inital frequency
             wrSID(0b00000101, 0b00001001 );    // 54277      -Set Attack/Decay voice 1
             wrSID(0b00000110, 0b10000000 );    // 54278      -Set Sustain/Release voice 1
             //*************
             wrSID(0b00000100, 0b00010001 );    // 54276,17   -V1 Triangle waveform and Gate bits 
             //wrSID(0b00000100, 0b00100001 );  // 54276,33   -V1 Sawtooth waveform and Gate bits 
             //wrSID(0b00000100, 0b01000001 );  // 54276,65   -V1 Pulse waveform and Gate bits
             //*************
         }
         //test_filters();
         ////////////////
    }

}




/***********************/

uint8_t oldsid[25] = {0};
uint8_t newsid[25] = {0};
uint8_t buffer[50] = {0};
int idx = 0;
bool dataready = false;

/***********************/

uint8_t decode(uint8_t ch)
{
  if (ch >= 0x41) // "A" 
    return ch - 55;
  else
    return ch - 48;
}

/***********************/

void readData()
{
    PORTC |= (0x8); //pc3 on - green  
    uint8_t ch = USART_receive();

    if (ch == 0x21)//"!")
    {
        if (idx == 50)
        {
          for (int i = 0; i < 25; i++)
          {
            char highnibble = buffer[i * 2];
            char lownibble  = buffer[i * 2 + 1];
            newsid[i] = (decode(highnibble) << 4) | decode(lownibble);
          }
          dataready = true;
        }
        idx = 0;
    }
    else
    {
        if (idx < 50){
            buffer[idx] = ch;
        }
        idx++;
    }


     PORTC &= ~(0x38);;  //all LEDS off (pc3,pc4,pc5) 
}

/***********************/

void updateSID()
{
    for (int i = 0; i < 25; i++)
    {
        if (oldsid[i] != newsid[i])
        {
            oldsid[i] = newsid[i];
            wrSID( i, newsid[i] );
        }
    } 
}

/***********************/

void listen_realsid()
{
   while(1)
   {
       
        if (!dataready){readData();}

          if (dataready == true)
          {
            dataready = false;
            updateSID();
          }
        
          // Send more data!
          USART_Transmit(0x3f); // "?" = Send more data!
          //Serial.flush();

       

         /////////////////////

         /*
         int a = 0;
         for(a=0;a<50;a++){
            USART_receive();
         }
         _delay_ms(100);
         USART_Transmit(0x3f); // "?" = Send more data!
         */

     }//loop forever
}



/**************************************/
void echo_twochars()
{

    PORTC |= (0x56);  //all LEDS on (pc3,pc4,pc5)

    uint8_t addrbyte = USART_receive();
    USART_Transmit( addrbyte );
    
    uint8_t databyte = USART_receive();
    USART_Transmit( databyte );


    PORTC &= ~(0x56);  //all LEDS off (pc3,pc4,pc5)

}

/**************************************/
void listen_twoBytes()
{
    //while(1)  //remove this to behave like a single command
    //{ 
        PORTC |= (0x56);  //all LEDS on (pc3,pc4,pc5)

        uint8_t addrbyte = USART_receive();
        uint8_t databyte = USART_receive();

        wrSID( addrbyte, databyte ); //receive commands over serial port

        PORTC &= ~(0x56);  //all LEDS off (pc3,pc4,pc5)

        //USART_Transmit( 0x61 );//signal ACK
    //}

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




