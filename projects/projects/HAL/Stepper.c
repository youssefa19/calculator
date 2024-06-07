#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Stepper.h"

#define  F_CPU 8000000
#include <util/delay.h>

  
void STEPPER_BiPolar_CW(void)
{
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	
	_delay_ms(DELAY);
	
}

void STEPPER_BiPolar_CCW(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);

	
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);

	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
}

void STEPPER_UniPolar_CW(void)
{
	
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);

	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);

	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
}

void STEPPER_UniPolar_CCW(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);

	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);

	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
}

void STEPPER_UniPolar_CW_HS(void)
{
	

	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);

	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);

	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);

	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,HIGH);

	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	
	_delay_ms(DELAY);
	
}


void STEPPER_UniPolar_CW_ByAngle(u32 angle)
{
	for(u32 i=0;i<(2048*angle)/(4*360);i++)
	STEPPER_UniPolar_CW();
}
void STEPPER_UniPolar_CCW_ByAngle(u32 angle)
{
	for(u32 i=0;i<(2048*angle)/(4*360);i++)
	STEPPER_UniPolar_CCW();
}
void STEPPER_UniPolar_CW_ByRotation(u32 rotation)
{
	for(u32 i=0;i<512*rotation;i++)
	STEPPER_UniPolar_CW();
}
void STEPPER_UniPolar_CCW_ByRotation(u32 rotation)
{
	for(u32 i=0;i<512*rotation;i++)
	STEPPER_UniPolar_CCW();
}
