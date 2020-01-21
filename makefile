all: main.o functions.o
	gcc -o program main.o functions.o

main.o: main.c header.h
	gcc -c -g main.c

functions.o: functions.c header.h
	gcc -c -g functions.c

run:
	./program

clean:
	rm *.o
	rm program
