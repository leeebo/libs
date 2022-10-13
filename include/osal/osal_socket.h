/**
 * @file osal_socket.h
 * @author Li Bo (libo_go@163.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef OSAL_SORKET_H
#define OSAL_SORKET_H

#ifdef _WIN32 //If Windows Platform
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#include "export_global.h"
//#pragma comment(lib, "ws2_32.lib") //MSVC
#else //If Linux/UNIX Platform
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _WIN32 
typedef int socklen_t;
#endif

int osal_socket(int domain, int type, int protocol);
int socket_accept(int socket, struct sockaddr *addr, socklen_t *addrlen);
int socket_bind(int socket, const struct sockaddr *name, socklen_t namelen);
int socket_shutdown(int socket, int how);
int socket_connect(int socket, const struct sockaddr *name, socklen_t namelen);
int socket_listen(int socket, int backlog);
int socket_recv(int socket, void *mem, size_t len, int flags);
int socket_recvfrom(int socket, void *mem, size_t len, int flags, struct sockaddr *from, socklen_t *fromlen);
int socket_send(int socket, const void *dataptr, size_t size, int flags);
int socket_sendto(int socket, const void *dataptr, size_t size, int flags, const struct sockaddr *to, socklen_t tolen);
int socket_close(int socket);

#ifdef __cplusplus
}
#endif
#endif
