/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#include <stdlib.h>
#include <plib/delays.h>
#include "lcd_trials_4bits.h"
#include "xlcd.h"

/* LCD lib related User defines these routines according to the oscillator frequency */
void init_XLCD (void){
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
//    WriteCmdXLCD(SHIFT_CUR_RIGHT);
//    while(BusyXLCD());
//    WriteCmdXLCD(DON);
//    while(BusyXLCD());
//    WriteCmdXLCD(CURSOR_OFF);
    WriteCmdXLCD(0x06); // SHIFT_CUR_RIGHT
    while(BusyXLCD());
    WriteCmdXLCD(0x0C); // DON & CURSOR_OFF & BLINK_OFF
    while(BusyXLCD());
    WriteCmdXLCD(0x01); // clear screen
    
}
void DelayFor18TCY(void){
    Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop();
    Nop(); Nop();
    return;
} // 18 cycles
void DelayPORXLCD(void){
    Delay1KTCYx(30);
//    __delay_ms(15);
}  // 15ms
void DelayXLCD(void){
    Delay1KTCYx(10);
//    __delay_ms(5);
}     // 5ms

void Delay1Sec(void){
    for (int cntDelay = 0; cntDelay < 20; cntDelay ++) __delay_ms(50);
}

void DelayHalfSec(void){
    for (int cntDelay = 0; cntDelay < 10; cntDelay ++) __delay_ms(50);
}

void Delay200ms(void){
    for (int cntDelay = 0; cntDelay < 10; cntDelay ++) __delay_ms(20);
}