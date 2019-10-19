/*
 * File:   main.c
 * Author: georg
 *
 * Created on October 27, 2018, 10:59 AM
 */


#include <xc.h>
#include <stdio.h>
#include "bit_settings.h"
#include "config.h"
#include "led_patterns.h"

#define data_line LATCbits.LATC0
#define clock_line PORTAbits.RA2
#define button PORTCbits.RC1

#define low 0
#define high 1
#define True 1
#define False 0

unsigned int clk_low = False;

char rx_ser = 0;

void send_data(long int data )
{
    TRISCbits.TRISC0 = 0;
    int i = 0;
    long int temp = 0;
    INTCONbits.GIE = 1;
    data_line = low;//signal start of command
    
    __delay_ms(2);
    
    for(i=0;i<11;i++)
    {
        while(clk_low == False){}
        
        if(i == 10)
        {
            data_line = high;
        }
        else{
            temp = (data >> (9-i)) & 0x01;
            if(temp == 1)
            {
                data_line = high;
            }
            else{
                data_line = low; 
            }

            clk_low = False;
        }
        
    }
    
    clk_low = False;
    INTCONbits.GIE = 0;
    data_line = high;
    
    TRISCbits.TRISC0 = 1;
    
}


void __interrupt() int0(void)
{
    clk_low = True;
    INTCONbits.INTF=0;
    
    if(RCIF == 1){
        rx_ser = RCREG;
        
        TXREG=rx_ser;
        
        RCIF = 0;
    }
}

void main(void) {
    
    config(); 
    
    send_data(CLEAR_ERR1);
    send_data(SET_RED_LEDS_OFF);
    send_data(SET_GREEN_LEDS_OFF);
    
    send_data(LED_INIT);
    __delay_ms(1000);
    send_data(CTRLR_OFF);
    __delay_ms(2000);
    send_data(BOOTANIM);

    __delay_ms(5000);
    
   
    
    while(1){
        
       send_data(rx_ser);
       __delay_ms(500);
    }
    
    
    while(1)
    {if(button == low){
        send_data(SET_GREEN_LEDS_OFF);
        
        __delay_ms(100);
        
        send_data(SYNC);
        
        __delay_ms(3000);
        
        send_data(SET_GREEN_LED1);	
    }}
    
 }