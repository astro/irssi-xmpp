/* $Id: fe-xmpp-status.h,v 1.1 2007/10/15 11:59:19 cdidier Exp $ */

#ifndef __FE_XMPP_STATUS_H
#define __FE_XMPP_STATUS_H

extern const char *fe_xmpp_presence_show[];

__BEGIN_DECLS
char		*fe_xmpp_status_get_window_name(XMPP_SERVER_REC *);
WINDOW_REC	*fe_xmpp_status_get_window(XMPP_SERVER_REC *);

void fe_xmpp_status_init(void);
void fe_xmpp_status_deinit(void);
__END_DECLS

#endif
