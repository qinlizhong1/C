//
// Created by qin on 2022/7/14.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <memory.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 9999
#define Buflen 1024
int main(int argc,char *argv[])
{
    struct sockaddr_in server_addr;
    int n,count=0;
    int sockfd;
    char sendline[Buflen];
    sockfd= socket(AF_INET,SOCK_STREAM,0);
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));

    //与服务器端进行通信
    memset(sendline,'a',sizeof(Buflen));

    while ( (n=write(sockfd,sendline,Buflen))>0 )
    {
        count++;
        printf("already write %d bytes -- %d\n",n,count);
    }

    if(n<0)
        perror("write error");
    close(sockfd);
}
