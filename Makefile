CC 		= gcc
FLAGS   = -std=c99 -D_SVID_SOURCE

all: graph02.c intVec.c loadGraph.c
	$(CC) $(FLAGS) -g -o graph02 graph02.c intVec.c loadGraph.c

.o: graph02.c intVec.c loadGraph.c
	$(CC) $(FLAGS) -g -O -c graph02.c intVec.c loadGraph.c


clean:
	rm -f graph02 graph02.o intVec.o loadGraph.o out_file.txt
