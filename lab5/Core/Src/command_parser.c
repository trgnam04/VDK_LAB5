/*
 * command_parser.c
 *
 *  Created on: Sep 30, 2024
 *      Author: ASUS
 */

#include "command_parser.h"

unsigned char start_send_data = 0;
unsigned char stop_send_data = 0;
unsigned char flag_timeout = 0;

enum command_parser_state {
	IDLE,
	START_PROCESS,
	RECEIVE_R,
	RECEIVE_S,
	RECEIVE_T,
	RECEIVE_O,
	RECEIVE_K,
	START_SEND_DATA_SIGNAL,
	STOP_SEND_DATA_SIGNAL
};

enum uart_communication_state {
	ERROR,
	IDLE_HANDLER,
	TIME_OUT_STATE,
	START_SEND_DATA,
	STOP_SEND_DATA
};

enum command_parser_state commandParserState =  IDLE;
enum uart_communication_state uartCommunicationState = IDLE_HANDLER;

void command_parser_fsm(void){
	unsigned char bufferCheck = buffer[index_buffer - 1];
	switch(commandParserState){
	case IDLE:{
		if(bufferCheck == '!'){
			commandParserState = START_PROCESS;
		}
		break;
	}
	case START_PROCESS:{
		if(bufferCheck == 'O'){
			commandParserState = RECEIVE_O;
		}
		else if(bufferCheck == 'R'){
			commandParserState = RECEIVE_R;
		}
		else{
			commandParserState = IDLE;
		}
		break;
	}
	case RECEIVE_R:{
		if(bufferCheck == 'S'){
			commandParserState = RECEIVE_S;
		}
		else{
			commandParserState = IDLE;
		}
		break;
	}
	case RECEIVE_S:{
		if(bufferCheck == 'S'){
			commandParserState = RECEIVE_S;
		}
		else{
			commandParserState = IDLE;
		}
		break;
	}
	case RECEIVE_T:{
		if(bufferCheck == '#'){
			commandParserState = START_SEND_DATA_SIGNAL;
		}
		else{
			commandParserState = IDLE;
		}
		break;
	}
	case RECEIVE_O:{
		if(bufferCheck == 'K'){
			commandParserState = RECEIVE_K;
		}
		else{
			commandParserState = IDLE;
		}
		break;
	}
	case RECEIVE_K:{
		if(bufferCheck == '#'){
			commandParserState = STOP_SEND_DATA_SIGNAL;
		}
		else{
			commandParserState = IDLE;
		}
		break;
	}
	case START_SEND_DATA_SIGNAL:{
		start_send_data = 1;
		stop_send_data = 0;
		break;
	}
	case STOP_SEND_DATA_SIGNAL:{
		start_send_data = 0;
		stop_send_data = 1;
		break;
	}
	}

}

void uart_communication_fsm(void){
	switch(uartCommunicationState){
	case ERROR:{
		break;
	}
	case IDLE_HANDLER:{
		break;
	}
	}
}
