/*************************************************************************
	> File Name: clientsocket.c
	> Author: gaofeng
	> Mail: gsligaofeng@163.com 
	> Created Time: 2016年12月23日 星期五 20时31分15秒
 ************************************************************************/

#include <stdio.h>

#include "mainbase.h"
/**
 * create main socket and connect server
 */
int open_client_socket(char* socket_path)
{
    struct sockaddr_un addr;
    char buf[100] = "abcdefgh";
    int fd;

    chdir("/tmp/");
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
      perror("socket error");
      exit(-1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    if (*socket_path == '\0') {
      *addr.sun_path = '\0';
      strncpy(addr.sun_path+1, socket_path+1, sizeof(addr.sun_path)-2);
    } else {
      strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
    }

    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
      perror("connect error");
      exit(-1);
    }
    printf("connect success \n");
    return fd;
}
