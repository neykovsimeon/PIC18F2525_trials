/*
 * File:   lcd_trials_4bits.c
 * Author: PC
 *
 * Created on September 8, 2018, 4:19 PM
 */

#include <xc.h>
#include <math.h>
#include <stdint.h>              // needed for uint8_t types, etc
#include <stdbool.h>             // needed for boolean types, etc
#include <stdio.h>
#include <stdlib.h>

#include "lcd_trials_4bits.h"
#include "LCD_user_functions.h"
#include "ADC_user_functions.h"
#include <plib/adc.h>
#include <plib/delays.h>
#include "xlcd.h"

// ADC functions
void init_ADC (void);


/* LCD lib related User defines these routines according to the oscillator frequency */
void init_XLCD (void);
void DelayFor18TCY(void); // 18 cycles
void DelayPORXLCD(void);  // 15ms
void DelayXLCD(void);     // 5ms

void Delay1Sec(void);
void DelayHalfSec(void);
void Delay200ms(void);

unsigned int ADCResult = 0;
float u_AN0 = 0.0;
unsigned char ResultString[10];
//float vRef = 4.83; //  vdd
float vRef = 2.5; // tl41div
//float vRef = 1.024; // tl41div trimmed
float voltage=0;


void main(void) {
    
    TRISAbits.RA4 = 0;
    OSCCON = 0x76;
    LATAbits.LATA4 = 1;
    
//    CloseADC();
    init_ADC ();
    
    // LCD trials
    init_XLCD();
//    while(BusyXLCD());
//    putrsXLCD("ADC measure:");
    putrsXLCD("  Power Supply  ");
    SetDDRamAddr (0x40);
    putrsXLCD("v1.0");
    Delay1Sec();
    Delay1Sec();
    SetDDRamAddr (0x00);
    putrsXLCD("U(out)[V]=      ");
    SetDDRamAddr (0x40);
    putrsXLCD("I(out)[A]=      ");
    SetDDRamAddr (0x0A);
       
    
    while (1) {
        
        LATAbits.LATA4 = ~LATAbits.LATA4;
        
        ADCResult = 0;
        
        // first channel - U(OUT))
        SetChanADC(ADC_CH0);
        for(int i=0;i<16;i++)
        {
            ConvertADC();
            while(BusyADC());
            ADCResult += (unsigned int) ReadADC();
        }
        ADCResult /= 16;
        voltage = ((ADCResult*vRef)/1024)*6; // convert ADC count into voltage
        sprintf(ResultString, "%.3g", voltage);
        putsXLCD(ResultString);
     //   putrsXLCD("V");
        putrsXLCD("     ");
        SetDDRamAddr (0x4A);
        voltage = 0;
        ADCResult = 0;
        
        // second channel - I(OUT))
        SetChanADC(ADC_CH1);
        for(int i=0;i<16;i++)
        {
            ConvertADC();
            while(BusyADC());
            ADCResult += (unsigned int) ReadADC();
        }
        ADCResult /= 16;
        voltage = (ADCResult*vRef)/1024; // convert ADC count into voltage
        sprintf(ResultString, "%.3g", voltage);
        putsXLCD(ResultString);
     //   putrsXLCD("V");
        putrsXLCD("     ");
        SetDDRamAddr (0x0A);
        voltage = 0;
        ADCResult = 0;
               
       // introduce 1/2 seconds delay
        //Delay200ms();
        //__delay_ms(500);
        DelayHalfSec();
    }
    return;
}
