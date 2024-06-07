
#ifndef MOTORS_PRIVATE_H_
#define MOTORS_PRIVATE_H_

#define  MOTOR_PIN_NUMBERS   3

#ifdef  MOTOR_PROG

DIO_Pin_type MotorPinsArray[NUMBER_MOTORS][MOTOR_PIN_NUMBERS]={
	/* IN1   IN2     EN  */
	/* motor 1*/{ M1_IN1,M1_IN2,M1_EN},
	/* motor 2*/{ M2_IN1,M2_IN2,M2_EN},
	/* motor 3*/{ M1_IN1,M1_IN2,M1_EN},
	/* motor 4*/{ M1_IN1,M1_IN2,M1_EN},
};


MOTOR_Pins_type MotorPinsArray2[NUMBER_MOTORS]={
	/* IN1   IN2     EN  */
	/* motor 1*/{ M1_IN1,M1_IN2,M1_EN},
	/* motor 2*/{ M2_IN1,M2_IN2,M2_EN},
	/* motor 3*/{ M1_IN1,M1_IN2,M1_EN},
	/* motor 4*/{ M1_IN1,M1_IN2,M1_EN},
	
}

#endif /* MOTORS_PRIVATE_H_ */