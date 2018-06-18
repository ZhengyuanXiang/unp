include ../Make.defines

PROGS =	tcpserv01

all:	${PROGS}

tcpserv01:	tcpserv01.o
		${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}