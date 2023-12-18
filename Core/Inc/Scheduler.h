/*
 * Scheduler.h
 *
 *  Created on: Sep 5, 2023
 *      Author: williampfaltz
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "stdint.h"
#include "Button_Driver.h"

#define LED_TOGGLE_MASK (1 << 0)
#define DELAY_EVENT     (1 << 1)
#define BUTTON_POLL     (1 << 2)
#define GYRO_TEMPER     (1 << 3)
#define GYRO_AXIS_VALS  (1 << 4)
#define GYRO_REBOOT     (1 << 5)

uint32_t getScheduledEvents();
void addSchedulerEvent(uint32_t);
void removeSchedulerEvent(uint32_t);

#endif /* SCHEDULER_H_ */






