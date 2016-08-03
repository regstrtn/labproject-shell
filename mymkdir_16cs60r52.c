#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<signal.h>
#include <sys/stat.h>

/**********************************************
 * Filename: mymkdir.c
 * Created by: Mohammad Luqman
 * Implements the mkdir functionality
	********************************************/



int main(int argc, char* argv[]) {
				int i = 0;
				for(i=1;i<=argc;i++) {
					mkdir(argv[i], 0777);
					if(errno == EEXIST) perror("mymkdir error: ");
				}
				return 1;
}
