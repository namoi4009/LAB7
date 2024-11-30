/*
 * screen.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "screen.h"

void screen_init(){
	lcd_ShowStr(60,90,"WELCOME TO",WHITE,WHITE,24,1);
	lcd_ShowStr(40,120,"SNAKE GAME",WHITE,WHITE,32,1);
}

void screen_play(){
	lcd_Fill(0, 0, 240, 200, WHITE);
	lcd_DrawCircle(120, 230, GBLUE, 20, 1);
	lcd_DrawCircle(120, 280, GBLUE, 20, 1);
	lcd_DrawCircle(50, 280, GBLUE, 20, 1);
	lcd_DrawCircle(190, 280, GBLUE, 20, 1);
}

void screen_score(){
	lcd_ShowStr(0, 205, "Score: ", WHITE, WHITE, 24, 1);
	lcd_ShowIntNum(70, 205, score, 2, WHITE, BLACK, 24);
}

void screen_game_over(){
	lcd_ShowStr(40,110,"GAME OVER!",WHITE,WHITE,32,1);
	lcd_ShowStr(70, 220, "Score: ", WHITE, WHITE, 24, 1);
	lcd_ShowIntNum(150, 220, score, 2, WHITE, BLACK, 24);
}

