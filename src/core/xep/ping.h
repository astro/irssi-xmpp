/* $Id: ping.h,v 1.1 2008/08/16 21:54:40 cdidier Exp $ */

#ifndef __PING_H
#define __PING_H

__BEGIN_DECLS
void xmpp_ping_send(XMPP_SERVER_REC *, const char *);

void ping_init(void);
void ping_deinit(void);
__END_DECLS

#endif
