/*
 * main.c
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */
#include <stdio.h>
#include <stddef.h>
#include "compress_run_length.h"

int main()
{
	uint8_t data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
	                0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
	                0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };

	size_t data_size = 24;

	for (int i = 0; i < data_size; i++)
	{
		printf("index %d is 0x%02X \n", i, data_ptr[i]);
	}
	printf("Let's start the interview\n");
	return 0;
}
