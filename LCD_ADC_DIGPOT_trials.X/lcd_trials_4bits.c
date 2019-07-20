/*
 * File:   lcd_trials_4bits.c
 * Author: PC
 *
 * Created on September 8, 2018, 4:19 PM
 */

#include <xc.h>
#include <math.h>
#include <stdint.h>              // needed for uint8_t types, etc
#include <stdbool.h>             // needed for boolean types, etc
#include <stdio.h>
#include <stdlib.h>

#include "lcd_trials_4bits.h"
#include "LCD_user_functions.h"
#include "ADC_user_functions.h"
#include <plib/adc.h>
#include <plib/delays.h>
#include <plib/spi.h>
#include "xlcd.h"

/*
#define DISPLAY_DEFAULT         0           // display voltmeter and ampermeter
#define DISPLAY_U_SET           1           // display output voltage set, dac v set
#define DISPLAY_I_PROT_SET      2           // display output voltage set, dac v set
#define DISPLAY_I_LIMIT_SET     3           // display output voltage set, dac v set
#define DISPLAY_I_AUTO_LIMIT    4           // select constant power disipation mode
#define DISPLAY_SET_CONTRAST    5           // select contrast or brightness settings
#define DISPLAY_SET_BRIGHTNESS  6           // select contrast or brightness settings
#define INC_VALUE               1           // select contrast or brightness settings
#define DEC_VALUE               0           // select contrast or brightness settings
#define I_MODE_PROTECTION       0           // shutdown the output when I out/measure  exceed I set
#define I_MODE_LIMIT            1           // control the I output = I set (output is active, voltage clamp could occur)
#define I_MODE_PCONST           2           // limit power disipation of the output driver no more than 6W (I limit/prot = 6 / (Uin-Uo))


// digital pots variables spi MCP42010
#define CMD_DIG_POT_NONE 0                          // dummy command, no effect
#define CMD_DIG_POT0_WRITE_BYTE     0b00010001      // write data byte to pot0 -> contrast
#define CMD_DIG_POT1_WRITE_BYTE     0b00010010      // write data byte to pot1 -> brightness
#define CMD_DIG_POTBOTH_WRITE_BYTE  0b00010011      // write data byte to oth pots
#define CMD_DIG_POT0_SHDN           0b00100001      // SHDN pot0
#define CMD_DIG_POT1_SHDN           0b00100010      // SHDN pot1
#define CMD_DIG_POTBOTH_SHDN        0b00100011      // SHDN Both pots
*/

//unsigned char cmd_dig_pot = 0;
//unsigned char send_byte = 0;



// adc valiables
unsigned int ADCResult = 0;
unsigned char ResultString_u[10];
unsigned char ResultString_i[10];
unsigned char ResultString_set_u[10];
unsigned char ResultString_set_i[10];
//float vRef = 4.83;            //  vdd
float ADC_vRef = 2.5;           // tl41div
float DAC_vRef = 2.5;           // tl41div
//float vRef = 1.024;           // tl41div trimmed
float voltage_u=0;
float voltage_i=0;
float raw_adc_offset_voltage = 0.015;  // calibration variable 
//float constant_power_disipation = 6.0; // 6.0W constant power for automated i limit setting

// dac variables
//unsigned int DAC_i = 0;
//unsigned int DAC_u = 0;
//unsigned char cmd_dac_i_high = 0;
//unsigned char dac_i_low = 0;
//unsigned char cmd_dac_u_high = 0;
//unsigned char dac_u_low = 0;
//unsigned char cmd_dac = 0b01110000;



float constant_power = 10.0;
float voltage_in = 16; // will be measured with external adc if tracking pre-regulator is implemented

// supply output settings display variables
float voltage_set_u =0;
float voltage_set_i =0;

// display variables
unsigned char display_mode = DISPLAY_DEFAULT;               // select display mode (default -> ADC, v set, i set, i mode select, contrast, brightness )
//unsigned int display_contrast = 200;                       // byte to communicate to digital pot
float display_contrast_percent;            // in percent: (display_contrast/255)*100
unsigned char ResultString_contrast_percent[5];
unsigned char ResultString_contrast[5];
//unsigned int display_brightness = 90;                                 // byte to communicate to digital pot
float display_brightness_percent;        // in percent: (display_brightness/255)*100
unsigned char ResultString_brightness[5];
unsigned char ResultString_brightness_percent[5];

// general purpose variables
unsigned int main_loop_counter = 0;
unsigned int button_delay_counter = 0;
unsigned int return_default_display_counter = 0;
bool set_contrast = 0;  // 0-> set brightness, 1-> set contrast
bool button_enable = 1; // 1-> button enabled, 0 -> button disabled
bool button_delay_counter_enable = 0;
bool return_default_display_counter_enable = 0;
unsigned char i_mode = 0;
unsigned int step_size = 1;
//unsigned int step_size_rough = 10;
bool step_size_mode = FINE; 
bool step_size_mode_enable = 1;

bool rotary_direction = 0; // this is current limit
// ADC functions
void init_ADC (void);
void send_contrast_spi (void);


/* LCD lib related User defines these routines according to the oscillator frequency */
void init_XLCD (void);
void DelayFor18TCY(void);       // 18 cycles
void DelayPORXLCD(void);        // 15ms
void DelayXLCD(void);           // 5ms

// general purpose delays
void Delay1Sec(void);
void DelayHalfSec(void);
void Delay200ms(void);
void init_GPIO_DIR (void);

void default_display (void){
    // display voltmeter and ampermeter if default display
      SetDDRamAddr (0x00);
      putrsXLCD("Uo=");
      SetDDRamAddr (0x40);
      putrsXLCD("Io=");
      SetDDRamAddr (0x03);
      putsXLCD(ResultString_u);
      putrsXLCD("V          ");
      SetDDRamAddr (0x43);        
      putsXLCD(ResultString_i);
      putrsXLCD("A          ");
      SetDDRamAddr (0x0D);
    switch (i_mode){
        case I_MODE_PROTECTION:{
            putrsXLCD("PRO");
            //voltage_set_i = (DAC_i*DAC_vRef)/4096; // convert 12bit DAC count into voltage
            sprintf(ResultString_set_i, "%-.2g", voltage_set_i);
            SetDDRamAddr (0x4C);
            putsXLCD(ResultString_set_i);
            putrsXLCD("A          ");
            break;
        }
        case I_MODE_LIMIT:{
            putrsXLCD("LIM"); 
            //voltage_set_i = (DAC_i*DAC_vRef)/4096; // convert 12bit DAC count into voltage
            sprintf(ResultString_set_i, "%-.2g", voltage_set_i);
            SetDDRamAddr (0x4C);
            putsXLCD(ResultString_set_i);  
            putrsXLCD("A          ");
            break;
        }

        case I_MODE_PCONST:{
            putrsXLCD("PWR");   
            voltage_set_i = constant_power / (voltage_in - voltage_u);
            DAC_i = (voltage_set_i * 4096) / DAC_vRef;
            sprintf(ResultString_set_i, "%-.2g", voltage_set_i);
            SetDDRamAddr (0x4C);
            putsXLCD(ResultString_set_i);  
            putrsXLCD("A          ");            
            break;
        }

        default:{
            break;
        }
    }      
}

void contrast_display (void) {
    // display contrast settings
      display_contrast_percent = ((display_contrast)*100)/255;
      sprintf(ResultString_contrast, "%-3u", (display_contrast));
      sprintf(ResultString_contrast_percent, "%3.3g", display_contrast_percent);
      SetDDRamAddr (0x00);
      if (step_size_mode == FINE) {
        //putrsXLCD("CONTRAST        ");
        putrsXLCD("CONTRAST FINE:  ");
      } else{
        //putrsXLCD("CONTRAST        ");
        putrsXLCD("CONTRAST ROUGH: ");
      }
      //putrsXLCD("CONTRAST:       ");
      SetDDRamAddr (0x40);
      putrsXLCD("(1:255):");
      putrsXLCD(ResultString_contrast);
      SetDDRamAddr (0x4C);        
      putrsXLCD(ResultString_contrast_percent);
      putrsXLCD("%");
}

void brightness_display (void) {
    // display contrast settings
      display_brightness_percent = (display_brightness*100)/255;
      sprintf(ResultString_brightness, "%-3u", display_brightness);
      sprintf(ResultString_brightness_percent, "%3.3g", display_brightness_percent);
      SetDDRamAddr (0x00);
      if (step_size_mode == FINE) {
        //putrsXLCD("BACKLIGHT       ");
        putrsXLCD("BACKLIGHT FINE: ");
      } else{
        //putrsXLCD("BACKLIGHT       ");
        putrsXLCD("BACKLIGHT ROUGH:");
      }      
      //putrsXLCD("BACKLIGHT:      ");
      SetDDRamAddr (0x40);
      putrsXLCD("(1:255):");
      putrsXLCD(ResultString_brightness);
      SetDDRamAddr (0x4C);
      putrsXLCD(ResultString_brightness_percent);
      putrsXLCD("%");
}

void voltage_set_display (void) {
    // display contrast settings
      voltage_set_u = ((DAC_u*DAC_vRef)/4096)*6; // convert DAC count into voltage
      sprintf(ResultString_set_u, "%-.2g", voltage_set_u);
      SetDDRamAddr (0x00);
      putrsXLCD("Uset=");
      //SetDDRamAddr (0x40);
      //putrsXLCD("Uset=");
      putrsXLCD(ResultString_set_u);
      putrsXLCD("V        ");
      SetDDRamAddr (0x40);
      putrsXLCD("Uo=");
      sprintf(ResultString_u, "%-.2g", voltage_u);
      putrsXLCD(ResultString_u);
      putrsXLCD("V        ");
      SetDDRamAddr (0x4B);
      if (step_size_mode == FINE) {
        putrsXLCD(" FINE");
      } else{
        putrsXLCD("ROUGH");
      }
}

void current_protection_set_display (void) {
    // display contrast settings
      voltage_set_i = (DAC_i*DAC_vRef)/4096; // convert DAC count into voltage
      sprintf(ResultString_set_i, "%-.2g", voltage_set_i);
      SetDDRamAddr (0x00);   
      putrsXLCD("Iprot=");
      putrsXLCD(ResultString_set_i);
      putrsXLCD("A        ");
      SetDDRamAddr (0x40);
      sprintf(ResultString_i, "%-.2g", voltage_i);
      putrsXLCD("Io =");
      putrsXLCD(ResultString_i);
      putrsXLCD("A        ");
      SetDDRamAddr (0x4B);
      if (step_size_mode == FINE) {
        putrsXLCD(" FINE");
      } else{
        putrsXLCD("ROUGH");
      }
}

void current_limit_set_display (void) {
    // display contrast settings
      voltage_set_i = (DAC_i*DAC_vRef)/4096; // convert DAC count into voltage
      sprintf(ResultString_set_i, "%-.2g", voltage_set_i);
      SetDDRamAddr (0x00);      
      putrsXLCD("Ilimit=");
      putrsXLCD(ResultString_set_i);
      putrsXLCD("A        ");
      SetDDRamAddr (0x40);
      sprintf(ResultString_i, "%-.2g", voltage_i);
      putrsXLCD("Io =");
      putrsXLCD(ResultString_i);
      putrsXLCD("A         ");
      SetDDRamAddr (0x4B);
      if (step_size_mode == FINE) {
        putrsXLCD(" FINE");
      } else{
        putrsXLCD("ROUGH");
      }
}

void current_auto_limit_set_display (void) {
    // display contrast settings
      voltage_set_i = constant_power / (voltage_in - voltage_u);
      DAC_i = (voltage_set_i * 4096) / DAC_vRef;
      send_dac_i_spi();
      sprintf(ResultString_set_i, "%-.3g", voltage_set_i);
      SetDDRamAddr (0x00);
      putrsXLCD(" P=10W,  Uin=16V ");
      SetDDRamAddr (0x40);
      putrsXLCD("Iset=");
      putrsXLCD(ResultString_set_i);
      putrsXLCD("A           ");
}

void protection_display (void) {
    // display contrast settings
      clear_display();
      SetDDRamAddr (0x00);
      putrsXLCD("!! PROTECTION !!");
      SetDDRamAddr (0x40);
      putrsXLCD("!CHECK SETTINGS!");      
}

void interrupt rotary_encoder(void){
        // interrupt on change at portb_7 -> rotary encoder
    GIE = 0; // interrupts disabled. Interrupts will be enabled outside with delay (de-bouncing))
    if (RBIF == 1) {
    if ((IPROT == 1) && (i_mode == I_MODE_PROTECTION)) {
        //DAC_i = 0;
        //send_dac_i_spi();
        DAC_u = 0;
        send_dac_u_spi();
        DAC_u = 11;
        display_mode = DISPLAY_PROTECTION;
        return_default_display_counter = 0;
    } else {
        if (ROTARY_CK == ROTARY_DA) {
            rotary_direction = DEC_VALUE;
        } else {
            rotary_direction = INC_VALUE;
        }
        __delay_ms(1);
        return_default_display_counter = 0;
        switch (display_mode){
            case DISPLAY_U_SET:
            {
                if (rotary_direction == INC_VALUE) {
                    if ((DAC_u + step_size) < 4096) {                
                        DAC_u = DAC_u + step_size;
                    }
                //if ((DAC_u + step_size) > 4095) {
                //    DAC_u = DAC_u;
                //}
                    send_dac_u_spi();
                }
                if (rotary_direction == DEC_VALUE) {                          
                    if ((DAC_u - step_size) > step_size) {                
                        DAC_u = DAC_u - step_size;
                    }
                //if (DAC_u < step_size) {
                //    DAC_u = DAC_u;
                //}
                    send_dac_u_spi();
                }
            break;
        }
        case DISPLAY_I_PROT_SET:
        {
            if (rotary_direction == INC_VALUE) {
                if ((DAC_i + step_size) < 4096) {                
                    DAC_i = DAC_i + step_size;
                }
                //if ((DAC_i + step_size) > 4095) {
                //    DAC_i = DAC_i;
                //}
                send_dac_i_spi();
            }
            if (rotary_direction == DEC_VALUE) {                          
                if ((DAC_i - step_size) > step_size) {                
                    DAC_i = DAC_i - step_size;
                }
                //if (DAC_i < step_size) {
                //    DAC_i = DAC_i;
                //}
                send_dac_i_spi();
            }                        
            break;
        }
        case DISPLAY_I_LIMIT_SET:
        {
            if (rotary_direction == INC_VALUE) {
                if ((DAC_i + step_size) < 4096) {                
                    DAC_i = DAC_i + step_size;
                }
                //if ((DAC_i + step_size) > 4095) {
                //    DAC_i = DAC_i;
                //}
                send_dac_i_spi();
            }
            if (rotary_direction == DEC_VALUE) {                          
                if ((DAC_i - step_size) > step_size) {                
                    DAC_i = DAC_i - step_size;
                }
                //if (DAC_i < step_size) {
                //    DAC_i = DAC_i;
                //}
                send_dac_i_spi();
            }                        
            break;
        }
        case DISPLAY_I_AUTO_LIMIT:
        {                        
            break;
        }                                      
        default:
        {
            break;
        }
        }
    }
    if (ROTARY_CK == 1) NOP();
    if (ROTARY_CK == 0) NOP();
    RBIF = 0; // clear flag and mismatch condition
    }
    //return;    
}
    

void main(void) {
    
    OSCCON  = 0x76;     // internal 8MHz oscilator, RA6 and RA7 are GPIO
    CMCON   = 0x07;     // Comparator OFF, RA2 and RA5 are digital inputs
    
    //DAC_u = 3276;

    
    init_GPIO_DIR ();

    // interrupts registers setup
    // enable PORTB interrupt on change (encoder service)
    RBIE = 1;
    //INTERRUPT CONTROL REGISTER 2:
    INTCON2 = 0b00000000; // portb pull-ups disabled, RB Port Change Interrupt Priority low
   
    RCONbits.IPEN = 0;  // Interrupt High Priority disabled
    
    // initialization of the output voltmeter and ampermeter
    init_ADC ();
    
    // initialization of digital pots for contrast and back-light control
    send_contrast_spi ();
    send_backlight_spi ();
    
    // initialization of spi dacs for voltage and current settings
    send_dac_i_spi ();
    send_dac_u_spi ();
    
    init_XLCD();

    // LCD default intro screen and display voltmeter and ampermeter
    putrsXLCD("  Power Supply  ");
    SetDDRamAddr (0x40);
    putrsXLCD("v1.0");
    Delay1Sec();
    Delay1Sec();
    clear_display();
    
       
 // main cycle   
    while (1) {

        //main_loop_counter = main_loop_counter + 1;
        //if (main_loop_counter > 20) {
        //    main_loop_counter = 0;
        //}
               
        // 2) voltmeter and ampermeter: ADC default display
        ADCResult = 0;
        // adc as voltmeter and ampermeter
        // first channel - U(OUT))
        SetChanADC(ADC_CH0);
        for(int i=0;i<16;i++)
        {
            ConvertADC();
            while(BusyADC());
            ADCResult += (unsigned int) ReadADC();
        }
        ADCResult /= 16;
        voltage_u = (((ADCResult*ADC_vRef)/1024) + raw_adc_offset_voltage)*6; // convert ADC count into voltage
        //voltage_u = voltage_u + (raw_adc_offset_voltage * 6);
        sprintf(ResultString_u, "%-.3g", voltage_u);
        ADCResult = 0;
        
        // second channel - I(OUT))
        SetChanADC(ADC_CH1);
        for(int i=0;i<16;i++)
        {
            ConvertADC();
            while(BusyADC());
            ADCResult += (unsigned int) ReadADC();
        }
        ADCResult /= 16;
        voltage_i = raw_adc_offset_voltage + ((ADCResult*ADC_vRef)/1024); // convert ADC count into voltage
        sprintf(ResultString_i, "%-.3g", voltage_i);
        ADCResult = 0;
        
       // 3.1) Buttons check - display settings - contrast, brightness
        if (button_enable == 1){
            if (DISPLAY_SET_MODE_SELECT == 0){
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                set_contrast = ~set_contrast;
                display_mode = DISPLAY_SET_CONTRAST;
                if (set_contrast == 0) {
                    display_mode = DISPLAY_SET_BRIGHTNESS;
                }
                clear_display();
                return_default_display_counter_enable = 1;
                return_default_display_counter = 0;             
            }
            if (DISPLAY_SET_UP == 0) {
                switch (display_mode){
                    case DISPLAY_SET_CONTRAST:{
                        button_enable = 0;                  // enable de-bouncing delay, disable button function
                        button_delay_counter_enable = 1;
                        button_delay_counter = 0;
                        return_default_display_counter_enable = 1;
                        return_default_display_counter = 0;
                        if (display_contrast < (255 - step_size)) {
                        display_contrast = display_contrast + step_size;
                        }
                        if ((display_contrast +step_size) > 255) {
                            display_contrast = display_contrast;
                        }
                        send_contrast_spi ();
                        break;
                    }
                    case DISPLAY_SET_BRIGHTNESS:{
                        button_enable = 0;                  // enable de-bouncing delay, disable button function
                        button_delay_counter_enable = 1;
                        button_delay_counter = 0;
                        return_default_display_counter_enable = 1;
                        return_default_display_counter = 0;
                        if (display_brightness < (255 - step_size)) {
                        display_brightness = display_brightness + step_size;
                        }
                        if ((display_brightness + step_size) > 255) {
                            display_brightness = display_brightness;
                        }
                        send_backlight_spi ();
                        break;
                }
                    default:{
                        break;
                    }
                }
            }
            if (DISPLAY_SET_DOWN == 0) {
                switch (display_mode){
                    case DISPLAY_SET_CONTRAST:{
                        button_enable = 0;                  // enable de-bouncing delay, disable button function
                        button_delay_counter_enable = 1;
                        button_delay_counter = 0;
                        return_default_display_counter_enable = 1;
                        return_default_display_counter = 0;
                        if (display_contrast > step_size) {
                            display_contrast = display_contrast - step_size;
                            if (display_contrast < step_size) {
                                display_contrast = display_contrast;
                            }
                        }
                        send_contrast_spi ();
                        break;
                    }
                    case DISPLAY_SET_BRIGHTNESS:{
                        button_enable = 0;                  // enable de-bouncing delay, disable button function
                        button_delay_counter_enable = 1;
                        button_delay_counter = 0;
                        return_default_display_counter_enable = 1;
                        return_default_display_counter = 0;
                        if (display_brightness > step_size) {
                            display_brightness = display_brightness - step_size;
                            if (display_brightness < step_size) {
                                display_brightness = display_brightness;
                            }
                        }
                        send_backlight_spi ();
                        break;
                }
                    default:{
                        break;
                    }
                }
            }
        }
        
        // 3.2) Buttons check - output settings
        if (button_enable == 1){
            if (ROTARY_SW == 0){
                button_enable = 0;                  // enable de-bouncing delay, disable button function
                button_delay_counter_enable = 1;
                button_delay_counter = 0;
                if (display_mode < 5) {
                    display_mode = display_mode + 1;
                    GIE = 1; // enable interrupt on change at portb_7
                    if (display_mode > 4) {
                        display_mode = 0;
                        GIE = 0; // enable interrupt on change at portb_7
                    }
                    
                } else {
                    display_mode = 0;
                    GIE = 0; // enable interrupt on change at portb_7
                }
                clear_display();
                return_default_display_counter_enable = 1;
                return_default_display_counter = 0; 
                //GIE = 1; // enable interrupt on change at portb_7
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
        if (return_default_display_counter_enable == 1) {
            return_default_display_counter = return_default_display_counter + 1;
            if (return_default_display_counter > 66) {
                if (step_size_mode_enable == 1) {
                    step_size_mode =~step_size_mode;
                    step_size_mode_enable = 0;
                }
                if (step_size_mode == FINE) {
                    step_size = 1;
                } else{
                    step_size = 10;
                }
            } else {                                                                             
                step_size_mode_enable = 1;
            }
            if (return_default_display_counter > 120) {
                return_default_display_counter = 0;
                return_default_display_counter_enable = 0;
                display_mode = DISPLAY_DEFAULT;
                clear_display();
                GIE = 0;
                step_size_mode = FINE;
                step_size = 1;
                step_size_mode_enable = 1;
            }
        }
       // 4) DISPLAY     
        switch (display_mode){
            case DISPLAY_DEFAULT:
            {
                default_display ();
                GIE = 0;
                break;
            }
            case DISPLAY_U_SET:{
                voltage_set_display();
                GIE = 1;
                break;
            }
            case DISPLAY_I_PROT_SET:
            {  
                current_protection_set_display();
                GIE = 1;
                i_mode = I_MODE_PROTECTION;
                break;
            }
            case DISPLAY_I_LIMIT_SET:
            {
                current_limit_set_display();
                GIE = 1;
                i_mode = I_MODE_LIMIT;
                break;
            }
            case DISPLAY_I_AUTO_LIMIT:
            {
                current_auto_limit_set_display();
                i_mode = I_MODE_PCONST;
                GIE = 0;
                break;
            }
            case DISPLAY_SET_CONTRAST:
            {
                contrast_display();
                GIE = 0;
                break;
            }
            case DISPLAY_SET_BRIGHTNESS:
            {
                brightness_display();
                GIE = 0;
                break;
            }
            case DISPLAY_PROTECTION:
            {
                protection_display();
                GIE = 0;
                break;
            }
            default:
            {
                break;
            }              
        } 
        // 5) Cycle delay
        // introduce cycle delay
        //Delay200ms();
        //__delay_ms(500);
        __delay_ms(1);
        //GIE = 1;
        //DelayHalfSec();
    }
    return;
}
