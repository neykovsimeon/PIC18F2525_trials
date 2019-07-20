#include <stdlib.h>
#include <plib/delays.h>
#include <plib/adc.h>

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
    OpenADC(ADC_FOSC_2 & ADC_RIGHT_JUST & ADC_4_TAD, ADC_CH0 & ADC_INT_ON & ADC_REF_VREFPLUS_VSS, ADC_2ANA);
}