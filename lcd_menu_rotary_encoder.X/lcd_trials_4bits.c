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
#include "psu_1_0_ver02_hardware.h"

// general purpose variables
unsigned int button_delay_counter = 0;
unsigned int return_default_display_counter = 0;
bool button_enable = 1; // 1-> button enabled, 0 -> button disabled
bool button_delay_counter_enable = 0;
bool return_default_display_counter_enable = 0;
bool lastStateROTARY_CK = 0;
bool currentStateROTARY_CK = 0;

// user HW definitions in psu_1_0_ver02_hardware.h

void start (void){
    clear_display();
    gotoxy(0, 0);
    //__delay_ms(50);
    putrsXLCD("!This is SPARTA!");
    Delay1Sec();
    selected = 1;
    while ((DISPLAY_SET_MODE_SELECT) && (ROTARY_SW)); 
    __delay_ms(50);
    Delay1Sec();
    return;
}

void init_GPIO_DIR (void){
    TRISAbits.RA7 = 0;  // digital output cs dac i set
    TRISAbits.RA4 = 1;  // digital input button,  ROTARY_DA (rotary data)
    TRISBbits.RB4 = 0;  // digital output cs dac v set
    TRISBbits.RB5 = 0; //0;  // will be used in I protection function
    TRISBbits.RB7 = 1;  // digital input button,  ROTARY_CK (rotary clock)
    TRISBbits.RB6 = 0;  // digital output, cs digital pot for displ contrast and brightness
    TRISAbits.RA2 = 1;  // digital input ROTARY_SW (rotary switch)
    TRISAbits.RA6 = 1;  // digital input active low -> contrast / brightness decrease
    TRISAbits.RA5 = 1;  // digital input active low -> contrast / brightness increase
    SPI_CS_IOUT = 1;    // digital output cs dac i set
    SPI_CS_DISPLAY = 1;   // digital output, cs digital pot for displ contrast and brightness
    SPI_CS_UOUT = 1;    // digital output cs dac v set   
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 0;    
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


/*
void interrupt rotary_encoder(void){
        // interrupt on change at portb_7 -> rotary encoder
    GIE = 0; // interrupts disabled. Interrupts will be enabled outside with delay (de-bouncing))
    __delay_ms(10);
    if (RBIF == 1) {
        if (ROTARY_CK == ROTARY_DA) {
            selected  = my_menu[selected].up; 
        } else {
            selected  = my_menu[selected].down;
        }
    }

    button_enable = 0;                  // enable de-bouncing delay, disable button function
    button_delay_counter_enable = 1;
    button_delay_counter = 0;
    //return_default_display_counter_enable = 1;
    //return_default_display_counter = 0;
    if (ROTARY_CK == 1) NOP();
    if (ROTARY_CK == 0) NOP();
    RBIF = 0; // clear flag and mismatch condition
    //return;    
}
*/

void main(void) {
    
    OSCCON  = 0x76;     // internal 8MHz oscilator, RA6 and RA7 are GPIO
    CMCON   = 0x07;     // Comparator OFF, RA2 and RA5 are digital inputs
    ADCON1  = 0x0F;     // needed to enable digital I/O function for RA5. Otherwise after reset reading returns 0
    selected = 1;
    //DAC_u = 3276;
    
    init_GPIO_DIR ();
    init_XLCD();
    
    // interrupts registers setup
    // enable PORTB interrupt on change (encoder service)
    //RBIE = 1;
    //INTERRUPT CONTROL REGISTER 2:
    //INTCON2 = 0b00000000; // portb pull-ups disabled, RB Port Change Interrupt Priority low
   
    //RCONbits.IPEN = 0;  // Interrupt High Priority disabled
    //GIE = 1;

    // LCD default intro screen
    gotoxy(0, 0);
    putrsXLCD("Basi Mamata");
    gotoxy(12, 2);
    putrsXLCD("v3.0");
    Delay1Sec();
    Delay1Sec();
    clear_display();
    
    RxD = 0;
    TxD = 1;
    
    lastStateROTARY_CK = ROTARY_CK;
 // main cycle   
    while (1) {
        
        RxD =~ RxD;
        TxD =~ TxD;
        show_menu();
        currentStateROTARY_CK = ROTARY_CK;
       // 3.1) Buttons check - display settings - contrast, brightness
        if (button_enable == 1){
            if ((DISPLAY_SET_MODE_SELECT == 0) || (ROTARY_SW == 0)){
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                //return_default_display_counter_enable = 1;
                //return_default_display_counter = 0; 
                if (my_menu[selected].fp != 0) my_menu[selected].fp();
                selected  = my_menu[selected].enter; 
            }
            if (DISPLAY_SET_UP == 0) {
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                //return_default_display_counter_enable = 1;
                //return_default_display_counter = 0;
                selected  = my_menu[selected].up;  
            }
            if (DISPLAY_SET_DOWN == 0) {
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                //return_default_display_counter_enable = 1;
                //return_default_display_counter = 0;
                selected  = my_menu[selected].down;
            }
            if (currentStateROTARY_CK != lastStateROTARY_CK) {
                if (ROTARY_CK == ROTARY_DA) {
                    selected  = my_menu[selected].up; 
                    //__delay_ms(50);
                } else {
                    selected  = my_menu[selected].down;
                    //__delay_ms(50);
                }
                //lastStateROTARY_CK = currentStateROTARY_CK;
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                //return_default_display_counter_enable = 1;
                //return_default_display_counter = 0;           
            }            
        }    
        lastStateROTARY_CK = ROTARY_CK;
        //3.3) delay counters
        if (button_delay_counter_enable == 1) {
            button_delay_counter = button_delay_counter +1;
                if (button_delay_counter > 30){   // about 200ms
                    button_delay_counter = 0;
                    button_enable = 1;
                    button_delay_counter_enable = 0;
                    // enable again button function
                    //GIE = 1;
                }
        }
       // 4) DISPLAY 

        __delay_ms(1);
    }
    return;
}
