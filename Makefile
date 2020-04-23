OBJS=main.o screen.o heat.o utils.o settings.o
CFLAGS= -g

all: main.x 

main.x: $(OBJS)
	gcc $(CFLAGS) -o  $@ $^ -lncurses

%.o: %.c
	gcc -c $(CFLAGS) $<

run: main.x
	./main.x -m center -t 100000

clean:
	rm *.o *.x

