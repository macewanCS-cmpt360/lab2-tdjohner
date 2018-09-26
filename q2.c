/*
 * Teagan Johner
 * q2.c
 *
 * q2 written response:
 * Both the parent and the child process can write to the file
 * descriptor returned by open. When both processes write to 
 * the file 'at the same time' the parent writes to the file
 * first, probably because the scheduler has the parent do IO
 * while the child process is created. The child writes after.
 * The outputs involved are finished before the scheduler 
 * would probably want to interupt them, but I assume that if
 * the scheduler was trying to juggle two very large outputs
 * and those outputs happened to be to the same file, the
 * result would be the file containing both of the completed
 * ouputs but they would be interwoven inconveniently.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	
	int file = open("./q2.output", O_CREAT|O_APPEND|O_WRONLY, S_IRWXU);
	
	int rc = fork();

	if (rc < 0)
		fprintf(stderr, "call to fork failed: %d\n", rc);
	else if (rc == 0)
		dprintf(file, "I am the child process, %d\n", (int) getpid());
	else
		dprintf(file, "I am the parent process, %d\n", (int) getpid());

	dprintf(file, "Both processes can will write this: %d\n", (int) getpid());
	
	close(file);
	return 0;
}



