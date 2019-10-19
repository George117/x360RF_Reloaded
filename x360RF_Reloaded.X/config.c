/*
 * File:   config.c
 * Author: georg
 *
 * Created on January 1, 2017, 1:37 PM
 */

#include <xc.h>
#include "bit_settings.h"
#include "config.h"
#include "usart_pic16.h"

#define data_line LATCbits.LATC0
#define clock_line PORTAbits.RA2
#define button PORTCbits.RC1

void config()
{

    data_line=1;//set HIGH: no command incoming
    
    OSCCONbits.IRCF0=0;
    OSCCONbits.IRCF1=1;//8Mhz
    OSCCONbits.IRCF2=1;
    OSCCONbits.IRCF3=1;
    
    INTCONbits.GIE=0;

    ANSELA=0X00;
    ANSELC=0X00;
    TRISA=0X00;
    TRISC=0X00;
    PORTA=0X00;
    PORTC=0X00;
    LATA=0X00;
    LATC=0X00;
    
    data_line=1;//set HIGH: no command incoming
    OPTION_REGbits.nWPUEN=0;//PORTB pull-ups are enabled
    WPUAbits.WPUA2=1;//weak pull-up enabled
    
    TRISAbits.TRISA2 = 1;//clock_line input 
    TRISCbits.TRISC1 = 1;//button input
    OPTION_REGbits.INTEDG = 1;//Interrupt on falling edge
    __delay_ms(1000);

    INTCONbits.GIE = 1;
    INTCONbits.INTE = 1;
    INTCONbits.PEIE = 1;
    
    
    
    USARTInit(9600);

    
}


