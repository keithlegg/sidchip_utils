#include "sid_ctrl.h"

//extern volatile unsigned long timenow; //test 

unsigned long lastupdate = 0; //test 


/***********************/

/*





PORTD - DATA 
PORTC - 

C5 - RGB
C4 - RGB
C3 - RGB 










*/

//OLD STANDBY external no divide by eight
//sudo avrdude -V -c usbtiny -p atmega328p  -U lfuse:w:0xff:m -U hfuse:w:0xd9:m 

//FUSE SETTINGS ??
//sudo avrdude -V -c usbtiny -p atmega328p  -U lfuse:w:0xde:m -U hfuse:w:0xd9:m  /----NO---->/ -U efuse:w:0xff:m 
//sudo avrdude -V -c usbtiny -p atmega328p  -U lfuse:w:0xde:m -U hfuse:w:0xd9:m -U efuse:w:0xff:m 


/*
10 S=54272
20 FOR L = 0 TO 24: POKE S+L,0: NEXT
30 POKE S+1,10
40 POKE S+5,10
50 POKE S+15,255
60 POKE S+24,100
70 POKE S+4,33
--------------------------
POKE 54273,10   = 11010100-00000001, 00001010  -NOTE TO PLAY // xx273 and xx272 = high freq , low freq  
POKE 54277,10   = 11010100-00000101, 00001010 - Attack Decay    - 255 is slowest attack
POKE 54278,255  = 11010100-00000110, 11111111 - Attack Decay    - 255 is slowest attack
POKE 54287,100  = 11010100-00001111, 01100100 - 
POKE 54296,15   = 11010100-00011000, 00011111 - volume 15 is highest
POKE 54276,33   = 11010100-00000100, 00100001

void play_sound2()
{
    //POKE 54273,10    - Note to play
    wrSID(0b00000001 , 0b00001010 );  
    //POKE 54277,10    - Attack Decay
    wrSID(0b00000101 , 0b00001010 );
    //POKE 54278,255    - Sustain Release
    wrSID(0b00000110 , 0b11111111 );
    //POKE 54287,100    -   
    wrSID(0b00001111 , 0b01100100 );
    //POKE 54296,15     - full volume 
    wrSID(0b00011000 , 0b00011111 );

    //wrSID(0b00000100 , 0b00010001 );//POKE54276,17      - triangle wave
    wrSID(0b00000100 , 0b00100001 );//POKE54276,33      - sawtooth wave

}

*/


/***********************/


void play_spacechip()
{
  int x = 0;

  for (x=0;x<20;x++)
  {
      wrSID(0b00000001 , 0b000101000); //POKE 54273, 40     - Note to play
      _delay_ms(10);  

      wrSID(0b00000001 , 0b01010000); //POKE 54273, 80     - Note to play
      _delay_ms(10); 

      wrSID(0b00000001 , 0b01100100); //POKE 54273, 100     - Note to play
      _delay_ms(10); 
      
      wrSID(0b00000001 , 0b01111000); //POKE 54273, 120     - Note to play
      _delay_ms(10); 
      
      wrSID(0b00000001 , 0b10001100); //POKE 54273, 140     - Note to play
      _delay_ms(10); 
     
      wrSID(0b00000001 , 0b10100000);  //POKE 54273, 160     - Note to play
      _delay_ms(10);
  } 
}

/*************************************/

//FILTERS
/*

30 POKE 54296,31  : REM FULL VOLUME PLUS LOW PASS FILTER
35 POKE 54295,1   : REM SELECT FILTER FOR VOICE 1
37 POKE 54294,128 : POKE 54293,7  : REM SELECT CUTOFF FREQUENCY
// 
50 pokes+10,8:pokes+22,128:pokes+23,244

*/

void test_filters()
{
    int delay     = 100;
    int num_loops = 4;

    //wrSID(0b00011000 , 0b00001111 ); // Set maximum Volume
    wrSID(0b00011000 , 0b00001111 );   // 54296,31  FULL VOLUME PLUS LOW PASS FILTER
    wrSID(0b00000100 , 0b00100001 );   // 54276,33  - sawtooth wave

    /************/
    wrSID(0b00010111 , 0b00000000 );   // 54295,0  - Voice 1 filter enable
    
    wrSID(0b00010101 , 0b00000010 );   // (l) 54293,0  - cutoff filter 0-2 
    wrSID(0b00010110 , 0b00000111 );   // (h) 54293,0  - cutoff filter 0-7 
    
    //wrSID(0b00010111 , 0b00000100 );   //     54295,0  - resonance filter 4-7 

    //wrSID(0b00010111 , 0b00000100 );   //     54296,4  - low pass filter
    //wrSID(0b00010111 , 0b00000101 );   //     54296,5  - band pass filter
    //wrSID(0b00010111 , 0b00000110 );   //     54296,6  - high pass filter    

    wrSID(0b00000001 , 0b01000000); // 54273, 40     - Note to play

    for (int x= 0;x<num_loops;x++)
    {
        wrSID(0b00010111 , 0b00000100 );   //     54295,0  - resonance filter 4-7 
        //wrSID(0b00010111 , 0b00000100 );   //     54296,4  - low pass filter      
        _delay_ms(delay);  

         wrSID(0b00010111 , 0b00000101 );   //     54295,0  - resonance filter 4-7 
        //wrSID(0b00010111 , 0b00000101 );   //     54296,5  - band pass filter        
        _delay_ms(delay); 

         wrSID(0b00010111 , 0b00000111 );   //     54295,0  - resonance filter 4-7 
        //wrSID(0b00010111 , 0b00000110 );   //     54296,6  - high pass filter  
        _delay_ms(delay); 
        

    }


}

/*************************************/

/*************************************/
void voice1_scale()
{

      int delay     = 100;
      int num_loops = 2;
            
      for (int x= 0;x<num_loops;x++)
      {
        wrSID(0b00011000, 0b00001111 ); // Set maximum Volume
        wrSID(0b00000100, 0b00010001 );// 54276,17      - triangle wave

        wrSID(0b00000001, 0b000101000); // 54273, 40     - Note to play
        _delay_ms(delay);  

        wrSID(0b00000001, 0b01010000); // 54273, 80     - Note to play
        _delay_ms(delay); 

        wrSID(0b00000001, 0b01100100); // 54273, 100     - Note to play
        _delay_ms(delay); 
        
        wrSID(0b00000001, 0b01111000); // 54273, 120     - Note to play
        _delay_ms(delay); 
        
        wrSID(0b00000001, 0b10001100); // 54273, 140     - Note to play
        _delay_ms(delay); 
       
        wrSID(0b00000001, 0b10100000);  // 54273, 160     - Note to play
        _delay_ms(delay); 
    }

      for (int x= 0;x<num_loops;x++)
      {
        wrSID(0b00011000, 0b00001111 ); // Set maximum Volume
        wrSID(0b00000100, 0b00100001 );//54276,33      - sawtooth wave

        wrSID(0b00000001, 0b000101000); // 54273, 40     - Note to play
        _delay_ms(delay);  

        wrSID(0b00000001, 0b01010000); // 54273, 80     - Note to play
        _delay_ms(delay); 

        wrSID(0b00000001, 0b01100100); // 54273, 100     - Note to play
        _delay_ms(delay); 
        
        wrSID(0b00000001, 0b01111000); // 54273, 120     - Note to play
        _delay_ms(delay); 
        
        wrSID(0b00000001, 0b10001100); // 54273, 140     - Note to play
        _delay_ms(delay); 
       
        wrSID(0b00000001, 0b10100000);  // 54273, 160     - Note to play
        _delay_ms(delay); 
    }


}

/*********************/

void voice2_scale()
{

      int delay     = 200;
      int num_loops = 2;

      wrSID(0b00001011, 0b00100001 );// 54283,33  - sawtooth wave
      //wrSID(0b00001011, 0b00100001 );// 54283,17    - triangle wave
     
      wrSID(0b00001000, 0b00001000 );  //54280  - pulse width (l)     
      wrSID(0b00001001, 0b00001000 );  //54281  - pulse width (h)


      //MULTI VOICE TEST 
      wrSID(0b00000001, 0b00110000); // 54273,   - voice1 Note to play

      
      for (int x= 0;x<num_loops;x++)
      {
        wrSID(0b00000111, 0b10000010 ); // (l) 54279       - Set Frequency of voice 2
        wrSID(0b00001000, 0b00101000 ); // (h) 54280, 40   - Note to play
        _delay_ms(delay);  


        wrSID(0b00001000, 0b00010000 );  //54280  - pulse width (l)     
        wrSID(0b00001001, 0b00010000 );  //54281  - pulse width (h)
        _delay_ms(delay); 
       
        //wrSID(0b00001000, 0b00100000 );  //54280  - pulse width (l)     
        //wrSID(0b00001001, 0b00100000 );  //54281  - pulse width (h)

      }

}


/***********************/

void sweep_freqency_v1()
{
    int delay = 10;//ms 
    int steps = 255;

    wrSID(0b00011000, 0b00001111 ); // Set maximum Volume
    //wrSID(0b00000100, 0b00010001 );// 54276,17      - triangle wave
    wrSID(4, 0b00010001 );// 54276,17      - triangle wave

    for (int x= 0;x<steps;x++)
    {
      wrSID(1,x);
      _delay_ms(delay); 
    }
      

}

void sweep_pulse_width()
{
    int delay = 10;//ms 
    int steps = 255;

    wrSID(0b00011000, 0b00001111 ); // Set maximum Volume

    //MULTI VOICE TEST 
    wrSID(1, 40); // ,   - voice1 Note to play

    for (int x= 0;x<steps;x++)
    {

      //wrSID(2, x );    //54274  - pulse width (l)     
      wrSID(3, x );    //54275  - pulse width (h)

      _delay_ms(delay); 
    }
      

}

void setup_sid_voices()
{
    //********************** setup SID parameters   *************************

    // SET GLOBAL VOLUME 
    wrSID(0b00011000, 0b00001111 );  // (24) 54296, 15  Set maximum Volume


 
    //********************** Voice 1 parameters   *************************
      // OSCILLATOR  SETUP
      wrSID(0b00000000, 0b000000000);    // (0) 54272, 0   -low inital frequency
      wrSID(0b00000001, 0b000100000);    // (1) 54273, 32  -high inital frequency
      //Voice1 ADSR *****
      wrSID(0b00000101, 0b00001001 );    // (5) 54277      -Set Attack/Decay voice 1
      wrSID(0b00000110, 0b10000000 );    // (6) 54278      -Set Sustain/Release voice 1
      
      //**** Voice1 WAVE ENABLE  *****
      //wrSID(0b00000100, 0b00010001 );     // (4) 54276,17   -V1 Triangle waveform and Gate bits 
      //wrSID(0b00000100, 0b00100001 );       // (4) 54276,33      -V1 Sawtooth waveform and Gate bits 
      wrSID(0b00000100, 0b01000001 );     // (4) 54276,65   -V1 Pulse waveform and Gate bits
      //wrSID(0b00000100,    );             // (4) 54276,128   -V1 Noise waveform and Gate bits

      // these only work with pulse type?      
      wrSID(0b00000010, 0b00000010 );     // (2) 54274  - pulse width (l)     
      wrSID(0b00000011, 0b00001000 );     // (3) 54275  - pulse width (h)
      //**** V1 ENVELOPE SETUP******** 
      //**** V1 FILTER SETUP ********* 

    //********************** Voice 2 parameters   *************************
    
      wrSID(0b00000111, 0b000000000);    // (7) 54279, 0   -Set inital frequency
      wrSID(0b00001000, 0b000101000);    // (8) 54280, 40  -Set inital frequency
 
     // wrSID(0b00001011, 0b01000001 );    // (11) 54283,65     CR - enable tone by setting waveform

      wrSID(0b00001100, 0b00001001 );    // (12) 54284     Set Attack/Decay voice 2
      wrSID(0b00001101, 0b10000000 );    // (13) 54285     Set Sustain/Release voice 2

      //wrSID(0b00001011, 0b00010001 );  // (11) 54290,17   -V2 Triangle waveform and Gate bits 
      //wrSID(0b00001011, 0b00100001 );  // (11) 54290,33   -V2 Sawtooth waveform and Gate bits 
      wrSID(0b00001011, 0b01000001 );    // (11) 54290,65   -V2 Pulse waveform and Gate bits 
      
      // these only work with pulse type?
      wrSID(0b00001001, 0b00000010 );  //(9) 54281   - pulse width (l)
      wrSID(0b00001010, 0b00001000 );  //(10) 54282  - pulse width (h)
    
   
    //********************** Voice 3 parameters   *************************
    
      wrSID(0b00001110, 0b000000000);  // (14) 54286, 0  -Set inital frequency
      wrSID(0b00001111, 0b000101000);  // (15) 54286, 40  -Set inital frequency
     
      //wrSID(0b00010010, 0b01000001 );  // (18) 54290, 65     CR - enable tone by setting pulse ?

      wrSID(0b00010011, 0b00001001 );  // (19) 54291     Set Attack/Decay voice 3
      wrSID(0b00010100, 0b10000000 );  // (20) 54292     Set Sustain/Release voice 3

      //wrSID(0b00010010, 0b00010001 );  // (18) 54290,17   -V2 Triangle waveform and Gate bits 
      //wrSID(0b00010010, 0b00100001 );  // (18) 54290,33   -V2 Sawtooth waveform and Gate bits 
      wrSID(0b00010010, 0b01000001 );    // (18) 54290,65   -V2 Pulse waveform and Gate bits 

      wrSID(0b00010000, 0b00000010 );  //(16) 54280  - pulse width (l)     
      wrSID(0b00010001, 0b00001000 );  //(17) 54281  - pulse width (h)
     
   

}


/**************************************/

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


/**************************************/


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
/***********************/

uint8_t oldsid[25] = {0};
uint8_t newsid[25] = {0};
uint8_t buffer[50] = {0};
int idx = 0;
bool dataready = false;

///
uint8_t decode(uint8_t ch)
{
  if (ch >= 0x41) // "A" 
    return ch - 55;
  else
    return ch - 48;
}

///

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

///

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

/***********************/
//used as a hello user and to test RGB led connections
void test_leds(void){

   int a = 0;
   for (a=0;a<5;a++){
      PORTC &= ~(0x38);;  //all LEDS off (pc3,pc4,pc5) 
      PORTC |= (0x8); //pc3 on - green  
      _delay_ms(10); 

      PORTC &= ~(0x38);;  //all LEDS off 
      PORTC |= (0x10); //pc4 on - blue  
      _delay_ms(10);

      PORTC &= ~(0x38);;  //all LEDS off 
      PORTC |= (0x20); //pc5 on - red 
      _delay_ms(10); 

      PORTC &= ~(0x1c);;  //all LEDS off  
   }
}

/***********************/
//sweep the address port to test bits are connected
void test_addr_bus(void){

   int a = 0;
   for (a=0;a<5;a++){
      PORTB = 0x00;  //bus off 
      PORTB = 0x1;   
      _delay_ms(50); 

      PORTB = 0x00;  //bus off 
      PORTB = 0x2;   
      _delay_ms(50); 

      PORTB = 0x00;  //bus off 
      PORTB = 0x4;   
      _delay_ms(50); 

      PORTB = 0x00;  //bus off 
      PORTB = 0x8;   
      _delay_ms(50); 

      PORTB = 0x00;  //bus off 
      PORTB = 0x10;   
      _delay_ms(50); 

      PORTB = 0x00;  //bus off 
      PORTB = 0x20;   
      _delay_ms(50); 

      PORTB = 0x00;  //bus off 
      PORTB = 0x40;   
      _delay_ms(50); 

      PORTB = 0x00;  //bus off 
      PORTB = 0x80;   
      _delay_ms(50);  
           
      PORTB = 0x00;  //bus off 
   }


}

/***********************/
//sweep the address port to test bits are connected
void test_data_bus(void){

   int a = 0;
   for (a=0;a<5;a++){
      PORTD = 0x00;  //bus off 
      PORTD = 0x1;   
      _delay_ms(50); 

      PORTD = 0x00;  //bus off 
      PORTD = 0x2;   
      _delay_ms(50); 

      PORTD = 0x00;  //bus off 
      PORTD = 0x4;   
      _delay_ms(50); 

      PORTD = 0x00;  //bus off 
      PORTD = 0x8;   
      _delay_ms(50); 

      PORTD = 0x00;  //bus off 
      PORTD = 0x10;   
      _delay_ms(50); 

      PORTD = 0x00;  //bus off 
      PORTD = 0x20;   
      _delay_ms(50); 

      PORTD = 0x00;  //bus off 
      PORTD = 0x40;   
      _delay_ms(50); 

      PORTD = 0x00;  //bus off 
      PORTD = 0x80;   
      _delay_ms(50);  
           
      PORTD = 0x00;  //bus off 
      } 
}

/***********************/


int main (void)
{


    //enable_timer_isr(); //activate timer interrupt to pulse SID clock pin 
    init_SID_bus();     //setup AVR ports to send commands to  SID 

    sid_clear_registers(); //poke 53272+24,0 

    setup_sid_voices();
   
    test_leds();     // alert user we are online and ready to play
    //test_addr_bus(); // flash each bit in address bus

    while(1)
    {
         play_spacechip();
         sweep_pulse_width();
         sweep_freqency_v1();
         voice2_scale();
         voice1_scale();
    }

 

} 



