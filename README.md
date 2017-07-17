# Dual-Shift-Register-Arduino
Interfacing of two shift register 74HC595 with Arduino UNO


In this project two 74hc595 are connected to Arduino board. the output of shift register 
is used to drive the 16 relays. the code will read relay status from array in the included 
header file and convert them into two bytes and then these two bytes are shifted out using 
built in shiftOut function of Arduino.
