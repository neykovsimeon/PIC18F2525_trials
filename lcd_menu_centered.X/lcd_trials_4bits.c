#include <xc.h>
#include <math.h>
#include <stdint.h>              // needed for uint8_t types, etc
#include <stdbool.h>             // needed for boolean types, etc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delays.h"
#include "xlcd.h"
#include "lcd_menu.h"
#include "lcd_trials_4bits.h"

// general purpose variables
unsigned int button_delay_counter = 0;
unsigned int return_default_display_counter = 0;
bool button_enable = 1; // 1-> button enabled, 0 -> button disabled
bool button_delay_counter_enable = 0;
bool return_default_display_counter_enable = 0;

// user HW definitions
#define DISPLAY_SET_MODE_SELECT RE3 //PORTEbits.RE3         // digital input button, active low -> select contrast or brightness control
#define DISPLAY_SET_UP          RA5 //PORTAbits.RA5         // digital input button, active low -> contrast / brightness increase
#define DISPLAY_SET_DOWN        RA6 //PORTAbits.RA6         // digital input button, active low -> contrast / brightness decrease

void start (void){
    clear_display();
    gotoxy(0, 0);
    //__delay_ms(50);
    putrsXLCD("!This is SPARTA!");
    Delay1Sec();
    selected = 1;
    while (DISPLAY_SET_MODE_SELECT); 
    __delay_ms(50);
    Delay1Sec();
    return;
}

void init_GPIO_DIR (void){
    TRISAbits.RA6 = 1;  // digital input active low -> contrast / brightness decrease
    TRISAbits.RA5 = 1;  // digital input active low -> contrast / brightness increase   
}

/* LCD lib related User defines these routines according to the oscillator frequency */
void init_XLCD (void){
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
//    WriteCmdXLCD(SHIFT_CUR_RIGHT);
//    while(BusyXLCD());
//    WriteCmdXLCD(DON);
//    while(BusyXLCD());
//    WriteCmdXLCD(CURSOR_OFF);
    WriteCmdXLCD(0x06);
   // WriteCmdXLCD(SHIFT_CUR_RIGHT); // SHIFT_CUR_RIGHT
    while(BusyXLCD());
    WriteCmdXLCD(0x0C); // DON & CURSOR_OFF & BLINK_OFF
    while(BusyXLCD());
    WriteCmdXLCD(0x01); // clear screen
}

void main(void) {
    
    OSCCON  = 0x76;     // internal 8MHz oscilator, RA6 and RA7 are GPIO
    CMCON   = 0x07;     // Comparator OFF, RA2 and RA5 are digital inputs
    ADCON1  = 0x0F; // needed to enable digital I/O function for RA5. Otherwise after reset reading returns 0
    selected = 1;
    //DAC_u = 3276;
    
    init_GPIO_DIR ();
    init_XLCD();

    // LCD default intro screen
    gotoxy(0, 0);
    putrsXLCD("Basi Mamata");
    gotoxy(12, 2);
    putrsXLCD("v3.0");
    Delay1Sec();
    Delay1Sec();
    clear_display();
 // main cycle   
    while (1) {
       show_menu();
       // 3.1) Buttons check - display settings - contrast, brightness
        if (button_enable == 1){
            if (DISPLAY_SET_MODE_SELECT == 0){
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                return_default_display_counter_enable = 1;
                return_default_display_counter = 0; 
                if (my_menu[selected].fp != 0) my_menu[selected].fp();
                selected  = my_menu[selected].enter; 
            }
            if (DISPLAY_SET_UP == 0) {
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                return_default_display_counter_enable = 1;
                return_default_display_counter = 0;
                selected  = my_menu[selected].up;  
            }
            if (DISPLAY_SET_DOWN == 0) {
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                return_default_display_counter_enable = 1;
                return_default_display_counter = 0;
                selected  = my_menu[selected].down;
            }
        }        
        //3.3) delay counters
        if (button_delay_counter_enable == 1) {
            button_delay_counter = button_delay_counter +1;
                if (button_delay_counter > 10){   // about 200ms
                    button_delay_counter = 0;
                    button_enable = 1;
                    button_delay_counter_enable = 0;
                    // enable again button function
                }
        }
       // 4) DISPLAY 

        __delay_ms(25);
    }
    return;
}
