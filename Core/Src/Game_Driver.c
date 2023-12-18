/*
 * Game_Driver.c
 *
 *  Created on: Dec 13, 2023
 *      Author: williampfaltz
 */
#include "Game_Driver.h"

static int BUT_PRESS = 0;

static int lvl1Time;
static int lvl2Time;
static int lvl3aTime;
static int lvl3bTime;
static int lvl3cTime;

int RNG_Digit_Extractor(int num) {
	int digit;

	digit = num % 10;

	return digit;
}

int smallestLvl3() {
	if(lvl3aTime < lvl3bTime && lvl3aTime < lvl3cTime) {
		return lvl3aTime;
	}
	else if(lvl3bTime < lvl3cTime) {
		return lvl3bTime;
	}
	else {
		return lvl3cTime;
	}
}

uint32_t RNG_App_Get() {
	return RNG_Get();
}

void Start_Screen(void) {
	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(55, 30, 'W');
	LCD_DisplayChar(68, 30, 'e');
	LCD_DisplayChar(78, 30, 'l');
	LCD_DisplayChar(85, 30, 'c');
	LCD_DisplayChar(95, 30, 'o');
	LCD_DisplayChar(110, 30, 'm');
	LCD_DisplayChar(125, 30, 'e');

	LCD_DisplayChar(145, 30, 't');
	LCD_DisplayChar(155, 30, 'o');
	LCD_DisplayChar(165, 30, ':');

	LCD_SetTextColor(LCD_COLOR_MAGENTA);

	LCD_DisplayChar(40, 50, 'R');
	LCD_DisplayChar(53, 50, 'e');
	LCD_DisplayChar(63, 50, 'f');
	LCD_DisplayChar(70, 50, 'l');
	LCD_DisplayChar(77, 50, 'e');
	LCD_DisplayChar(90, 50, 'x');

	LCD_DisplayChar(110, 50, 'R');
	LCD_DisplayChar(125, 50, 'a');
	LCD_DisplayChar(137, 50, 'n');
	LCD_DisplayChar(150, 50, 'g');
	LCD_DisplayChar(160, 50, 'e');
	LCD_DisplayChar(170, 50, 'r');
	LCD_DisplayChar(177, 50, 's');
	LCD_DisplayChar(184, 50, '!');

	LCD_SetTextColor(LCD_COLOR_BLACK);

	LCD_DisplayChar(30, 80, 'T');
	LCD_DisplayChar(43, 80, 'h');
	LCD_DisplayChar(55, 80, 'e');
	LCD_DisplayChar(65, 80, 'r');
	LCD_DisplayChar(72, 80, 'e');

	LCD_DisplayChar(90, 80, 'a');
	LCD_DisplayChar(100, 80, 'r');
	LCD_DisplayChar(110, 80, 'e');

	LCD_DisplayChar(130, 80, '3');

	LCD_DisplayChar(150, 80, 'l');
	LCD_DisplayChar(157, 80, 'e');
	LCD_DisplayChar(167, 80, 'v');
	LCD_DisplayChar(177, 80, 'e');
	LCD_DisplayChar(185, 80, 'l');
	LCD_DisplayChar(192, 80, 's');

	LCD_SetTextColor(LCD_COLOR_GREEN);

	LCD_DisplayChar(40, 100, 'G');
	LCD_DisplayChar(53, 100, 'r');
	LCD_DisplayChar(60, 100, 'e');
	LCD_DisplayChar(73, 100, 'e');
	LCD_DisplayChar(85, 100, 'n');
	LCD_DisplayChar(95, 100, ',');

	LCD_SetTextColor(LCD_COLOR_YELLOW);

	LCD_DisplayChar(110, 100, 'Y');
	LCD_DisplayChar(120, 100, 'e');
	LCD_DisplayChar(130, 100, 'l');
	LCD_DisplayChar(135, 100, 'l');
	LCD_DisplayChar(145, 100, 'o');
	LCD_DisplayChar(160, 100, 'w');
	LCD_DisplayChar(170, 100, ',');

	LCD_SetTextColor(LCD_COLOR_RED);

	LCD_DisplayChar(70, 120, 'a');
	LCD_DisplayChar(83, 120, 'n');
	LCD_DisplayChar(96, 120, 'd');

	LCD_DisplayChar(120, 120, 'R');
	LCD_DisplayChar(133, 120, 'e');
	LCD_DisplayChar(146, 120, 'd');

	LCD_SetTextColor(LCD_COLOR_BLACK);

	LCD_DisplayChar(40, 150, 'E');
	LCD_DisplayChar(53, 150, 'a');
	LCD_DisplayChar(63, 150, 'c');
	LCD_DisplayChar(75, 150, 'h');

	LCD_DisplayChar(93, 150, 'l');
	LCD_DisplayChar(100, 150, 'e');
	LCD_DisplayChar(110, 150, 'v');
	LCD_DisplayChar(120, 150, 'e');
	LCD_DisplayChar(130, 150, 'l');

	LCD_DisplayChar(150, 150, 'w');
	LCD_DisplayChar(160, 150, 'i');
	LCD_DisplayChar(165, 150, 'l');
	LCD_DisplayChar(170, 150, 'l');

	LCD_DisplayChar(30, 170, 'd');
	LCD_DisplayChar(43, 170, 'e');
	LCD_DisplayChar(53, 170, 's');
	LCD_DisplayChar(63, 170, 'c');
	LCD_DisplayChar(73, 170, 'r');
	LCD_DisplayChar(80, 170, 'i');
	LCD_DisplayChar(90, 170, 'b');
	LCD_DisplayChar(103, 170, 'e');

	LCD_DisplayChar(120,170, 'i');
	LCD_DisplayChar(127,170,'t');
	LCD_DisplayChar(137,170,'s');

	LCD_DisplayChar(155,170,'r');
	LCD_DisplayChar(165,170,'u');
	LCD_DisplayChar(175,170,'l');
	LCD_DisplayChar(182,170,'e');
	LCD_DisplayChar(195,170,'s');
	LCD_DisplayChar(203,170,'.');

	LCD_DisplayChar(20,210,'H');
	LCD_DisplayChar(33,210,'a');
	LCD_DisplayChar(43,210,'v');
	LCD_DisplayChar(53,210,'e');

	LCD_DisplayChar(70,210,'f');
	LCD_DisplayChar(80,210,'u');
	LCD_DisplayChar(93,210,'n');

	LCD_DisplayChar(110,210,'a');
	LCD_DisplayChar(120,210,'n');
	LCD_DisplayChar(133,210,'d');

	LCD_DisplayChar(150,210,'b');
	LCD_DisplayChar(163,210,'e');

	LCD_DisplayChar(180,210,'f');
	LCD_DisplayChar(190,210,'a');
	LCD_DisplayChar(200,210,'s');
	LCD_DisplayChar(210,210,'t');
	LCD_DisplayChar(217,210,'!');

	LCD_SetTextColor(LCD_COLOR_MAGENTA);

	LCD_DisplayChar(45,240,'P');
	LCD_DisplayChar(58,240,'r');
	LCD_DisplayChar(65,240,'e');
	LCD_DisplayChar(78,240,'s');
	LCD_DisplayChar(88,240,'s');

	LCD_DisplayChar(105,240,'t');
	LCD_DisplayChar(115,240,'h');
	LCD_DisplayChar(128,240,'e');

	LCD_DisplayChar(145,240,'u');
	LCD_DisplayChar(158,240,'s');
	LCD_DisplayChar(168,240,'e');
	LCD_DisplayChar(180,240,'r');

	LCD_DisplayChar(40,260,'b');
	LCD_DisplayChar(53,260,'u');
	LCD_DisplayChar(63,260,'t');
	LCD_DisplayChar(73,260,'t');
	LCD_DisplayChar(83,260,'o');
	LCD_DisplayChar(96,260,'n');

	LCD_DisplayChar(113,260,'t');
	LCD_DisplayChar(123,260,'o');

	LCD_DisplayChar(143,260,'s');
	LCD_DisplayChar(153,260,'t');
	LCD_DisplayChar(163,260,'a');
	LCD_DisplayChar(174,260,'r');
	LCD_DisplayChar(183,260,'t');

	BUT_PRESS = 0;

	while (BUT_PRESS != 1) {}

	Level_One();
}

void Level_One(void) {
	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_GREEN);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(68, 50, 'L');
	LCD_DisplayChar(80, 50, 'e');
	LCD_DisplayChar(90, 50, 'v');
	LCD_DisplayChar(100, 50, 'e');
	LCD_DisplayChar(110, 50, 'l');

	LCD_DisplayChar(128, 50, 'O');
	LCD_DisplayChar(143, 50, 'n');
	LCD_DisplayChar(155, 50, 'e');
	LCD_DisplayChar(164, 50, ':');

	LCD_SetTextColor(LCD_COLOR_BLACK);

	LCD_DisplayChar(45, 80, 'W');
	LCD_DisplayChar(58, 80, 'h');
	LCD_DisplayChar(70, 80, 'e');
	LCD_DisplayChar(83, 80, 'n');

	LCD_DisplayChar(100, 80, 'y');
	LCD_DisplayChar(110, 80, 'o');
	LCD_DisplayChar(123, 80, 'u');

	LCD_DisplayChar(140, 80, 's');
	LCD_DisplayChar(150, 80, 'e');
	LCD_DisplayChar(162, 80, 'e');

	LCD_DisplayChar(180, 80, 'a');

	LCD_DisplayChar(30, 100, 's');
	LCD_DisplayChar(40, 100, 'q');
	LCD_DisplayChar(53, 100, 'u');
	LCD_DisplayChar(65, 100, 'a');
	LCD_DisplayChar(75, 100, 'r');
	LCD_DisplayChar(83, 100, 'e');

	LCD_DisplayChar(105, 100, 'o');
	LCD_DisplayChar(115, 100, 'r');

	LCD_DisplayChar(130, 100, 't');
	LCD_DisplayChar(140, 100, 'r');
	LCD_DisplayChar(147, 100, 'i');
	LCD_DisplayChar(155, 100, 'a');
	LCD_DisplayChar(167, 100, 'n');
	LCD_DisplayChar(180, 100, 'g');
	LCD_DisplayChar(190, 100, 'l');
	LCD_DisplayChar(197, 100, 'e');

	LCD_DisplayChar(50, 120, 'p');
	LCD_DisplayChar(60, 120, 'r');
	LCD_DisplayChar(67, 120, 'e');
	LCD_DisplayChar(80, 120, 's');
	LCD_DisplayChar(90, 120, 's');

	LCD_DisplayChar(108, 120, 't');
	LCD_DisplayChar(118, 120, 'h');
	LCD_DisplayChar(130, 120, 'e');

	LCD_DisplayChar(150, 120, 'u');
	LCD_DisplayChar(162, 120, 's');
	LCD_DisplayChar(173, 120, 'e');
	LCD_DisplayChar(183, 120, 'r');

	LCD_DisplayChar(58, 140, 'b');
	LCD_DisplayChar(70, 140, 'u');
	LCD_DisplayChar(80, 140, 't');
	LCD_DisplayChar(90, 140, 't');
	LCD_DisplayChar(100, 140, 'o');
	LCD_DisplayChar(112, 140, 'n');

	LCD_DisplayChar(130, 140, 'a');
	LCD_DisplayChar(140, 140, 's');
	LCD_DisplayChar(152, 140, 'a');
	LCD_DisplayChar(163, 140, 'p');
	LCD_DisplayChar(171, 140, '.');

	LCD_DisplayChar(63, 170, 'G');
	LCD_DisplayChar(78, 170, 'o');
	LCD_DisplayChar(90, 170, 'o');
	LCD_DisplayChar(102, 170, 'd');

	LCD_DisplayChar(118, 170, 'l');
	LCD_DisplayChar(125, 170, 'u');
	LCD_DisplayChar(138, 170, 'c');
	LCD_DisplayChar(149, 170, 'k');
	LCD_DisplayChar(156, 170, '!');

	HAL_Delay(5000);
	LCD_Clear(0, LCD_COLOR_GREEN);

	uint32_t shape = RNG_App_Get() % 2;

	uint32_t randDelay = RNG_App_Get();

	HAL_Delay(randDelay % 7000);
// start timer here
	int start = HAL_GetTick();
	switch(shape) {
		case 0:
			LCD_Draw_Triangle_Fill(60, 200, 120, LCD_COLOR_BLUE);
			break;
		case 1:
			LCD_Draw_Square_Fill(60, 100, 120, LCD_COLOR_BLUE);
			break;
	 }

	BUT_PRESS = 0;

	while (BUT_PRESS != 1) {}
//stop timer
	int end = HAL_GetTick();

	lvl1Time = end - start;

	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(68, 50, 'G');
	LCD_DisplayChar(83, 50, 'o');
	LCD_DisplayChar(94, 50, 'o');
	LCD_DisplayChar(106, 50, 'd');

	LCD_DisplayChar(125, 50, 'j');
	LCD_DisplayChar(132, 50, 'o');
	LCD_DisplayChar(145, 50, 'b');
	LCD_DisplayChar(152, 50, '!');

	LCD_DisplayChar(50, 80, 'N');
	LCD_DisplayChar(63, 80, 'o');
	LCD_DisplayChar(76, 80, 'w');

	LCD_DisplayChar(93, 80, 'i');
	LCD_DisplayChar(100, 80, 't');
	LCD_DisplayChar(110, 80, 's');

	LCD_DisplayChar(130, 80, 't');
	LCD_DisplayChar(138, 80, 'i');
	LCD_DisplayChar(150, 80, 'm');
	LCD_DisplayChar(164, 80, 'e');

	LCD_DisplayChar(45, 100, 'f');
	LCD_DisplayChar(55, 100, 'o');
	LCD_DisplayChar(68, 100, 'r');

	LCD_DisplayChar(82, 100, 'l');
	LCD_DisplayChar(90, 100, 'e');
	LCD_DisplayChar(100, 100, 'v');
	LCD_DisplayChar(110, 100, 'e');
	LCD_DisplayChar(120, 100, 'l');

	LCD_DisplayChar(140, 100, 't');
	LCD_DisplayChar(153, 100, 'w');
	LCD_DisplayChar(167, 100, 'o');
	LCD_DisplayChar(175, 100, '!');

	HAL_Delay(5000);
	Level_Two();
}

void Level_Two(void) {
	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_YELLOW);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(68, 50, 'L');
	LCD_DisplayChar(80, 50, 'e');
	LCD_DisplayChar(90, 50, 'v');
	LCD_DisplayChar(100, 50, 'e');
	LCD_DisplayChar(110, 50, 'l');

	LCD_DisplayChar(128, 50, 'T');
	LCD_DisplayChar(143, 50, 'w');
	LCD_DisplayChar(156, 50, 'o');
	LCD_DisplayChar(165, 50, ':');

	LCD_SetTextColor(LCD_COLOR_BLACK);

	LCD_DisplayChar(45, 80, 'W');
	LCD_DisplayChar(58, 80, 'h');
	LCD_DisplayChar(70, 80, 'e');
	LCD_DisplayChar(83, 80, 'n');

	LCD_DisplayChar(100, 80, 'y');
	LCD_DisplayChar(110, 80, 'o');
	LCD_DisplayChar(123, 80, 'u');

	LCD_DisplayChar(140, 80, 's');
	LCD_DisplayChar(150, 80, 'e');
	LCD_DisplayChar(162, 80, 'e');

	LCD_DisplayChar(180, 80, 'a');

	LCD_DisplayChar(30, 102, 's');
	LCD_DisplayChar(40, 102, 'q');
	LCD_DisplayChar(53, 102, 'u');
	LCD_DisplayChar(65, 102, 'a');
	LCD_DisplayChar(75, 102, 'r');
	LCD_DisplayChar(83, 102, 'e');

	LCD_DisplayChar(105, 102, 'b');
	LCD_DisplayChar(116, 102, 'e');
	LCD_DisplayChar(128, 102, 'c');
	LCD_DisplayChar(138, 102, 'o');
	LCD_DisplayChar(152, 102, 'm');
	LCD_DisplayChar(167, 102, 'e');

	LCD_DisplayChar(185, 102, 'a');

	LCD_DisplayChar(30, 123, 't');
	LCD_DisplayChar(40, 123, 'r');
	LCD_DisplayChar(47, 123, 'i');
	LCD_DisplayChar(57, 123, 'a');
	LCD_DisplayChar(70, 123, 'n');
	LCD_DisplayChar(83, 123, 'g');
	LCD_DisplayChar(91, 123, 'l');
	LCD_DisplayChar(100, 123, 'e');

	LCD_DisplayChar(120, 123, 'p');
	LCD_DisplayChar(130, 123, 'r');
	LCD_DisplayChar(138, 123, 'e');
	LCD_DisplayChar(150, 123, 's');
	LCD_DisplayChar(160, 123, 's');

	LCD_DisplayChar(180, 123, 't');
	LCD_DisplayChar(190, 123, 'h');
	LCD_DisplayChar(202, 123, 'e');

	LCD_DisplayChar(38, 146, 'u');
	LCD_DisplayChar(50, 146, 's');
	LCD_DisplayChar(60, 146, 'e');
	LCD_DisplayChar(71, 146, 'r');

	LCD_DisplayChar(89, 146, 'b');
	LCD_DisplayChar(100, 146, 'u');
	LCD_DisplayChar(111, 146, 't');
	LCD_DisplayChar(120, 146, 't');
	LCD_DisplayChar(130, 146, 'o');
	LCD_DisplayChar(142, 146, 'n');

	LCD_DisplayChar(160, 146, 'a');
	LCD_DisplayChar(170, 146, 's');
	LCD_DisplayChar(183, 146, 'a');
	LCD_DisplayChar(194, 146, 'p');
	LCD_DisplayChar(202, 146, '.');

	LCD_DisplayChar(63, 170, 'G');
	LCD_DisplayChar(78, 170, 'o');
	LCD_DisplayChar(90, 170, 'o');
	LCD_DisplayChar(102, 170, 'd');

	LCD_DisplayChar(118, 170, 'l');
	LCD_DisplayChar(125, 170, 'u');
	LCD_DisplayChar(138, 170, 'c');
	LCD_DisplayChar(149, 170, 'k');
	LCD_DisplayChar(156, 170, '!');

	HAL_Delay(5000);

	LCD_Clear(0, LCD_COLOR_YELLOW);

	LCD_Draw_Square_Fill(30, 40, 60, LCD_COLOR_BLUE);

	LCD_Draw_Square_Fill(150, 40, 60, LCD_COLOR_BLUE);

	LCD_Draw_Square_Fill(30, 200, 60, LCD_COLOR_BLUE);

	LCD_Draw_Square_Fill(150, 200, 60, LCD_COLOR_BLUE);

	uint32_t triPos = RNG_App_Get() % 4;

	uint32_t randDelay = RNG_App_Get();

	HAL_Delay(randDelay % 7000);
// start timer here
	int start;

	switch(triPos) {
		case 0:

			LCD_Clear(0, LCD_COLOR_YELLOW);

			LCD_Draw_Square_Fill(150, 40, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(30, 200, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(150, 200, 60, LCD_COLOR_BLUE);

			LCD_Draw_Triangle_Fill(30, 100, 60, LCD_COLOR_MAGENTA);

			start = HAL_GetTick();
			break;
		case 1:
			LCD_Clear(0, LCD_COLOR_YELLOW);

			LCD_Draw_Square_Fill(30, 40, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(30, 200, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(150, 200, 60, LCD_COLOR_BLUE);

			LCD_Draw_Triangle_Fill(150, 100, 60, LCD_COLOR_MAGENTA);

			start = HAL_GetTick();
			break;
		case 2:
			LCD_Clear(0, LCD_COLOR_YELLOW);

			LCD_Draw_Square_Fill(30, 40, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(150, 40, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(150, 200, 60, LCD_COLOR_BLUE);

			LCD_Draw_Triangle_Fill(30, 260, 60, LCD_COLOR_MAGENTA);

			start = HAL_GetTick();
			break;
		case 3:
			LCD_Clear(0, LCD_COLOR_YELLOW);

			LCD_Draw_Square_Fill(30, 40, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(150, 40, 60, LCD_COLOR_BLUE);

			LCD_Draw_Square_Fill(30, 200, 60, LCD_COLOR_BLUE);

			LCD_Draw_Triangle_Fill(150, 260, 60, LCD_COLOR_MAGENTA);

			start = HAL_GetTick();
			break;
	 }

	BUT_PRESS = 0;

	while (BUT_PRESS != 1) {}
//stop timer
	int end = HAL_GetTick();

	lvl2Time = end - start;

	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(68, 50, 'G');
	LCD_DisplayChar(83, 50, 'o');
	LCD_DisplayChar(94, 50, 'o');
	LCD_DisplayChar(106, 50, 'd');

	LCD_DisplayChar(125, 50, 'j');
	LCD_DisplayChar(132, 50, 'o');
	LCD_DisplayChar(145, 50, 'b');
	LCD_DisplayChar(152, 50, '!');

	LCD_DisplayChar(50, 80, 'N');
	LCD_DisplayChar(63, 80, 'o');
	LCD_DisplayChar(76, 80, 'w');

	LCD_DisplayChar(93, 80, 'i');
	LCD_DisplayChar(100, 80, 't');
	LCD_DisplayChar(110, 80, 's');

	LCD_DisplayChar(130, 80, 't');
	LCD_DisplayChar(138, 80, 'i');
	LCD_DisplayChar(150, 80, 'm');
	LCD_DisplayChar(164, 80, 'e');

	LCD_DisplayChar(45, 100, 'f');
	LCD_DisplayChar(55, 100, 'o');
	LCD_DisplayChar(68, 100, 'r');

	LCD_DisplayChar(82, 100, 'l');
	LCD_DisplayChar(90, 100, 'e');
	LCD_DisplayChar(100, 100, 'v');
	LCD_DisplayChar(110, 100, 'e');
	LCD_DisplayChar(120, 100, 'l');

	LCD_DisplayChar(132, 100, 't');
	LCD_DisplayChar(142, 100, 'h');
	LCD_DisplayChar(152, 100, 'r');
	LCD_DisplayChar(160, 100, 'e');
	LCD_DisplayChar(172, 100, 'e');
	LCD_DisplayChar(180, 100, '!');

	HAL_Delay(5000);
	Level_Three();
}

void Level_Three(void) {
	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_RED);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(68, 50, 'L');
	LCD_DisplayChar(80, 50, 'e');
	LCD_DisplayChar(90, 50, 'v');
	LCD_DisplayChar(100, 50, 'e');
	LCD_DisplayChar(110, 50, 'l');

	LCD_DisplayChar(128, 50, 'T');
	LCD_DisplayChar(138, 50, 'h');
	LCD_DisplayChar(148, 50, 'r');
	LCD_DisplayChar(156, 50, 'e');
	LCD_DisplayChar(168, 50, 'e');
	LCD_DisplayChar(176, 50, ':');

	LCD_SetTextColor(LCD_COLOR_BLACK);

	LCD_DisplayChar(35, 80, 'W');
	LCD_DisplayChar(48, 80, 'h');
	LCD_DisplayChar(60, 80, 'e');
	LCD_DisplayChar(73, 80, 'n');

	LCD_DisplayChar(90, 80, 'y');
	LCD_DisplayChar(100, 80, 'o');
	LCD_DisplayChar(113, 80, 'u');

	LCD_DisplayChar(130, 80, 's');
	LCD_DisplayChar(140, 80, 'e');
	LCD_DisplayChar(152, 80, 'e');

	LCD_DisplayChar(170, 80, 't');
	LCD_DisplayChar(180, 80, 'h');
	LCD_DisplayChar(192, 80, 'e');

	LCD_DisplayChar(35, 102, 'c');
	LCD_DisplayChar(43, 102, 'i');
	LCD_DisplayChar(51, 102, 'r');
	LCD_DisplayChar(60, 102, 'c');
	LCD_DisplayChar(69, 102, 'l');
	LCD_DisplayChar(77, 102, 'e');

	LCD_DisplayChar(100, 102, 'c');
	LCD_DisplayChar(110, 102, 'r');
	LCD_DisplayChar(119, 102, 'o');
	LCD_DisplayChar(130, 102, 's');
	LCD_DisplayChar(140, 102, 's');

	LCD_DisplayChar(160, 102, 't');
	LCD_DisplayChar(170, 102, 'h');
	LCD_DisplayChar(182, 102, 'e');

	LCD_DisplayChar(20, 123, 'c');
	LCD_DisplayChar(30, 123, 'e');
	LCD_DisplayChar(42, 123, 'n');
	LCD_DisplayChar(52, 123, 't');
	LCD_DisplayChar(62, 123, 'e');
	LCD_DisplayChar(73, 123, 'r');

	LCD_DisplayChar(90, 123, 'l');
	LCD_DisplayChar(97, 123, 'i');
	LCD_DisplayChar(106, 123, 'n');
	LCD_DisplayChar(117, 123, 'e');

	LCD_DisplayChar(140, 123, 'p');
	LCD_DisplayChar(150, 123, 'r');
	LCD_DisplayChar(158, 123, 'e');
	LCD_DisplayChar(170, 123, 's');
	LCD_DisplayChar(180, 123, 's');

	LCD_DisplayChar(195, 123, 't');
	LCD_DisplayChar(205, 123, 'h');
	LCD_DisplayChar(217, 123, 'e');

	LCD_DisplayChar(38, 146, 'u');
	LCD_DisplayChar(50, 146, 's');
	LCD_DisplayChar(60, 146, 'e');
	LCD_DisplayChar(71, 146, 'r');

	LCD_DisplayChar(89, 146, 'b');
	LCD_DisplayChar(100, 146, 'u');
	LCD_DisplayChar(111, 146, 't');
	LCD_DisplayChar(120, 146, 't');
	LCD_DisplayChar(130, 146, 'o');
	LCD_DisplayChar(142, 146, 'n');

	LCD_DisplayChar(160, 146, 'a');
	LCD_DisplayChar(170, 146, 's');
	LCD_DisplayChar(183, 146, 'a');
	LCD_DisplayChar(194, 146, 'p');
	LCD_DisplayChar(202, 146, '.');

	LCD_DisplayChar(20, 169, 'Y');
	LCD_DisplayChar(30, 169, 'o');
	LCD_DisplayChar(42, 169, 'u');

	LCD_DisplayChar(63, 169, 'w');
	LCD_DisplayChar(74, 169, 'i');
	LCD_DisplayChar(80, 169, 'l');
	LCD_DisplayChar(85, 169, 'l');

	LCD_DisplayChar(105, 169, 'h');
	LCD_DisplayChar(117, 169, 'a');
	LCD_DisplayChar(127, 169, 'v');
	LCD_DisplayChar(137, 169, 'e');

	LCD_DisplayChar(160, 169, '3');

	LCD_DisplayChar(180, 169, 't');
	LCD_DisplayChar(190, 169, 'r');
	LCD_DisplayChar(197, 169, 'i');
	LCD_DisplayChar(205, 169, 'e');
	LCD_DisplayChar(216, 169, 's');

	LCD_DisplayChar(63, 200, 'G');
	LCD_DisplayChar(78, 200, 'o');
	LCD_DisplayChar(90, 200, 'o');
	LCD_DisplayChar(102, 200, 'd');

	LCD_DisplayChar(118, 200, 'l');
	LCD_DisplayChar(125, 200, 'u');
	LCD_DisplayChar(138, 200, 'c');
	LCD_DisplayChar(149, 200, 'k');
	LCD_DisplayChar(156, 200, '!');

	HAL_Delay(5000);

	LCD_Clear(0, LCD_COLOR_RED);

	int timesCrossed = 0;

	int xPos = 50;
	int yPos = 160;

	int prevX = xPos;
	int prevY = yPos;

	int start = 0;
	int end = 0;

	int direction = 0;

	BUT_PRESS = 0;

//	uint32_t randDelay = RNG_App_Get();

	while (timesCrossed < 3) {
		LCD_Draw_Circle_Fill(prevX, prevY, 50, LCD_COLOR_RED);
		LCD_Draw_Circle_Fill(xPos, yPos, 50, LCD_COLOR_WHITE);
		LCD_Draw_Vertical_Line(120, 0, 320, LCD_COLOR_BLACK);
		prevX = xPos;
		prevY = yPos;
		if (xPos <= 50) {
			direction = 0;
		}
		if (xPos >= 190) {
			direction = 1;
		}
		switch(direction) {
			case 0:
				if (xPos == 170) {
					//timer start
					start = HAL_GetTick();
					BUT_PRESS = 0;
					while (BUT_PRESS != 1) {}
					//timer stop
					end = HAL_GetTick();

					if (timesCrossed == 0) {
						lvl3aTime = end - start;
					} else {
						lvl3cTime = end - start;
					}

					timesCrossed += 1;
				}
				xPos++;
				break;
			case 1:
				if (xPos == 70) {
					//timer start
					start = HAL_GetTick();
					BUT_PRESS = 0;
					while (BUT_PRESS != 1) {}
					//timer stop
					end = HAL_GetTick();

					lvl3bTime = end - start;

					timesCrossed += 1;
				}
				xPos--;
				break;
		}
		if (timesCrossed == 0) {
			LCD_SetTextColor(LCD_COLOR_RED);
			LCD_DisplayChar(prevX - 8, prevY - 12, '1');
			LCD_SetTextColor(LCD_COLOR_BLACK);
			LCD_DisplayChar(xPos - 8, yPos - 12, '1');
		}
		if (timesCrossed == 1) {
			LCD_SetTextColor(LCD_COLOR_RED);
			LCD_DisplayChar(xPos - 8, yPos - 12, '2');
			LCD_SetTextColor(LCD_COLOR_BLACK);
			LCD_DisplayChar(xPos - 8, yPos - 12, '2');
		}
		if (timesCrossed == 2) {
			LCD_SetTextColor(LCD_COLOR_RED);
			LCD_DisplayChar(xPos - 8, yPos - 12, '3');
			LCD_SetTextColor(LCD_COLOR_BLACK);
			LCD_DisplayChar(xPos - 8, yPos - 12, '3');
		}

//		HAL_Delay(randDelay % 25);
		HAL_Delay(50);
	}

	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(68, 50, 'G');
	LCD_DisplayChar(83, 50, 'o');
	LCD_DisplayChar(94, 50, 'o');
	LCD_DisplayChar(106, 50, 'd');

	LCD_DisplayChar(125, 50, 'j');
	LCD_DisplayChar(132, 50, 'o');
	LCD_DisplayChar(145, 50, 'b');
	LCD_DisplayChar(152, 50, '!');

	LCD_DisplayChar(50, 80, 'N');
	LCD_DisplayChar(63, 80, 'o');
	LCD_DisplayChar(76, 80, 'w');

	LCD_DisplayChar(93, 80, 'i');
	LCD_DisplayChar(100, 80, 't');
	LCD_DisplayChar(110, 80, 's');

	LCD_DisplayChar(130, 80, 't');
	LCD_DisplayChar(138, 80, 'i');
	LCD_DisplayChar(150, 80, 'm');
	LCD_DisplayChar(164, 80, 'e');

	LCD_DisplayChar(30, 100, 't');
	LCD_DisplayChar(40, 100, 'o');

	LCD_DisplayChar(60, 100, 's');
	LCD_DisplayChar(70, 100, 'e');
	LCD_DisplayChar(80, 100, 'e');

	LCD_DisplayChar(97, 100, 'h');
	LCD_DisplayChar(109, 100, 'o');
	LCD_DisplayChar(122, 100, 'w');

	LCD_DisplayChar(140, 100, 'y');
	LCD_DisplayChar(150, 100, 'o');
	LCD_DisplayChar(162, 100, 'u');

	LCD_DisplayChar(180, 100, 'd');
	LCD_DisplayChar(192, 100, 'i');
	LCD_DisplayChar(200, 100, 'd');
	LCD_DisplayChar(210, 100, '!');

	HAL_Delay(5000);
	End_Screen();
}

void End_Screen(void) {
	int levelOneTime[4];
	levelOneTime[0] = RNG_Digit_Extractor(lvl1Time);
	lvl1Time /= 10;
	levelOneTime[1] = RNG_Digit_Extractor(lvl1Time);
	lvl1Time /= 10;
	levelOneTime[2] = RNG_Digit_Extractor(lvl1Time);
	lvl1Time /= 10;
	levelOneTime[3] = RNG_Digit_Extractor(lvl1Time);

	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_MAGENTA);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(40, 50, 'Y');
	LCD_DisplayChar(52, 50, 'o');
	LCD_DisplayChar(64, 50, 'u');
	LCD_DisplayChar(76, 50, 'r');

	LCD_DisplayChar(90, 50, 'R');
	LCD_DisplayChar(102, 50, 'e');
	LCD_DisplayChar(114, 50, 's');
	LCD_DisplayChar(124, 50, 'u');
	LCD_DisplayChar(134, 50, 'l');
	LCD_DisplayChar(140, 50, 't');
	LCD_DisplayChar(150, 50, 's');
	LCD_DisplayChar(160, 50, ':');

	LCD_SetTextColor(LCD_COLOR_GREEN);
	LCD_DisplayChar(50, 80, 'G');
	LCD_DisplayChar(64, 80, 'r');
	LCD_DisplayChar(72, 80, 'e');
	LCD_DisplayChar(84, 80, 'e');
	LCD_DisplayChar(96, 80, 'n');
	LCD_DisplayChar(104, 80, ':');

	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_DisplayChar(130, 80, levelOneTime[3] + '0');
	LCD_DisplayChar(140, 80, '.');
	LCD_DisplayChar(150, 80, levelOneTime[2] + '0');
	LCD_DisplayChar(163, 80, levelOneTime[1] + '0');
	LCD_DisplayChar(176, 80, levelOneTime[0] + '0');
	LCD_DisplayChar(188, 80, 's');

	int levelTwoTime[4];
	levelTwoTime[0] = RNG_Digit_Extractor(lvl2Time);
	lvl2Time /= 10;
	levelTwoTime[1] = RNG_Digit_Extractor(lvl2Time);
	lvl2Time /= 10;
	levelTwoTime[2] = RNG_Digit_Extractor(lvl2Time);
	lvl2Time /= 10;
	levelTwoTime[3] = RNG_Digit_Extractor(lvl2Time);

	LCD_SetTextColor(LCD_COLOR_YELLOW);
	LCD_DisplayChar(50, 110, 'Y');
	LCD_DisplayChar(64, 110, 'e');
	LCD_DisplayChar(72, 110, 'l');
	LCD_DisplayChar(82, 110, 'l');
	LCD_DisplayChar(90, 110, 'o');
	LCD_DisplayChar(104, 110, 'w');
	LCD_DisplayChar(114, 110, ':');

	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_DisplayChar(130, 110, levelTwoTime[3] + '0');
	LCD_DisplayChar(140, 110, '.');
	LCD_DisplayChar(150, 110, levelTwoTime[2] + '0');
	LCD_DisplayChar(163, 110, levelTwoTime[1] + '0');
	LCD_DisplayChar(176, 110, levelTwoTime[0] + '0');
	LCD_DisplayChar(188, 110, 's');

	int lvl3Fin = smallestLvl3();

	int levelThrTime[4];
	levelThrTime[0] = RNG_Digit_Extractor(lvl3Fin);
	lvl3Fin /= 10;
	levelThrTime[1] = RNG_Digit_Extractor(lvl3Fin);
	lvl3Fin /= 10;
	levelThrTime[2] = RNG_Digit_Extractor(lvl3Fin);
	lvl3Fin /= 10;
	levelThrTime[3] = RNG_Digit_Extractor(lvl3Fin);

	LCD_SetTextColor(LCD_COLOR_RED);
	LCD_DisplayChar(50, 140, 'R');
	LCD_DisplayChar(64, 140, 'e');
	LCD_DisplayChar(76, 140, 'd');
	LCD_DisplayChar(86, 140, ':');

	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_DisplayChar(130, 140, levelThrTime[3] + '0');
	LCD_DisplayChar(140, 140, '.');
	LCD_DisplayChar(150, 140, levelThrTime[2] + '0');
	LCD_DisplayChar(163, 140, levelThrTime[1] + '0');
	LCD_DisplayChar(176, 140, levelThrTime[0] + '0');
	LCD_DisplayChar(188, 140, 's');

	LCD_SetTextColor(LCD_COLOR_MAGENTA);

	LCD_DisplayChar(45,240,'P');
	LCD_DisplayChar(58,240,'r');
	LCD_DisplayChar(65,240,'e');
	LCD_DisplayChar(78,240,'s');
	LCD_DisplayChar(88,240,'s');

	LCD_DisplayChar(105,240,'t');
	LCD_DisplayChar(115,240,'h');
	LCD_DisplayChar(128,240,'e');

	LCD_DisplayChar(145,240,'u');
	LCD_DisplayChar(158,240,'s');
	LCD_DisplayChar(168,240,'e');
	LCD_DisplayChar(180,240,'r');

	LCD_DisplayChar(35,260,'b');
	LCD_DisplayChar(48,260,'u');
	LCD_DisplayChar(58,260,'t');
	LCD_DisplayChar(68,260,'t');
	LCD_DisplayChar(78,260,'o');
	LCD_DisplayChar(91,260,'n');

	LCD_DisplayChar(108,260,'t');
	LCD_DisplayChar(118,260,'o');

	LCD_DisplayChar(138,260,'g');
	LCD_DisplayChar(148,260,'o');

	LCD_DisplayChar(165,260,'a');
	LCD_DisplayChar(177,260,'g');
	LCD_DisplayChar(189,260,'a');
	LCD_DisplayChar(199,260,'i');
	LCD_DisplayChar(209,260,'n');

	BUT_PRESS = 0;

	while (BUT_PRESS != 1) {}

	Level_One();
}

void Button_Set() {
	BUT_PRESS = 1;
}

void Button_Tester(void) {
	LCD_Clear(0,LCD_COLOR_BLACK);
}

































