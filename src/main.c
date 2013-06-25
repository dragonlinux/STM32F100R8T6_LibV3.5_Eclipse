/********************************************************************************
 * @file    main.c
 * @author  叶玉龙
 * @version V3.5.0
 * @date    2013-6-25
 * @brief   有github了
 ******************************************************************************/

/************** 串口缓冲环的使用 *****************/

/* Includes -----------------------------------------------*/
#include "stm32f10x.h"
#include "stdio.h"
#include "function.h"

#include "My_usart/my_usart.h"
#include "My_gpio/my_gpio.h"
#include "My_timer/my_timer.h"
#include "My_exti/my_exti.h"

unsigned char LedPB1 = 'b';
unsigned char test_buffer[] = "I am fine,OK\r\n";

int main(void)
{
	u8 data = 0;
	/* Set the Vector Table base location at 0x08000000 */
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	/* Configure the NVIC Preemption Priority Bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0 );
	SysTick_Configuration();

	my_Gpio_Init();
	my_Timer2_Init(); //use Timer2-->Green_LED
	my_Timer3_Init(); //use Timer3-->Blue_LED
	my_Usart_Init();
	my_EXTI0_Config(); //外部中断，上升沿触发
	my_EXTI9_5_Config(); //外部中断，下降沿触发

//	All_LED_light();//打开所有的LED
	printf("OK-->1%s\n", test_buffer);

	while (1)
	{
		function1(&data);
	}
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}

#endif

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
