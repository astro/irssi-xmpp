# $Id: rules.mk,v 1.6 2008/08/15 00:25:21 cdidier Exp $

include ../../config.mk

OBJS = ${SRCS:.c=.o}

all: ${LIB}

.c.o:
	@echo ${CC} -c $<
	@${CC} -c $< -o $@ ${CFLAGS}

${LIB}: ${OBJS}
	@echo ${CC} -o lib$@.so
	@${CC} -o lib$@.so ${OBJS} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f lib${LIB}.so ${OBJS}

install: all
	@echo installing the module lib${LIB}.so to ${DESTDIR}${IRSSI_LIB}/modules
	@install -d ${DESTDIR}${IRSSI_LIB}/modules
	@install lib${LIB}.so ${DESTDIR}${IRSSI_LIB}/modules

uninstall:
	@echo deinstalling the module lib${LIB}.so from ${DESTDIR}${IRSSI_LIB}/modules
	@rm -f ${DESTDIR}${IRSSI_LIB}/modules/lib${LIB}.so

user-install:
	@env DESTDIR= IRSSI_LIB=~/.irssi ${MAKE} install

user-uninstall:
	@env DESTDIR= IRSSI_LIB=~/.irssi ${MAKE} uninstall

.PHONY: clean install uninstall user-install user-uninstall
