#ifndef __XLCD_H
#define __XLCD_H
#include "p18cxxx.h"
/* PIC18 XLCD peripheral routines.
 *
 *   Notes:
 *      - These libraries routines are written to support the
 *        Hitachi HD44780 LCD controller.
 *      - The user must define the following items:
 *          - The LCD interface type (4- or 8-bits)
 *          - If 4-bit mode
 *              - whether using the upper or lower nibble
 *          - The data port
 *              - The tris register for data port
 *              - The control signal ports and pins
 *              - The control signal port tris and pins
 *          - The user must provide three delay routines:
 *              - DelayFor18TCY() provides a 18 Tcy delay
 *              - DelayPORXLCD() provides at least 15ms delay
 *              - DelayXLCD() provides at least 5ms delay
 */

/* Interface type 8-bit or 4-bit
 * For 8-bit operation uncomment the #define BIT8
 */
/* #define BIT8 */

/* When in 4-bit interface define if the data is in the upper
 * or lower nibble.  For lower nibble, comment the #define UPPER
 */
/* #define UPPER */

/* DATA_PORT defines the port to which the LCD data lines are connected */
 #define DATA_PORT      		PORTB
 #define TRIS_DATA_PORT 		TRISB

/* CTRL_PORT defines the port where the control lines are connected.
 * These are just samples, change to match your application.
 */
 #define RW_PIN   LATCbits.LATC2   		/* PORT for RW */
 #define TRIS_RW  TRISCbits.RC2    	/* TRIS for RW */

 #define RS_PIN   LATCbits.LATC0   		/* PORT for RS */
 #define TRIS_RS  TRISCbits.RC0    	/* TRIS for RS */

 #define E_PIN    LATCbits.LATC1  		/* PORT for D  */
 #define TRIS_E   TRISCbits.RC1    	/* TRIS for E  */

#endif
