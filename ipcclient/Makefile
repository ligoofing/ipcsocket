PROGS = clientmain

all: $(PROGS)

clientmain: clientmain.c clientpipe.c clientsocket.c notification.c

.PHONY: clean

clean:
	rm -f *.o socket $(PROGS)
