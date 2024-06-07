#include "StdTypes.h"
#include "ADC_Interface.h"
#include "Sensors.h"
#include "Sensors_Cfg.h"


//RETUTN TEMP C*10
u16 TEMP_Read(){
	u16 volt = ADC_ReadVolt(LM35_CH);
	u16 temp = volt;
	return temp;
}

// RETURN PRESSURE *10
u16 PRESS_Read(){
	u16 adc = ADC_Read(MPX4115_CH);
	u16 press = (((u32)1000*(adc-55))/921)+150;
	return press;
}

u8 POT_Read(void){
	u16 adc = ADC_Read(POT_CH);
	u8 pot = (adc*(u32)100)/1023;
	return pot;
}