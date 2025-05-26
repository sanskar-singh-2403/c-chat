#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <errno.h>
#include "common.h"

int main() {
    char str[100];
    char sendLine1[100];
    memset(sendLine1, 0, 100);

    int listen_fd, comm_fd;

    struct sockaddr_in servaddr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(str, 0, 100);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(21000);

    bind(listen_fd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    listen(listen_fd,5);

    comm_fd=accept(listen_fd,(struct sockaddr *)NULL,NULL);

    while(1) {
        recv(comm_fd,str,100,0);
        printf("Client: %s",str);
        printf("Your message: ");
        fgets(sendLine1,100,stdin);
        send(comm_fd,sendLine1,strlen(sendLine1),0);
        bzero(sendLine1,100);
    }
    close(comm_fd);
}
