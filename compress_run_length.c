/*
 * compress_run_length.c
 *
 * Run Length Algorithm Lossless Data compression
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */

#include "compress_run_length.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 *  private variable structure
 */
typedef struct _cprs_runLength_privateVariable
{
	uint8_t *symbol;
	uint8_t *freq;
}cprs_runLength_privateVariable;

/**
 * Run-Length algorithm private variable
 */
cprs_runLength_privateVariable cprs_rl_p;

/**
 * @brief Run-Length algorithm initialization
 * @retval true if successful
 * @retval false otherwise
 */
bool cprs_runLength_init( size_t data_size)
{
	cprs_rl_p.symbol = (uint8_t*)calloc(data_size, sizeof(uint8_t));
	cprs_rl_p.freq = (uint8_t*)calloc(data_size, sizeof(uint8_t));

	return (true);
}

/**
 * @brief static inline helper to create the symbol array and calculate the frequency
 */
static inline size_t crps_runLength_encode_makeSymbolArray(const uint8_t * data_ptr, const size_t data_size)
{
	 uint8_t symbol_index = 0;
	 uint8_t pre_symbol_index = 0;

	for (uint8_t i = 0; i < data_size; i++)
	{
		if(i == 0)
		{
			cprs_rl_p.symbol[symbol_index] = data_ptr[i];
			symbol_index++;
		}
		else if( cprs_rl_p.symbol[pre_symbol_index] != data_ptr[i] )
		{
		    cprs_rl_p.symbol[symbol_index] = data_ptr[i];
		    pre_symbol_index = symbol_index;
		    symbol_index++;
		}

		cprs_rl_p.freq[pre_symbol_index]++;
	}
/*
	for(int i =0; i < symbol_index; i++)
	{
	    printf("current symbol frequeny 0x%02X and 0x%02X \n", cprs_rl_p.freq[i],cprs_rl_p.symbol[i] );
	}
*/
	return symbol_index;
}

/**
 * @brief static inline helper to shuffle the symbol and frequency together
 */
 static inline bool crps_runLength_shuffleSymbolAndFreq(uint8_t * data_ptr, size_t data_size)
{
	uint8_t half_data_size = data_size/2;

	for(uint8_t i = 0; i < half_data_size ; i++)
	{
		data_ptr[i*2] = cprs_rl_p.freq[i];
		data_ptr[i*2+1] = cprs_rl_p.symbol[i];
	}
	for(int i =0; i < data_size; i++)
	{
	    printf("current data 0x%02X \n", data_ptr[i] );
	}

	return true;
}

/**
 * @brief Run-Length algorithm encode data
 * @param [out] data_ptr the pointer to data buffer
 * @param [in]  data_size the number of bytes to compress
 */
size_t cprs_runLength_encode(uint8_t * data_ptr, size_t data_size)
{

	uint8_t symbol_num = crps_runLength_encode_makeSymbolArray( data_ptr,  data_size);
	data_size = symbol_num * 2;
	(void)crps_runLength_shuffleSymbolAndFreq( data_ptr, data_size);

	return data_size;
}

/**
 * Run-Length algorithm decode data
 */
bool cprs_runLength_decode(uint8_t * data_ptr)
{
	return false;
}

bool cprs_runLength_deinit()
{
	free(cprs_rl_p.symbol);
	free(cprs_rl_p.freq);
	return true;
}

