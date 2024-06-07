#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "KeyPad_Cfg.h"
#include "KeyPad_Interface.h"



//FIRST STEP SET HIGH FOR ALL PIN
void KEYPAD_Init(){
	for (u8 row = 0; row<ROWS;row++)
	{
		DIO_WritePin(Key_PINS[row][0],HIGH);
		
	}
}

u8 KEYPAD_GetKey(){
	u8 row,col,key='N';
	
	for(row=0;row<ROWS;row++){
		DIO_WritePin(Key_PINS[row][0],LOW);
		for(col=0;col<COLS;col++){
			if(DIO_ReadPin(Key_PINS[col][1]) == LOW){
				key = Key_Array[row][col];
				while(DIO_ReadPin(Key_PINS[col][1]) == LOW){}
			}
		}
		DIO_WritePin(Key_PINS[row][0],HIGH);
	}
	return key;
}

