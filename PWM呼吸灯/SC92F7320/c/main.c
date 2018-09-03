#include "H/Function_Init.H"
#include "bsp_pwm.h"

PWM_Para_t Para_t;
unsigned char flag;

/**************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
3��ע�⣺����Function.H����ѡ������ͺţ�SC92F7320��LCD/LED��PWM���ܣ�
***************************************************************/
//#define Test   4  //BTM:0 EXTI:1 Timer:2 LCD:3 PWM:4 Uart0:5 ADC:7 IAP:8 

void main(void)
{
	IO_Init();
	PWM_Init();
	//WDTCON |= 0x10;		    //�忴�Ź�
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