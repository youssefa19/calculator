
#ifndef STEPPER_H_
#define STEPPER_H_
/********************************/
#define  COIL1A PINB0
#define  COIL1B PINB1
#define  COIL2A PINB2
#define  COIL2B PINB3

#define DELAY 2
/********************************/
void STEPPER_Bipolar_CW (void);
void STEPPER_Bipolar_CCW (void);
void STEPPER_Unipolar_CW (void);
void STEPPER_Unipolar_CW2 (void);
void STEPPER_Unipolar_CCW (void);
void STEPPER_Unipolar_CW_HS (void);
void STEPPER_Unipolar_stop (void);

void STEPPER_UniPolar_CW_ByAngle(u32);
void STEPPER_UniPolar_CCW_ByAngle(u32);
void STEPPER_UniPolar_CW_ByRotation(u32);
void STEPPER_UniPolar_CCW_ByRotation(u32);


#endif /* STEPPER_H_ */