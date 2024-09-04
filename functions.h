/******************************************************************************* 
* Library to General Functions developed under ATEMEGA328P data sheet
* Developed by Nivaldo T. Schiefler Jr.  DSc.
* Build under XC8 compiler
* Created on 1 de Janeiro de 2021, 13:57
* Updates: 
*
 ******************************************************************************/

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
//******************************************************************************
//                        PIN FUNCTIONS
//******************************************************************************    
#define set_pin(port, pin_bit)     (port) |=  ((unsigned char)pow(2,pin_bit))
#define clear_pin(port, pin_bit)   (port) &= ~((unsigned char)pow(2,pin_bit))
#define set_pin_value(port,pin_bit,value)  ((value == 1) ?  \
                                           (set_pin(port, pin_bit)) :  \
                                           (clear_pin(port, pin_bit)))
//******************************************************************************
//                        PORT FUNCTIONS
//******************************************************************************       
#define set_port(port, value)  (port) =  (value)
#define clear_port(port)       (port) =  (0)
//******************************************************************************
//                        READER FUNCTIONS
//******************************************************************************       
#define read_port(pinx) (pinx)             
#define read_pin(pinx,pin_bit)    (((pinx >> pin_bit) & 0x01) ==  1 ? 1 : 0)
    
//******************************************************************************
#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

