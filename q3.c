/*
 * Teagan Johner
 * q3.c
 *
 * q3 written response:
 * I don't think I can guarantee the parent process writes
 * after the child without using the wait() function. I
 * looked at the man page for fork() and saw that it does
 * not take any arguments. I thought it might take an arg
 * to specify shecduler behavior.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int rc = fork();

	if (rc < 0)
		fprintf(stderr, "call to fork failed: %d\n", rc);
	else if (rc == 0)
		printf("hello\n");
	else {
		wait(NULL);
		printf("goodbye\n");
	}
}
