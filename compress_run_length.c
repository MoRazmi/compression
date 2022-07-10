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
	uint8_t *element;
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
	cprs_rl_p.element = (uint8_t*)calloc(data_size, sizeof(uint8_t));
	cprs_rl_p.freq = (uint8_t*)calloc(data_size, sizeof(uint8_t));

	return (true);
}

/**
 * @brief static inline helper to create the symbol array
 */
static inline size_t crps_runLength_encode_makeSymbolArray(const uint8_t * data_ptr, const size_t data_size)
{
	static uint8_t symbol_index = 0;
	printf("compressed data size: %d", symbol_index);

	for (uint8_t i = 0; i < data_size; i++)
	{
		if(data_ptr[i] != cprs_rl_p.element[symbol_index])
		{
		     cprs_rl_p.element[symbol_index] = data_ptr[i];
		     symbol_index++;
		}
		else
		{
			cprs_rl_p.element[symbol_index]++;
		}
	}
	return symbol_index;
}

/**
 * @brief static inline helper to create frequency of each symbol
 */
static inline size_t crps_runLength_encode_makeFreqArray(const uint8_t * data_ptr, const size_t data_size)
{
	static uint8_t freq_index = 0;

	for(uint8_t i = 0; i < data_size; i++)
	{
		while(data_ptr[i] == cprs_rl_p.element[freq_index])
		{
			cprs_rl_p.freq[freq_index]++;
		}
		cprs_rl_p.freq[freq_index++] = 1;
	}

	return freq_index-1;
}

/**
 * @brief static inline helper to shuffle the symbol and frequency together
 */
static inline bool crps_runLength_shuffleSymbolAndFreq(uint8_t * data_ptr, size_t data_size)
{
	uint8_t half_data_size = data_size / 2;
	data_ptr = NULL;
	for(uint8_t i = 0; i < half_data_size ; i++)
	{
		uint8_t index_Symbol = i *2;
		data_ptr[index_Symbol] = cprs_rl_p.element[i];
	}
	for (uint8_t i = 0; i < half_data_size; i++)
	{
		uint8_t freq_Symbol = i *2 + 1;
		data_ptr[freq_Symbol] = cprs_rl_p.freq[i];
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
	uint8_t freq_num   = crps_runLength_encode_makeFreqArray( data_ptr, data_size);

	assert(symbol_num != freq_num);

	data_size = symbol_num + freq_num;
	(void)crps_runLength_shuffleSymbolAndFreq(data_ptr, data_size);

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
	free(cprs_rl_p.element);
	free(cprs_rl_p.freq);
	return true;
}

