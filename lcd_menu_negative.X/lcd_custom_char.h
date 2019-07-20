/* 
 * File:   lcd_custom_char.h
 * Author: PC
 *
 */
#include <xc.h>

//unsigned char Pattern1[]= {0x0e,0x0e,0x04,0x04,0x1f,0x04,0x0a,0x0a}; 
//unsigned char Pattern2[]= {0x0e,0x0e,0x15,0x0e,0x04,0x04,0x0a,0x11};
//unsigned char Pattern3[]= {0x00,0x00,0x0a,0x15,0x11,0x0a,0x04,0x00};
//unsigned char Pattern4[]= {0x00,0x00,0x0a,0x1f,0x1f,0x0e,0x04,0x00};


#define DLINES  26
#define BOLDS   5

typedef struct customChar_dline {
    const char      *dlineChar;
    const char      ascii_dline_char;
    const char      num_dlines;
    bool            dline_used; 
    unsigned char   in_dline_pos;
}dlineStructure;

/*
typedef const struct customChar_bold {
    const char *boldChar;
    const char ascii_bold_char;
    const char num_bolds;
    bool       bold_used;
    unsigned char   in_bold_pos;    
    //void ( *fp ) (void);
}boldStructure;
*/
extern dlineStructure my_dline_chars[];
//extern boldStructure my_bold_chars[];

const char openBracket[]  = {3,3,15,31,15,3,3};
const char closeBracket[] = {24,24,30,31,30,24,24};

void CreateCustomCharacter (const char *Pattern, const char Location);
void clear_display_black (void);
void LCDWriteCustomString_dlines (unsigned char x, unsigned char y, const char *my_text, unsigned char add_line, char add_char);
