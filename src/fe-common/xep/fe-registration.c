/*
 * $Id: fe-registration.c,v 1.1 2008/12/08 11:16:19 cdidier Exp $
 *
 * Copyright (C) 2007 Colin DIDIER
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "module.h"
#include "ignore.h"
#include "levels.h"
#include "module-formats.h"
#include "printtext.h"
#include "signals.h"
#include "fe-common/core/module-formats.h"
#include "fe-common/irc/module-formats.h"

#include "xmpp-servers.h"
#include "xep/registration.h"

static void
sig_failed(const char *username, const char *domain, gpointer error)
{
	char *reason;

	switch(GPOINTER_TO_INT(error)) {
	case REGISTRATION_ERROR_UNAUTHORIZED:
	case REGISTRATION_ERROR_UNAUTHORIZED_REG:
		reason = "Registration unauthorized";
		break;
	case REGISTRATION_ERROR_UNIMPLEMENTED:
	case REGISTRATION_ERROR_UNAVAILABLE:
		reason = "Service unavailable";
		break;
	case REGISTRATION_ERROR_CONFLICT:
		reason = "Account already exists";
		break;
	case REGISTRATION_ERROR_TIMEOUT:
	case REGISTRATION_ERROR_TIMEOUT_SERVER:
		reason = "Connection times out";
		break;
	case REGISTRATION_ERROR_CONNECTION:
		reason = "Cannot open connection";
		break;
	case REGISTRATION_ERROR_INFOS:
		reason = "Cannot send informations";
		break;
	default:
		reason = "Cannot register account";
	}
	printformat_module(MODULE_NAME, NULL, NULL,
	    MSGLEVEL_CRAP, XMPPTXT_REGISTRATION_FAILED, username, domain,
	    reason);
}

static void
sig_succeed(const char *username, const char *domain)
{
	printformat_module(MODULE_NAME, NULL, NULL,
	    MSGLEVEL_CRAP, XMPPTXT_REGISTRATION_SUCCEED, username, domain);
}

static void
sig_started(const char *username, const char *domain)
{
	printformat_module(MODULE_NAME, NULL, NULL,
	    MSGLEVEL_CRAP, XMPPTXT_REGISTRATION_STARTED, username, domain);
}

void
fe_registration_init(void)
{
	signal_add("xmpp registration failed", sig_failed);
	signal_add("xmpp registration succeed", sig_succeed);
	signal_add("xmpp registration started", sig_started);
}

void
fe_registration_deinit(void)
{
	signal_remove("xmpp registration failed", sig_failed);
	signal_remove("xmpp registration succeed", sig_succeed);
	signal_remove("xmpp registration started", sig_started);
}
