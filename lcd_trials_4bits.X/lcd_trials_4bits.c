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
#include <plib/delays.h>
#include "xlcd.h"

/* LCD lib related User defines these routines according to the oscillator frequency */
void init_XLCD (void);
void DelayFor18TCY(void); // 18 cycles
void DelayPORXLCD(void);  // 15ms
void DelayXLCD(void);     // 5ms


void main(void) {
    
    TRISAbits.RA4 = 0;
    OSCCON = 0x76;
    LATAbits.LATA4 = 1;
    
    // LCD trials
    init_XLCD();
//    while(BusyXLCD());
    putrsXLCD("Basi Mamata");
    SetDDRamAddr (0x40);
    putrsXLCD("LCD on PORTC & B");
    
    
    
    while (1) {
        
        LATAbits.LATA4 = ~LATAbits.LATA4;
        
        // introduce 1 seconds delay
        for (int cntDelay = 0; cntDelay < 20; cntDelay ++) __delay_ms(50);
    }
    return;
}
