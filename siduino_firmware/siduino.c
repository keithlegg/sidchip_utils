#include "sid_ctrl.h"

//extern volatile unsigned long timenow; //test 

unsigned long lastupdate = 0; //test 

extern volatile bool running;

/***************************************************/

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


/***************************************************/

/*

  //FROM // http://www.oxyron.de/html/registers_sid.html
  ------------------------------------------------------------------------------------------------
                      7         6         5         4         3        2         1         0     
  ------------------------------------------------------------------------------------------------
   0  - $D400 - 54272 - (W) FREQLO1                          Channel 1 Frequency Low-Byte
   1  - $D401 - 54273 - (W) FREQHI1                          Channel 1 Frequency High-Byte
   2  - $D402 - 54274 - (W) PWLO1                            Channel 1 Pulse Width (PW7-0)
   3  - $D403 - 54275 - (W) PWHI1                     UNUSED              |       Channel 1 Pulse Width (PW11-8)
   4  - $D404 - 54276 - (W) CR1     NOISE  |   PULSE  |   SAW  |   TRI    |  TEST  |  RING  |   SYNC  |   GATE
   5  - $D405 - 54277 - (W) AD1             Channel 1 Attack              |       Channel 1 Decay
   6  - $D406 - 54278 - (W) SR1             Channel 1 Sustain             |       Channel 1 Release
   7  - $D407 - 54279 - (W) FREQLO2                          Channel 2 Frequency Low-Byte
   8  - $D408 - 54280 - (W) FREQHI2                          Channel 2 Frequency High-Byte
   9  - $D409 - 54281 - (W) PWLO2                            Channel 2 Pulse Width (PW7-0)
   10 - $D40A - 54282 - (W) PWHI2                     UNUSED              |       Channel 2 Pulse Width (PW11-8)
   11 - $D40B - 54283 - (W) CR2     NOISE  |   PULSE  |   SAW  |   TRI    |  TEST  |  RING  |   SYNC  |   GATE
   12 - $D40C - 54284 - (W) AD2             Channel 2 Attack              |       Channel 2 Decay
   13 - $D40D - 54285 - (W) SR2             Channel 2 Sustain             |       Channel 2 Release
   14 - $D40E - 54286 - (W) FREQLO3                         Channel 3 Frequency Low-Byte
   15 - $D40F - 54287 - (W) FREQHI3                         Channel 3 Frequency High-Byte
   16 - $D410 - 54288 - (W) PWLO3                           Channel 3 Pulse Width (PW7-0)
   17 - $D411 - 54289 - (W) PWHI3     unused                              | Channel 3 Pulse Width (PW11-8)
   18 - $D412 - 54290 - (W) CR3     NOISE  |   PULSE  |   SAW  |   TRI    | TEST   |   RING |   SYNC  |   GATE
   19 - $D413 - 54291 - (W) AD3              Channel 3 Attack             |       Channel 3 Decay
   20 - $D414 - 54292 - (W) SR3              Channel 3 Sustain            |       Channel 3 Release
   21 - $D415 - 54293 - (W) FCLO             unused                       |       Filter Cutoff Low (FC2-FC0)
   22 - $D416 - 54294 - (W) FCHI      Filter Cutoff High (FC10-FC3)
   23 - $D417 - 54295 - (W) Res/Filt  Filter Resonance  Filt Ex   Filt 3  Filt 2                           Filt 1
   24 - $D418 - 54296 - (W) Mode/Vol  Ch3Off    HighPass  BandPass  LoPass|             Volume
   25 - $D419 - 54297 - (R) POTX                        Potentiometer X
   26 - $D41A - 54298 - (R) POTY                        Potentiometer Y
   27 - $D41B - 54299 - (R) OSC3                        Channel 3 Oscillator
   28 - $D41C - 54300 - (R) ENV3                        Channel 3 Envelope
  ------------------------------------------------------------------------------------------------

   The GATE bit controls the Envelope Generator. When this bit is set to 1, it triggers the Envelope Generator 
   and the ATTACK/DECAY/SUSTAIN cycle begins. When the bit is reset to zero, the RELEASE cycle begins. 
   Setting bits 4,5 or 6 to 1 selects that particular waveform.

*/


void play_spacechip()
{
  int x = 0;
  int delay = 2;
 
  for (x=0;x<20;x++)
  {
      wrSID(0b00000001 , 0b000101000); //POKE 54273, 40     - Note to play
      _delay_ms(delay);  

      wrSID(0b00000001 , 0b01010000); //POKE 54273, 80     - Note to play
      _delay_ms(delay); 

      wrSID(0b00000001 , 0b01100100); //POKE 54273, 100     - Note to play
      _delay_ms(delay); 
      
      wrSID(0b00000001 , 0b01111000); //POKE 54273, 120     - Note to play
      _delay_ms(delay); 
      
      wrSID(0b00000001 , 0b10001100); //POKE 54273, 140     - Note to play
      _delay_ms(delay); 
     
      wrSID(0b00000001 , 0b10100000);  //POKE 54273, 160     - Note to play
      _delay_ms(delay);
  } 
}

/***************************************************/

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

/***************************************************/

void voice1_scale()
{

      int delay     = 10;
      int num_loops = 2;

      wrSID(0b00000100, 0b00010001 );// 54276,17      - triangle wave

      for (int x= 0;x<num_loops;x++)
      {
      
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

      
      wrSID(0b00000100, 0b00100001 );//54276,33      - sawtooth wave

      for (int x= 0;x<num_loops;x++)
      {
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

/***************************************************/

void voice2_scale()
{

      int delay     = 3;
      int num_loops = 255;

      //wrSID(0b00001011, 0b00100001 );// 54283,33  - sawtooth wave
      //wrSID(0b00001011, 0b00100001 );// 54283,17  - triangle wave
     
      //wrSID(0b00001000, 0b00001000 );  //54280  - pulse width (l)     
      //wrSID(0b00001001, 0b00001000 );  //54281  - pulse width (h)


      //MULTI VOICE TEST 
      //wrSID(0b00000001, 0b00110000); // 54273,   - voice1 Note to play

      // wrSID(0b00000111, 0b10000010 ); // (l) 54279       - Set Frequency of voice 2
      // wrSID(0b00001000, 0b00101000 ); // (h) 54280, 40   - Note to play
      // _delay_ms(delay);  

      for (int x= 0;x<num_loops;x++)
      {
        //wrSID(0b00001000, 0 );  //54280  - pulse width (l)     
        //wrSID(0b00001001, x );  //54281  - pulse width (h)
        _delay_ms(delay); 
       
        //wrSID(0b00001000, 0b00100000 );  //54280  - pulse width (l)     
        //wrSID(0b00001001, 0b00100000 );  //54281  - pulse width (h)

      }

}


/***************************************************/

void sweep_freqency_v1()
{
    int delay = 5;
    int steps = 255;

    wrSID(0b00011000, 0b00001111 ); // Set maximum Volume
    
    //wrSID(0b00000100, 0b00010001 );// 54276,17      - triangle wave
    wrSID(4, 17 );// 54276,17      - triangle wave

    int x,y = 0;

    //DEBUG does not work 
    //for (x = 0;x<steps;x++)
    //{
    //    for (y= 0;y<steps;y++)
    //    {
    //      poke(0,y);poke(1,x);
    //      _delay_ms(delay); 
    //    }
    //}

    for (int x= 0;x<steps;x++)
    {
      wrSID(1,x);//1 is HIGH register (zero indexed) 
      _delay_ms(delay); 
    }
      

}

/***************************************************/

void sweep_pulse_width_v1()
{
    int delay = 20;//ms 
    int steps = 255;

    wrSID(0b00011000, 0b00001111 ); // Set maximum Volume
 
    //wrSID(1, 40); // ,   - voice1 Note to play

    for (int x= 0;x<steps;x++)
    {

      //wrSID(2, 0 );  // 54274  - pulse width (l)     
      wrSID(3, x );  // 54275  - pulse width (h)

      _delay_ms(delay); 
    }
      

}


/***************************************************/


//used as a hello user and to test RGB led connections
void test_leds(void){

   int a = 0;
   for (a=0;a<5;a++)
   {
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

/***************************************************/
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

/***************************************************/
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

/***************************************************/
void setup_sid_voices()
{

    // 17= TRIANGLE , 33= SAW, 65= PULSE, 129= NOISE 

    //********************** setup SID parameters   *************************
    // SET GLOBAL VOLUME 
    
    //wrSID(0b00011000, 0b00001111 );       // (24) 54296, 15  Set maximum Volume
    //wrSID(0b00011000, 15 );               // (24) 54296, 15  Set maximum Volume
 
    //********************** Voice 1 parameters   *************************
      // OSCILLATOR  SETUP
      wrSID(0b00000000, 0b000000000);       // (0) 54272, 0    - low  inital frequency
      wrSID(0b00000001, 0b000100000);       // (1) 54273, 32   - high inital frequency
      //Voice1 ADSR *****
      wrSID(0b00000101, 0b00001001 );       // (5) 54277       - Set Attack/Decay voice 1
      wrSID(0b00000110, 0b10000000 );       // (6) 54278       - Set Sustain/Release voice 1
      //**** Voice1 WAVE ENABLE  *****
      wrSID(0b00000100, 0b00010001 );       // (4) 54276,17    - V1 Triangle waveform and Gate bits 
      //wrSID(0b00000100, 0b00100001 );     // (4) 54276,33    - V1 Sawtooth waveform and Gate bits 
      //wrSID(0b00000100, 0b01000001 );     // (4) 54276,65    - V1 Pulse waveform and Gate bits
      //wrSID(0b00000100,    );             // (4) 54276,128   - V1 Noise waveform and Gate bits
      // these only work with pulse type?      
      wrSID(0b00000010, 0b00000010 );       // (2) 54274       - pulse width (l)     
      wrSID(0b00000011, 0b00001000 );       // (3) 54275       - pulse width (h)
      //**** V1 ENVELOPE SETUP******** 
      //**** V1 FILTER SETUP ********* 

    //********************** Voice 2 parameters   *************************
    
      wrSID(0b00000111, 0b000000000);       // (7) 54279, 0    - Set inital frequency
      wrSID(0b00001000, 0b000101000);       // (8) 54280, 40   - Set inital frequency
      // wrSID(0b00001011, 0b01000001 );    // (11) 54283,65     CR - enable tone by setting waveform
      wrSID(0b00001100, 0b00001001 );       // (12) 54284        Set Attack/Decay voice 2
      wrSID(0b00001101, 0b10000000 );       // (13) 54285        Set Sustain/Release voice 2
      //wrSID(0b00001011, 0b00010001 );     // (11) 54290,17   - V2 Triangle waveform and Gate bits 
      //wrSID(0b00001011, 0b00100001 );     // (11) 54290,33   - V2 Sawtooth waveform and Gate bits 
      wrSID(0b00001011, 0b01000001 );       // (11) 54290,65   - V2 Pulse waveform and Gate bits 
      // these only work with pulse type?
      wrSID(0b00001001, 0b00000010 );       // (9) 54281       - pulse width (l)
      wrSID(0b00001010, 0b00001000 );       // (10) 54282      - pulse width (h)
    
   
    //********************** Voice 3 parameters   *************************
      wrSID(0b00001110, 0b000000000);       // (14) 54286,0    - Set inital frequency
      wrSID(0b00001111, 0b000101000);       // (15) 54286,40   - Set inital frequency
      //wrSID(0b00010010, 0b01000001 );     // (18) 54290,65     CR - enable tone by setting pulse ?
      wrSID(0b00010011, 0b00001001 );       // (19) 54291        Set Attack/Decay voice 3
      wrSID(0b00010100, 0b10000000 );       // (20) 54292        Set Sustain/Release voice 3
      //wrSID(0b00010010, 0b00010001 );     // (18) 54290,17   - V2 Triangle waveform and Gate bits 
      //wrSID(0b00010010, 0b00100001 );     // (18) 54290,33   - V2 Sawtooth waveform and Gate bits 
      wrSID(0b00010010, 0b01000001 );       // (18) 54290,65   - V2 Pulse waveform and Gate bits 
      wrSID(0b00010000, 0b00000010 );       // (16) 54280      - pulse width (l)     
      wrSID(0b00010001, 0b00001000 );       // (17) 54281      - pulse width (h)


}





void poketest(void)
{
    // 10 FOR L=54272 TO 54296:POKE L,0:NEXT Clears the SID chip
    // 20 POKE 54296,15  Set maximum volume
    // 30 POKE 54277,64  Set ATTACK/DECAY
    // 40 POKE 54273,162:POKE 54272,37 POKE one note in voice 1
    // 50 PRINT"PRESS ANY KEY" Screen message
    // 60 GET K$:IF K$="" THEN 60  Check the keyboard
    // 70 POKE 54276,17:FOR T=1 TO 200:NEXT  Start triangle waveform
    // 80 POKE 54276,16:FOR T=1 TO 50:NEXT Stop note
    // 90 GOTO 50


    // VOICE1 //-------------------------------------------- 
    poke( 54296 ,15  );    //  Set maximum volume
    poke( 54277 , 240  );  //  Set ATTACK/DECAY
    poke( 54278 , 240  );  //  Set SUSTAIN/RELEASE
    poke( 54273 , 50 );    //
    poke( 54272 , 0  );    // POKE one note in voice 1
    poke( 54274 , 203  );  //pulse width 
    poke( 54276 ,65  );    //choose pulse type and set gate bit (first bit is gate 0x1)
    // //  wrSID(4,65  );  //same poke, expressed as a direct register write 
    
    // VOICE2 //--------------------------------------------
    poke( 54296 ,15  );    //  Set maximum volume
    poke( 54285 , 240  );  //  Set SUSTAIN/RELEASE
    poke( 54284 , 240  );  //  Set ATTACK/DECAY
    poke( 54280 , 162 );   //    
    poke( 54279 , 100  );  // POKE one note in voice 1
    poke( 54281 , 0  );    // pulse width 
    poke( 54282 , 50  );   // pulse width 
    poke( 54283 , 33  );   // choose pulse type and set gate bit (first bit is gate 0x1)

    // VOICE3 //--------------------------------------------
    poke( 54296 ,15  );    //  Set maximum volume
    poke( 54291 , 240  );  //  Set ATTACK/DECAY
    poke( 54292 , 240  );  //  Set SUSTAIN/RELEASE
    poke( 54286 , 0  );  // POKE one note in voice 1
    poke( 54287 , 255 );   //
    poke( 54288 , 203  );  //pulse width 
    poke( 54290 , 65  );   // choose pulse type and set gate bit (first bit is gate 0x1)

    // poke(54276,16); //stop voice1
    // poke(54283,16); //stop voice2
    // poke(54290,16); //stop voice3

}

void poketest2(void)
{

    // VOICE1 //-------------------------------------------- 
    poke( 54296 ,15  );    //  Set maximum volume
    poke( 54277 , 240  );  //  Set ATTACK/DECAY
    poke( 54278 , 240  );  //  Set SUSTAIN/RELEASE
    
    poke( 54273 , 100 );   //
    poke( 54272 , 0  );  // POKE one note in voice 1
    
    poke( 54274 , 103  ); //pulse width 
    poke( 54276 ,65  );   //choose pulse type and set gate bit (first bit is gate 0x1)
    // //  wrSID(4,65  );   //same poke, expressed as a direct register write 

    poke( 54293 , 100  );   // filter width
    poke( 54295 , 100  );    // filter width

    uint16_t z = 0;

    while(1){
        for (z=0;z<50;z++)
        {
           poke( 54295 , z  );    // filter resonance
        }
    }
}

/***************************************************/

/*
   example to set a note across two 8 bit registers from a single 16 bit number 
   splits a 16 bit into two 8 bits 
*/
void voice_one_note(uint16_t note)
{
    //we really want 8 bit, but poke only accepts 16 cast to 8 
    uint16_t high  = ((uint16_t)note >> 0) & 0xFF;  // shift by 0 not needed, of course, just stylistic
    uint16_t low   = ((uint16_t)note >> 8) & 0xFF;
    poke( 54272 , low  );  // POKE one note in voice 1
    poke( 54273 , high );  //

    // you can do the same thing with 8 bit if you dont use poke() 
    // uint8_t high  = ((uint8_t)note >> 0) & 0xFF;  // shift by 0 not needed, of course, just stylistic
    // uint8_t low   = ((uint8_t)note >> 8) & 0xFF;
    // wrSID( 0 , low  );  
    // wrSID( 1 , high ); 

}

void test_notecmd(void)
{
    poke( 54296 ,15  );    //  Set maximum volume
    poke( 54277 , 240  );  //  Set ATTACK/DECAY
    poke( 54278 , 240  );  //  Set SUSTAIN/RELEASE
    poke( 54273 , 50 );   //
    poke( 54272 , 100  );  // POKE one note in voice 1
    poke( 54274 , 203  ); //pulse width 
    poke( 54276 ,65  );   //choose pulse type and set gate bit (first bit is gate 0x1)
    uint16_t x = 0;

    while(1)
    {
        for(x=0;x<255;x++){
            voice_one_note(x);
            delay();
        }
        for(x=255;x>0;x--){
            voice_one_note(x);
            delay();
        }
    }
}


void voice_sync_test(void)
{

  // 10 s=54272
  // 20 forl=0to24:pokes+l,0:next
  // 30 pokes+1,100
  // 40 pokes+5,219
  // 50 pokes+15,28
  // 60 pokes+24,15
  // 70 pokes+4,19
  // 80 fort=1to5000:next
  // 90 pokes+4,18
  // 100 fort=1to1000:next:pokes+24,0
 
  poke(54273,100); // Set high frequency voice 1. 
  poke(54277,219); // Set Attack/Decay for voice 1 (A=13, D=11).
  poke(54287,28);  // Set high frequency voice 3.
  poke(54296,15);  // set volume.
  poke(54276,19);  // Set start triangle, sync waveform control for voice 1. 
  //fort=1to5000:next
  poke(54276,18);  //Set stop triangle, sync waveform control for voice 1.

}


void voice_ring_test(void)
{
    // 30 pokes+1,130
    // 40 pokes+5,9
    // 50 pokes+15,30
    // 60 pokes+24,15
    // 70 forl=1to12:pokes+4,21
    // 80 fort=1to1000:next:pokes+4,20
    // 90 fort=1to1000:next:next

    poke(54273, 30); // Set high frequency for voice 1
    poke(54277, 9  ); // Set Attack/Decay for voice 1 (A=0, D=9).
    poke(54287, 230 ); // Set high frequency for voice 3.
    poke(54296,15);  // set volume.

    _delay_ms(100);    // forl=1to12:pokes+4,21
    poke(54276,21);  // set stop triangle, ring mod.

    _delay_ms(100);   // fort=1to1000:next:pokes+4,20
    poke(54276,20);  // next ding.  

}


/***************************************************/

int main (void)
{


    enable_timer_isr(); //activate timer interrupt to pulse SID clock pin 
    init_SID_bus();     //setup AVR ports to send commands to  SID 
    sid_clear_registers(); //poke 53272+24,0 

    
    //setup_sid_voices();
    
    // test_leds();     // alert user we are online and ready to play
    //test_addr_bus(); // flash each bit in address bus

    // VOICE1 //-------------------------------------------- 
    poke( 54296 , 15  );    //  Set maximum volume
    poke( 54277 , 240  );  //  Set ATTACK/DECAY
    poke( 54278 , 100  );  //  Set SUSTAIN/RELEASE

    poke( 54272 , 200  );    // POKE one note in voice 1
    poke( 54273 , 150 );     // POKE one note in voice 1
   
    poke( 54274 , 153  );   // pulse width 
    poke( 54276 , 65  );    // choose waveform type and set gate bit (first bit is gate 0x1)
    

    /* 
    // // VOICE2 //--------------------------------------------
    poke( 54296 , 15  );    //  Set maximum volume
    poke( 54285 , 240  );  //  Set SUSTAIN/RELEASE
    poke( 54284 , 240  );  //  Set ATTACK/DECAY
    poke( 54280 , 162 );   //    
    poke( 54279 , 100  );  // POKE one note in voice 2
    poke( 54281 , 0  );    // pulse width 
    poke( 54282 , 50  );   // pulse width 
    poke( 54283 , 65  );   // choose waveform type and set gate bit (first bit is gate 0x1)
    

    // VOICE3 //--------------------------------------------
    poke( 54296 , 15  );   //  Set maximum volume
    poke( 54291 , 240  );  //  Set ATTACK/DECAY
    poke( 54292 , 240  );  //  Set SUSTAIN/RELEASE
    poke( 54286 , 0  );    // POKE one note in voice 3
    poke( 54287 , 255  );  //
    poke( 54288 , 203  );  // pulse width 
    poke( 54290 , 65  );   // choose waveform type and set gate bit (first bit is gate 0x1)
    */

   while(1)
   {
    
      sweep_pulse_width_v1();
      
      //sweep_freqency_v1();

      //test_notecmd();

      //poketest();

      //poketest2();

      //voice_ring_test();

      //voice_sync_test();

   }



 

} 



