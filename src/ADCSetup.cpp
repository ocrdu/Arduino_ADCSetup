#include "ADCSetup.h"

void ADCsetup(unsigned int prescaler, unsigned int cyclesPerSample) {
  int my_ADC_CTRLB_PRESCALER_DIV;
  int my_SAMPCTRLREGVal;
  
  if (prescaler == 4) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV4;
  } else if (prescaler == 8) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV8;
  } else if (prescaler == 16) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV16;
  } else if (prescaler == 32) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV32;
  } else if (prescaler == 64) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV64;
  } else if (prescaler == 128) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV128;
  } else if (prescaler == 256) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV256;
  } else if (prescaler == 512) {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV512;
  } else {
    my_ADC_CTRLB_PRESCALER_DIV = ADC_CTRLB_PRESCALER_DIV512;
  }
  ADC->CTRLB.reg = my_ADC_CTRLB_PRESCALER_DIV | ADC_CTRLB_RESSEL_12BIT;
  while (ADC->STATUS.bit.SYNCBUSY);
  
  if (cyclesPerSample < 0) {
    cyclesPerSample = 0;
  }
  if (cyclesPerSample > 63) {
    cyclesPerSample = 63;
  }
  ADC->SAMPCTRL.reg = cyclesPerSample;
  
  analogReadCorrection(20, 2080);
}
