# _*_ Makefile _*_

out: main.o functions.o
	gcc main.o functions.o -o out
main.o: main.c funcheader.h
	gcc -c main.c
functions.o: functions.c funcheader.h
	gcc -c -c functions.c
clean:
	rm -f *.o out