/*
 * Assignment1.c
 * In a group of two, create a game in which two people compete on how fast they can light on their set of LEDs. Each user will be assigned a press button and his set of LEDs.
 * As a user presses the button his assigned LED will lit up one after the other. The person who switch on all his LEDs first wins.
 * The winner will be exposed by flashing their assigned LEDs for a while, before reseting the system for a new competation.
 * 
 * Your program should make use of arrays, functions, and for-loop. A report should be submitted here, and the hardware will be presented in the classroom. 
 * Created: 16.01.2023 15:01:44
 * Author : Markus F. Skjøthaug
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

const int NUMBERTOWIN = 3;

// Making functions that runs if a spesific user wins the game

//IDEA: implement function that displays the total number of wins per user on the LED's mid games. A countdown blinker would also be cool.

//IDEA: bruke mattebiblioteket og 10^n for å ligthe de forskjellige pærene

void USR_A_Win(){
	for (int i = 0; i < 10; i++){
		PORTA = 0b00011111;
		_delay_ms(500);
		PORTA = 0b00000000;	
	}
}
void Victory_A(){
	//Code that flashes the Victory fanfare!
}

void USR_B_Win(){
	for (int i = 0; i < 10; i++){
		PORTD = 0b00011111;
		_delay_ms(500);
		PORTD = 0b00000000;
	}
}
void Victory_B(){
	//Victory fanfare!!
}

int main(void)
{
	// USR_A parametres/variables
    DDRA = 0b00011111;
	PORTA = 0b00100000;
	int USR_A_Count = 0;
	int USR_A_TOT_WINS = 0;
	
	//USR_B parametres/variables
    DDRD = 0b00011111;
	PORTD = 0b00100000;
	int USR_B_Count = 0;
	int USR_B_TOT_WINS = 0;

    while ((USR_A_TOT_WINS != 4) | (USR_B_TOT_WINS != 4)){
		/*USR_A: if USR_A pushes the button, the lights will light up one at a time, and the lights will stay on.
		* It also increments the value needed to win the game. */
		if (!(PINA & (1 << 5))){
			PORTA += 0b00000001;
			USR_A_Count++;
		}
		//USR_B
		if (!(PIND & (1 << 5))){
			PORTD = (PORTD << 1) + 0b00000001;
			USR_B_Count++;
		}
		// @markusskjothaug
		// Det funker som en drøm å kode i GitHub!

		if (USR_A_Count == NUMBERTOWIN){
			USR_A_Win();
			USR_A_TOT_WINS++;
		} else if (USR_B_Count == NUMBERTOWIN){
			USR_B_Win();
			USR_B_TOT_WINS++;
		}		
    }

	// If a player wins 4 rounds in total, the victoryfunctions will run.
	if (USR_A_TOT_WINS == 4){
		Victory_A();
	} else if (USR_B_TOT_WINS == 4){
		Victory_B();
	}
}