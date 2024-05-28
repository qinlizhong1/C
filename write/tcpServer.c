//
// Created by ������ on 2022/7/14.
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
#define PORT 8888 //����ͨ�Ŷ˿�
#define BACKLOG 5 //�����������г���
#define buflen 1024
int listenfd,connfd;
int main(int argc,char *argv[])
{
    struct sockaddr_in server_addr; //�洢��������socket��ַ�ṹ
    struct sockaddr_in client_addr; //�洢�ͻ��� socket��ַ�ṹ
    pid_t pid;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET; //Э����
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //���ص�ַ
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
            sleep(1000);//�ӽ��̲��������ݣ�sleep 1000��
            exit(0);
        }
        else
        {
            close(connfd);
        }
    }
}