# heat-curses
Compute and display in the terminal heat difussion processes.

## Build
Be sure to have ncurses installed an execute:
```bash
make
```

## Execute
```bash
./main.x -t 10000 -m random 
```

## Parameters

* `-t INT`: Usecs between frames.
* `-m CONFIG`: Configuration used. Right now center, 2center and random supported.
