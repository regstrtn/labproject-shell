CC=g++
CFLAGS=-I.
DEPS = 
OBJ = myls.o mymv.o myrm.o mytail.o mypwd.o mymkdir.o shell.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

serial: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
