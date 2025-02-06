CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lraylib -lm
SRC = main.c
OBJ = $(SRC:.c=.o)
EXEC = Raysort

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

l:
	make clean
	make
	./$(EXEC)

.PHONY: all clean l
