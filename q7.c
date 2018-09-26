/*
 * Teagan Johner
 * q7.c
 *
 * q7 written response:
 * When I close the STDOUT_FILENO and then try to print,
 * I get nothing back in the prompt when the program is
 * run. I don't know where that output ends up. But when
 * I open a file to try write the printf() return code,
 * I get the return code 12 and then the "some output"
 * ends up in that file afterward! I know that the file
 * is being assigned the file descriptor '1' that was
 * 'freed up' when STDOUT_FILENO was closed. Then I
 * can only guess that the "some output" was queued up
 * for output and then descheduled until the file
 * descriptor became available. When the file descriptor
 * was assigned to q7.output, the scheduler used the
 * opportunity to schedule the "some output" and it was
 * written to the file. (?)
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
	else if (rc == 0) {
		close(STDOUT_FILENO);
		int x = printf("some output\n");
		int file = open("./q7.output", O_CREAT|O_APPEND|O_WRONLY, S_IRWXU);

		dprintf(file, "%d\n", x);
	}
}
