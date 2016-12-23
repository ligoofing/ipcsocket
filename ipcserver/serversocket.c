/*
 * serversocket.c
 *
 *  Created on: 2016年12月23日
 *      Author: ligaofeng
 */

#include "mainbase.h"

int open_server_socket(char* socket_path) {
	struct sockaddr_un addr;
	int fd;

	chdir("/tmp/");
	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket error");
		exit(-1);
	}

	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	if (*socket_path == '\0') {
		*addr.sun_path = '\0';
		strncpy(addr.sun_path + 1, socket_path + 1, sizeof(addr.sun_path) - 2);
	} else {
		strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);
		unlink(socket_path);
	}

	if (bind(fd, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
		perror("bind error");
		exit(-1);
	}

	if (listen(fd, 5) == -1) {
		perror("listen error");
		exit(-1);
	}

	return fd;
}

