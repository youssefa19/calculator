
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

#include "ADC_Interface.h"
#include "ADC_Cfg.h"

u16 volt_ref;
static u8 ADC_ReadFlag = 0;

void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler)
{
	/* vref*/
	switch(vref)
	{	//VREF_AREF (REFS1,REFS0)(0,0)
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		volt_ref= AREF;
		break;
		//VREF_VCC (REFS1,REFS0)(0,1)
		case VREF_VCC:
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		volt_ref= 5000;
		break;
		//VREF_VCC (REFS1,REFS0)(1,1)
		case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		volt_ref= 2560;
		break;
	}
		/*clock Setting Prescaler*/
		ADCSRA=ADCSRA&0xf8; // clear place for 3 bit of prescaler
		scaler=scaler&0x07;  //check number not greater than 3bit by clear other bits
		ADCSRA=ADCSRA|scaler; //place data without change 5bits
		
	/*ADC enable*/
	SET_BIT(ADCSRA,ADEN);
}
	
u16 ADC_Read(ADC_Channel_type channel)
{
	/* select ch using MUX*/
		ADMUX=ADMUX& 0xe0;
		ADMUX=ADMUX | channel;
	/* start conversion*/
	//ADSC set 1 if we need work adc when finish read hardware write 0
		SET_BIT(ADCSRA,ADSC);
	/*wait until end */
	  while(READ_BIT(ADCSRA,ADSC));
	/* get reading from 2 registers*/
	return ADC;
}

void ADC_StartConversion(ADC_Channel_type channel){
	if(!ADC_ReadFlag){
		/* select ch using MUX*/
		ADMUX=ADMUX& 0xe0;
		ADMUX=ADMUX | channel;
		/* start conversion*/
		//ADSC set 1 if we need work adc when finish read hardware write 0
		SET_BIT(ADCSRA,ADSC);
		ADC_ReadFlag=1;
	}
}

u8 ADC_GetReadPeriodicCheck(u16* pdate){
	if(!READ_BIT(ADCSRA,ADSC)){
		*pdate= ADC;
		ADC_ReadFlag=0;
		return 1;
	}
	return 0;
}

u16 ADC_GetRead(void){
	 /*wait until end */
	 while(READ_BIT(ADCSRA,ADSC));
	 /* get reading from 2 registers*/
	 return ADC;
}

// RETURN m_v
u16 ADC_ReadVolt(ADC_Channel_type CH){
	u16 adc= ADC_Read(CH);
	u16 volt =(adc*(u32)volt_ref)/1024;
	return volt;
}

u16 ACD_GetReadNoBlock(){
	  
}