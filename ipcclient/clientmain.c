#include "mainbase.h"
#include "notification.h"


int main(int argc, char *argv[]) {
  char buf[100] = "abcdefgh";
  int rc;  
  char *socket_path = "\0";

  if (argc > 1) socket_path = argv[1];

  int fd = open_client_socket(socket_path);
  client_socket_fd = fd;

  init_notify(fd);
  
  send_notification("gogogogo");


//  int client_pipe_fd;
//  client_pipe_fd = recv_fd(fd);
//  printf("client pipe fd = %d \n", client_pipe_fd);
//
//  while(1) {
//    if(rc = write(client_pipe_fd, buf, 10)) {
//      if (rc > 0) fprintf(stderr,"write ok \n");
//      else {
//	    printf("write error \n");
//        exit(-1);
//      }
//    }
//	sleep(2);
//  }

  return 0;
}
