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
	b = a;
	for(i=1;i<n;i++) {
		b->next = (cbuffer*)malloc(sizeof(cbuffer));
	 	b->next->i = i;
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
	do {
		printf("%s", b->str);
		b = b->next;
	} while(a!=b->next);
}

int main(int argc, char* argv[]) {
//	printf("%s %s\n", argv[1], argv[2]);
	//if(argv[1]==NULL) return 1;
	char nline[10];
	strcpy(nline, argv[1]+1);
	int n = atoi(nline);
	FILE *fp;
	fp = fopen("2015.txt", "r");
	cbuffer *a, *b;
	printf("%s %d\n", nline, n*3);
	printlines(fp, 10);
}
