/*
 * ApplicationCode.h
 *
 *  Created on: Sep 5, 2023
 *      Author: williampfaltz
 */

#include "Gyro.h"
#include "LED_Driver.h"
#include "Game_Driver.h"

#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#define NAME_LENGTH   7
#define MAGNIFY_DELAY 250000

//#define USE_INTERRUPT_FOR_BUTTON 1

	void Application_Init();

	void Red_Init();
	void Green_Init();
	void Both_LED_Init();

	void Red_Toggle();
	void Green_Toggle();

	void Red_ON();
	void Green_ON();

	void Red_OFF();
	void Green_OFF();

	void Delay(uint32_t);

	void Btn_Init();
	void executeButtonPollingRoutine();

	void Btn_Interrupt_Init();

	void Gyr_Init();
	void Gyr_GetDevID();
	void Gyr_On();
	void Gyr_Rboot();
	void Gyr_Temp();
	void Gyr_Coords();

	void Game_Start (void);


#endif /* APPLICATIONCODE_H_ */













