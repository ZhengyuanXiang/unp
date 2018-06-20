#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/syslog.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>

#define	MAXLINE	4096
#define SERV_PORT 9877
#define	LISTENQ	1024

#define	SA	struct sockaddr
typedef	void Sigfunc(int);