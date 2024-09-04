/******************************************************************************* 
* File:   config.h  
* Developed by Nivaldo T. Schiefler Jr.  DSc.
* Build under XC8 compiler
* Created on 1 de Janeiro de 2021, 13:57
* Updates: 
*
 ******************************************************************************/

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif
      /* CPU frequency */
    #define F_CPU 16000000UL // 16 MHz
    void configuracao(void);


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

