CFLAGS=-Wall
all: subconjuntos.o prox_subconjunto.o subconjuntos2.o
	g++ -o subconjuntos subconjuntos.o $(CFLAGS)
	g++ -o subconjuntos2 subconjuntos2.o $(CFLAGS)
	g++ -o prox-subconj prox_subconjunto.o $(CFLAGS)

clean:
	rm *.o subconjuntos prox-subconj subconjuntos2
