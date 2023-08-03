/*
net_stub.h - stub BSD sockets
Copyright (C) 2020 mittorn

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#ifndef NET_STUB_H
#define NET_STUB_H

#define INVALID_SOCKET (-1)
#define SOCKET_ERROR (-1)
#define SOCKET int
typedef int WSAsize_t;
#define IN6_IS_ADDR_V4MAPPED(a) \
        (((uint32_t *) (a))[0] == 0 && ((uint32_t *) (a))[1] == 0 && \
         ((uint8_t *) (a))[8] == 0 && ((uint8_t *) (a))[9] == 0 && \
         ((uint8_t *) (a))[10] == 0xff && ((uint8_t *) (a))[11] == 0xff)
struct in_addr {unsigned long s_addr;};
struct in6_addr {
	uint8_t* s6_addr;			/* 128-bit IP6 address */
};
struct sockaddr_in{ short sin_family;unsigned short sin_port;struct in_addr sin_addr;};
typedef unsigned char bsd_sa_family_t;
struct sockaddr_in6 {
	uint8_t		sin6_len;	/* length of this struct */
	bsd_sa_family_t	sin6_family;	/* AF_INET6 */
	in_port_t	sin6_port;	/* Transport layer port # */
	uint32_t	sin6_flowinfo;	/* IP6 flow information */
	struct in6_addr	sin6_addr;	/* IP6 address */
	uint32_t	sin6_scope_id;	/* scope zone index */
};
struct sockaddr {short sa_family;int stub[32];};
struct hostent {int h_addr_list[1];};
typedef unsigned int socklen_t;

#define	_SS_MAXSIZE	128U
#define	_SS_ALIGNSIZE	(sizeof(int64_t))
#define	_SS_PAD1SIZE	(_SS_ALIGNSIZE - sizeof(unsigned char) - \
			    sizeof(bsd_sa_family_t))
#define	_SS_PAD2SIZE	(_SS_MAXSIZE - sizeof(unsigned char) - \
			    sizeof(bsd_sa_family_t) - _SS_PAD1SIZE - _SS_ALIGNSIZE)
struct sockaddr_storage {
	unsigned char	ss_len;		/* address length */
	bsd_sa_family_t 	ss_family;	/* address family */
	char		__ss_pad1[_SS_PAD1SIZE];
	int64_t	__ss_align;	/* force desired struct alignment */
	char		__ss_pad2[_SS_PAD2SIZE];
};
#if !XASH_AMIGA
struct timeval {long tv_sec;long tv_usec;};
#endif
const struct in6_addr in6addr_any, in6addr_loopback;
#define AF_INET 0
#define AF_INET6 1
#define PF_INET 0
#define PF_INET6 1
#define AF_UNSPEC 0
#define INADDR_BROADCAST 0
#define INADDR_ANY 0
//! Network to host conversion for a word.
#define ntohs(n) ( (((n) & 0xFF00) >> 8) | (((n) & 0x00FF) << 8) )
//! Host to network conversion for a word.
#define htons(n) ( (((n) & 0xFF00) >> 8) | (((n) & 0x00FF) << 8) )
//! Network to host conversion for a double word.
#define ntohl(n) ( (((n) & 0xFF000000) >> 24) | (((n) & 0x00FF0000) >> 8) \
	 | (((n) & 0x0000FF00) << 8) | (((n) & 0x000000FF) << 24) )
//! Host to network conversion for a double word.
#define htonl(n) ( (((n) & 0xFF000000) >> 24) | (((n) & 0x00FF0000) >> 8) \
	 | (((n) & 0x0000FF00) << 8) | (((n) & 0x000000FF) << 24) )

#define gethostbyname(...) NULL
#define inet_addr(...) (-1)
#define recvfrom(...) (-1)
#define sendto(...) (-1)
#define socket(...) (-1)
#define ioctlsocket(...) (-1)
#define setsockopt(...) (-1)
#define bind(...) (-1)
#define gethostname(...) (-1)
#define getsockname(...) (-1)
#define connect(...) (-1)
#define send(...) (-1)
#define recv(...) (-1)
#define bind(...) (-1)
#define closesocket(...) (-1)
#define select(...) (-1)

#define WSAGetLastError() (22) //ENETDOWN
#define WSAEINTR           1 //EINTR
#define WSAEBADF           2 //EBADF
#define WSAEACCES          3 //EACCES
#define WSAEFAULT          4 //EFAULT
#define WSAEINVAL          5 //EINVAL
#define WSAEMFILE          6 //EMFILE
#define WSAEWOULDBLOCK     7 //EWOULDBLOCK
#define WSAEINPROGRESS     8 //EINPROGRESS
#define WSAEALREADY        9 //EALREADY
#define WSAENOTSOCK        10 //ENOTSOCK
#define WSAEDESTADDRREQ    11 //EDESTADDRREQ
#define WSAEMSGSIZE        12 //EMSGSIZE
#define WSAEPROTOTYPE      13 //EPROTOTYPE
#define WSAENOPROTOOPT     14 //ENOPROTOOPT
#define WSAEPROTONOSUPPORT 15 //EPROTONOSUPPORT
#define WSAESOCKTNOSUPPORT 16 //ESOCKTNOSUPPORT
#define WSAEOPNOTSUPP      17 //EOPNOTSUPP
#define WSAEPFNOSUPPORT    18 //EPFNOSUPPORT
#define WSAEAFNOSUPPORT    19 //EAFNOSUPPORT
#define WSAEADDRINUSE      20 //EADDRINUSE
#define WSAEADDRNOTAVAIL   21 //EADDRNOTAVAIL
#define WSAENETDOWN        22 //ENETDOWN
#define WSAENETUNREACH     23 //ENETUNREACH
#define WSAENETRESET       24 //ENETRESET
#define WSAECONNABORTED    25 //ECONNABORTED
#define WSAECONNRESET      26 //ECONNRESET
#define WSAENOBUFS         27 //ENOBUFS
#define WSAEISCONN         28 //EISCONN
#define WSAENOTCONN        29 //ENOTCONN
#define WSAESHUTDOWN       30 //ESHUTDOWN
#define WSAETOOMANYREFS    31 //ETOOMANYREFS
#define WSAETIMEDOUT       32 //ETIMEDOUT
#define WSAECONNREFUSED    33 //ECONNREFUSED
#define WSAELOOP           34 //ELOOP
#define WSAENAMETOOLONG    35 //ENAMETOOLONG
#define WSAEHOSTDOWN       36 //EHOSTDOWN

#endif // NET_STUB_H
