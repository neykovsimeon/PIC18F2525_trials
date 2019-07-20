#include <stdlib.h>
#include <plib/delays.h>
#include <plib/adc.h>
#include <plib/spi.h>


#define DISPLAY_DEFAULT         0           // display voltmeter and ampermeter
#define DISPLAY_U_SET           1           // display output voltage set, dac v set
#define DISPLAY_I_PROT_SET      2           // display output voltage set, dac v set
#define DISPLAY_I_LIMIT_SET     3           // display output voltage set, dac v set
#define DISPLAY_I_AUTO_LIMIT    4           // select constant power disipation mode
#define DISPLAY_SET_CONTRAST    5           // select contrast or brightness settings
#define DISPLAY_SET_BRIGHTNESS  6           // select contrast or brightness settings
#define DISPLAY_PROTECTION      7           // select contrast or brightness settings

#define INC_VALUE               1           // select contrast or brightness settings
#define DEC_VALUE               0           // select contrast or brightness settings
#define I_MODE_PROTECTION       0           // shutdown the output when I out/measure  exceed I set
#define I_MODE_LIMIT            1           // control the I output = I set (output is active, voltage clamp could occur)
#define I_MODE_PCONST           2           // limit power disipation og the output driver no more than 6W (I limit/prot = 6 / (Uin-Uo))
#define FINE                    1           // step size fine
#define ROUGH                   0           // step size rough


// digital pots variables spi MCP42010
#define CMD_DIG_POT_NONE 0                          // dummy command, no effect
#define CMD_DIG_POT0_WRITE_BYTE     0b00010001      // write data byte to pot0 -> contrast
#define CMD_DIG_POT1_WRITE_BYTE     0b00010010      // write data byte to pot1 -> brightness
#define CMD_DIG_POTBOTH_WRITE_BYTE  0b00010011      // write data byte to oth pots
#define CMD_DIG_POT0_SHDN           0b00100001      // SHDN pot0
#define CMD_DIG_POT1_SHDN           0b00100010      // SHDN pot1
#define CMD_DIG_POTBOTH_SHDN        0b00100011      // SHDN Both pots

// dac variables
unsigned int DAC_i = 2;
unsigned int DAC_u = 2;
unsigned char cmd_dac_i_high = 0;
unsigned char dac_i_low = 0;
unsigned char cmd_dac_u_high = 0;
unsigned char dac_u_low = 0;
unsigned char cmd_dac = 0b01110000;

// dig pots variables
unsigned char cmd_dig_pot = 0;
unsigned char send_byte = 0;
unsigned int display_contrast = 200;     
unsigned int display_brightness = 90;  

void init_ADC (void){
    // initialize ADC
    // FOSC/2
    // result is right justified
    // aqc time 2 AD
    // channel 1 for sampling
    // ADC interrupt ON
    // ADC ref voltage VDD vs GND(VSS)
    
    unsigned char channel=0x00,config1=0x00,config2=0x00,config3=0x00,portconfig=0x00,i=0;
        
    config1 = ADC_FOSC_2 | ADC_RIGHT_JUST | ADC_4_TAD ;
    config2 = ADC_CH0 | ADC_INT_ON | ADC_REF_VREFPLUS_VSS ;
    portconfig = ADC_2ANA ;
    
    CloseADC();
    OpenADC(ADC_FOSC_2 & ADC_RIGHT_JUST & ADC_4_TAD, ADC_CH0 & ADC_INT_OFF & ADC_REF_VREFPLUS_VSS, ADC_2ANA);
}
void init_dig_pot_SPI (void) {
    
    unsigned char config_sync_mode = SPI_FOSC_64; 
    unsigned char config_bus_mode = MODE_10;
    unsigned char config_smp_phase = SMPMID;
    
    OpenSPI( config_sync_mode, config_bus_mode, config_smp_phase);
}

void send_contrast_spi (void) {

    init_dig_pot_SPI ();
    cmd_dig_pot = CMD_DIG_POT0_WRITE_BYTE;
    send_byte = 256 - display_contrast;
    SPI_CS_DISPLAY = 0;
    NOP(); NOP(); NOP();
    WriteSPI(cmd_dig_pot);
    WriteSPI(send_byte);
    SPI_CS_DISPLAY = 1;
    CloseSPI();
}

void send_backlight_spi (void) {
    init_dig_pot_SPI ();
    cmd_dig_pot = CMD_DIG_POT1_WRITE_BYTE;
    send_byte = display_brightness;
    SPI_CS_DISPLAY = 0;
    NOP(); NOP(); NOP();
    WriteSPI(cmd_dig_pot);
    WriteSPI(send_byte);
    SPI_CS_DISPLAY = 1;
    CloseSPI();
}

void init_dac_SPI (void) {
    
    unsigned char config_sync_mode = SPI_FOSC_64; 
    unsigned char config_bus_mode = MODE_10;
    unsigned char config_smp_phase = SMPMID;
    
    OpenSPI( config_sync_mode, config_bus_mode, config_smp_phase);
}

void send_dac_u_spi (void) {
    dac_u_low = DAC_u; // & 0b0000000011111111;
    cmd_dac_u_high = (DAC_u >> 8) & 0b00001111;
    cmd_dac_u_high = cmd_dac_u_high | cmd_dac;
    init_dac_SPI();
    SPI_CS_UOUT = 0;
    NOP(); NOP(); NOP();
    WriteSPI(cmd_dac_u_high);
    WriteSPI(dac_u_low);
    SPI_CS_UOUT = 1;
    CloseSPI();
}

void send_dac_i_spi (void) {
    dac_i_low = DAC_i; // & 0b0000000011111111;
    cmd_dac_i_high = (DAC_i >> 8) & 0b00001111;
    cmd_dac_i_high = cmd_dac_i_high | cmd_dac;
    init_dac_SPI();
    SPI_CS_IOUT = 0;
    NOP(); NOP(); NOP();
    WriteSPI(cmd_dac_i_high);
    WriteSPI(dac_i_low);
    SPI_CS_IOUT = 1;
    CloseSPI();
}