/*
 * compress_huffman.c
 *
 * Run Length Algorithm Lossless Data compression
 * Resource: www.programiz.com/dsa/huffman-coding
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */

#include "compress_huffman.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TREE_HT 50

/**
 * huffman structure
 */
struct MinHNode{
	uint8_t symbol;
	uint8_t freq;
	struct MinHNode *left, *right;
};

/**
 * huffman structure
 */
struct MinHeap {
	uint8_t size;
	uint8_t capacity;
	struct MinHNode **array;
};

/**
 * private variable structure
 */
typedef struct _cprs_huffman_privateVariable
{
	struct MinHHeap * minHeap;
}cprs_huffman_privateVariable;

/**
 * Huffman algorithm private variable
 */
cprs_huffman_privateVariable cprs_huffman_p;



bool   cprs_huffman_init( uint8_t * data_ptr,size_t data_size)
{
	return true;
}

size_t cprs_huffman_encode(uint8_t * data_ptr, size_t data_size)
{
	return data_size;
}

size_t cprs_huffman_decode(uint8_t * data_ptr, size_t data_size)
{
	return data_size;
}

bool   cprs_huffman_deinit()
{
	return true;
}

