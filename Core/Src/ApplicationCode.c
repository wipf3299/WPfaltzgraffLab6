/*
 * ApplicationCode.c
 *
 *  Created on: Sep 5, 2023
 *      Author: williampfaltz
 */

#include "ApplicationCode.h"

static uint8_t currLED;

#define redLED   0
#define greenLED 1

void Red_Init() {
	LED_Init(RED_LED);
}

void Green_Init() {
	LED_Init(GREEN_LED);
}

void Both_LED_Init() {
	Red_Init();
	Green_Init();
}

void Red_Toggle() {
	LED_Toggle(RED_LED);
}

void Green_Toggle() {
	LED_Toggle(GREEN_LED);
}

void Red_ON() {
	LED_Activate(RED_LED);
}

void Green_ON() {
	LED_Activate(GREEN_LED);
}

void Red_OFF() {
	LED_Deactivate(RED_LED);
}

void Green_OFF() {
	LED_Deactivate(GREEN_LED);
}

void Gyr_Init() {
	Gyro_Init();
	HAL_Delay(100);
	Gyro_DummyRead();
	Gyro_GetDeviceID();
	Gyro_RegConfig();
	return;
}

void Gyr_GetDevID() {
	Gyro_GetDeviceID();
	return;
}

void Gyr_On() {
	Gyro_ON();
	return;
}

void Gyr_Rboot() {
	Gryo_Reboot();
	printf("The Device has rebooted. \n");
	removeSchedulerEvent(GYRO_REBOOT);
	return;
}

void Gyr_Temp() {
	Gyro_GetTemp();
	return;
}

void Gyr_Coords() {
	Gyro_GetXYZ();
	return;
}

void Game_Start (void) {
	Start_Screen();
}

void Btn_Test(void) {
	Button_Tester();
}

void Delay(uint32_t time) {
	char name[NAME_LENGTH] = {'W', 'i', 'l', 'l', 'i', 'a', 'm'};
	[[maybe_unused]]char nameDest[NAME_LENGTH] = {};

	for (int i = 0; i < time; i++) {
		for (int j = 0; j < NAME_LENGTH; j++) {
			nameDest[j] = name[j];
		}
	}
}

void Application_Init() {
	Btn_Interrupt_Init();

//	Gyr_Init();

	LTCD__Init();
	LTCD_Layer_Init(0);
	LCD_Clear(0, LCD_COLOR_WHITE);

	addSchedulerEvent(DELAY_EVENT);

	addSchedulerEvent(GYRO_TEMPER);
	addSchedulerEvent(GYRO_AXIS_VALS);
}

void Btn_Init() {
	Button_Init();
	return;
}

void executeButtonPollingRoutine() {
	if (Button_Pressed()) {
		switch (currLED) {
			case redLED:
				Red_ON();
				break;
			case greenLED:
				Green_ON();
				break;
		}
		return;
	} else {
		switch (currLED) {
			case redLED:
				Red_OFF();
				break;
			case greenLED:
				Green_OFF();
				break;
		}
		return;
	}
}

void Btn_Interrupt_Init() {
	Btn_IntMod_Init();
	return;
}

//static EXTI_HandleTypeDef red_led   = {EXTI_LINE_14};
//static EXTI_HandleTypeDef green_led = {EXTI_LINE_13};


void EXTI0_IRQHandler(void) {
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);

	Button_Set();

	clearExtiPending(0);

	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

//	switch (currLED) {
//		case redLED:
//			Red_Toggle();
//			clearExtiPending(PIN14);
//			HAL_EXTI_ClearPending(&red_led, EXTI_TRIGGER_RISING_FALLING);
//			break;
//		case greenLED:
//			Green_Toggle();
//			clearExtiPending(PIN13);
//			HAL_EXTI_ClearPending(&green_led, EXTI_TRIGGER_RISING_FALLING);
//			break;
//	}

//	#if USE_INTERRUPT_FOR_BUTTON == 1

//	#elif USE_INTERRUPT_FOR_BUTTON == 0
//		Btn_Init();
//		addSchedulerEvent(BUTTON_POLL);
//	#endif

//	Both_LED_Init();
//	currLED = redLED;
//	Red_OFF();





















