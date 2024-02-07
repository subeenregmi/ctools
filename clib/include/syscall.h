// C Wrapper for x86_64 Linux System Calls
#ifndef CLIB_SYSCALL_H
#define CLIB_SYSCALL_H

#include "string.h"

// File descriptors
#define STDIN_FD        0
#define STDOUT_FD       1
#define STDERR_FD       2

// Linux syscalls
#define SYS_READ        0
#define SYS_WRITE       1
#define SYS_OPEN        2
#define SYS_CLOSE       3

/* sys_open requires:
 *      - Filename or path
 *      - Flags: These are the creation and status flags for the file 
 *      - Mode: The permission of the file.
 */

// sys_open - Required flags 
#define READ_ONLY       0
#define WRITE_ONLY      1
#define READ_WRITE      2

// sys_open - Optional flags
// File creation flags
#define CREATE_IFNOT    100

// File status flags
#define APPEND          2000
#define ASYNC           20000

// sys_open - Modes/Permissions


int syscall(void *arg1, void *arg2, void *arg3, void *arg4);

int sys_write(int fd, String str);
int sys_read(int fd, String str, int bytes);
int sys_open(String filename, int flags, int mode);
int sys_close(int fd);

#endif // CLIB_SYSCALL_H

