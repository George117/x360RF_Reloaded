/*
 * File:   config.c
 * Author: georg
 *
 * Created on January 1, 2017, 1:37 PM
 */

#include <xc.h>
#include <pic18f46k22.h>
#include "bit_settings.h"
#include "config.h"
#define data_line LATBbits.LATB1
#define clock_line PORTBbits.RB0

void config()
{

    data_line=1;//set HIGH: no command incoming
    
    OSCCONbits.IRCF0=1;
    OSCCONbits.IRCF1=1;//4Mhz
    OSCCONbits.IRCF2=1;
    OSCTUNEbits.PLLEN = 0; // turn on the PLL 64 MHz
    INTCONbits.GIE=0;

    ANSELA=0X00;
    ANSELB=0X00;
    ANSELC=0X00;
    ANSELD=0X00;
    ANSELE=0X00;
    TRISA=0X00;
    TRISB=0X00;
    TRISC=0X00;
    TRISD=0X00;
    TRISE=0X00;
    PORTA=0X00;
    PORTB=0X00;
    PORTC=0X00;
    PORTD=0X00;
    PORTE=0X00;
    LATA=0X00;
    LATB=0b00000010;
    LATC=0X00;
    LATD=0X00;
    LATE=0X00;
    
    data_line=1;//set HIGH: no command incoming
    INTCON2bits.RBPU=0;//PORTB pull-ups are enabled
    WPUBbits.WPUB1=1;//weak pull-up enabled
    TRISBbits.RB0=1;///clock_line input 
    INTCON2bits.INTEDG0 = 1; //Interrupt on falling edge
    
    __delay_ms(1000);

    INTCONbits.GIE = 0;
    INTCONbits.INT0IE = 1;

    
}


