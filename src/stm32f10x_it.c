/**
 ******************************************************************************
 * @file    GPIO/IOToggle/stm32f10x_it.c
 * @author  MCD Application Team
 * @version V3.5.0
 * @date    08-April-2011
 * @brief   Main Interrupt Service Routines.
 *          This file provides template for all exceptions handler and peripherals
 *          interrupt service routine.
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "My_delay/my_delay.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

extern void BufferWrite(void);

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 * @param  None
 * @retval None
 */
void NMI_Handler(void)
{
}

/**
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @retval None
 */
void HardFault_Handler(void)
{
	/* Go to infinite loop when Hard Fault exception occurs */
	while (1)
	{
	}
}

/**
 * @brief  This function handles Memory Manage exception.
 * @param  None
 * @retval None
 */
void MemManage_Handler(void)
{
	/* Go to infinite loop when Memory Manage exception occurs */
	while (1)
	{
	}
}

/**
 * @brief  This function handles Bus Fault exception.
 * @param  None
 * @retval None
 */
void BusFault_Handler(void)
{
	/* Go to infinite loop when Bus Fault exception occurs */
	while (1)
	{
	}
}

/**
 * @brief  This function handles Usage Fault exception.
 * @param  None
 * @retval None
 */
void UsageFault_Handler(void)
{
	/* Go to infinite loop when Usage Fault exception occurs */
	while (1)
	{
	}
}

/**
 * @brief  This function handles SVCall exception.
 * @param  None
 * @retval None
 */
void SVC_Handler(void)
{
}

/**
 * @brief  This function handles Debug Monitor exception.
 * @param  None
 * @retval None
 */
void DebugMon_Handler(void)
{
}

/**
 * @brief  This function handles PendSV_Handler exception.
 * @param  None
 * @retval None
 */
void PendSV_Handler(void)
{
}

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/*******************************************************************************
 * Function Name  : USART1_IRQHandler
 * Description    : This function handles USART1 global interrupt request.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/

void USART1_IRQHandler(void)
{
	/****************************************************************/
	if (USART_GetFlagStatus(USART1, USART_FLAG_ORE ) != RESET)
	{
		USART_ReceiveData(USART1 ); //进行空读操作，目的是清除ORE位
	}
	if (USART_GetITStatus(USART1, USART_IT_RXNE ) != RESET)
	{
		BufferWrite(); //将接收到的数据写入缓冲
		USART_ClearITPendingBit(USART1, USART_IT_RXNE );
	}

	/******************************************************************/
//	if (USART_GetITStatus(USART1, USART_IT_RXNE ) != RESET)
//	{
//		USART_ITConfig(USART1, USART_IT_TXE, DISABLE); //关闭发送中断
//	}
//	LedPB1 = USART_ReceiveData(USART1 );
}
void USART2_IRQHandler(void)
{
//	if (USART_GetITStatus(USART2, USART_IT_TXE ) != RESET)
//	{
//		USART_ITConfig(USART2, USART_IT_TXE, DISABLE); //关闭发送中断
//	}
}

void TIM2_IRQHandler(void)
{
	GPIO_WriteBit(GPIOC, GPIO_Pin_9, (BitAction) !GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_9 ));
//	if (GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_9 ) == 0)
//	{
//		GPIO_SetBits(GPIOC, GPIO_Pin_9 );
//	}
//	else
//	{
//		GPIO_ResetBits(GPIOC, GPIO_Pin_9 );
//	}
	TIM_ClearFlag(TIM2, TIM_FLAG_Update );
}

void TIM3_IRQHandler(void)
{
	GPIO_WriteBit(GPIOC, GPIO_Pin_8, (BitAction) !GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_8 ));
//	if (GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_9 ) == 0)
//	{
//		GPIO_SetBits(GPIOC, GPIO_Pin_9 );
//	}
//	else
//	{
//		GPIO_ResetBits(GPIOC, GPIO_Pin_9 );
//	}
	TIM_ClearFlag(TIM3, TIM_FLAG_Update );
}

void EXTI0_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line0 ) != RESET)
	{
		/* Clear the  EXTI line 0 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line0 );
		/********************** do what you want *****************************/
		/* Toggle LED1 */
		GPIO_WriteBit(GPIOB, GPIO_Pin_0, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_0 ));
		/**********************************************************************/
	}
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line9 ) != RESET)
	{
		/* Clear the  EXTI line 9 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line9 );
		/********************** do what you want *****************************/
		/* Toggle LED2 */
		GPIO_WriteBit(GPIOB, GPIO_Pin_2, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_2 ));
		/**********************************************************************/
	}
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
