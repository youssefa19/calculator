#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"
#include "Calculator_Interface.h"
#define  F_CPU 8000000
#include <util/delay.h>

static s32 result=0,num1=0,num2=0,num3=0,num=0;
const u8 Calc_Init[]="WELCOME";
const u8 Calc_Init2[]="My Calculator APP";

u8 POS_CUR=0,key,En_b=0;

u8 Array_Input[16]={0};


void Calc_start(){
	u8 i;
	s8 j;
	LCD_SetCursor(0,5);
	for(i=0;i<Calc_Init[i];i++){
	LCD_WriteChar(Calc_Init[i]);
	_delay_ms(100);
	}
	for(j = i+5;j>=0;j--){
		LCD_SetCursor(0,j);
		LCD_WriteChar(' ');
		_delay_ms(100);
	}
	LCD_SetCursor(0,0);
	for(i=0;Calc_Init2[i];i++){
		LCD_WriteChar(Calc_Init2[i]);
		_delay_ms(100);
	}
	for(j = i;j>=0;j--){
		LCD_SetCursor(0,j);
		LCD_WriteChar(' ');
		_delay_ms(100);
	}
	LCD_SetCursor(0,0);
}

void Calc_Select(){
	u8 select;
	LCD_Clear();
	LCD_SetCursor(0,2);
	LCD_WriteString("Select process");
	LCD_SetCursor(1,0);
	LCD_WriteString("1-math 2-convert");
	
	while(1){
		select = KEYPAD_GetKey();
		if (select == '1'||select == '2')
		{
			LCD_Clear();
			LCD_WriteString("START");
			_delay_ms(150);
			LCD_Clear();
			break;
		}
	}
	if(select == '1'){
		Get_Input();
	}else{
		Convert_select();
	}
}

void Get_Input(){
	u8 flag=0;
	while(1){
		key = KEYPAD_GetKey();
		
		if (key == '=')
		{
			Calc_opertion();
			break;
		} 
		else if ((key == '*'||key == '+'||key == '-'||key == '/')&flag)
		{
			LCD_WriteChar(key);	
			Calc_Add(key);	
		}else if(key>='0' && key<='9'){
			flag=1;
			LCD_WriteChar(key);	
			Calc_Add(key);
				
		}else if (key == 'c')
		{
			if (POS_CUR > 0)
			{
				--POS_CUR;
				LCD_ClearLoc(0,POS_CUR,8);
				LCD_SetCursor(0,POS_CUR);
			}
			
		}
	}
}

void Calc_Add(u8 key){
	Array_Input[POS_CUR]=key;
	POS_CUR++;
}

void  Calc_opertion(){
	u8 i,op1='0',op2='0',flag=1;
	for(i=0;i<POS_CUR;i++){
		if (Array_Input[i]>='0' && Array_Input[i]<='9')
		{
			num = num*10+Array_Input[i]-'0';
		}else if (Array_Input[i] =='-' || Array_Input[i]=='+' || Array_Input[i] =='*' || Array_Input[i]=='/')
		{
			if (flag == 1)
			{
				op1 = Array_Input[i];
				num1=num;
				flag++;
				num=0;
			}else if (flag == 2)
			{
				op2 = Array_Input[i];
				num2=num;
				num=0;
				flag++;
			}
			
		}
	}
	if (flag==3)
	{
		switch (op1){
			case '-':
			 result = num1-num2;
			break;
			case '+':
			 result = num1+num2;
			break;
			case '*':
			 result = num1*num2;
			break;
			case '/':
			 result = num1/num2;
			break;	
		}
		switch (op2){
			case '-':
			result = result-num;
			break;
			case '+':
			result = result+num;
			break;
			case '*':
			result = result*num;
			break;
			case '/':
			result = result/num;
			break;
		}
		  
	}else{
		switch (op1){
			case '-':
			result = num1-num;
			break;
			case '+':
			result = num1+num;
			break;
			case '*':
			result = num1*num;
			break;
			case '/':
			result = num1/num;
			break;
		}
	}
	POS_CUR=0;
	LCD_SetCursor(1,0);
	LCD_WriteNumber(result);
	gain();	
}

void Get_Input2(){
	while(1){
		key = KEYPAD_GetKey();
		if (key == '=')
		{
			Calc_opertion2();
			break;
	    }else if(key>='0' && key<='9'){
			LCD_WriteChar(key);
			Calc_Add(key);
		}else if (key == 'c')
		{
			LCD_SetCursor(0,0);
			LCD_Clear();
			POS_CUR=0;
			Calc_Select();
			break;
		}
	}
}

void  Calc_opertion2(){
	u8 i,op1,flag=1;
	num=0;
	for(i=0;i<POS_CUR;i++){
		if (Array_Input[i]>='0' && Array_Input[i]<='9')
		{
			num = num*10 + Array_Input[i]-'0';
		}else if (Array_Input[i] =='-' || Array_Input[i]=='+' || Array_Input[i] =='*' || Array_Input[i]=='/')
		{
			if (flag == 1)
			{
				op1 = Array_Input[i];
				flag++;
			}
		}
	}
		switch (op1){
			case '-':
			result = result-num;
			break;
			case '+':
			result = result+num;
			break;
			case '*':
			result = result*num;
			break;
			case '/':
			result = result/num;
			break;
		}
	
	LCD_SetCursor(1,0);
	LCD_WriteNumber(result);
	gain();
}

void gain(){
	for (u8 i =0;i<300;i++)
	{
		key = KEYPAD_GetKey();
		if (key >='0' && key<='9')
		{
			LCD_Clear();
			LCD_WriteChar(key);
			POS_CUR=0;
			result=0,num=0,num1=0,num2=0,num3=0;
			Calc_Add(key);
			Get_Input();
			break;
	    }else if(key == '*'||key == '+'||key == '-'||key == '/'){
			LCD_SetCursor(1,0);
			LCD_WriteString("                     ");
			LCD_SetCursor(0,0);
			LCD_WriteString("                     ");
			LCD_SetCursor(0,0);
			LCD_WriteNumber(result);
			LCD_WriteChar(key);
			POS_CUR =0;
			Calc_Add(key);
			Get_Input2();
			break;					
		}else if(key == 'c'){
			result=0,num=0,num1=0,num2=0,num3=0;
			POS_CUR=0;
			LCD_SetCursor(0,0);
			LCD_Clear();
			Calc_Select();
		}	
	}
}



s32 Get_Number(){
	num=0,POS_CUR=0;
	u8 flag=0;
	LCD_SetCursor(0,4);

	while(1){
		key = KEYPAD_GetKey();
     
		if (key == '=')
		{
			for(u8 i=0;i<POS_CUR;i++){
				num = num*10+Array_Input[i]-'0';
			}
			POS_CUR=0;
			return num;
		}else if(key>='0' && key<='9'){	
			LCD_WriteChar(key);
			Calc_Add(key);
			flag=1;	
		}else if (key == 'c' & flag){
			if (POS_CUR <=3 )
			{
				flag=0;
				
			}else{
			--POS_CUR;
			LCD_SetCursor(0,POS_CUR);
			LCD_WriteChar(' ');
			}
			
		}
	}
}

void DEC_TO_BIN(s32 n){
	
	LCD_SetCursor(1,4);
	u8 flag=0,POS_CUR=0;
	for(int i = 31; i >= 0;i--){
		if (((n>>i)&1) == 1)
		{
			flag=1;
		}
		if (flag == 1)
		{
			if(En_b == 1) {
				//convert to binary
				LCD_WriteChar(((n>>i)&1)+48);
		     }else{
				//convert to hex
				Calc_Add((n>>i)&1);
			}
		}
	}
	if(En_b == 1){
	while(1){
		key=KEYPAD_GetKey();
		if (key>='0' && key<='9')
		{
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("DEC: ");
			LCD_SetCursor(1,0);
			LCD_WriteString("BIN: ");
			LCD_SetCursor(0,4);
			En_b=1;
			DEC_TO_BIN(Get_Number());
		}else if (key == 'c')
		{
			Calc_Select();
		}
	}
	}
}

void DEC_TO_HEX(s32 n){
	s8 b1=0,c=0,c2=0,c3=0,flag=0;
	u8 arr_he[4]={0,0,0,0};
	LCD_SetCursor(1,4);
		for(int i = 31; i >= 0;i--){
			c2++;
			if (i == 15)
			{flag=1;}
			if(flag == 1){
				Array_Input[c3]=((n>>i)&1);
			c3++;
		}

	}
	for (int i = 15; i > 0 ;i=i-4)
	{
		b1=0;
		b1= Array_Input[i]*1;
		b1= b1+(Array_Input[(i-1)]*2);
		b1= b1+(Array_Input[(i-2)]*4);
		b1= b1+(Array_Input[(i-3)]*8);
		arr_he[c]=b1;
		c++;
	}
	if (arr_he[3]>=1){(arr_he[3] >= 10)?LCD_WriteChar(arr_he[3]+55):LCD_WriteNumber(arr_he[3]);}	
	if (arr_he[2]>=1){(arr_he[2] >= 10)?LCD_WriteChar(arr_he[2]+55):LCD_WriteNumber(arr_he[2]);}
	(arr_he[1] >= 10)?LCD_WriteChar(arr_he[1]+55):LCD_WriteNumber(arr_he[1]);
	(arr_he[0] >= 10)?LCD_WriteChar(arr_he[0]+55):LCD_WriteNumber(arr_he[0]);

		
	while(1){
		key=KEYPAD_GetKey();
		if (key>='0' && key<='9')
		{
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("DEC: ");
			LCD_SetCursor(1,0);
			LCD_WriteString("HEX: ");
			LCD_SetCursor(0,4);
			En_b=0;
			DEC_TO_HEX(Get_Number());
		}else if (key == 'c')
		{
			Calc_Select();
		}
	}
}

//convert 
void Convert_select(){
	LCD_SetCursor(0,0);
	LCD_WriteString("1- DEC TO HEX");
	LCD_SetCursor(1,0);
	LCD_WriteString("2- DEC TO BIN .....");
	
	while(1){
		key = KEYPAD_GetKey();
		if (key == '1')
		{
			LCD_Clear();
 			LCD_SetCursor(0,0);
 			LCD_WriteString("DEC: ");
 			LCD_SetCursor(1,0);
			LCD_WriteString("HEX: ");
			En_b=0;
			DEC_TO_HEX(Get_Number());
			
			break;
		}else if (key == '2')
		{
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("DEC: ");
			LCD_SetCursor(1,0);
			LCD_WriteString("BIN: ");
			LCD_SetCursor(0,4);
			En_b=1;
			DEC_TO_BIN(Get_Number());
			break;
		}	
	}	
}


