#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularByteBuffer.h"

#define APP_REQUIRED_CBB_SIZE 32

int
main(int argc, char **argv){
    CircularByteBuffer *cbb;
    char s1[] = "foo", s2[] = "bazz",
	s3[] = "1234567890";

    cbb = CBB_init(APP_REQUIRED_CBB_SIZE);

    printf("Circular Byte Buffer has been initialized.\n");

    /* + 3 */
    printf("Write %zu bytes\n", CBB_write(cbb, s1, strlen(s1)));
    CBB_dump_snapshot(cbb);

    /* + 4 */
    printf("Write %zu bytes\n", CBB_write(cbb, s2, strlen(s2)));
    CBB_dump_snapshot(cbb);

    /* + 10 */
    printf("Write %zu bytes\n", CBB_write(cbb, s3, strlen(s3)));
    CBB_dump_snapshot(cbb);

    /* + 10 */
    printf("Write %zu bytes\n", CBB_write(cbb, s3, strlen(s3)));
    CBB_dump_snapshot(cbb);

    /* + 10, but will be reduced to 5 */
    printf("Write %zu bytes\n", CBB_write(cbb, s3, strlen(s3)));
    CBB_dump_snapshot(cbb);

    /* + 10, but will be reduced to 0 */
    printf("Write %zu bytes\n", CBB_write(cbb, s3, strlen(s3)));
    CBB_dump_snapshot(cbb);

    return 0;
}
