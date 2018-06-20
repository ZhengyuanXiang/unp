#include "unp.h"

int main(int argc, char **argv)
{
    int listenfd, connfd;
    pid_t childpip;
    socklen_t chilen;

    struct sockaddr_in cliaddr, servaddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    Signal(SIGCHLD, sigchld);

    Listen(listenfd, LISTENQ);
    for (;;)
    {
        chilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr*)&cliaddr, &chilen);
        if ((childpip = Fork()) == 0)
        {
            printf("pid=%d\n", getpid());
            printf("ppid=%d\n", getppid());
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        Close(connfd);
    }
}