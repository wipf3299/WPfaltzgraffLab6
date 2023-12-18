/*
 * Button_Driver.h
 *
 *  Created on: Sep 26, 2023
 *      Author: williampfaltz
 */

//button is PA0

#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "InterruptControl.h"

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#define BTN_PORT_VALUE  GPIOA
#define BUTTON_PIN_NUM  0x0
#define BUTTON_PRESSED  0x1
#define BUTTON_UNPRESS  0x0

void Button_Init();
void Button_Clock_Enable();
bool Button_Pressed();
void Btn_IntMod_Init();

#endif /* BUTTON_DRIVER_H_ */























