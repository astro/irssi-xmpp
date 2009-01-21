# $Id: Makefile,v 1.6 2007/12/05 16:47:18 cdidier Exp $

all clean user-install install:
	@echo "core module:"
	@cd core/ && ${MAKE} $@
	@echo "fe-common submodule:"
	@cd fe-common/ && ${MAKE} $@
	@echo "fe-text submodule:"
	@cd fe-text/ && ${MAKE} $@	

.PHONY: all clean user-install install
