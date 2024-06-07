
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*MUST PUT IN PRIVATE*/
#define _4_BIT   0
#define _8_BIT   1

#define L4_C16   0
#define L2_C16   1

/*CHANGE MODE _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT

/*CHANGE MODE L4_C16 OR L2_C16*/
#define  LCD_LINE_COLUMN L4_C16


// help to change connect 
#define  RS PIND4
#define  EN PIND5


/*IF _8_BIT SET POSITION OF 8PIN*/
const DIO_Pin_type LCD_8BITArray[]={
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7
};

/*IF _4_BIT SET POSITION OF 4PIN*/
const DIO_Pin_type LCD_4BITArray[]={
	PIND0,
	PIND1,
	PIND2,
	PIND3
};

#endif /* LCD_CFG_H_ */