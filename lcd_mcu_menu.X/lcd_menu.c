#include <xc.h>
#include <math.h>
#include <stdint.h>              // needed for uint8_t types, etc
#include <stdbool.h>             // needed for boolean types, etc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <plib/delays.h>

#include "lcd_menu.h"
#include "xlcd.h"

unsigned char selected = 1;

const char menu_000[] = "-- Main  Menu --";   // 0
const char menu_001[] = " Option1";         // 1
const char menu_002[] = " Option2";         // 2
const char menu_003[] = " Option3";         // 3
const char menu_004[] = " Option4";         // 4
const char menu_005[] = " Option5";         // 5
const char menu_006[] = " Option6";         // 6
const char menu_007[] = " Option7";         // 7
const char menu_008[] = " Option8";         // 8
const char menu_009[] = " START";           // 9

const char menu_010[] = " [Sub Menu]";      // 10
const char menu_011[] = " SubOption1";      // 11
const char menu_012[] = " SubOption2";      // 12
const char menu_013[] = " SubOption3";      // 13
const char menu_014[] = " SubOption4";      // 14
const char menu_015[] = " SubOption5";      // 15
const char menu_016[] = " RETURN";          // 16


MenuEntry my_menu[] = 
{
    {menu_000, 10, 0, 0, 0,  0},
    {menu_001, 10, 1, 2, 1,  0},
    {menu_002, 10, 1, 3, 11, 0},
    {menu_003, 10, 2, 4, 3,  0},
    {menu_004, 10, 3, 5, 4,  0},
    {menu_005, 10, 4, 6, 5,  0},
    {menu_006, 10, 5, 7, 6,  0},
    {menu_007, 10, 6, 8, 7,  0},
    {menu_008, 10, 7, 9, 8,  0},
    {menu_009, 10, 8, 9, 9,  start},
    
    {menu_010, 7, 0,  0,  0,  0},
    {menu_011, 7, 1,  12, 11, 0},
    {menu_012, 7, 11, 13, 12, 0},
    {menu_013, 7, 12, 14, 13, 0},
    {menu_014, 7, 13, 15, 14, 0},
    {menu_015, 7, 14, 16, 15, 0},
    {menu_016, 7, 15, 16, 1,  0},         
};


void LCDWriteCmd (unsigned char command) {
    while(BusyXLCD());
    WriteCmdXLCD(command); // clear screen
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

void gotoxy (unsigned char x_pos, unsigned char y_pos) {
    unsigned char ddramaddress = 0;
    
    if (x_pos > (INITIAL_MAXX - 1)) x_pos = 0;      // t.b.d.
    if (y_pos > (INITIAL_MAXY - 1)) y_pos = 0;      // t.b.d.
    switch ( y_pos ) { // for 16x4 display
        case 0:  {
            ddramaddress = (0x00 + x_pos); 
            break;
        }   // row 1
        case 1:  {
            ddramaddress = (0x40 + x_pos); 
            break;
        }   // row 2
        case 2:  {
            ddramaddress = (START_ROW3 + x_pos); 
            break;
        }   // row 3
        case 3:  {
            ddramaddress = (START_ROW4 + x_pos); 
            break;
        }   // row 4
        default: {
            ddramaddress = (0x00 + x_pos); 
            break;
        }   // row 1
    }
    while(BusyXLCD());
    SetDDRamAddr(ddramaddress);
}

void LCDWriteStringROM (unsigned char x, unsigned char y, const char *lcd_menu_items, unsigned char add_line, char add_char) {
    unsigned char lcd_i;
    unsigned char lcd_offset = 0;
    //unsigned char offsetstring[5];
    if (x > (INITIAL_MAXX - 1)) x = 0;      // t.b.d.
    if (y > (INITIAL_MAXY - 1)) y = 0;      // t.b.d.
    switch ( y ) {
        case 0:  {
            lcd_offset = 0x00 + x; 
            break;
        }   // row 1
        case 1:  {
            lcd_offset = 0x40 + x; 
            break;
        }   // row 2
        case 2:  {
            lcd_offset = START_ROW3 + x; 
            break;
        }   // row 3
        case 3:  {
            lcd_offset = START_ROW4 + x; 
            break;
        }   // row 4
        default: {
            lcd_offset = 0x00; 
            break;
        }   // row 1
    }
    while(BusyXLCD());
    SetDDRamAddr(lcd_offset);
    lcd_offset = strlen(lcd_menu_items);
    //sprintf(offsetstring, "%d", lcd_offset);
    //putrsXLCD(offsetstring);
  
    if (lcd_offset > INITIAL_MAXX) lcd_offset = INITIAL_MAXX;
    for (lcd_i = lcd_offset; lcd_i; lcd_i--){
        while(BusyXLCD());
        putcXLCD(*lcd_menu_items);
        lcd_menu_items++;
    }
    if (add_line){
        for (lcd_i = INITIAL_MAXX - lcd_offset - x; lcd_i; lcd_i--) {
            while(BusyXLCD());
            putcXLCD(add_char);
        }
    }
   
}

void show_menu(void){
    unsigned char line_cnt = 0;
    unsigned char from = 0; // from which row of menu points
    unsigned char till = 0; // till which row of menu points
    unsigned char temp = 0;
    
    // define from and till spec for the menu
    while (till <= selected){
        till += my_menu[till].num_menupoints;
    }
    from = till - my_menu[selected].num_menupoints;
    till--;
    temp = from;
    
    if ((selected >= (from +UPPER_SPACE)) && (selected <= (till - LOWER_SPACE))) {
        from = selected - UPPER_SPACE;
        till = from + (DISPLAY_ROWS - 1);
        if (VISIBLE_MENU_HEADER) {
            LCDWriteStringROM(0, 0, my_menu[temp].text, 1, ' '); //
            line_cnt = 1; //
            from ++;
        }
        for (from; from <= till; from++) {
            if (from == selected) {
                LCDWriteStringROM(0, line_cnt, my_menu[from].text, 1, SELECTION_CHAR_END);
                line_cnt++;
            } else {
                LCDWriteStringROM(0, line_cnt, my_menu[from].text, 1, ' ');
                line_cnt++;
            }
        }
        
        gotoxy(0, UPPER_SPACE); // t.b.d.
        while(BusyXLCD());
        putcXLCD(SELECTION_CHAR);        
    } else {
        if (selected < (from +UPPER_SPACE)) {
            till = from + (DISPLAY_ROWS - 1);
            for (from; from <= till; from++) {
                if (from == selected) {
                    LCDWriteStringROM(0, line_cnt, my_menu[from].text, 1, SELECTION_CHAR_END);
                    line_cnt++;
                } else {
                    LCDWriteStringROM(0, line_cnt, my_menu[from].text, 1, ' ');
                    line_cnt++;
                }
            }
            gotoxy(0,selected - temp); // t.b.d.
            while(BusyXLCD());
            putcXLCD(SELECTION_CHAR);
        } else {
            if (selected == till) {
                from = till - (DISPLAY_ROWS - 1);
                if (VISIBLE_MENU_HEADER) {
                    LCDWriteStringROM(0, 0, my_menu[temp].text, 1, ' '); //
                    line_cnt = 1; //
                    from ++;
                }
                for (from; from <= till; from++) {
                    if (from == selected) {
                        LCDWriteStringROM(0, line_cnt, my_menu[from].text, 1, SELECTION_CHAR_END);
                        line_cnt++;
                    } else {
                        LCDWriteStringROM(0, line_cnt, my_menu[from].text, 1, ' ');
                        line_cnt++;
                    }
                }
                gotoxy(0,(DISPLAY_ROWS - 1)); // t.b.d.
                while(BusyXLCD());
                putcXLCD(SELECTION_CHAR);
            }
        }
    } 
}



