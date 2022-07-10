/*
 * compress_run_length.h
 *
 * Run Length Algorithm Lossless Data compression
 *
 *  Created on: Jul. 10, 2022
 *      Author: Mo Razmi
 */

#ifndef COMPRESS_RUN_LENGTH_H_
#define COMPRESS_RUN_LENGTH_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool cprs_runLengthEncoding_init(uint8_t * data_smpl);
size_t cprs_runLength_encode(uint8_t * data_ptr, size_t data_size);
bool cprs_runLength_decode(uint8_t * data_ptr);


#endif /* COMPRESS_RUN_LENGTH_H_ */
