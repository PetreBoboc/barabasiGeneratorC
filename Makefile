co:
	rm -rf graph
	gcc -o graph barabasi.c main.c -fopenmp
clean:
	rm -rf network.net *.rep x.txt y.txt