#include "bsp_pwm.h"

/*****************************************************
*函数名称：void PWM_Init(void)
*函数功能：PWM初始化
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Init(void)
{
	PWMCON  = 0x3A;		//PWM输出到IO，PWM时钟为Fsys/4
	PWMPRD  = 255;		//PWM周期=(59+1)*(1/6us)=10us	;
	PWMCFG  = 0x07;		//PWM输出不反向,输出至P25/P26/P27
	PWMDTY2 = 254;       //PWM0的Duty = 10/60 =1/6
	PWMDTYA = 0x00;
	IE1 |= 0x02;        //开启PWM中断
	EA = 1;
}


void PWM_Open(void)
{
	PWM_Init();
	PWMCON |= 0x80;     //开启PWM
}

