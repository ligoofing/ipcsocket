/*************************************************************************
	> File Name: notification.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年12月24日 星期六 12时46分33秒
 ************************************************************************/

#include<stdio.h>
#include "mainbase.h"
#include "notification.h"

char init_notify_flag[20] = "_initnotify";
int notify_write_fd; // pipe[1]form server


int init_notify()
{
	int ret;
    ret =  write(client_socket_fd,init_notify_flag,20 );
    if(ret <= 0)
	{
		printf("init notification error! \n");
		return -1;
	}

	get_write_pipe();
    return 0;
}

int get_write_pipe()
{
    int fd;

    fd = recv_fd(client_socket_fd);
    if(fd < 0)printf("get write pipe error! \n");
	notify_write_fd = fd;
	return fd;
}

int send_notification(char* notify)
{
    int size;
    
    size = write(notify_write_fd, notify, sizeof(notify));

    return size;
}
