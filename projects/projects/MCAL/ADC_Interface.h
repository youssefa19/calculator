 
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum{
	VREF_AREF,
	VREF_VCC,
	VREF_256	
}ADC_VoltRef_type;

typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Prescaler_type;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;

void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler);

// Return NUmber In port then calculate volt

u16 ADC_Read(ADC_Channel_type channel);

u16 ADC_ReadVolt(u8 CH);

u16 ADC_GetRead(void);

void ADC_StartConversion(ADC_Channel_type channel);

u8 ADC_GetReadPeriodicCheck(u16* pdate);

u16 ACD_GetReadNoBlock(void);

#endif /* ADC__INTERFACE_H_ */