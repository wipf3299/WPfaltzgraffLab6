/*
 * Game_Driver.h
 *
 *  Created on: Dec 13, 2023
 *      Author: williampfaltz
 */

#include "LCD_Driver.h"
#include <stdlib.h>
#include "Scheduler.h"
#include "RNG_Driver.h"

#ifndef INC_GAME_DRIVER_H_
#define INC_GAME_DRIVER_H_

uint32_t RNG_App_Get();

void Start_Screen(void);

void Level_One(void);
void Level_Two(void);
void Level_Three(void);

void End_Screen(void);

void Button_Set();

void Button_Tester(void);


#endif /* INC_GAME_DRIVER_H_ */
