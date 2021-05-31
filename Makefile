OBJS=main.o screen.o heat.o utils.o settings.o
CFLAGS= -g 
EXTRALIB=-lncurses 

all: main.x 

main.x: $(OBJS)
	gcc $(CFLAGS) -o  $@ $^ $(EXTRALIB)

%.o: %.c
	gcc -c $(CFLAGS) $<

run: main.x
	./main.x -m center -t 100000

clean:
	rm *.o *.x

