#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularByteBuffer.h"

CircularByteBuffer *
CBB_init(uint16_t max_buffer_size){
    CircularByteBuffer *cbb;

    if ((cbb = (CircularByteBuffer *) malloc(sizeof(CircularByteBuffer))) == NULL){
	perror("malloc");
	exit(-1);
    }

    if ((cbb->main_data = (char *) malloc(sizeof(char) * max_buffer_size)) == NULL){
	perror("malloc");
	exit(-1);
    }

    memset(cbb->main_data, '\0', max_buffer_size);
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

size_t
CBB_write(CircularByteBuffer *cbb, char *write_data, size_t write_data_length){
    int i, write_len, write_start_index;

    write_len = write_data_length <= CBB_get_left_size(cbb) ?
	write_data_length : CBB_get_left_size(cbb);

    write_start_index = cbb->rear;

    for (i = 0; i < write_len; i++){
	cbb->main_data[cbb->rear  % cbb->max_buffer_size] = write_data[i];
	printf("inserting '%c' to index '%d'\n",
	       write_data[i], cbb->rear % cbb->max_buffer_size);
	cbb->rear++;
	cbb->used_buffer_size++;
    }

    return write_len;
}

size_t
CBB_read(CircularByteBuffer *cbb, char *read_buf, size_t read_data_len,
	 bool clean_data_source){
    return 0;
}

void
CBB_dump_snapshot(CircularByteBuffer *cbb){
    if (!cbb)
	return;

    printf("\n<Circular Byte Buffer Snapshot>\n"
	   "Max buffer size : %d, Used buffer size : %d\n"
	   "Front index : %d, Rear index : %d\n"
	   "--------------------------------------\n"
	   "%s\n"
	   "--------------------------------------\n",
	   cbb->max_buffer_size, cbb->used_buffer_size,
	   cbb->front, cbb->rear, cbb->main_data);
}

void
CBB_destroy(CircularByteBuffer *cbb){
    free(cbb->main_data);
    free(cbb);
}
