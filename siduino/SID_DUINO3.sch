EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "noname.sch"
Date "19 jun 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SID_DUINO3-rescue:CONN_2-SID_DUINO3-rescue P3
U 1 1 520D5550
P 850 3350
F 0 "P3" H 950 3600 40  0000 C CNN
F 1 "UART" H 750 3600 40  0000 C CNN
F 2 "" H 850 3350 60  0001 C CNN
F 3 "" H 850 3350 60  0000 C CNN
	1    850  3350
	-1   0    0    1   
$EndComp
Text Label 1250 3250 0    60   ~ 0
TX_D0
Text Label 1250 3450 0    60   ~ 0
RX_D1
$Comp
L SID_DUINO3-rescue:DIODE-SID_DUINO3-rescue D2
U 1 1 520D5556
P 1750 1600
F 0 "D2" H 1750 1700 40  0000 C CNN
F 1 "DIODE" H 1750 1500 40  0000 C CNN
F 2 "" H 1750 1600 60  0001 C CNN
F 3 "~" H 1750 1600 60  0000 C CNN
	1    1750 1600
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:CONN_2-SID_DUINO3-rescue P5
U 1 1 520D5557
P 1200 1600
F 0 "P5" V 1150 1600 40  0000 C CNN
F 1 "5V_IN" V 1250 1600 40  0000 C CNN
F 2 "" H 1200 1600 60  0001 C CNN
F 3 "" H 1200 1600 60  0000 C CNN
	1    1200 1600
	-1   0    0    1   
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C2
U 1 1 520D5558
P 2050 1600
F 0 "C2" H 2050 1700 40  0000 L CNN
F 1 "C" H 2056 1515 40  0000 L CNN
F 2 "" H 2088 1450 30  0001 C CNN
F 3 "~" H 2050 1600 60  0000 C CNN
	1    2050 1600
	1    0    0    -1  
$EndComp
Text Label 2200 1400 0    60   ~ 0
5vin
Text Label 2200 1800 0    60   ~ 0
GND
$Comp
L SID_DUINO3-rescue:CONN_2-SID_DUINO3-rescue P4
U 1 1 520D5559
P 1200 1050
F 0 "P4" V 1150 1050 40  0000 C CNN
F 1 "12V_IN" V 1250 1050 40  0000 C CNN
F 2 "" H 1200 1050 60  0001 C CNN
F 3 "" H 1200 1050 60  0000 C CNN
	1    1200 1050
	-1   0    0    1   
$EndComp
$Comp
L SID_DUINO3-rescue:DIODE-SID_DUINO3-rescue D1
U 1 1 520D555A
P 1750 1050
F 0 "D1" H 1750 1150 40  0000 C CNN
F 1 "DIODE" H 1750 950 40  0000 C CNN
F 2 "" H 1750 1050 60  0001 C CNN
F 3 "~" H 1750 1050 60  0000 C CNN
	1    1750 1050
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C1
U 1 1 520D555B
P 2000 1050
F 0 "C1" H 2000 1150 40  0000 L CNN
F 1 "C" H 2006 965 40  0000 L CNN
F 2 "" H 2038 900 30  0001 C CNN
F 3 "~" H 2000 1050 60  0000 C CNN
	1    2000 1050
	1    0    0    -1  
$EndComp
Text Label 2100 1250 0    60   ~ 0
GND
$Comp
L SID_DUINO3-rescue:R-SID_DUINO3-rescue R1
U 1 1 520D555D
P 1200 5600
F 0 "R1" V 1280 5600 40  0000 C CNN
F 1 "R" V 1207 5601 40  0000 C CNN
F 2 "" V 1130 5600 30  0001 C CNN
F 3 "~" H 1200 5600 30  0000 C CNN
	1    1200 5600
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:LED-SID_DUINO3-rescue D3
U 1 1 520D555E
P 1700 5600
F 0 "D3" H 1700 5700 50  0000 C CNN
F 1 "LED" H 1700 5500 50  0000 C CNN
F 2 "" H 1700 5600 60  0001 C CNN
F 3 "~" H 1700 5600 60  0000 C CNN
	1    1700 5600
	1    0    0    -1  
$EndComp
Text Label 850  5600 0    60   ~ 0
5V
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR01
U 1 1 520D555F
P 1900 5750
F 0 "#PWR01" H 1900 5750 30  0001 C CNN
F 1 "GND" H 1900 5680 30  0001 C CNN
F 2 "" H 1900 5750 60  0000 C CNN
F 3 "" H 1900 5750 60  0000 C CNN
	1    1900 5750
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:ATMEGA328P-A-SID_DUINO3-rescue IC1
U 1 1 520D5560
P 4850 2400
F 0 "IC1" H 4100 3650 40  0000 L BNN
F 1 "ATMEGA328P-A" H 5250 1000 40  0000 L BNN
F 2 "" H 4850 2400 30  0001 C CIN
F 3 "" H 4850 2400 60  0000 C CNN
	1    4850 2400
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:SW_PUSH-SID_DUINO3-rescue SW1
U 1 1 520D5561
P 7950 2750
F 0 "SW1" H 8100 2860 50  0000 C CNN
F 1 "SW_PUSH" H 7950 2670 50  0000 C CNN
F 2 "" H 7950 2750 60  0001 C CNN
F 3 "~" H 7950 2750 60  0000 C CNN
	1    7950 2750
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CP1-SID_DUINO3-rescue C7
U 1 1 520D5562
P 3300 1150
F 0 "C7" H 3350 1250 50  0000 L CNN
F 1 "4.7uf" H 3350 1050 50  0000 L CNN
F 2 "" H 3300 1150 60  0001 C CNN
F 3 "~" H 3300 1150 60  0000 C CNN
	1    3300 1150
	0    1    1    0   
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C6
U 1 1 520D5563
P 3300 950
F 0 "C6" H 3300 1050 40  0000 L CNN
F 1 ".1uf" H 3306 865 40  0000 L CNN
F 2 "" H 3338 800 30  0001 C CNN
F 3 "~" H 3300 950 60  0000 C CNN
	1    3300 950 
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:R-SID_DUINO3-rescue 10K1
U 1 1 520D5564
P 7500 2500
F 0 "10K1" V 7580 2500 40  0000 C CNN
F 1 "R" V 7507 2501 40  0000 C CNN
F 2 "" V 7430 2500 30  0001 C CNN
F 3 "~" H 7500 2500 30  0000 C CNN
	1    7500 2500
	-1   0    0    1   
$EndComp
$Comp
L SID_DUINO3-rescue:LED-SID_DUINO3-rescue D4
U 1 1 520D5565
P 1850 5100
F 0 "D4" H 1850 5200 50  0000 C CNN
F 1 "LED" H 1850 5000 50  0000 C CNN
F 2 "" H 1850 5100 60  0001 C CNN
F 3 "~" H 1850 5100 60  0000 C CNN
	1    1850 5100
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR02
U 1 1 520D5567
P 8550 3000
F 0 "#PWR02" H 8550 3000 30  0001 C CNN
F 1 "GND" H 8550 2930 30  0001 C CNN
F 2 "" H 8550 3000 60  0000 C CNN
F 3 "" H 8550 3000 60  0000 C CNN
	1    8550 3000
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CRYSTAL-SID_DUINO3-rescue X1
U 1 1 520D5568
P 6650 2000
F 0 "X1" H 6650 2150 60  0000 C CNN
F 1 "16Mhz" H 6650 1850 60  0000 C CNN
F 2 "" H 6650 2000 60  0001 C CNN
F 3 "~" H 6650 2000 60  0000 C CNN
	1    6650 2000
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR03
U 1 1 520D5569
P 7250 2000
F 0 "#PWR03" H 7250 2000 30  0001 C CNN
F 1 "GND" H 7250 1930 30  0001 C CNN
F 2 "" H 7250 2000 60  0000 C CNN
F 3 "" H 7250 2000 60  0000 C CNN
	1    7250 2000
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR04
U 1 1 520D556A
P 2900 1350
F 0 "#PWR04" H 2900 1350 30  0001 C CNN
F 1 "GND" H 2900 1280 30  0001 C CNN
F 2 "" H 2900 1350 60  0000 C CNN
F 3 "" H 2900 1350 60  0000 C CNN
	1    2900 1350
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C5
U 1 1 520D556C
P 2900 2300
F 0 "C5" H 2900 2400 40  0000 L CNN
F 1 "C" H 2906 2215 40  0000 L CNN
F 2 "" H 2938 2150 30  0001 C CNN
F 3 "~" H 2900 2300 60  0000 C CNN
	1    2900 2300
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CONN_3X2-SID_DUINO3-rescue P10
U 1 1 520D556D
P 1400 2650
F 0 "P10" H 1400 2900 50  0000 C CNN
F 1 "ICSP" V 1400 2700 40  0000 C CNN
F 2 "" H 1400 2650 60  0001 C CNN
F 3 "" H 1400 2650 60  0000 C CNN
	1    1400 2650
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR05
U 1 1 520D556F
P 1950 2850
F 0 "#PWR05" H 1950 2850 30  0001 C CNN
F 1 "GND" H 1950 2780 30  0001 C CNN
F 2 "" H 1950 2850 60  0000 C CNN
F 3 "" H 1950 2850 60  0000 C CNN
	1    1950 2850
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR06
U 1 1 520D5570
P 3750 3800
F 0 "#PWR06" H 3750 3800 30  0001 C CNN
F 1 "GND" H 3750 3730 30  0001 C CNN
F 2 "" H 3750 3800 60  0000 C CNN
F 3 "" H 3750 3800 60  0000 C CNN
	1    3750 3800
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR07
U 1 1 520D5571
P 2300 5200
F 0 "#PWR07" H 2300 5200 30  0001 C CNN
F 1 "GND" H 2300 5130 30  0001 C CNN
F 2 "" H 2300 5200 60  0000 C CNN
F 3 "" H 2300 5200 60  0000 C CNN
	1    2300 5200
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:R-SID_DUINO3-rescue R2
U 1 1 520D5572
P 1250 5100
F 0 "R2" V 1330 5100 40  0000 C CNN
F 1 "330" V 1257 5101 40  0000 C CNN
F 2 "" V 1180 5100 30  0001 C CNN
F 3 "~" H 1250 5100 30  0000 C CNN
	1    1250 5100
	0    -1   -1   0   
$EndComp
Text Label 5950 1400 0    60   ~ 0
D9
Text Label 5950 1500 0    60   ~ 0
D10
Text Label 5950 1600 0    60   ~ 0
D11
Text Label 5950 1700 0    60   ~ 0
D12
Text Label 5950 1800 0    60   ~ 0
D13
Text Label 5950 2150 0    60   ~ 0
A0
Text Label 5950 2250 0    60   ~ 0
A1
Text Label 5950 2350 0    60   ~ 0
A2
Text Label 5950 2450 0    60   ~ 0
A3
Text Label 5950 2550 0    60   ~ 0
A4
Text Label 5950 2650 0    60   ~ 0
A5
Text Label 5900 3100 0    60   ~ 0
D2
Text Label 5900 3200 0    60   ~ 0
D3
Text Label 5900 3300 0    60   ~ 0
D4
Text Label 5900 3400 0    60   ~ 0
D5
Text Label 5900 3500 0    60   ~ 0
D6
Text Label 5900 3600 0    60   ~ 0
D7
Text Label 3700 2650 0    60   ~ 0
A6
Text Label 3700 2750 0    60   ~ 0
A7
Text Label 5950 1300 0    60   ~ 0
D8
Text Label 800  5100 0    60   ~ 0
D13
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue U5
U 1 1 520D5577
P 7000 1700
F 0 "U5" H 7000 1800 40  0000 L CNN
F 1 "18pf" H 7006 1615 40  0000 L CNN
F 2 "" H 7038 1550 30  0001 C CNN
F 3 "~" H 7000 1700 60  0000 C CNN
	1    7000 1700
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue U6
U 1 1 520D5578
P 7000 2300
F 0 "U6" H 7000 2400 40  0000 L CNN
F 1 "18pf" H 7006 2215 40  0000 L CNN
F 2 "" H 7038 2150 30  0001 C CNN
F 3 "~" H 7000 2300 60  0000 C CNN
	1    7000 2300
	0    -1   -1   0   
$EndComp
Text Label 5950 2900 0    60   ~ 0
TX_D0
Text Label 5950 3000 0    60   ~ 0
RX_D1
NoConn ~ 3600 2650
NoConn ~ 3600 2750
Text Label 3800 750  1    60   ~ 0
5V
Text Label 1900 2500 0    60   ~ 0
5V
Text Label 7500 2100 1    60   ~ 0
5V
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR08
U 1 1 520D82E7
P 2900 2500
F 0 "#PWR08" H 2900 2500 30  0001 C CNN
F 1 "GND" H 2900 2430 30  0001 C CNN
F 2 "" H 2900 2500 60  0000 C CNN
F 3 "" H 2900 2500 60  0000 C CNN
	1    2900 2500
	1    0    0    -1  
$EndComp
Text Label 800  2700 0    60   ~ 0
RST
Text Label 800  2500 0    60   ~ 0
D12
Text Label 1900 2600 0    60   ~ 0
D11
Text Label 800  2600 0    60   ~ 0
D13
Text Notes 700  2250 0    60   ~ 12
ICSP\n
Text Notes 1100 700  0    59   ~ 12
Power in\n
Text Notes 750  3050 0    59   ~ 12
Data ports\n
Text Notes 800  5350 0    60   ~ 12
power LED\n\n
Text Notes 4100 1000 0    79   ~ 16
Atmega328p\n\n
$Comp
L SID_DUINO3-rescue:MOS6581-SID_DUINO3-rescue U1
U 1 1 557F477A
P 8300 6400
F 0 "U1" H 8000 6300 60  0000 C CNN
F 1 "MOS6581" H 8400 6300 60  0000 C CNN
F 2 "" H 8300 6400 60  0001 C CNN
F 3 "~" H 8300 6400 60  0000 C CNN
	1    8300 6400
	1    0    0    -1  
$EndComp
Text Label 2150 850  0    60   ~ 0
12vin
$Comp
L SID_DUINO3-rescue:CONN_1-SID_DUINO3-rescue aux_areff1
U 1 1 557F4D6E
P 3350 2200
F 0 "aux_areff1" V 3400 2100 40  0000 L CNN
F 1 "CONN_1" H 3350 2255 30  0001 C CNN
F 2 "" H 3350 2200 60  0001 C CNN
F 3 "" H 3350 2200 60  0000 C CNN
	1    3350 2200
	0    1    1    0   
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C9
U 1 1 557F5E4D
P 7200 4400
F 0 "C9" H 7200 4500 40  0000 L CNN
F 1 "C" H 7206 4315 40  0000 L CNN
F 2 "" H 7238 4250 30  0001 C CNN
F 3 "~" H 7200 4400 60  0000 C CNN
	1    7200 4400
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C10
U 1 1 557F5E5C
P 7200 4700
F 0 "C10" H 7200 4800 40  0000 L CNN
F 1 "C" H 7206 4615 40  0000 L CNN
F 2 "" H 7238 4550 30  0001 C CNN
F 3 "~" H 7200 4700 60  0000 C CNN
	1    7200 4700
	0    -1   -1   0   
$EndComp
NoConn ~ 9250 5150
NoConn ~ 9250 5000
NoConn ~ 9250 4700
Text Label 9150 4400 0    60   ~ 0
12v
Text Label 9200 4850 0    60   ~ 0
5v
Text Label 9200 4550 0    60   ~ 0
audio out
Text Label 9150 6350 0    60   ~ 0
TX_D0
Text Label 9150 6200 0    60   ~ 0
RX_D1
Text Label 9150 6050 0    60   ~ 0
D2
Text Label 9150 5900 0    60   ~ 0
D3
Text Label 9150 5750 0    60   ~ 0
D4
Text Label 9150 5600 0    60   ~ 0
D5
Text Label 9150 5450 0    60   ~ 0
D6
Text Label 9150 5300 0    60   ~ 0
D7
Text Label 7450 5150 0    60   ~ 0
A2
Text Label 7450 5300 0    60   ~ 0
A1
Text Label 7450 5450 0    60   ~ 0
A0
Text Notes 700  4900 0    59   ~ 12
Status LED\n
$Comp
L SID_DUINO3-rescue:CONN_6-SID_DUINO3-rescue P6
U 1 1 557FE0A5
P 850 4150
F 0 "P6" H 1000 4550 60  0000 C CNN
F 1 "FTDI" H 750 4550 60  0000 C CNN
F 2 "" H 850 4150 60  0001 C CNN
F 3 "" H 850 4150 60  0000 C CNN
	1    850  4150
	-1   0    0    1   
$EndComp
Text Label 7450 5600 0    60   ~ 0
D8
Text Label 7450 5750 0    60   ~ 0
D9
Text Label 7450 5900 0    60   ~ 0
D10
Text Label 7450 6050 0    60   ~ 0
D11
Text Label 7450 6200 0    60   ~ 0
D12
Text Notes 7000 4100 0    63   ~ 13
SID\n
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR09
U 1 1 55826711
P 7450 6550
F 0 "#PWR09" H 7450 6550 30  0001 C CNN
F 1 "GND" H 7450 6480 30  0001 C CNN
F 2 "" H 7450 6550 60  0000 C CNN
F 3 "" H 7450 6550 60  0000 C CNN
	1    7450 6550
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR010
U 1 1 558267AB
P 1350 4500
F 0 "#PWR010" H 1350 4500 30  0001 C CNN
F 1 "GND" H 1350 4430 30  0001 C CNN
F 2 "" H 1350 4500 60  0000 C CNN
F 3 "" H 1350 4500 60  0000 C CNN
	1    1350 4500
	1    0    0    -1  
$EndComp
Text Label 1300 4100 0    60   ~ 0
TX_D0
Text Label 1300 4000 0    60   ~ 0
RX_D1
NoConn ~ 1500 3900
NoConn ~ 1500 4200
NoConn ~ 1500 4300
$Comp
L SID_DUINO3-rescue:LM7812-SID_DUINO3-rescue U2
U 1 1 55827B31
P 1500 6850
F 0 "U2" H 1650 6654 60  0000 C CNN
F 1 "LM7812" H 1500 7050 60  0000 C CNN
F 2 "" H 1500 6850 60  0001 C CNN
F 3 "" H 1500 6850 60  0000 C CNN
	1    1500 6850
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:LM7805-SID_DUINO3-rescue U3
U 1 1 55827B40
P 3000 6850
F 0 "U3" H 3150 6654 60  0000 C CNN
F 1 "LM7805" H 3000 7050 60  0000 C CNN
F 2 "" H 3000 6850 60  0001 C CNN
F 3 "" H 3000 6850 60  0000 C CNN
	1    3000 6850
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CONN_2-SID_DUINO3-rescue P1
U 1 1 55827B4F
P 950 1050
F 0 "P1" V 900 1050 40  0000 C CNN
F 1 "12VPWR" V 1000 1050 40  0000 C CNN
F 2 "" H 950 1050 60  0001 C CNN
F 3 "" H 950 1050 60  0000 C CNN
	1    950  1050
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CONN_2-SID_DUINO3-rescue P2
U 1 1 55827B66
P 950 1600
F 0 "P2" V 900 1600 40  0000 C CNN
F 1 "5VPWR" V 1000 1600 40  0000 C CNN
F 2 "" H 950 1600 60  0001 C CNN
F 3 "" H 950 1600 60  0000 C CNN
	1    950  1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 3250 1200 3250
Wire Wire Line
	1400 3450 1200 3450
Wire Wire Line
	1550 1700 1600 1700
Wire Wire Line
	1600 1700 1600 1800
Wire Wire Line
	1550 1500 1600 1500
Wire Wire Line
	1600 1500 1600 1400
Connection ~ 1750 1800
Connection ~ 1750 1400
Wire Wire Line
	1600 1400 1750 1400
Wire Wire Line
	1600 1800 1750 1800
Wire Wire Line
	1550 1150 1650 1150
Wire Wire Line
	1650 1150 1650 1250
Wire Wire Line
	1650 1250 1750 1250
Wire Wire Line
	1550 950  1650 950 
Wire Wire Line
	1650 950  1650 850 
Wire Wire Line
	1650 850  1750 850 
Connection ~ 1750 1250
Connection ~ 1750 850 
Wire Wire Line
	1450 5600 1500 5600
Wire Wire Line
	950  5600 800  5600
Wire Wire Line
	1900 5600 1900 5750
Wire Wire Line
	8250 2750 8550 2750
Wire Wire Line
	8550 2750 8550 3000
Wire Wire Line
	5850 2750 7500 2750
Wire Wire Line
	7500 2700 7500 2750
Wire Wire Line
	7500 2250 7500 2000
Connection ~ 7500 2750
Wire Wire Line
	5850 2000 6350 2000
Wire Wire Line
	6350 2000 6350 2300
Wire Wire Line
	5850 1900 6350 1900
Wire Wire Line
	6350 1900 6350 1700
Connection ~ 6650 2300
Connection ~ 6650 1700
Wire Wire Line
	3800 1600 3950 1600
Wire Wire Line
	3800 1400 3950 1400
Wire Wire Line
	3800 1300 3950 1300
Wire Wire Line
	3800 550  3800 950 
Connection ~ 3800 1400
Connection ~ 3800 1300
Connection ~ 3800 1150
Wire Wire Line
	3500 1150 3800 1150
Wire Wire Line
	3500 950  3800 950 
Wire Wire Line
	3100 950  2900 950 
Wire Wire Line
	2900 950  2900 1150
Wire Wire Line
	3100 1150 2900 1150
Connection ~ 2900 1150
Connection ~ 3800 950 
Wire Wire Line
	2900 1900 3350 1900
Wire Wire Line
	2900 1900 2900 2100
Wire Wire Line
	1000 2600 750  2600
Wire Wire Line
	1000 2700 750  2700
Wire Wire Line
	1800 2500 2150 2500
Wire Wire Line
	1800 2600 2150 2600
Wire Wire Line
	1800 2700 1950 2700
Wire Wire Line
	1950 2700 1950 2850
Wire Wire Line
	5850 1400 6200 1400
Wire Wire Line
	5850 1500 6200 1500
Wire Wire Line
	5850 1600 6200 1600
Wire Wire Line
	5850 1700 6200 1700
Wire Wire Line
	5850 1800 6200 1800
Wire Wire Line
	5850 2150 6200 2150
Wire Wire Line
	5850 2250 6200 2250
Wire Wire Line
	5850 2350 6200 2350
Wire Wire Line
	5850 2450 6200 2450
Wire Wire Line
	5850 2550 6200 2550
Wire Wire Line
	5850 2650 6200 2650
Wire Wire Line
	5850 3100 6200 3100
Wire Wire Line
	5850 3200 6200 3200
Wire Wire Line
	5850 3300 6200 3300
Wire Wire Line
	5850 3400 6200 3400
Wire Wire Line
	5850 3500 6200 3500
Wire Wire Line
	5850 3600 6200 3600
Wire Wire Line
	3950 2650 3600 2650
Wire Wire Line
	3950 2750 3600 2750
Wire Wire Line
	3950 3400 3750 3400
Wire Wire Line
	3950 3500 3750 3500
Wire Wire Line
	3750 3600 3950 3600
Wire Wire Line
	3750 3400 3750 3500
Connection ~ 3750 3500
Connection ~ 3750 3600
Wire Wire Line
	2300 5100 2300 5200
Wire Wire Line
	5850 1300 6200 1300
Wire Wire Line
	1500 5100 1650 5100
Wire Wire Line
	2050 5100 2300 5100
Wire Wire Line
	1000 5100 700  5100
Wire Wire Line
	6350 2300 6650 2300
Wire Wire Line
	6350 1700 6650 1700
Wire Wire Line
	7200 1700 7200 2000
Wire Wire Line
	7200 2000 7250 2000
Connection ~ 7200 2000
Wire Wire Line
	1000 2500 750  2500
Wire Wire Line
	5850 2900 6250 2900
Wire Wire Line
	5850 3000 6250 3000
Wire Wire Line
	3350 2050 3350 1900
Connection ~ 3350 1900
Wire Wire Line
	7550 5150 7350 5150
Wire Wire Line
	7550 5300 7350 5300
Wire Wire Line
	7550 5450 7350 5450
Wire Wire Line
	7550 5600 7350 5600
Wire Wire Line
	7550 5750 7350 5750
Wire Wire Line
	7550 5900 7350 5900
Wire Wire Line
	7550 6050 7350 6050
Wire Wire Line
	7550 6200 7350 6200
Wire Wire Line
	9050 4400 9250 4400
Wire Wire Line
	9050 4700 9250 4700
Wire Wire Line
	9050 4850 9250 4850
Wire Wire Line
	9050 5000 9250 5000
Wire Wire Line
	9050 5150 9250 5150
Wire Wire Line
	9050 5300 9250 5300
Wire Wire Line
	9050 5450 9250 5450
Wire Wire Line
	9050 5600 9250 5600
Wire Wire Line
	9050 5750 9250 5750
Wire Wire Line
	9050 5900 9250 5900
Wire Wire Line
	9050 6050 9250 6050
Wire Wire Line
	9050 6200 9250 6200
Wire Wire Line
	9050 6350 9250 6350
Wire Wire Line
	7550 4400 7400 4400
Wire Wire Line
	7550 4700 7400 4700
Wire Wire Line
	7550 4550 7000 4550
Wire Wire Line
	7000 4550 7000 4400
Wire Wire Line
	7550 4850 7000 4850
Wire Wire Line
	7000 4850 7000 4700
Wire Wire Line
	1200 3900 1500 3900
Wire Wire Line
	1200 4000 1500 4000
Wire Wire Line
	1200 4100 1500 4100
Wire Wire Line
	1200 4200 1500 4200
Wire Wire Line
	1200 4300 1500 4300
Wire Wire Line
	7550 6350 7450 6350
Wire Wire Line
	7450 6350 7450 6550
Wire Wire Line
	1200 4400 1350 4400
Wire Wire Line
	1350 4400 1350 4500
Wire Wire Line
	1500 7100 1500 7300
Wire Wire Line
	3000 7100 3000 7300
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR011
U 1 1 558280F5
P 3000 7300
F 0 "#PWR011" H 3000 7300 30  0001 C CNN
F 1 "GND" H 3000 7230 30  0001 C CNN
F 2 "" H 3000 7300 60  0000 C CNN
F 3 "" H 3000 7300 60  0000 C CNN
	1    3000 7300
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR012
U 1 1 55828102
P 1500 7300
F 0 "#PWR012" H 1500 7300 30  0001 C CNN
F 1 "GND" H 1500 7230 30  0001 C CNN
F 2 "" H 1500 7300 60  0000 C CNN
F 3 "" H 1500 7300 60  0000 C CNN
	1    1500 7300
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CP-SID_DUINO3-rescue C12
U 1 1 5582823E
P 3400 7100
F 0 "C12" H 3450 7200 40  0000 L CNN
F 1 "CP" H 3450 7000 40  0000 L CNN
F 2 "" H 3500 6950 30  0001 C CNN
F 3 "~" H 3400 7100 300 0000 C CNN
	1    3400 7100
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CP-SID_DUINO3-rescue C11
U 1 1 55828262
P 2600 7100
F 0 "C11" H 2650 7200 40  0000 L CNN
F 1 "CP" H 2650 7000 40  0000 L CNN
F 2 "" H 2700 6950 30  0001 C CNN
F 3 "~" H 2600 7100 300 0000 C CNN
	1    2600 7100
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CP-SID_DUINO3-rescue C4
U 1 1 5582827E
P 1900 7100
F 0 "C4" H 1950 7200 40  0000 L CNN
F 1 "CP" H 1950 7000 40  0000 L CNN
F 2 "" H 2000 6950 30  0001 C CNN
F 3 "~" H 1900 7100 300 0000 C CNN
	1    1900 7100
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:CP-SID_DUINO3-rescue C3
U 1 1 5582828E
P 1100 7100
F 0 "C3" H 1150 7200 40  0000 L CNN
F 1 "CP" H 1150 7000 40  0000 L CNN
F 2 "" H 1200 6950 30  0001 C CNN
F 3 "~" H 1100 7100 300 0000 C CNN
	1    1100 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 6900 1100 6800
Wire Wire Line
	1900 6900 1900 6800
Wire Wire Line
	2600 6900 2600 6800
Wire Wire Line
	3400 6900 3400 6800
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR013
U 1 1 558284E2
P 1100 7300
F 0 "#PWR013" H 1100 7300 30  0001 C CNN
F 1 "GND" H 1100 7230 30  0001 C CNN
F 2 "" H 1100 7300 60  0000 C CNN
F 3 "" H 1100 7300 60  0000 C CNN
	1    1100 7300
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR014
U 1 1 558284F2
P 1900 7300
F 0 "#PWR014" H 1900 7300 30  0001 C CNN
F 1 "GND" H 1900 7230 30  0001 C CNN
F 2 "" H 1900 7300 60  0000 C CNN
F 3 "" H 1900 7300 60  0000 C CNN
	1    1900 7300
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR015
U 1 1 558284F8
P 2600 7300
F 0 "#PWR015" H 2600 7300 30  0001 C CNN
F 1 "GND" H 2600 7230 30  0001 C CNN
F 2 "" H 2600 7300 60  0000 C CNN
F 3 "" H 2600 7300 60  0000 C CNN
	1    2600 7300
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR016
U 1 1 558284FE
P 3400 7300
F 0 "#PWR016" H 3400 7300 30  0001 C CNN
F 1 "GND" H 3400 7230 30  0001 C CNN
F 2 "" H 3400 7300 60  0000 C CNN
F 3 "" H 3400 7300 60  0000 C CNN
	1    3400 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 6800 950  6800
Wire Wire Line
	2600 6800 2500 6800
Text Label 950  6800 0    60   ~ 0
12vin
Text Label 2000 6800 0    60   ~ 0
12v
Text Label 2500 6800 0    60   ~ 0
5vin
Text Label 3450 6800 0    60   ~ 0
5v
Wire Wire Line
	9050 4550 9250 4550
NoConn ~ 600  1700
NoConn ~ 600  1500
NoConn ~ 600  1150
NoConn ~ 600  950 
$Comp
L SID_DUINO3-rescue:KL_RGBLED-SID_DUINO3-rescue U4
U 1 1 5583B7EF
P 9350 1200
F 0 "U4" H 9050 950 60  0000 C CNN
F 1 "KL_RGBLED" H 9150 800 60  0000 C CNN
F 2 "" H 9300 950 60  0001 C CNN
F 3 "" H 9300 950 60  0000 C CNN
	1    9350 1200
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:R-SID_DUINO3-rescue R3
U 1 1 5583B94A
P 8500 950
F 0 "R3" V 8580 950 40  0000 C CNN
F 1 "R" V 8507 951 40  0000 C CNN
F 2 "" V 8430 950 30  0001 C CNN
F 3 "~" H 8500 950 30  0000 C CNN
	1    8500 950 
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:R-SID_DUINO3-rescue R4
U 1 1 5583B957
P 8500 1150
F 0 "R4" V 8580 1150 40  0000 C CNN
F 1 "R" V 8507 1151 40  0000 C CNN
F 2 "" V 8430 1150 30  0001 C CNN
F 3 "~" H 8500 1150 30  0000 C CNN
	1    8500 1150
	0    -1   -1   0   
$EndComp
$Comp
L SID_DUINO3-rescue:R-SID_DUINO3-rescue R5
U 1 1 5583B95D
P 8500 1350
F 0 "R5" V 8580 1350 40  0000 C CNN
F 1 "R" V 8507 1351 40  0000 C CNN
F 2 "" V 8430 1350 30  0001 C CNN
F 3 "~" H 8500 1350 30  0000 C CNN
	1    8500 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8750 950  8850 950 
Wire Wire Line
	8750 1150 8850 1150
Wire Wire Line
	8750 1350 8850 1350
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR017
U 1 1 5583BB42
P 9550 1750
F 0 "#PWR017" H 9550 1750 30  0001 C CNN
F 1 "GND" H 9550 1680 30  0001 C CNN
F 2 "" H 9550 1750 60  0000 C CNN
F 3 "" H 9550 1750 60  0000 C CNN
	1    9550 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 950  8150 950 
Wire Wire Line
	8250 1150 8150 1150
Wire Wire Line
	8250 1350 8150 1350
Text Label 8150 950  0    60   ~ 0
A3
Text Label 8150 1150 0    60   ~ 0
A4
Text Label 8150 1350 0    60   ~ 0
A5
Wire Wire Line
	7550 5000 7350 5000
Text Label 7450 5000 0    60   ~ 0
5v
Text Label 6450 2750 0    60   ~ 0
RST
$Comp
L SID_DUINO3-rescue:CONN_2-SID_DUINO3-rescue P7
U 1 1 5583C96C
P 10450 4600
F 0 "P7" V 10400 4600 40  0000 C CNN
F 1 "AudioOut" V 10500 4600 40  0000 C CNN
F 2 "" H 10450 4600 60  0001 C CNN
F 3 "" H 10450 4600 60  0000 C CNN
	1    10450 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 4500 9950 4500
Wire Wire Line
	9950 4500 9950 4550
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR018
U 1 1 5583CA21
P 9950 4550
F 0 "#PWR018" H 9950 4550 30  0001 C CNN
F 1 "GND" H 9950 4480 30  0001 C CNN
F 2 "" H 9950 4550 60  0000 C CNN
F 3 "" H 9950 4550 60  0000 C CNN
	1    9950 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 4700 9850 4700
Text Label 9850 4700 0    60   ~ 0
audio out
$Comp
L SID_DUINO3-rescue:PWR_FLAG-SID_DUINO3-rescue #FLG019
U 1 1 5583CE79
P 9550 1750
F 0 "#FLG019" H 9550 1845 30  0001 C CNN
F 1 "PWR_FLAG" H 9550 1930 30  0000 C CNN
F 2 "" H 9550 1750 60  0000 C CNN
F 3 "" H 9550 1750 60  0000 C CNN
	1    9550 1750
	0    1    1    0   
$EndComp
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C13
U 1 1 5583E728
P 3700 7100
F 0 "C13" H 3700 7200 40  0000 L CNN
F 1 "C" H 3706 7015 40  0000 L CNN
F 2 "" H 3738 6950 30  0001 C CNN
F 3 "~" H 3700 7100 60  0000 C CNN
	1    3700 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 6800 3700 6800
Wire Wire Line
	3700 6800 3700 6900
$Comp
L SID_DUINO3-rescue:C-SID_DUINO3-rescue C8
U 1 1 5583E7D2
P 2150 7100
F 0 "C8" H 2150 7200 40  0000 L CNN
F 1 "C" H 2156 7015 40  0000 L CNN
F 2 "" H 2188 6950 30  0001 C CNN
F 3 "~" H 2150 7100 60  0000 C CNN
	1    2150 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6800 2150 6800
Wire Wire Line
	2150 6800 2150 6900
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR020
U 1 1 5583E876
P 2150 7300
F 0 "#PWR020" H 2150 7300 30  0001 C CNN
F 1 "GND" H 2150 7230 30  0001 C CNN
F 2 "" H 2150 7300 60  0000 C CNN
F 3 "" H 2150 7300 60  0000 C CNN
	1    2150 7300
	1    0    0    -1  
$EndComp
$Comp
L SID_DUINO3-rescue:GND-SID_DUINO3-rescue #PWR021
U 1 1 5583E87C
P 3700 7300
F 0 "#PWR021" H 3700 7300 30  0001 C CNN
F 1 "GND" H 3700 7230 30  0001 C CNN
F 2 "" H 3700 7300 60  0000 C CNN
F 3 "" H 3700 7300 60  0000 C CNN
	1    3700 7300
	1    0    0    -1  
$EndComp
Text Notes 1000 6350 0    60   ~ 12
Power regulation\n
Wire Wire Line
	7500 2750 7650 2750
Wire Wire Line
	6650 2300 6800 2300
Wire Wire Line
	6650 1700 6800 1700
Wire Wire Line
	3800 1400 3800 1600
Wire Wire Line
	3800 1300 3800 1400
Wire Wire Line
	3800 1150 3800 1300
Wire Wire Line
	2900 1150 2900 1350
Wire Wire Line
	3800 950  3800 1150
Wire Wire Line
	3750 3500 3750 3600
Wire Wire Line
	3750 3600 3750 3800
Wire Wire Line
	7200 2000 7200 2300
Wire Wire Line
	3350 1900 3950 1900
Wire Wire Line
	1750 1800 2300 1800
Wire Wire Line
	1750 1400 2300 1400
Wire Wire Line
	1750 1250 2300 1250
Wire Wire Line
	1750 850  2300 850 
$EndSCHEMATC