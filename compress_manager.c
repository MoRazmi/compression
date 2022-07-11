/*
 * compress_manager.c
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "compress_manager.h"
#include "compress_run_length.h"

/**
 * compress manager private variable to control the algorithm type
 */
enum cprs_method cprs_method_state;

/**
 * @brief function to set the compression algorithm type
 * @param [in] compression algorithm enum type
 * @retval true if successful false if unsuccessful
 */
bool cprs_setAlgType (enum cprs_method method)
{
	if(method >= CPRS_MAX_VALUE )
	{
		return false;
	}
	cprs_method_state = method;
	switch (cprs_method_state)
	{
	case cprs_run_length:
	{
		bool (*cprs_init)(size_t) = &cprs_runLength_init;
		size_t (*cprs_encode)(uint8_t *, size_t) = &cprs_runLength_encode;
		size_t (*cprs_decode)(uint8_t *, size_t) = &cprs_runLength_decode;
		bool   (*cprs_deinit)() = &cprs_runLength_deinit;
	}
	break;
	case cprs_huffman:
	{

	}
	break;
	case CPRS_MAX_VALUE:
	{
	}
	break;
	default:
	{}
	break;
    }

	return (true);
}

/**
 * @brief return the type of algorithm selcted
 * @retval type of algorithm selected enum number
 */
enum cprs_method cprs_getAlgType()
{
	return (cprs_method_state);
}
