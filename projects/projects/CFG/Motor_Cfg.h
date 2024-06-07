
#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_

#define  IN1   0
#define  IN2   1
#define  EN    2

/*
typedef struct{
	DIO_Pin_type IN1;
	DIO_Pin_type IN2;
	DIO_Pin_type EN;
}MOTOR_Pins_type;
*/

/************* pin config******************/

#define   M1_IN1   PINA4
#define   M1_IN2   PINA5
#define   M1_EN    PIND0

#define   M2_IN1   PINA0
#define   M2_IN2   PINA1
#define   M2_EN    PIND0

#define   M3_IN1   PINA6
#define   M3_IN2   PINA7
#define   M3_EN    PIND0

#define   M4_IN1   PINA2
#define   M4_IN2   PINA3
#define   M4_EN    PIND0


#ifdef  MOTOR_PROG

DIO_Pin_type MotorPinsArray[NUMBER_MOTORS][MOTOR_PIN_NUMBERS]={
	/* IN1   IN2     EN  */
	/* motor 1*/{ M1_IN1,M1_IN2,M1_EN},
	/* motor 2*/{ M2_IN1,M2_IN2,M2_EN},
	/* motor 3*/{ M3_IN1,M3_IN2,M3_EN},
	/* motor 4*/{ M4_IN1,M4_IN2,M4_EN}
};


//MOTOR_Pins_type MotorPinsArray2[NUMBER_MOTORS]={
	/* IN1   IN2     EN  */
//	/* motor 1*/{ M1_IN1,M1_IN2,M1_EN},
//	/* motor 2*/{ M2_IN1,M2_IN2,M2_EN},
//	/* motor 3*/{ M3_IN1,M3_IN2,M3_EN},
//	/* motor 4*/{ M4_IN1,M4_IN2,M4_EN}	
//};
#endif


#endif /* MOTOR_CFG_H_ */