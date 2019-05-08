/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_LED_PATTERNS_H
#define	XC_LED_PATTERNS_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define  SYNC	          	0x004      //Displays the XBOX 360 controller sync LED sequence, syncs RF module with controlers
#define  CTRLR_OFF	      	0x009      //Turns off all controllers
#define  CONFIG	         	0x01X      //Configures the module (R bit is RF on/off, P bit is 0 for standing orientation)
#define  LED_OFF	      	0x080      //Turns off the LED controller
#define  LED_INIT	      	0x084      //Initializes the LEDs (required before any other LED commands) and turns on the power LED
#define  BOOTANIM	      	0x085      //Same as LED_INIT, plus it runs the Xbox 360 boot animation on the LED ring
#define  LED_INIT_NOPWR     0x088      //Same as LED_INIT but does not turn on power LED?
#define  BOOTANIM_NOPWR     0x089      //Same as BOOTANIM but does not turn on power LED?
#define  LED_INIT_BLPWR     0x088      //Same as LED_INIT and blinks the power LED
#define  BOOTANIM_BLPWR     0x089      //Same as BOOTANIM and blinks the power LED
#define  SET_GREEN_LEDS     0x0AX      //Sets the four green LEDs on or off (four least significant bits encode green led value)
#define  SET_RED_LEDS	  	0x0BX      //Sets the four red LEDs on or off (same as SET_GREEN_LEDS but independent of it)
#define  CLEAR_ERR1   	  	0x0C0      //Clears any error display (blinking red leds or orange solid)
#define  SLOW_BLINK_ALL     0x0C1      //Blinks all four red LEDs
#define  SLOW_BLINK_1	  	0x0C2      //Blinks top left red LED
#define  SLOW_BLINK_2	  	0x0C3      //Blinks top right red LED
#define  SLOW_BLINK_3	  	0x0C4      //Blinks bottom right red LED
#define  SLOW_BLINK_4	  	0x0C5      //Blinks top left red LED
#define  CLEAR_ERR2	    	0x0D0      //Clears any error display (blinking red leds or orange solid)
#define  FAST_BLINK_ALL     0x0D1      //Blinks all four red LEDs
#define  FAST_BLINK_1	  	0x0D2      //Blinks top left red LED
#define  FAST_BLINK_2	  	0x0D3      //Blinks top right red LED
#define  FAST_BLINK_3	  	0x0D4      //Blinks bottom right red LED
#define  FAST_BLINK_4	  	0x0D5      //Blinks top left red LED
#define  CLEAR_ERR3 	  	0x0E0      //Clears any error display (blinking red leds or orange solid)
#define  LED_AMBER	  	    0x0E1      //Sets all leds to amber colour



#endif	/* XC_LED_PATTERNS_H */

