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

/**********************************************
 * Filename: mymv.c
 * Created by: Mohammad Luqman
 * Implements the move/rename functionality
	********************************************/


int main(int argc, char * argv[]) {
	if(argv[1]==NULL)  {
		printf("mymv: No file specified\n");
		return 1;
		}
	int rv = rename(argv[1], argv[2]);
	if(rv) {
	printf("mymv: %d\n", errno);
	}
}
