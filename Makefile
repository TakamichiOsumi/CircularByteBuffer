CC	= gcc
CFLAGS	= -O0 -Wall
TEST	= exec_cbb_test
OUTPUT_LIB = libcbb.a

all: $(TEST) $(OUTPUT_LIB)

.phony: test clean

CircularByteBuffer.o: CircularByteBuffer.c
	$(CC) $(CFLAGS) $^ -c

$(TEST): CircularByteBuffer.o
	$(CC) $(CFLAGS) test_cbb.c $^ -o $@

$(OUTPUT_LIB): CircularByteBuffer.o
	ar rs $@ $<

test: $(TEST)
	@./$(TEST) 2>&1 > /dev/null && echo "Success if zero >>> $$?"

clean:
	@rm -rf *.o $(TEST) $(OUTPUT_LIB)
