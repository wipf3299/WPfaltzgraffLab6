/*
 * LED_Driver.c
 *
 *  Created on: Sep 5, 2023
 *      Author: williampfaltz
 */
#include "LED_Driver.h"

//static GPIO_Handle_t redConfig;
//static GPIO_Handle_t greenConfig;

void LED_Init(uint8_t led) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	switch (led) {
		case RED_LED:
			LED_Clock_Enable(RED_LED);
			GPIO_InitStruct.Pin =   GPIO_PIN_14;
			GPIO_InitStruct.Mode =  GPIO_MODE_OUTPUT_PP;
			GPIO_InitStruct.Pull =  GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
			HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
			return;
		case GREEN_LED:
			LED_Clock_Enable(GREEN_LED);
			GPIO_InitStruct.Pin =   GPIO_PIN_13;
			GPIO_InitStruct.Mode =  GPIO_MODE_OUTPUT_PP;
			GPIO_InitStruct.Pull =  GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
			HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
			return;
		default:
			return;
	}
}

//GPIO_RegDef_t* port, uint8_t pin
void LED_Toggle(uint8_t led) {
	switch (led) {
		case RED_LED:
			HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
			return;
			case GREEN_LED:
			HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
			return;
		default:
			return;
	}
}

void LED_Deactivate(uint8_t led) {
	switch (led) {
		case RED_LED:
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, 0);
			return;
		case GREEN_LED:
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, 0);
			return;
		default:
			return;
	}
}


void LED_Activate(uint8_t led) {
	switch (led) {
		case RED_LED:
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, 1);
			return;
		case GREEN_LED:
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, 1);
		default:
			return;
	}
}

//GPIO_RegDef_t* port, uint8_t EORD
void LED_Clock_Enable(uint8_t led) {
	switch (led) {
		case RED_LED:
			__HAL_RCC_GPIOG_CLK_ENABLE();
			return;
		case GREEN_LED:
			__HAL_RCC_GPIOG_CLK_ENABLE();
		default:
			return;
	}
}




//switch (led) {
//			case RED_LED:
//
//			case GREEN_LED:
//
//			default:
//				return;
//	}




























