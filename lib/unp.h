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

#define	MAXLINE	4096