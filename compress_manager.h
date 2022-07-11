/*
 * compress_manager.h
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */

#ifndef COMPRESS_MANAGER_H_
#define COMPRESS_MANAGER_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * Enumeration for type of compress algorithm
 */
enum cprs_method
{
	cprs_run_length = 0,
	cprs_huffman = 1,
	CPRS_MAX_VALUE
};


bool cprs_setAlgType (enum cprs_method method);
enum cprs_method cprs_getAlgType();

extern bool    (*cprs_init)( size_t );
extern size_t  (*cprs_encode)(uint8_t *, size_t);
extern size_t  (*cprs__decode)(uint8_t *, size_t);
extern bool    (*cprs_deinit)();

#endif /* COMPRESS_MANAGER_H_ */
