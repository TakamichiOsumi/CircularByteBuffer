CC	= gcc
CFLAGS	= -O0 -Wall
TEST	= exec_cbb_test

all: $(TEST)

.phony: test clean

CircularByteBuffer.o: CircularByteBuffer.c
	$(CC) $(CFLAGS) $^ -c

$(TEST): CircularByteBuffer.o
	$(CC) $(CFLAGS) test_cbb.c $^ -o $@

test:
	@./$(TEST) 2>&1 > /dev/null && echo "Success if zero >>> $$?"

clean:
	@rm -rf *.o $(TEST)
