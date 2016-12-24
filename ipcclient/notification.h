/*************************************************************************
	> File Name: notification.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年12月24日 星期六 12时47分48秒
 ************************************************************************/

#ifndef NOTIFY
#define NOTIFY
int init_notify();

int get_write_pipe();

int send_notifaction(char*);

#endif
