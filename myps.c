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

int main(int argc, char* argv[]) {
	struct dirent *de, de2;
	struct stat st;
	struct passwd *pw;
	struct group *gr;
	char dirtolist[200];	
	strcpy(dirtolist, "/proc");
	DIR *dr = opendir(dirtolist);
	DIR *dr2;
	FILE *fp;
	char filetoread[300];
	char *buffer = NULL;
	int bufsize = 0;
	while((de = readdir(dr))!=NULL) {
		strcpy(filetoread, de->d_name);
		strcat(filetoread, "/status");
		fp = fopen("/proc/30956/status", "r");
		stat(de->d_name, &st);
		printf("%s\n", filetoread);
		printf("Is digit: %d %d\n", atoi(de->d_name), isnumber(atoi(de->d_name)));
		printf("%c\n", fgetc(fp));
		//getline(&buffer, &bufsize, fp);
		//	printf("%s", buffer);
}
}
