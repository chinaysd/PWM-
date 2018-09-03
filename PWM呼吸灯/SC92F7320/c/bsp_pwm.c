#include "bsp_pwm.h"

/*****************************************************
*�������ƣ�void PWM_Init(void)
*�������ܣ�PWM��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Init(void)
{
	PWMCON  = 0x3A;		//PWM�����IO��PWMʱ��ΪFsys/4
	PWMPRD  = 255;		//PWM����=(59+1)*(1/6us)=10us	;
	PWMCFG  = 0x07;		//PWM���������,�����P25/P26/P27
	PWMDTY2 = 254;       //PWM0��Duty = 10/60 =1/6
	PWMDTYA = 0x00;
	IE1 |= 0x02;        //����PWM�ж�
	EA = 1;
}


void PWM_Open(void)
{
	PWM_Init();
	PWMCON |= 0x80;     //����PWM
}

