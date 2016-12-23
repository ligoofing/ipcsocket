/*************************************************************************
	> File Name: serverpipe.c
	> Author: gaofeng
	> Mail: gsligaofeng@163.com 
	> Created Time: 2016年12月23日 星期五 19时36分03秒
 ************************************************************************/

#include "mainbase.h"

static const int CONTROL_LEN = CMSG_LEN(sizeof(int));
void server_send_fd(int fd, int fd_to_send)
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
   cm.cmsg_len = CONTROL_LEN;
   cm.cmsg_level = SOL_SOCKET;
   cm.cmsg_type = SCM_RIGHTS;
   *(int*)CMSG_DATA(&cm) = fd_to_send;
   msg.msg_control = &cm; /*设置辅助数据*/
   msg.msg_controllen = CONTROL_LEN;

   sendmsg(fd, &msg, 0);
}
