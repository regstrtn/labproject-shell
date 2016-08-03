all: shell myps myls mymv mymkdir mypwd mytail myrm
myls:
	gcc -o myls myls_16cs60r52.c
mymv:
	gcc -o mymv mymv_16cs60r52.c
mypwd:
	gcc -o mypwd mypwd_16cs60r52.c
myrm:
	gcc -o myrm myrm_16cs60r52.c
mymkdir:
	gcc -o mymkdir mymkdir_16cs60r52.c
mytail:
	gcc -o mytail mytail_16cs60r52.c
myps:
	gcc -o myps myps_16cs60r52.c
shell:
	gcc -o shell shell_16cs60r52.c
