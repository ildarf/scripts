#define _POSIX_SOURCE

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char **argv) {
	
	if (argc < 2) {
		printf ("Usage: %s <Command ...>\n", argv[0]);
		return 1;
	}
	
	// 
	int numArgs = argc - 1;
	char *args[numArgs + 1];
	char *cmd = argv[1];
	
	// 
// 	printf ("Command: %s\n", cmd);
	for (int i = 1; i < argc; i++) {
// 		printf ("Arg #%i => %s\n", i - 1, argv[i]);
		args[i - 1] = argv[i];
	}
	
	// 
	args[numArgs] = 0x0;
	
	// 
	if (fork () == 0) {
		
		close (fileno(stdout));
		close (fileno(stderr));
		close (fileno(stdin));
		
		open ("/dev/null", O_WRONLY | O_NONBLOCK);
		open ("/dev/null", O_RDONLY | O_NONBLOCK);
		open ("/dev/null", O_RDONLY | O_NONBLOCK);
		
		execvp (cmd, args);
		
		perror ("Failed to execute");
		return errno;
		
	}
	
	// 
	return 0;
	
}