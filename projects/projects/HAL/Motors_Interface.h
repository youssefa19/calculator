
#ifndef MOTORS_INTERFACE_H_
#define MOTORS_INTERFACE_H_

#define  MOTOR_PIN_NUMBERS   3


typedef enum{
	M1,
	M2,
	M3,
	M4,
	NUMBER_MOTORS
}MOTOR_type;

void MOTOR_Init(void);

void MOTOR_Stop(MOTOR_type motor);

void MOTOR_CW(MOTOR_type motor);

void MOTOR_CCW(MOTOR_type motor);


#endif /* MOTORS_INTERFACE_H_ */