#include <stdio.h>
#include <stdlib.h>
#include "CircularByteBuffer.h"

#define APP_REQUIRED_CBB_SIZE 1024

int
main(int argc, char **argv){
    CircularByteBuffer *cbb;

    cbb = CBB_init(APP_REQUIRED_CBB_SIZE);

    printf("Circular Byte Buffer has been initialized.\n");

    return 0;
}
