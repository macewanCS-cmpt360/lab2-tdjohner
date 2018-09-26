all:	q1.c q2.c q3.c q7.c
	gcc -o q1 q1.c
	gcc -o q2 q2.c
	gcc -o q3 q3.c
	gcc -o q7 q7.c
clean:
	rm q1 q2 q3 q7 q2.output q7.output
