/*
 * File:   main.c
 * Author: SERVARIVERA
 *
 * Created on 3 de septiembre de 2018, 10:21 PM
 */


#include <xc.h>
#include "CONFIG.h"
#define _XTAL_FREQ 32000000

void main(void) {
    //configuracion del oscilador a 32MHz OSC = HFINT DIV 1:1
    OSCFRQbits.HFFRQ = 0b110; //HFINT a 32MHz
    
    //configuracion de puertos
    
    PORTB = 0; //Limpia puerto B
    ANSELB = 0; //Puerto B como digtal 
    TRISB = 0b11110000; //RB0-3 salidas, RB4-7 entradas
    WPUB5 = 1; //La resistencia pull up se conecta al pin PORTBbits.RB5
    WPUB6 = 1;
    //Ciclo infinito**************
    
    while(1){
        if (PORTBbits.RB5==0){
            __delay_ms(250);
            LATBbits.LATB1 = LATBbits.LATB1 + 1;
        }
                if (PORTBbits.RB6==0){
            __delay_ms(250);
            LATBbits.LATB2 = LATBbits.LATB2 + 1;
        }    return;

    }
    return;
}
