/*
 * InterruptControl.h
 *
 *  Created on: Sep 28, 2023
 *      Author: williampfaltz
 */

#include "InterruptControl.h"

//void interruptEnable(uint8_t irq) {
//	if (irq < 0x20) {
//		*SET_ENABLE |= (1 << irq);
//		return;
//	}
//	if (irq >= 0x20) {
//		*(SET_ENABLE + 0x4) |= (1 << irq % 32);
//		return;
//	}
//}
//
//void interruptDisable(uint8_t irq) {
//	if (irq < 0x20) {
//		*CLEAR_ENABLE |= (1 << irq);
//		return;
//	}
//	if (irq >= 0x20) {
//		*(CLEAR_ENABLE + 0x4) |= (1 << irq % 32);
//		return;
//	}
//}
//
//void setPending(uint8_t irq) {
//	if (irq < 0x20) {
//		*SET_PENDING |= (1 << irq);
//		return;
//	}
//	if (irq >= 0x20) {
//		*(SET_PENDING + 0x4) |= (1 << irq % 32);
//		return;
//	}
//}
//
//void clearPending(uint8_t irq) {
//	if (irq < 0x20) {
//		*CLEAR_PENDING |= (1 << irq);
//		return;
//	}
//	if (irq >= 0x20) {
//		*(CLEAR_PENDING + 0x4) |= (1 << irq % 32);
//		return;
//	}
//}

void clearExtiPending(uint8_t pin) {
	EXTI-> PR |= (1 << pin);
	return;
}

//If the IRQ number is less than 32, set the proper bit in the proper
//NVIC register by shifting a bitmask by the IRQ number
//a. There is some pointer logic you will need to be mindful of here
//i. Hint, how do we put a certain value at a certain memory address?
//b. Revisit the prelab if you need to be refreshed on why we care about the IRQ number here
//2. If the Irq number is greater than or equal to 32, we should set the
//appropriate bit in the proper NVIC register by shifting the bitmask by the module of the IRQ number and 32
//a. Recall the purpose of Modulo
























