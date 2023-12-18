/*
 * RNG_Driver.c
 *
 *  Created on: Dec 5, 2023
 *      Author: williampfaltz
 */
#include "RNG_Driver.h"

static RNG_HandleTypeDef rngMain;
static HAL_StatusTypeDef stat;

void RNG_Init() {

	rngMain.Instance = RNG;
	rngMain.State    = HAL_RNG_STATE_RESET;

	stat = HAL_RNG_Init(&rngMain);
	if (rngMain.State != HAL_RNG_STATE_READY) {
		while (1) {}
	}
	return;
}

uint32_t RNG_Get() {
	uint32_t randNum = 0;
//	stat = HAL_RNG_GenerateRandomNumber(&rngMain, &randNum);
//	if (stat != HAL_OK) {
//		while (1) {}
//	}
//	if (rngMain.State != HAL_RNG_STATE_READY) {
//		if (rngMain.State == HAL_RNG_STATE_BUSY) {
//			while (1) {}
//		}
//		if (rngMain.State == HAL_RNG_STATE_TIMEOUT) {
//			while (1) {}
//		}
//		if (rngMain.State == HAL_RNG_STATE_ERROR) {
//			while (1) {}
//		}
//		if (rngMain.State == HAL_RNG_STATE_RESET) {
//			while (1) {}
//		}
//	}
//	rngMain.State = HAL_RNG_STATE_READY;

	RNG_Init();

	randNum = HAL_RNG_GetRandomNumber(&rngMain);

	HAL_RNG_DeInit(&rngMain);

	return randNum;
}

void RNG_Reset() {
//	HAL_RNG_GenerateRandomNumber(&rngMain, uint32_t *random32bit);
	return;
}

























