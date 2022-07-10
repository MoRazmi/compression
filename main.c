/*
 * main.c
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

#include "compress_run_length.h"

int main()
{
	uint8_t data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
	                0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
	                0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };

	size_t data_size = 24;

	bool ini_state = cprs_runLength_init(data_size);
	assert(ini_state);


	printf("Let's start the interview\n");

	bool deini_state = cprs_runLength_deinit();
	assert(deini_state);

	return 0;
}
