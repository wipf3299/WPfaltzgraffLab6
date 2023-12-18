/*
 * RNG_Driver.h
 *
 *  Created on: Dec 5, 2023
 *      Author: williampfaltz
 */

#include "stm32f4xx_hal.h"

#ifndef INC_RNG_DRIVER_H_
#define INC_RNG_DRIVER_H_

#define randomNum 0xffff

void RNG_Init();
uint32_t RNG_Get();
void RNG_Reset();

#endif /* INC_RNG_DRIVER_H_ */
