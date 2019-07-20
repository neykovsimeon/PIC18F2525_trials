//#include "LCD_user_functions.h"
//#include "lcd_trials_4bits.h"

#define _XTAL_FREQ 8000000
// Define display type
#define TRUE  1
#define FALSE 0
#define DISPLAY_16x4
//#define DISPLAY_20x4
//#define DISPLAY_16x2
#define VISIBLE_MENU_HEADER TRUE

// Define selection symbol
#define SELECTION_CHAR      '>'
#define SELECTION_CHAR_END  '<'

#ifdef DISPLAY_16x4
    #define DISPLAY_ROWS    4
    #define UPPER_SPACE     2
    #define LOWER_SPACE     1
    #define INITIAL_MAXX    16
    #define INITIAL_MAXY    4
    #define START_ROW3      0x10
    #define START_ROW4      0x50
#endif

#ifdef DISPLAY_20x4
    #define DISPLAY_ROWS    4
    #define UPPER_SPACE     2
    #define LOWER_SPACE     1
    #define INITIAL_MAXX    20
    #define INITIAL_MAXY    4
    #define START_ROW3      0x14
    #define START_ROW4      0x54
#endif

#ifdef DISPLAY_16x2
    #define DISPLAY_ROWS    2
    #define UPPER_SPACE     1
    #define LOWER_SPACE     0
    #define INITIAL_MAXX    16
    #define INITIAL_MAXY    2
    #define START_ROW3      0x00
    #define START_ROW4      0x40
#endif

#ifdef DISPLAY_20x2
    #define DISPLAY_ROWS    2
    #define UPPER_SPACE     1
    #define LOWER_SPACE     0
    #define INITIAL_MAXX    20
    #define INITIAL_MAXY    2
    #define START_ROW3      0x00
    #define START_ROW4      0x40
#endif

typedef const struct MenuStructure {
    const char *text;
    unsigned char num_menupoints;
    unsigned char up;
    unsigned char down;
    unsigned char enter;
    void ( *fp ) (void);
}MenuEntry;

extern MenuEntry my_menu[];
extern unsigned char selected;

void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);
void Delay1Sec(void);
void DelayHalfSec(void);
void Delay200ms(void);

void start (void);
void show_menu(void);
void LCDWriteStringROM (unsigned char x, unsigned char y, const char *lcd_menu_items, unsigned char add_line, char add_char);
void LCDWriteCmd (unsigned char command);
void gotoxy (unsigned char x_pos, unsigned char y_pos);
void clear_display (void);


