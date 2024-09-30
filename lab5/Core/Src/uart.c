/*
 * uart.c
 *
 *  Created on: Sep 30, 2024
 *      Author: ASUS
 */

#include "uart.h"

#define BUFFER_SIZE 30
unsigned char msg[100]; // use for transmit string type
unsigned char buffer[BUFFER_SIZE];
unsigned char buffer_receive = 0;
unsigned char index_buffer = 0;


void UART_SendString(UART_HandleTypeDef *huart, unsigned char* str){
	HAL_UART_Transmit(&huart2, (void*)msg, sprintf((void*)msg,"%s",str), 10);
}


void UART_SendByte(unsigned char data){
	HAL_UART_Transmit(&huart2, data, 1, 100);
}


void UART_StartReceive(UART_HandleTypeDef *huart){
	HAL_UART_Receive_IT(huart, &buffer_receive, 1);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART2){
		buffer[index_buffer++] = buffer_receive;
		buffer_flag = 1;
		if(index_buffer == 30) index_buffer = 0;
		// communication loop
		HAL_UART_Receive_IT(huart, &buffer_receive, 1);
	}
}


