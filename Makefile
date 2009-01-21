# $Id: Makefile,v 1.7 2008/06/23 14:37:16 cdidier Exp $

include config.mk

all clean user-install user-uninstall:
	@cd src/ && ${MAKE} $@

install:
	@cd src/ && ${MAKE} $@
	@${MAKE} doc-install help-install

uninstall: doc-uninstall help-uninstall
	@cd src/ && ${MAKE} $@

doc-install:
	@echo installing documentation files to ${DESTDIR}${IRSSI_DOC}/irssi-xmpp
	@install -d ${DESTDIR}${IRSSI_DOC}/irssi-xmpp
	@cd docs/ && install FAQ GENERAL MUC STARTUP XEP ${DESTDIR}${IRSSI_DOC}/irssi-xmpp

doc-uninstall:
	@echo uninstalling documentation files from ${DESTDIR}${IRSSI_DOC}/irssi-xmpp
	@rm -rf ${DESTDIR}${IRSSI_DOC}/irssi-xmpp

help-install:
	@echo installing command help files to ${DESTDIR}${IRSSI_HELP}
	@install -d ${DESTDIR}${IRSSI_HELP}
	@cd help/ && install -m 644 roster xmppconnect xmppserver ${DESTDIR}${IRSSI_HELP}

help-uninstall:
	@echo uninstalling command help files from ${DESTDIR}${IRSSI_HELP}
	@cd ${DESTDIR}${IRSSI_HELP} && rm -f roster xmppconnect xmppserver

.PHONY: all clean install uninstall user-install user-uninstall doc-install doc-uninstall help-install help-uninstall
