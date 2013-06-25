/*
 * function.h
 *
 *  Created on: 2013-6-20
 *      Author: dragon
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

static __IO uint32_t TimingDelay;

void Delay(__IO uint32_t nTime);
void TimingDelay_Decrement(void);

void All_LED_light();
void All_Relay_On();
void function1(u8 *data);

#endif /* FUNCTION_H_ */
