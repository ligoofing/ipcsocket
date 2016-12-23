PROGS = servermain

all: $(PROGS)

servermain: servermain.c serverpipe.c serversocket.c

.PHONY: clean

clean:
	rm -f *.o socket $(PROGS)
