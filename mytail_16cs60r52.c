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
#define MAXLINESIZE 2000

/**********************************************
 * Filename: mytail.c
 * Created by: Mohammad Luqman
 * Implements the tail function 
 * Specify number of lines to print. Default is 10 lines.
	********************************************/


typedef struct node {
				char str[MAXLINESIZE];
				int i;
				struct node* next;
				struct node* prev;
} cbuffer;

int printlines(FILE *fp, int n) {
	int wordsread = 0;
	int i = 0, j = 0;
	char *buffer=NULL;
	size_t bufsize=0;
	cbuffer clist[n];
	cbuffer *a, *b;
	a = (cbuffer*)malloc(sizeof(cbuffer));
	a->i = 0;
	a->str[0] = 0;
	b = a;
	for(i=1;i<n;i++) {
		b->next = (cbuffer*)malloc(sizeof(cbuffer));
	 	b->next->i = i;
		b->next->str[0]=0;
		b->next->prev = b;
 		b = b->next;
	}
	b->next = a;
	b->next->prev = b;
	/*b = a->next;
	while(a!=b) {
		printf("%d\n", b->i);
		b = b->next;
	}*/
	b = a;
	while((wordsread = getline(&buffer, &bufsize, fp))>0) {
							strcpy(b->str, buffer);
							a = b;
							b = b->next;
							if(buffer!=NULL) {
							buffer = NULL;
							bufsize = 0;
			}
		}
	b = a;
	do {
		b = b->next;
		if(b->str[0]!=0) printf("%s",b->str);
	} while(a!=b);
return 1;
} 

int main(int argc, char* argv[]) {
//	printf("%s %s\n", argv[1], argv[2]);
	int n;
	char *flagidentifier = "-";
	int argnum = 1;
	if(argv[1]==NULL) return 1;
	char nline[20];
	if(strncmp(argv[1], flagidentifier, 1)==0){
	strcpy(nline, argv[1]+1);
	n = atoi(nline);
	argnum = 2;
	}
	else {
					n = 10;
	}
	FILE *fp;
	if((fp = fopen(argv[argnum], "r"))==NULL) {
					perror("mytail");
					return 1;
	}
	cbuffer *a, *b;
	printlines(fp, n);
}
