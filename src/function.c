/*
 * function.c
 *
 *  Created on: 2013-6-20
 *      Author: dragon
 */

#include "stm32f10x.h"
#include "function.h"
#include "My_usart/my_usart.h"
/**
 * @brief  精确的毫秒演示函数
 * @param  整数
 * @retval None
 */
void Delay(__IO uint32_t nTime)
{
	TimingDelay = nTime;

	while (TimingDelay != 0)
		;
}

/**
 * @brief  Decrements the TimingDelay variable.
 * @param  None
 * @retval None
 */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}

void All_LED_light()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_0 );
	Delay(100);
	GPIO_SetBits(GPIOB, GPIO_Pin_0 );
	Delay(100);

	GPIO_ResetBits(GPIOB, GPIO_Pin_1 );
	Delay(100);
	GPIO_SetBits(GPIOB, GPIO_Pin_1 );
	Delay(100);

	GPIO_ResetBits(GPIOB, GPIO_Pin_2 );
	Delay(100);
	GPIO_SetBits(GPIOB, GPIO_Pin_2 );
	Delay(100);

	GPIO_ResetBits(GPIOC, GPIO_Pin_8 );
	Delay(100);
	GPIO_SetBits(GPIOC, GPIO_Pin_8 );
	Delay(100);

	GPIO_ResetBits(GPIOC, GPIO_Pin_9 );
	Delay(100);
	GPIO_SetBits(GPIOC, GPIO_Pin_9 );
	Delay(100);
}

void function1(u8 *data)
{
	if (BufferRead(data))
	{
		while (USART_GetFlagStatus(USART2, USART_FLAG_TXE ) == RESET)
			;
		USART_SendData(USART2, *data);

		Delay(1); //延时太多，会丢失很多数据
		GPIO_WriteBit(GPIOB, GPIO_Pin_0, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_0 ));
		GPIO_WriteBit(GPIOB, GPIO_Pin_1, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1 ));
		GPIO_WriteBit(GPIOB, GPIO_Pin_2, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_2 ));

	}

}