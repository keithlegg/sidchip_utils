# sidchip_utils

![alt text](https://raw.githubusercontent.com/keithlegg/sidchip_utils/main/images/sidthing.png) 


If you ever get the chance to purchase 30 rusty old SID chips from an engineer who worked at Commodore .... 

DONT! Just put your energy into something else.  




This is my collection of tools, references files, and errata making those old chips sing.

What it is:

siduino - Kicad project / Gerbers 
          A one off PCB design thats an arduino (atmega328p) that has a SID chip on it 
          technically you could program it with the arduino tools if you mapped the pins out properly, but I havent tried
          it has a 12V and 5V power bus to satisfy the analog-y power needs of the old chips. They run HOT. 

siduino firmwware - AVR firmware to issue commands to the SID chip from an AtMega328

sidcom            - unfinished. A aerial protocol to talk to the SID chip from a modern machine. The board is flawed, the TX/RX
                    pins on the AVR ahre the lower two bits of the SID data bus, so a new board is needed before this can be used. A prototype board is under development. 


python tools      - Meh 



useful references 
      http://www.oxyron.de/html/registers_sid.html
  


If you are crazy enough to want to build one yourself (beware this revision has the TX/RX flaw): 

https://oshpark.com/profiles/klegg

