#include <unp.h>

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
    servaddr.sin_port = htons(8000);
    
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 5);
    for (;;)
    {
        chilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr*)&cliaddr, &chilen);
        if ((childpip = fork()) == 0)
        {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(listenfd);
    }
}