CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -fsanitize=address,undefined -g -Iheaders

all:
	$(CC) $(CFLAGS) src/s_vector.c tests/test-sv.c -o bin/test-sv

run: all
	./bin/test-sv

clean:
	rm -f bin/test-sv
