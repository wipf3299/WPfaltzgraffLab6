/*
 * Button_Driver.c
 *
 *  Created on: Sep 26, 2023
 *      Author: williampfaltz
 */

#include "Button_Driver.h"

void Button_Init() {
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	Button_Clock_Enable();

	GPIO_InitStruct.Pin =   GPIO_PIN_0;
	GPIO_InitStruct.Mode =  GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull =  GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}


void Button_Clock_Enable() {
	__HAL_RCC_GPIOA_CLK_ENABLE();
	return;
}

bool Button_Pressed() {
	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == BUTTON_PRESSED) {
		return true;
	} else {
		return false;
	}
}

void Btn_IntMod_Init() {
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	Button_Clock_Enable();

	GPIO_InitStruct.Pin =   GPIO_PIN_0;
	GPIO_InitStruct.Mode =  GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStruct.Pull =  GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}



























