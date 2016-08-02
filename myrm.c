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

//Need to handle multiple arguments more carefully

int remove_cb_fn(const char* fpath, const struct stat* sb, int typeflag, struct FTW *ftwbuf) {
	int retval = remove(fpath);
	if(retval) perror(fpath);
	return retval;	
}

int rmrf(char* path) {
	//replicate the functionality of rm -rf command in bash
	int retval;
	retval = nftw(path, remove_cb_fn, 64, 1 | 8);
	/* 	nftw: Traverses filetree. Parameters explained below: 
	char* path: name of the directory
	int(*) remove_cb_fn(char* fpath, struct stat* fb, int typeflag, struct FTW *ftwbuf): callback function on visiting each directory
	int nopenfd : number of simultaneously opened directories
	int flags : Flags to specify behaviour of nftw, depth means post order traversal
							phys means do not follow symbolic links
	*/
	return retval;
}

int delemptydir(char* path) {
    int retval = rmdir(path);
		switch(errno) {
			case ENOENT:
							perror(path);
							break;
			case ENOTEMPTY:
							perror(path);
							break;
			case ENOTDIR:
							perror(path);
			default:
							break;
		}
		return retval;
	}

int deldirrecursively(char* path) { 
	int retval = rmrf(path);
	return retval;
}

int main(int argc, char* argv[]) {
				int i = 0;
				char flags[100];
				if(argv[1]==NULL) {printf("myrm: No file specified\n"); return 1;}
				
				strcpy(flags, argv[1]);
				
				if(strcmp(flags, "-d")==0){
					for(i = 2;i<argc;i++) {
							 	delemptydir(argv[i]);
								}	return 1;
				} else if(strcmp(flags, "-r")==0 || strcmp(flags, "-rf")==0) {
			  	for(i=2;i<argc;i++) {
							 	deldirrecursively(argv[i]);
								} return 1;
				} else {
				for(i=1;i<=argc;i++) {
					unlink(argv[i]);
					switch(errno) {
									case ENOENT: 
													perror(argv[i]);
													break;
									case EBUSY:
													perror(argv[i]);
													break;
									case EISDIR:
													perror(argv[i]);
													break;
									case EPERM:
													perror(argv[i]);
													break;
									default:
													//printf("Error occured: %d\n", errno);
													break;
					}
				}
			}				
			return 1;
}
