CC=gcc
CFLAGS=-I.
DEPS = refugee.h
OBJ = refugee.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	-rm *.o $(objects) main