/*
 * Scheduler.c
 *
 *  Created on: Sep 5, 2023
 *      Author: williampfaltz
 */

#include "Scheduler.h"

static uint32_t scheduledEvents;

void addSchedulerEvent(uint32_t toSet) {
	scheduledEvents |= toSet;
}

void removeSchedulerEvent(uint32_t toRemove) {
	scheduledEvents &= ~toRemove;
}

uint32_t getScheduledEvents() {
	return scheduledEvents;
}



























