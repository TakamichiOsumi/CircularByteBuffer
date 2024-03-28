#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "CircularByteBuffer.h"

CircularByteBuffer *
CBB_init(uint16_t max_buffer_size){
    CircularByteBuffer *cbb;

    if ((cbb = (CircularByteBuffer *) malloc(sizeof(CircularByteBuffer))) == NULL){
	perror("malloc");
	exit(-1);
    }

    if ((cbb->main_data = (unsigned char *) malloc(sizeof(char) * max_buffer_size)) == NULL){
	perror("malloc");
	exit(-1);
    }

    cbb->max_buffer_size = max_buffer_size;
    cbb->front = cbb->rear = cbb->used_buffer_size = 0;

    return cbb;
}

bool
CBB_is_empty(CircularByteBuffer *cbb){
    return cbb->used_buffer_size == 0;
}

bool
CBB_is_full(CircularByteBuffer *cbb){
    return cbb->used_buffer_size == cbb->max_buffer_size;
}

uint16_t
CBB_get_left_size(CircularByteBuffer *cbb){
    return cbb->max_buffer_size - cbb->used_buffer_size;
}

uint16_t
CBB_write(CircularByteBuffer *cbb, unsigned char *write_data, uint16_t write_data_length){
    return 0;
}

uint16_t
CBB_read(CircularByteBuffer *cbb, unsigned char *read_buf, uint16_t read_data_len,
	 bool clean_data_source){
    return 0;
}

void
CBB_dump_status(CircularByteBuffer *cbb){
}

void
CBB_destroy(CircularByteBuffer *cbb){
    free(cbb->main_data);
    free(cbb);
}
