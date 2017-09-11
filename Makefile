CFLAGS=-Wall
all: subconjuntos.o
	gcc -o subconjuntos subconjuntos.o $(CFLAGS)

clean:
	rm *.o subconjuntos

