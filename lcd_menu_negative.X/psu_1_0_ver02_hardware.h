#include <stdlib.h>
#include <plib/delays.h>
#include "xlcd.h"

// user HW definitions
#define DISPLAY_SET_MODE_SELECT RE3                     // digital input button, active low -> select contrast or brightness control
#define SPI_CS_IOUT             LATAbits.LATA7          // digital output cs dac i set  
#define ROTARY_DA               PORTAbits.RA4           // digital input button, active low -> contrast / brightness decrease
#define SPI_CS_UOUT             LATBbits.LATB4          // digital output cs dac v set
#define DISPLAY_SET_UP          PORTAbits.RA5           // digital input button, active low -> contrast / brightness increase
#define DISPLAY_SET_DOWN        PORTAbits.RA6           // digital input button, active low -> contrast / brightness decrease
#define ROTARY_SW               PORTAbits.RA2           // digital input button, active low -> output settings menu
#define SPI_CS_DISPLAY          LATBbits.LATB6          // digital output, cs digital pot for displ contrast and brightness
#define ROTARY_CK               PORTBbits.RB7           // digital input button, active low -> contrast / brightness decrease
#define IPROT                   PORTBbits.RB5           // digital input, interrup on change -> detect current regulator comparator

void init_GPIO_DIR (void);

