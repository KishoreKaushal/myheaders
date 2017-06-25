output: main.o assist.o
	gcc -Wall -O2 main.o assist.o -o output

main.o: main.c
	gcc -Wall -O2 -c main.c

assist.o: assist.h assist.c
	gcc -Wall -O2 -c assist.c

clean:
	rm *.o output
