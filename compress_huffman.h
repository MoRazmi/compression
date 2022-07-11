/*
 * compress_huffman.h
 *
 * Huffamn Algorithm Lossless Data compression
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */

#ifndef COMPRESS_HUFFMAN_H_
#define COMPRESS_HUFFMAN_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool   cprs_huffman_init( uint8_t * data_ptr,size_t data_size);
size_t cprs_huffman_encode(uint8_t * data_ptr, size_t data_size);
size_t cprs_huffman_decode(uint8_t * data_ptr, size_t data_size);
bool   cprs_huffman_deinit();


#endif /* COMPRESS_HUFFMAN_H_ */
