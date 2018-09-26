/*
 * Teagan Johner
 * q1.c
 *
 * q1 written response:
 * If the variable is not explicitly changed in the
 * child process, it retains its originally assigned
 * value (in this case, 6).
 * If the child process changed the value stored at
 * the variable, that value is printed before the
 * process returns.
 * If both processes change the value stored at var,
 * the address space is virtualized so both processes
 * are writing to their own memory space. The variable
 * retains the value assigned by each respective
 * process. That respective value is printed before
 * each process returns.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int var = 6;
	int rc = fork();

	if (rc < 0)
		fprintf(stderr, "call to fork failed: %d\n", rc);
	else if (rc == 0)
		var = 4;
	else
		var = 2;

	printf("%d\n", var);
	return 0;
}



