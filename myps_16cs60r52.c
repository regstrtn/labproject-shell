#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

/**********************************************
 * Filename: myps.c
 * Created by: Mohammad Luqman
 * Implements the ps function
 * Usage:  
 * 	no flags	: Show current user's processes
 * 	-A 				: Show all processes
	********************************************/


int isnum(char* filename) {
	if(isdigit(filename[0])) return 1;
	else return 0;
}

int main(int argc, char* argv[]) {
	int flagset = 0;
	if(argv[1]==NULL) flagset = 0;
	else if(strcmp(argv[1],"-a")==0) flagset = 1;
	struct dirent *de, de2;
	struct stat st;
	struct passwd *pw;
	struct group *gr;
	char dirtolist[200];	
	strcpy(dirtolist, "/proc");
	DIR *dr = opendir(dirtolist);
	DIR *dr2;
	FILE *fp, *fp2;
	char filetoread[300];
	char *buffer = NULL;
	int bufsize = 0;
	int uidfound = 0;
	char * cuid;
	int numuid;
	char cmdfile[300];
	char *cmdbuffer;
	int curuseruid = getuid();
	printf("PID TTY TIME CMD\n");
	while((de = readdir(dr))!=NULL) {
		strcpy(filetoread, "/proc/");
		strcat(filetoread, de->d_name);
		strcpy(cmdfile, filetoread);
		strcat(filetoread, "/status");
		strcat(cmdfile, "/comm");
		
		if(isnum(de->d_name)) {
			uidfound = 0;
			if((fp = fopen(filetoread, "r")) == NULL) printf("File not found");
			if((fp2 = fopen(cmdfile, "r"))==NULL) printf("File not found");
			else {
				getline(&cmdbuffer, &bufsize, fp2);
			}
			//printf("Is digit: %d %d\n", atoi(de->d_name), isnum(de->d_name));
			stat(de->d_name, &st);
			//printf("%c\n", fgetc(fp));
			while(getline(&buffer, &bufsize, fp)>0) {
				if(strncmp(buffer, "Uid", 3)==0) { 
					//printf("%s\n", buffer);
					cuid = strtok(buffer, "\t"); cuid = strtok(NULL, "\t");
					if(atoi(cuid)==curuseruid || flagset) {
					//printf("userid: %d", atoi(cuid));
					printf("%s %s", de->d_name, cmdbuffer);
					}
				} 
			}
		}
	}
}
