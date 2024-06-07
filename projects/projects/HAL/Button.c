#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Utils.h"
#include "Button_Interface.h"

void Button_Init(void){

}
Button_Status Button_IsPressed(DIO_Pin_type pin){
     Button_Status Button;
	 DIO_PinStatus_type Status_Pin = DIO_ReadStatus_CfgPin(pin);
	 
	 switch(Status_Pin){
		 case  INPULL:
		 if(DIO_ReadPin(pin) == 0) {
		     Button = PRESSED;
		 }else{
		     Button = NOTPRESSED;
	     }
		 break;
	     case INFREE:
		 if(DIO_ReadPin(pin) == 1){
			 Button = PRESSED;
		 }else{
			 Button = NOTPRESSED;
		 }
		 break;
		 }
	 return Button;
}