/*
 * fsm.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */


#include "fsm.h"

int status = INIT;
int speed = 250;
int check_sent;
int count = 0;
char sec = '/';
//uint8_t count_adc = 0;
int countdown = 180;
int timer = 0;
int buzzer_flag = BUZZER_OFF;
int buzzer_check = 0;
int colon = 0;
int send_flag = 0;

void fsm_machine(){
	switch (status) {
	case INIT:
		screen_init();

		if(isButtonStart()){
			status = PLAY;
			count = 0;
			lcd_Clear(BLACK);
			re_init();
			screen_play();
			setTimer4(1000);
		}
		break;
	case PLAY:
		if(isButtonUp()){
			sw_up = 0;
			sw_down = 1;
			sw_left = 1;
			sw_right = 1;
		}
		if(isButtonDown()){
			sw_up = 1;
			sw_down = 0;
			sw_left = 1;
			sw_right = 1;
		}
		if(isButtonLeft()){
			sw_up = 1;
			sw_down = 1;
			sw_left = 0;
			sw_right = 1;
		}
		if(isButtonRight()){
			sw_up = 1;
			sw_down = 1;
			sw_left = 1;
			sw_right = 0;
		}
		wait_check();
		update_grid();
		if(flag_timer3 == 1){
			setTimer3(speed);
			move_snake();
			screen_score();
			update_grid();
		}
		if(lose == 1){
			status = GAME_OVER;
			send_flag = 1;
			send_flag =0;
			lcd_Clear(BLACK);
			lcd_Fill(50, 250, 190, 300, RED);
			lcd_ShowStr(80,260,"RESTART",WHITE,WHITE,24,1);
			lose = 0;
		}
		break;
	case GAME_OVER:
		screen_game_over();

		if(isButtonRestart()){
			count = 0;
			status = PLAY;
			lcd_Clear(BLACK);
			re_init();
			screen_play();
		}
		break;
	default:
		break;
	}
}


