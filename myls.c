#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#define PROMPT '>'
#define MAXPATHNAME 250

int main(int argc, char* argv[]) {
	struct dirent *de;
	struct stat st;
	struct passwd *pw;
	struct group *gr;
	time_t modtime;
	int maxwidth = 8;
	char s[200];
	size_t maxtime = 200;
	char format[200];
	struct tm* timeinfo;
	char time_format[] = "%a %b %d %Y";
	char dirtolist[200];
	strcpy(dirtolist, ".");
	if(argv[1] != NULL) strcpy(dirtolist, argv[1]); 
	DIR *dr = opendir(dirtolist);
	if(dr==NULL) {
		printf("Could not open directory\n");
		return 0;
	}
	while((de = readdir(dr))!=NULL) {
		if(strncmp(de->d_name, ".", 1)==0) continue;
		stat(de->d_name, &st);
		printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
    printf( (st.st_mode & S_IRUSR) ? "r" : "-");
    printf( (st.st_mode & S_IWUSR) ? "w" : "-");
    printf( (st.st_mode & S_IXUSR) ? "x" : "-");
    printf( (st.st_mode & S_IRGRP) ? "r" : "-");
    printf( (st.st_mode & S_IWGRP) ? "w" : "-");
    printf( (st.st_mode & S_IXGRP) ? "x" : "-");
    printf( (st.st_mode & S_IROTH) ? "r" : "-");
    printf( (st.st_mode & S_IWOTH) ? "w" : "-");
    printf( (st.st_mode & S_IXOTH) ? "x" : "-");
		pw = getpwuid(st.st_uid);
		gr 	= getgrgid(st.st_gid);
		printf(" %d", st.st_nlink);
		printf(" %s %s", pw->pw_name, gr->gr_name);
    //st.st_uid, st.st_gid,
		strcpy(format, "%b %d %H:%M:%S");
		timeinfo = localtime(&st.st_mtime);
		strftime(s, maxtime, format, timeinfo);
		printf(" %*lld %s %s\n", maxwidth, st.st_size, s,de->d_name);	
		}
	closedir(dr);
	return 0;
}
