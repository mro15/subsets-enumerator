all: subconjuntos.o prox_subconjunto.o
	g++ -o subconjuntos subconjuntos.o
	g++ -o prox-subconj prox_subconjunto.o

clean:
	rm *.o subconjuntos prox-subconj
