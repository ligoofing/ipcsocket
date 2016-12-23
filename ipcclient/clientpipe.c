/*************************************************************************
	> File Name: clientpipe.c
	> Author: gaofeng
	> Mail: gsligaofeng@163.com 
	> Created Time: 2016年12月23日 星期五 20时07分22秒
 ************************************************************************/

#include "mainbase.h"

static const int CONTROL_LEN = CMSG_LEN(sizeof(int));

/**
 * receive server pipe[1] fd
 */
int recv_fd(int fd)
{
    struct iovec iov[1];
    struct msghdr msg;
    char buf[0];

    iov[0].iov_base = buf;
    iov[0].iov_len = 1;
    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = iov;
    msg.msg_iovlen = 1;

    struct cmsghdr cm;
    msg.msg_control = &cm;
    msg.msg_controllen = CONTROL_LEN;

    recvmsg(fd, &msg, 0);

    int fd_to_read = *(int*)CMSG_DATA(&cm);
    return fd_to_read;
}
