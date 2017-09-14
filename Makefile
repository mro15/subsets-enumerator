CFLAGS=-Wall
all: subconjuntos.o prox_subconjunto.o
	gcc -o subconjuntos subconjuntos.o $(CFLAGS)
	gcc -o prox-subconj prox_subconjunto.o $(CFLAGS)

clean:
	rm *.o subconjuntos prox-subconj

