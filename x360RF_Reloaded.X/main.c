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

const long int sync_cmd = 0x004;
const long int led_cmd = 0b0010000100;
const long int anim_cmd = 0x085;

unsigned int clk_low = False;


void send_data(long int data )
{
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
    
}


void __interrupt() int0(void)
{
    clk_low = True;
    INTCONbits.INTF=0;
    
    
}

void main(void) {
    
    config(); 
    send_data(0x0C0);
    send_data(0x088);
    __delay_ms(2000);
    send_data(anim_cmd);

    __delay_ms(8000);
    
    
    while(1)
    {if(button == low){
        send_data(sync_cmd);
        __delay_ms(3000);
        send_data(0b0010100001);	
    }}
    
 }