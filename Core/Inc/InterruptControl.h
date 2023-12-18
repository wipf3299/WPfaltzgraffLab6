/*
 * InterruptControl.h
 *
 *  Created on: Sep 28, 2023
 *      Author: williampfaltz
 */

#include "stm32f4xx.h"
#include <stdint.h>

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

//#define EXTI_BASE_ADDR   (APB2_BASE_ADDR + 0x3C00)
//
//#define EXTI   ((EXTI_RegDef_t*) EXTI_BASE_ADDR)

#define NVIC_ISER0 ((volatile uint32_t*) 0xE000E100)
#define NVIC_ICER0 ((volatile uint32_t*) 0xE000E180)
#define NVIC_ISPR0 ((volatile uint32_t*) 0xE000E200)
#define NVIC_ICPR0 ((volatile uint32_t*) 0xE000E280)
#define NVIC_IPR0  ((volatile uint32_t*) 0xE000E400)

typedef struct {
	volatile uint32_t IMR;   //Address offset 0x00
	volatile uint32_t EMR;   //Address offset 0x04
	volatile uint32_t RTSR;  //Address offset 0x08
	volatile uint32_t FTSR;  //Address offset 0x0C
	volatile uint32_t SWIER; //Address offset 0x10
	volatile uint32_t PR;    //Address offset 0x14
}EXTI_RegDef_t;

void interruptEnable(uint8_t);
void interruptDisable(uint8_t);
void clearPending(uint8_t);
void setPending(uint8_t);
void clearExtiPending(uint8_t);

#endif /* INTERRUPTCONTROL_H_ */































