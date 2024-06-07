
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


/*CHANGE CONNECT OF PINS*/
#define  ROWS   4
#define  COLS   4

/*CHANGE CONNECT OF PINS*/
const DIO_Pin_type Key_PINS[ROWS][2]={
   /* ROW  , COL */
	{PINC0,PINC4},
	{PINC1,PINC5},
	{PINC2,PINC6},
	{PINC3,PINC7}
};
/*CHANGE DRAW*/
const u8 Key_Array[ROWS][COLS]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'},
};


#endif /* KEYPAD_CFG_H_ */