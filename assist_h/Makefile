output.out: main.o  assist.o linkedList.o stack.o queue.o
	gcc -Wall -O2 main.o linkedList.o stack.o queue.o assist.o -o output.out

main.o: main.c assist.h dataStructures.h linkedList.c stack.c queue.c
	gcc -Wall -O2 -c main.c

assist.o: assist.h assist.c
	gcc -Wall -O2 -c assist.c

linkedList.o: dataStructures.h linkedList.c
	gcc -Wall -O2 -c linkedList.c

stack.o: dataStructures.h stack.c
	gcc -Wall -O2 -c stack.c

queue.o: dataStructures.h queue.c
	gcc -Wall -O2 -c queue.c

clean:
	rm *.o output.out
