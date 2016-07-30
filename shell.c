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
#define CMDLEN 1250
#define MAXNUMTOKENS 100

int cmd_execute(char** args) {
	pid_t pid;
	int status;
	if((pid = fork())==0) {
	//printf("%s\n", args[0]);
		if(execvp(args[0], args)==-1) {
			perror("Error");
		}
	exit(0);
	}
	else wait(&status);
	return 1;
}

char** split_into_tokens(char* str) {
	/*This function takes a string as input and outputs tokens as command or parameter*/
	char* pch;
	char* delim = " \t\n\r";
	int pos = 0;
	char** tokens = malloc(MAXNUMTOKENS*sizeof(char*));
	pch = strtok(str, delim);
	while(pch!=NULL) {
		tokens[pos] = pch;
		//printf("%s\n", pch);
		pch = strtok(NULL, delim);
		pos++;
	}
	tokens[pos] = NULL;
	return tokens;
}

char* read_user_input() {
				char *inputline = NULL;
				size_t buffersize = 0;
				getline(&inputline, &buffersize, stdin);
				return inputline;
}

int main() {
	char *cmdinput;
	char **args;
	int retval; 
	char *debugarg[3] = {"./mypwd", "mypwd", NULL};
	while(1) {
			printf("%c", PROMPT);
			cmdinput = read_user_input();
			args 		 = split_into_tokens(cmdinput);
			//printf("%s\n", args[0]);
			retval 	 = cmd_execute(args);
		}
}
