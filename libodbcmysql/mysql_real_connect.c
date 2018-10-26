/* ========================================================================= **
**                       ____                                    __          **
**            ____  ____/ / /_  _________ ___  __  ___________ _/ /          **
**           / __ \/ __  / __ \/ ___/ __ `__ \/ / / / ___/ __ `/ /           **
**          / /_/ / /_/ / /_/ / /__/ / / / / / /_/ (__  ) /_/ / /            **
**          \____/\__,_/_.___/\___/_/ /_/ /_/\__, /____/\__, /_/             **
**                                          /____/        /_/                **
**                                                                           **
** ========================================================================= **
**                   MYSQL CLIENT LIBRARY DRIVER FOR ODBC                    **
** ========================================================================= **
**                                                                           **
** Copyright (c) 2008-2018 Jonah H. Harris.                                  **
**                                                                           **
** This library is free software; you can redistribute it and/or modify it   **
** under the terms of the GNU Lesser General Public License as published by  **
** the Free Software Foundation; either version 3 of the License, or (at     **
** your option) any later version.                                           **
**                                                                           **
** This library is distributed in the hope it will be useful, but WITHOUT    **
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or     **
** FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public       **
** License for more details.                                                 **
**                                                                           **
** You should have received a copy of the GNU Lesser General Public License  **
** along with this library; if not, write to the Free Software Foundation,   **
** Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                             **
** ========================================================================= */

/* ========================================================================= */
/* -- INCLUSIONS ----------------------------------------------------------- */
/* ========================================================================= */

/* Library Header */
#include "libodbcmysql.h"

/* ========================================================================= */
/* -- DEFINITIONS ---------------------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- MACROS --------------------------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- PRIVATE TYPES -------------------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- PRIVATE METHOD PROTOTYPES -------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- PRIVATE DATA --------------------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- PUBLIC DATA ---------------------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- EXTERNAL DATA -------------------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- EXTERNAL FUNCTION PROTOTYPES ----------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- STATIC ASSERTIONS ---------------------------------------------------- */
/* ========================================================================= */

/* ========================================================================= */
/* -- PRIVATE METHODS ------------------------------------------------------ */
/* ========================================================================= */

static inline MYSQL *
_odbcmysql_real_connect (
  MYSQL               *mysql,
  const char          *host,
  const char          *user,
  const char          *passwd,
  const char          *db,
  unsigned int         port,
  const char          *unix_socket,
#if (LIBMYSQL_VERSION_ID < 50724)
  unsigned int        clientflag
#else
  unsigned long       clientflag
#endif
) {
  log_trace("Entering Function %s", __func__);

  NOOP_RETURN(NULL);
} /* _odbcmysql_real_connect() */

/* ========================================================================= */
/* -- PUBLIC METHODS ------------------------------------------------------- */
/* ========================================================================= */

MYSQL * __stdcall
mysql_real_connect (
  MYSQL               *mysql,
  const char          *host,
  const char          *user,
  const char          *passwd,
  const char          *db,
  unsigned int         port,
  const char          *unix_socket,
#if (LIBMYSQL_VERSION_ID < 50724)
  unsigned int        clientflag
#else
  unsigned long       clientflag
#endif
) {
  log_trace("Entering Function %s", __func__);

  if (MYSQL_FPTR_IS_NOT_NULL(mysql_real_connect)) {
    return (MYSQL_FPTR(mysql_real_connect)(mysql, host, user, passwd, db,
      port, unix_socket, clientflag));
  } else {
    return (_odbcmysql_real_connect(mysql, host, user, passwd, db, port,
        unix_socket, clientflag));
  }

} /* mysql_real_connect() */

/* :vi set ts=2 et sw=2: */

