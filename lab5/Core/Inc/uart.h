/*
 * uart.h
 *
 *  Created on: Sep 30, 2024
 *      Author: ASUS
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"
#include <stdio.h>

extern unsigned char msg[100]; // use for transmit string type
extern unsigned char buffer[];
extern unsigned char buffer_flag;
extern unsigned char index_buffer;

void UART_SendString(UART_HandleTypeDef* huart, unsigned char* str);
void UART_SendByte(UART_HandleTypeDef* huart, unsigned char data);
void UART_StartReceive(UART_HandleTypeDef* huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart);

#endif /* INC_UART_H_ */
