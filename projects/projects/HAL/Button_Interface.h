
#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

typedef enum{
	NOTPRESSED=0,
	PRESSED=1
}Button_Status;

void Button_Init(void);
Button_Status Button_IsPressed(DIO_Pin_type pin);

#endif /* BUTTON_INTERFACE_H_ */