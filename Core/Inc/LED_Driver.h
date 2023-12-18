/*
 * LED_Driver.h
 *
 *  Created on: Sep 5, 2023
 *      Author: williampfaltz
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "stm32f4xx_hal.h"

#define RED_LED   0x0
#define GREEN_LED 0x1

void LED_Init(uint8_t);
void LED_Clock_Enable(uint8_t);
void LED_Activate(uint8_t);
void LED_Deactivate(uint8_t);
void LED_Toggle(uint8_t);

#endif /* LED_DRIVER_H_ */
