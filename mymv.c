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

int main(int argc, char* argv[]) {
	//char *args[] = {"./hello/vim/sm.txt", "."};
	int rv = rename(args[1], args[2]);
	if(rv) {
	printf("Error: %d\n", errno);
	}
}
