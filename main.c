/*
 * main.c
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

#include "compress_manager.h"
#include "compress_run_length.h"

int main()
{
	uint8_t data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
	                0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
	                0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };

	size_t data_size = 24;

	enum  cprs_method cprs_method_s;
	cprs_method_s = cprs_run_length;
	cprs_setAlgType(cprs_method_s);


	/****************************************************
	 * Check the compress algorithm encode
	 ****************************************************/

	bool ini_state = cprs_runLength_init(data_size);
	assert(ini_state);

	size_t new_encode_size;
	new_encode_size = cprs_runLength_encode(data_ptr, data_size);
	data_size = new_encode_size;

	for(int i =0; i < data_size; i++)
	{
	    printf(" data after compression encode 0x%02X \n", data_ptr[i] );
	}

	bool deini_state = cprs_runLength_deinit();
	assert(deini_state);


	/****************************************************
	 * Check the compress algorithm decode
	 ****************************************************/

	bool reini_state = cprs_runLength_init(data_size);
    assert(reini_state);

    size_t new_decoded_size;

    new_decoded_size = cprs_runLength_decode(data_ptr, data_size);
	data_size = new_decoded_size;
    printf(" data size %ld \n", data_size );

    for(int i =0; i < data_size; i++)
	{
	    printf(" data after compression deccode 0x%02X \n", data_ptr[i] );
	}


	bool redeini_state = cprs_runLength_deinit();
	assert(redeini_state);

	return 0;
}
