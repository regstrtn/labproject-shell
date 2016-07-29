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
#define PROMPT '>'
#define MAXPATHNAME 250

int main(int argc, char* argv[]) {
	char *pathname = (char *)malloc(sizeof(char)*MAXPATHNAME);
	getwd(pathname);
	printf("%s\n", pathname);
}
