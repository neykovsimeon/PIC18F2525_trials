#include <xc.h>
#include <math.h>
#include <stdint.h>              // needed for uint8_t types, etc
#include <stdbool.h>             // needed for boolean types, etc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <plib/delays.h>
#include "xlcd.h"
#include "lcd_custom_char.h"
#include "lcd_menu.h"

const char dlineSpace[] = {0,0,0,0,0,0,31,31};
const char dlineA[] = {14, 17, 31, 17, 17,  0, 31, 31};
const char dlineB[] = {30, 17, 30, 17, 30,  0, 31, 31};
const char dlineC[] = {14, 17, 16, 17, 14,  0, 31, 31};
const char dlineD[] = {30, 17, 17, 17, 30,  0, 31, 31};
const char dlineE[] = {31, 16, 30, 16, 31,  0, 31, 31};
const char dlineF[] = {31, 16, 30, 16, 16,  0, 31, 31};
const char dlineG[] = {14, 16, 19, 17, 14,  0, 31, 31};
const char dlineH[] = {17, 17, 31, 17, 17,  0, 31, 31};
const char dlineI[] = {14,  4,  4,  4, 14,  0, 31, 31};
const char dlineJ[] = { 7,  2,  2, 18, 12,  0, 31, 31};
const char dlineK[] = { 9, 10, 12, 10,  9,  0, 31, 31};
const char dlineL[] = { 8,  8,  8,  8, 15,  0, 31, 31};
const char dlineM[] = {17, 27, 21, 17, 17,  0, 31, 31};
const char dlineN[] = {17, 25, 21, 19, 17,  0, 31, 31};
const char dlineO[] = {14, 17, 17, 17, 14,  0, 31, 31};
const char dlineP[] = {30, 17, 17, 30, 16,  0, 31, 31};
const char dlineR[] = {30,17,30,20,18,0,31,31}; // 30,17,30,20,18,0,31,31
const char dlineS[] = {15, 16, 14,  1, 30,  0, 31, 31};
const char dlineT[] = {31,  4,  4,  4,  4,  0, 31, 31};
const char dlineU[] = {17, 17, 17, 17, 14,  0, 31, 31};
const char dlineV[] = {17, 17, 17, 10, 4,  0, 31, 31};
const char dlineW[] = {17, 17, 21, 21, 27, 0, 31, 31};
const char dlineX[] = {17, 10,  4, 10, 17, 0, 31, 31};
const char dlineY[] = {17, 17, 14,  4,  4,  0, 31, 31};
const char dlineZ[] = {31,  2,  4,  8, 31,  0, 31, 31};
const char dline0[] = {14,10,10,10,14,0,31,31};
const char dline1[] = {4,12,4,4,14,0,31,31};
const char dline2[] = {6,9,2,4,15,0,31,31};
const char dline3[] = {14,2,6,2,14,0,31,31};
const char dline4[] = {10,10,14,2,2,0,31,31};
const char dline5[] = {14,8,14,2,14,0,31,31};
const char dline6[] = {14,8,14,10,14,0,31,31};
const char dline7[] = {15,1,2,4,4,0,31,31};
const char dline8[] = {14,10,14,10,14,0,31,31};
const char dline9[] = {14,10,14,2,14,0,31,31};


const char boldA[] = {14,27,27,31,27,27,27};
const char boldB[] = {30,27,27,30,27,27,30};
const char boldC[] = {14,27,24,24,24,27,14};
const char boldD[] = {30,27,27,27,27,27,30};
const char boldE[] = {31,24,24,30,24,24,31};
const char boldF[] = {31,24,24,30,24,24,24};
const char boldG[] = {14,27,24,27,27,25,15};
const char boldH[] = {27,27,27,31,27,27,27};
const char boldI[] = {15,6,6,6,6,6,15};
const char boldJ[] = {15,6,6,6,22,30,14};
const char boldK[] = {25,26,28,30,27,27,27};
const char boldL[] = {24,24,24,24,24,27,31};
const char boldM[] = {17,27,31,27,27,27,27};
const char boldN[] = {25,29,31,27,25,25,25};
const char boldO[] = {14,27,27,27,27,27,14};
const char boldP[] = {30,27,27,30,24,24,24};
const char boldR[] = {30,27,27,30,28,26,27};
const char boldS[] = {14,27,24,14,3,27,14};
const char boldT[] = {31,31,21,4,4,4,14};
const char boldU[] = {27,27,27,27,27,27,14};
const char boldV[] = {27,27,27,27,27,14,4};
const char boldW[] = {27,27,27,27,31,27,17};
const char boldX[] = {27,27,10,4,10,27,27};
const char boldY[] = {27,27,27,27,14,4,14};
const char boldZ[] = {31,19,2,4,8,25,31};

const char bold0[] = {14,27,27,27,27,27,14};
const char bold1[] = {2,6,14,6,6,6,6};

const char bold2[] = {14,27,3,6,12,24,31};
const char bold3[] = {14,27,3,14,3,27,14};
const char bold4[] = {3,7,15,27,31,3,3};
const char bold5[] = {31,24,30,3,3,27,14};
const char bold6[] = {14,27,24,30,27,27,14};
const char bold7[] = {31,3,6,12,12,12,12};
const char bold8[] = {14,27,27,14,27,27,14};
const char bold9[] = {14,27,27,15,3,27,14};

//const char openBracket[]  = {3,3,15,31,15,3,3};
//const char closeBracket[] = {24,24,30,31,30,24,24};


dlineStructure my_dline_chars[] = 
{                                   // index
    {dlineSpace,  ' ', DLINES, FALSE, 0},  // 0
    {dlineA,      'A', DLINES, FALSE, 0},  // 1
    {dlineB,      'B', DLINES, FALSE, 0},  // 2
    {dlineC,      'C', DLINES, FALSE, 0},  // 3
    {dlineD,      'D', DLINES, FALSE, 0},  // 4
    {dlineE,      'E', DLINES, FALSE, 0},  // 5
    {dlineI,      'I', DLINES, FALSE, 0},  // 6    
    {dlineM,      'M', DLINES, FALSE, 0},  // 7
    {dlineN,      'N', DLINES, FALSE, 0},  // 8
    {dlineO,      'O', DLINES, FALSE, 0},  // 9
    {dlineP,      'P', DLINES, FALSE, 0},  // 10
    {dlineR,      'R', DLINES, FALSE, 0},  // 11  
    {dlineS,      'S', DLINES, FALSE, 0},  // 12
    {dlineT,      'T', DLINES, FALSE, 0},  // 13
    {dlineU,      'U', DLINES, FALSE, 0},  // 14   
    {dlineY,      'Y', DLINES, FALSE, 0},  // 15
    
    {dline0,      '0', DLINES, FALSE, 0},  // 16
    {dline1,      '1', DLINES, FALSE, 0},  // 17
    {dline2,      '2', DLINES, FALSE, 0},  // 18
    {dline3,      '3', DLINES, FALSE, 0},  // 19
    {dline4,      '4', DLINES, FALSE, 0},  // 20
    {dline5,      '5', DLINES, FALSE, 0},  // 21
    {dline6,      '6', DLINES, FALSE, 0},  // 22
    {dline7,      '7', DLINES, FALSE, 0},  // 23
    {dline8,      '8', DLINES, FALSE, 0},  // 24
    {dline9,      '9', DLINES, FALSE, 0},  // 25    

};

/*
boldStructure my_bold_chars[] = {                                   
                                    // index
    {boldA,      "A", BOLDS, FALSE},    // 0
    {boldB,      "B", BOLDS, FALSE},    // 1
    {boldC,      "C", BOLDS, FALSE,    // 2
    {boldD,      "D", BOLDS, FALSE},    // 3
    {boldE,      "E", BOLDS, FALSE},    // 4
};
 */

void CreateCustomCharacter (const char *Pattern, unsigned char cgramPos) { 
    unsigned char cgramaddr = 0;
    int i=0; 
    cgramaddr = cgramPos*8;
    while(BusyXLCD());
    SetCGRamAddr (cgramaddr);
    //LCDWriteCmd (0x40+(cgramPos*8));     //Send the Address of CGRAM
    for (i=0; i<8; i++){
        while(BusyXLCD());
        WriteDataXLCD (Pattern[i]);         //Pass the bytes of pattern on LCD 
    }
    //__delay_ms(50);
}


void LCDWriteCustomString_dlines (unsigned char x, unsigned char y, const char *my_text, unsigned char add_line, char add_char) {
    unsigned char lcd_i;
    unsigned char dline_index = 0;
    unsigned char lcd_offset = 0;
    unsigned char cgram_pos = 0;
    //unsigned char char_to_convert[];
    //unsigned char offsetstring[5];
    // find requested ddram address
    unsigned char initial_ddramaddress = 0;
    unsigned char ddramaddress_offset = 0;
    
    if (x > (INITIAL_MAXX - 1)) x = 0;      // t.b.d.
    if (y > (INITIAL_MAXY - 1)) y = 0;      // t.b.d.
    switch ( y ) { 
        case 0:  {
            initial_ddramaddress = (0x00 + x); 
            break;
        }   // row 1
        case 1:  {
            initial_ddramaddress = (0x40 + x); 
            break;
        }   // row 2
        case 2:  {
            initial_ddramaddress = (START_ROW3 + x); 
            break;
        }   // row 3
        case 3:  {
            initial_ddramaddress = (START_ROW4 + x); 
            break;
        }   // row 4
        default: {
            initial_ddramaddress = (0x00 + x); 
            break;
        }   // row 1
    }
    while(BusyXLCD());
    SetDDRamAddr(initial_ddramaddress);
    
    lcd_offset = strlen(my_text); // keep string lenght no more than 8 not repeated symbols
    //max_dline_index = DLINES;
    if (lcd_offset > INITIAL_MAXX) lcd_offset = INITIAL_MAXX;
    cgram_pos = 0;
    ddramaddress_offset = 0;
    for (lcd_i = lcd_offset; lcd_i; lcd_i--){
        for (dline_index = 0; dline_index < DLINES; dline_index++) {
            if (my_dline_chars[dline_index].ascii_dline_char == *my_text) {
                if (0) { // (my_dline_chars[dline_index].dline_used)
                    while(BusyXLCD());
                    SetDDRamAddr(initial_ddramaddress + ddramaddress_offset);
                    while(BusyXLCD());
                    WriteDataXLCD(my_dline_chars[dline_index].in_dline_pos);
                    //dline_index = 0;
                    break;
                } else {               
                    my_dline_chars[dline_index].dline_used = TRUE;
                    my_dline_chars[dline_index].in_dline_pos = cgram_pos;
                    CreateCustomCharacter(my_dline_chars[dline_index].dlineChar, cgram_pos);
                    while(BusyXLCD());
                    SetDDRamAddr(initial_ddramaddress + ddramaddress_offset);
                    while(BusyXLCD());
                    WriteDataXLCD(cgram_pos);
                    cgram_pos++;
                    //dline_index = 0;
                    break;
                }
            }            
        }
        if (cgram_pos > 7) break; // custom characters cgram is full, ignore the rest of the text
        my_text++;
        ddramaddress_offset++;
        //dline_index = 0;
    }
    //WriteDataXLCD(2);
    if (add_line){
        //if (add_char == SELECTION_CHAR) {
        //    WriteDataXLCD(2);
        //    lcd_offset++;
        //}
        
        gotoxy(x+lcd_offset+1, y);
        for (lcd_i = INITIAL_MAXX - lcd_offset - x - 1; lcd_i; lcd_i--) {
            while(BusyXLCD());
            putcXLCD(add_char);
        }
    }
}
