#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#define _XOPEN_SOURCE 500 //required by nftw function
#include <ftw.h>
#include <getopt.h>

int main() {
	char *args[] = {"./hello/vim", "."};
	int rv = rename(args[0], args[1]);
	if(rv) {
	printf("Error: %d\n", errno);
	}
}
