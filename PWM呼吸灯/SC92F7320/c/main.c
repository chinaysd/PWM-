#include "H/Function_Init.H"
#include "bsp_pwm.h"

PWM_Para_t Para_t;
unsigned char flag;

/**************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
3、注意：先在Function.H里面选择测试型号（SC92F7320无LCD/LED和PWM功能）
***************************************************************/
//#define Test   4  //BTM:0 EXTI:1 Timer:2 LCD:3 PWM:4 Uart0:5 ADC:7 IAP:8 

void main(void)
{
	IO_Init();
	PWM_Init();
	//WDTCON |= 0x10;		    //清看门狗
	while(1)
	{
		if(!flag)
		{
			flag = 1;
			PWM_Open();
		}
	}
}


void Bsp_PwmHandle() interrupt 8{
	PWMCON &=~0X40; 
  P21 = ~P21;
  if(Para_t.Cnt++ > Para_t.Base_Cnt)
	{
		Para_t.Cnt = 0;
		if(PWMDTY2 == 254)
		{
			Para_t.PWM_Down_Flag = True;
			Para_t.PWM_Up_Flag   = False;
			Para_t.Base_Cnt = 40;
		}
		if(PWMDTY2 == 0)
		{
			Para_t.PWM_Down_Flag = False;
			Para_t.PWM_Up_Flag   = True;
			Para_t.Base_Cnt = 20;
		}
		if(Para_t.PWM_Down_Flag)	 
		{
			PWMDTY2 -- ;
		}
		if(Para_t.PWM_Up_Flag)
		{
			PWMDTY2 ++ ;
		}
	}
  

}