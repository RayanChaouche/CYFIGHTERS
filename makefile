SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: exec

%.o : %.c h.h
	gcc -c $< -o $@

exec: $(OBJ)
	gcc $^ -o $@

clean :
	rm -f *.o
	rm exec
