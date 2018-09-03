#ifndef _BSP_PWM_H_
#define _BSP_PWM_H_

#include "SC92F732x_C.H"

#define True     1
#define False    0

typedef struct
{
	unsigned char PWM_Down_Flag,PWM_Up_Flag;
	unsigned int  Cnt,Base_Cnt;
}
PWM_Para_t;

void PWM_Init(void);
void PWM_Open(void);

#endif