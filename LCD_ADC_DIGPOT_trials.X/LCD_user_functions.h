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

// user HW definitions
#define DISPLAY_SET_MODE_SELECT RE3         // digital input button, active low -> select contrast or brightness control
#define SPI_CS_IOUT LATAbits.LATA7          // digital output cs dac i set  
#define ROTARY_DA RA4                      // digital input button, active low -> contrast / brightness decrease
#define SPI_CS_UOUT LATBbits.LATB4          // digital output cs dac v set
#define DISPLAY_SET_UP RA5                  // digital input button, active low -> contrast / brightness increase
#define DISPLAY_SET_DOWN RA6                // digital input button, active low -> contrast / brightness decrease
//#define GPLED LATAbits.LATA6              // digital output general purpose LED, light on at LOW
//#define GPLED_ON 0                        // digital output general purpose LED
//#define GPLED_OFF 1                       // digital output general purpose LED, light off at HIGH
#define ROTARY_SW RA2                       // digital input button, active low -> output settings menu
#define SPI_CS_DISPLAY LATBbits.LATB6       // digital output, cs digital pot for displ contrast and brightness
#define ROTARY_CK RB7                       // digital input button, active low -> contrast / brightness decrease
#define IPROT RB5


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

void clear_display (void){
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

void init_GPIO_DIR (void){
    //TRISAbits.RA6 = 0;  // digital output general purpose LED
    TRISAbits.RA7 = 0;  // digital output cs dac i set
    TRISAbits.RA4 = 1;  // digital input button,  ROTARY_DA (rotary data)
    TRISBbits.RB4 = 0;  // digital output cs dac v set
    TRISBbits.RB5 = 1; //0;  // will be used in I protection function
    TRISBbits.RB7 = 1;  // digital input button,  ROTARY_CK (rotary clock)
    TRISBbits.RB6 = 0;  // digital output, cs digital pot for displ contrast and brightness
    TRISAbits.RA2 = 1;  // digital input ROTARY_SW (rotary switch)
    TRISAbits.RA6 = 1;  // digital input active low -> contrast / brightness decrease
    TRISAbits.RA5 = 1;  // digital input active low -> contrast / brightness increase
    SPI_CS_IOUT = 1;    // digital output cs dac i set
    SPI_CS_DISPLAY = 1;   // digital output, cs digital pot for displ contrast and brightness
    SPI_CS_UOUT = 1;    // digital output cs dac v set   
}

//void OpenSPI( unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase)
/*
 * // user HW definitions
#define DISPL_SET_MODE_SELECT RE3       // digital input button, active low -> select contrast or brightness control
#define SPI_CS_IOUT LATAbits.LATA7      // digital output cs dac i set  
#define SPI_CS_DISPL LATAbits.LATA4     // digital output, cs digital pot for displ contrast and brightness
#define SPI_CS_UOUT LATBbits.LATB4      // digital output cs dac v set
#define DISPL_SET_UP RB7                // digital input button, active low -> contrast / brightness increase
#define DISPL_SET_DOWN RB6              // digital input button, active low -> contrast / brightness decrease
#define GPLED LATAbits.LATA6            // digital output general purpose LED
 * 
 * Functions
OpenSPI
WriteSPI
ReadSPI
putsSPI
getsSPI
Macros
EnableIntSPI
DisableIntSPI
SetPriorityIntSPI
SPI_Clear_Intr_Status_Bit
SPI_Intr_Status
SPI_Clear_Recv_OV
CloseSPI
DataRdySPI
getcSPI
putcSPI
 */