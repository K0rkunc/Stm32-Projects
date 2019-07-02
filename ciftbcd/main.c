#include <stdio.h>
#include <stdlib.h>
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"


void delay_ms(unsigned int nCount);           /* zaman geciktime fonksiyon tanimi*/
GPIO_InitTypeDef GPIO_InitStructure;          /* port ayarlama fonksiyonu tanimi*/
void goster(unsigned int sayac);
unsigned int sayac=0;
unsigned int k=0;
unsigned int basla=0;


int main(void)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);   /* Configure PC13 in output pushpull mode */

	
				
	
	
	
	while(1)  
{
	for(sayac=0;sayac<10;sayac++)
  {
		for(basla=0;basla<10;basla++){
		for(k=0;k<50000;k++)
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			GPIO_SetBits(GPIOA,GPIO_Pin_9);
			GPIO_ResetBits(GPIOA,GPIO_Pin_9);
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			GPIO_SetBits(GPIOA,GPIO_Pin_9);
			GPIO_ResetBits(GPIOA,GPIO_Pin_9);
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			GPIO_SetBits(GPIOA,GPIO_Pin_9);
			GPIO_ResetBits(GPIOA,GPIO_Pin_9);
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			GPIO_SetBits(GPIOA,GPIO_Pin_9);
			GPIO_ResetBits(GPIOA,GPIO_Pin_9);
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			GPIO_SetBits(GPIOA,GPIO_Pin_9);
			GPIO_ResetBits(GPIOA,GPIO_Pin_9);
		}
		
		goster(basla);
		delay_ms(10);
	}
		goster(sayac);
	 delay_ms(100);
		
  }
}
	}
void delay_ms(unsigned int nCount)
{
	unsigned int i,j;
	for(i=0; i< nCount; i++)
	{
		for(j=0;j<0x2AFF;j++) {;}
		}
	}

	void  goster (unsigned int sayac)
	{
switch (sayac | basla)
  {
	case 0x0:
			GPIO_SetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_6); 
	 
  		break;
		case 0x1:
			GPIO_SetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_0); 
	 
  		break;
				case 0x2:
			GPIO_SetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_1 | GPIO_Pin_0); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_2); 
	 
  		break;
								case 0x3:
			GPIO_SetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_6 | GPIO_Pin_1 | GPIO_Pin_0); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_4); 
	 
  		break;
												case 0x4:
			GPIO_SetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_1 | GPIO_Pin_2); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_4 | GPIO_Pin_3); 
	 
  		break;
											case 0x5:
			GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_2 | GPIO_Pin_3); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_4); 
	 
  		break;
					case 0x6:
			GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_1); 
	 
  		break;
					case 0x7:
			GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2); 
	 
			GPIO_ResetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6); 
	 
  		break;
										case 0x8:
			GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6); 
	 
  		break;
																				case 0x9:
			GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3| GPIO_Pin_5 | GPIO_Pin_6); 
	 
		GPIO_ResetBits(GPIOA, GPIO_Pin_4); 
	 
  		break;
  }
}
	

