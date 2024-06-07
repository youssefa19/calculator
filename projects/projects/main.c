#include "StdTypes.h"
#include "MemMap.h"
#define f_cpu 80
#define  F_CPU 8000000
#include <util/delay.h>
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Button_Interface.h"
#include "Motors_Interface.h"
#include "Car_Interface.h"
#include "Stop_Watch.h"
#include "Segment_Interface.h"
#include "MAN_GAME.h"
#include "KeyPad_Interface.h"
#include "ADC_Interface.h"
#include "Stepper.h"
#include "Sensors.h"
#include "EX_Interrupt.h"


int main(void)
{ 
	u8 key;
	
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	char customChar[8] = {
		0b00000,
		0b01010,
		0b10101,
		0b10001,
		0b01010,
		0b00100,
		0b00000,
		0b00000
	};
	//LCD_CustomChar(2,customChar);
	while (1) 
    {  
		 Display_menu_calculator();
		 
	}
}
