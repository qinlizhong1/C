//
// Created by 覃立中 on 2022/7/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <memory.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define PORT 8888 //定义通信端口
#define BACKLOG 5 //定义侦听队列长度
#define buflen 1024
int listenfd,connfd;
int main(int argc,char *argv[])
{
    struct sockaddr_in server_addr; //存储服务器端socket地址结构
    struct sockaddr_in client_addr; //存储客户端 socket地址结构
    pid_t pid;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET; //协议族
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //本地地址
    server_addr.sin_port = htons(PORT);
    bind(listenfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
    listen(listenfd,BACKLOG);
    for(;;)
    {
        socklen_t addrlen = sizeof(client_addr);
        connfd = accept(listenfd,(struct sockaddr *)&client_addr,&addrlen);
        if(connfd<0)
            perror("accept error");
        printf("receive connection\n");
        if((pid = fork()) == 0)
        {
            close(listenfd);
            sleep(1000);//子进程不接收数据，sleep 1000秒
            exit(0);
        }
        else
        {
            close(connfd);
        }
    }
}