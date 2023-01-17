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
#include F_CPU 1000000
#include <util/delay.h>


void USR_A_Win(){
	for (int i = 0; i < 10; i++){
		PORTA = 0b00011111;
		_delay_ms(500);
	}
}

void USR_B_Win(){
	for (int i = 0; i < 10; i++){
		PORTB = 0b00011111;
		_delay_ms(500);
	}
}


int main(void)
{
	// USR_A
    DDRA = 0b00011111;
	PORTA = 0b00000000;
	int USR_A_Count = 0;
	
	//USR_B
    DDRB = 0b00011111;
	PORTB = 0b00000000;
	int USR_B_Count = 0;

    while (1){
		//USR_A
		if ((PORTA & 0b00100000) == 0b00100000){
			PORTA = (PORTA << 1) + 0b00000001;
			USR_A_Count++;
		}
		//USR_B
		if ((PORTB & 0b00100000) == 0b00100000){
			PORTB = (PORTB << 1) + 0b00000001;
			USR_B_Count++
		}
		// @markusskjothaug
		// Det funker som en drøm å kode i GitHub!

		if (USR_A_Count == 5){
			USR_A_Win();
		} else if (USR_B_Count == 5){
			USR_B_Win();
		}
		
		
    }
	
	while(!win){
		if (usrAint == 0){
			PORTA = 0;
		} elif (usraint ==1)
		PORTA = 0b00001111
	}
}

