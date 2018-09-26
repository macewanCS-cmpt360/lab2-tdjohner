#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{

	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10];

	cmdline = calloc(1, 1024);
	i = 0;

	printf("prompt> ");
	fgets(cmdline, 1024, stdin);
	
	token = strtok(cmdline, "\n ");
	while (token != NULL) {
		args[i++] = strdup(token);
		token = strtok(NULL, "\n");
	}
	args[i] = NULL;
	rc = fork();
	
	if (rc < 0) {
		printf("fork failed: %d\n", rc);
		return 1;
	} else if (rc == 0) {
		execvp(args[0], args);		
	}
	free(cmdline);
	return 0;
}
