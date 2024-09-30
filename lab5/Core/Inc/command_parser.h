/*
 * command_parser.h
 *
 *  Created on: Sep 30, 2024
 *      Author: ASUS
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "main.h"
#include "uart.h"


void command_parser_fsm(void);
void uart_communication_fsm(void);


#endif /* INC_COMMAND_PARSER_H_ */
