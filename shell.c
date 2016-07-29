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
#define CMDLEN 250

void parseinputstring(char* str) {
	//printf("Input string was called");
	char* pch;
	pch = strtok(str, " ");
	while(pch!=NULL) {
		printf("%s\n", pch);
		pch = strtok(NULL, " ");
	}
}

void myshell() {
	char *inputstring;
	inputstring = (char *) malloc (CMDLEN*sizeof(char));
	while(1) {
	printf("%c",PROMPT);
	size_t maxsize = 250;
	getline(&inputstring, &maxsize, stdin);
	parseinputstring(inputstring);
	}
}

int main() {
  char* cmd[3] = {"./mypwd", "myname", "hello"};
	char *argv[5];
	argv[1] = (char*)malloc(100);
	strcpy(argv[1], "Mypwd");
	//myshell();
	execvp(cmd[0], cmd);
	}
