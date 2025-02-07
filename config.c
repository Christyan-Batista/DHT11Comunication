/******************************************************************************* 
* File:   config.c  
* Build under XC8 compiler
* Created on 1 de Janeiro de 2021, 13:57
* Updates: 
*
 ******************************************************************************/

// Biblioteca auxiliar para inicializar as portas do microcontrolador

#include <avr/io.h>

 void configuracao(void)
 {
     //*************************************************************************
     //    DDRx       The Port B Data Direction Register
     //               0  input      1  output
     //*************************************************************************
     DDRB  = 0b11111111;
     PORTB = 0;             // The Port B Data Register
     //*************************************************************************
     DDRC  = 0b11111111;    // analog/digital PORTS
     PORTC = 0;             // The Port C Data Register
     //*************************************************************************
     DDRD  = 0b11111110;    // 
     PORTD = 0;             // The Port D Data Register
     //*************************************************************************
     
 }
