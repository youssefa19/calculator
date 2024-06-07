#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Segment_Interface.h"
#include "Segment_Cfg.h"

unsigned char seg[]={0X3f,0X06,0X5b,0X4f,0X66,0X6d,0X7d,0X07,0X7f,0X6f};
	
void SEG_Display(unsigned char n){
		unsigned char b0,b1;
		b0=n%10;
		b1=n/10;
		DIO_WritePin(TRANSISTROR2,HIGH);
		DIO_WritePin(TRANSISTROR1,LOW);
		SEG_Write(seg[b1]);
		_delay_ms(1);
		DIO_WritePin(TRANSISTROR1,HIGH);
		DIO_WritePin(TRANSISTROR2,LOW);
		SEG_Write(seg[b0]);
		_delay_ms(1);

}
void SEG_Write(u8 data){
	/*for(u8 i=0;i< 7;i++){
		DIO_WritePin(SEG_PINArray[i],(DIO_PinVoltage_type)READ_BIT(data,i));
	}*/
    DIO_WritePort(PB,0X00);

	 DIO_WritePort(PB,data);
}
	
	

	
	
/*
void segment_display(unsigned char n){
	unsigned char b0,b1;
	b0=n%10;
	b1=n/10;
	PORTA=seg[b0]<<1;
	PORTA=seg[b1]<<1;
}


void segment_display_hex(unsigned char n){
	unsigned char b0,b1;
	b0=n&0x0f;
	b1=n>>4;
	PORTA=seg[b0];
	PORTA=seg[b1];
}
*/