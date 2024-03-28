#ifndef __CIRCULAR_BYTE_BUFFER__
#define __CIRCULAR_BYTE_BUFFER__

#include <stdbool.h>

typedef struct CircularByteBuffer {
    char *main_data;
    uint16_t max_buffer_size;
    uint16_t used_buffer_size;
    uint16_t front;
    uint16_t rear;
} CircularByteBuffer;

CircularByteBuffer *CBB_init(uint16_t max_buffer_size);
bool CBB_is_empty(CircularByteBuffer *cbb);
bool CBB_is_full(CircularByteBuffer *cbb);
uint16_t CBB_get_left_size(CircularByteBuffer *cbb);
size_t CBB_write(CircularByteBuffer *cbb,
		 char *write_data, size_t write_data_length);
size_t CBB_read(CircularByteBuffer *cbb,
		 char *read_buf, size_t read_data_len, bool clean_data_source);
void CBB_dump_snapshot(CircularByteBuffer *cbb);
void CBB_destroy(CircularByteBuffer *cbb);

#endif
