//#include <stdio.h>
//#include <unistd.h>
//#include <sys/socket.h>
//#include <sys/un.h>
//#include <stdlib.h>
#include "mainbase.h"

char *socket_path = "\0hidden";

int main(int argc, char *argv[]) {
	char buf[100];
	int cl, rc;
	if (argc > 1)
		socket_path = argv[1];

	int fd = open_server_socket(socket_path);

	while (1) {
		if ((cl = accept(fd, NULL, NULL)) == -1) {
			perror("accept error");
			continue;
		}

        rc = read(cl, buf, 20);
		printf("server socket recv %d, %s \n", rc, buf);
		if(strcmp(buf, "_initnotify") == 0)
		{
            printf("server init notify! \n");

	    	int pipefd[2];
	    	if (0 != pipe(pipefd)) {
		    	printf("create pipe err ! \n");
	    	}

	    	server_send_fd(cl, pipefd[1]);

		    while ((rc = read(pipefd[0], buf, sizeof(buf))) > 0) {
		    	printf("read %u bytes: %.*s\n", rc, rc, buf);
	    	}
	    	if (rc == -1) {
		    	perror("read");
		    	exit(-1);
	     	} else if (rc == 0) {
			    printf("\n");
			    close(cl);
	    	}
		}
		else{
            printf("not init notify \n");
		}
	}

	return 0;
}

