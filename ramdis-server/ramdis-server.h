#ifndef __RAMDIS_SERVER_H
#define __RAMDIS_SERVER_H

#include <string>
#include <vector>

#include "sds.h"

#define CONFIG_DEFAULT_TCP_BACKLOG       511     /* TCP listen backlog */
#define PROTO_IOBUF_LEN         (1024*16)  /* Generic I/O buffer size */
#define NET_IP_STR_LEN 46 /* INET6_ADDRSTRLEN is 46, but we need to be sure */

#define LOG_MAX_LEN    1024 /* Default maximum length of syslog messages */

/* Log levels */
#define LL_FATAL 0
#define LL_ERROR 1
#define LL_WARN 2
#define LL_INFO 3
#define LL_DEBUG 4
#define LL_TRACE 5

/* Messages with log level <= VERBOSITY will be printed. */
#ifndef VERBOSITY
#define VERBOSITY LL_INFO
#endif

/* Used to store client data coming in over the socket and parsing state as the
 * buffer is incrementally parsed for commands. */
struct clientBuffer {
  sds querybuf;                    // Buffer for data coming in over the wire.
  int reqtype;
  int multibulklen;
  long bulklen;
  std::vector<std::string> argv;   // Resulting command arguments.
};

#endif // __RAMDIS_SERVER_H
