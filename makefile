all: myls mymv mymkdir mypwd mytail myrm
myls:
	gcc -o myls myls.c
mymv:
	gcc -o mymv mymv.c
mypwd:
	gcc -o mypwd mypwd.c
myrm:
	gcc -o myrm myrm.c
mymkdir:
	gcc -o mymkdir mymkdir.c
mytail:
	gcc -o mytail mytail.c
