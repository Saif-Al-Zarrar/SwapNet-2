#define _GNU_SOURCE     /* for RTLD_NEXT */
#include <sys/socket.h>
#include <dlfcn.h>
#include <stdio.h>


//libc wrappers for sys/sockets.h
int  libc_accept(int socket, struct sockaddr *address, socklen_t *address_len) {
    int (*lib_accept)(int, struct sockaddr*, socklen_t*) = (int (*)(int, struct sockaddr*, socklen_t*))dlsym(RTLD_NEXT, "accept");
    return lib_accept(socket, address, address_len);
}
int libc_bind(int socket, const struct sockaddr *address, socklen_t address_len) {
    int (*lib_bind)(int, const struct sockaddr *, socklen_t) = (int (*)(int, const struct sockaddr *, socklen_t))dlsym(RTLD_NEXT, "bind");
    return lib_bind(socket, address, address_len);
}
int libc_connect(int socket, const struct sockaddr *address, socklen_t address_len) {
    int (*lib_connect)(int, const struct sockaddr *, socklen_t) = (int (*)(int, const struct sockaddr *, socklen_t))dlsym(RTLD_NEXT, "connect");
    return lib_connect(socket, address, address_len);
}
int libc_getsockopt(int socket, int level, int option_name, void *option_value, socklen_t *option_len) {
    int (*lib_getsockopt)(int, int, int, void *, socklen_t *) = (int (*)(int, int, int, void *, socklen_t *))dlsym(RTLD_NEXT, "getsockopt");
    return lib_getsockopt(socket, level, option_name, option_value, option_len);
}
int libc_setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len) {
    int (*lib_setsockopt)(int, int, int, const void *, socklen_t) = (int (*)(int, int, int, const void *, socklen_t))dlsym(RTLD_NEXT, "setsockopt");
    return lib_setsockopt(socket, level, option_name, option_value, option_len);
}
int libc_listen(int socket, int backlog) {
    int (*lib_listen)(int, int) = (int (*)(int, int))dlsym(RTLD_NEXT, "listen");
    return lib_listen(socket, backlog);
}
ssize_t libc_send(int socket, const void *message, size_t length, int flags) {
    ssize_t (*lib_send)(int, const void *, size_t, int) = (ssize_t (*)(int, const void *, size_t, int))dlsym(RTLD_NEXT, "send");
    return lib_send(socket, message, length, flags);
}
ssize_t libc_recv(int socket, void *buffer, size_t length, int flags) {
    ssize_t (*lib_recv)(int, void *, size_t, int) = (ssize_t (*)(int, void *, size_t, int))dlsym(RTLD_NEXT, "recv");
    return lib_recv(socket, buffer, length, flags);
}
int libc_shutdown(int socket, int how) {
    int (*lib_shutdown)(int, int) = (int (*)(int, int))dlsym(RTLD_NEXT, "shutdown");
    return lib_shutdown(socket, how);
}

int  accept(int socket, struct sockaddr *address, socklen_t *address_len) {
    printf("Intercepted accept\n");
    return libc_accept(socket, address, address_len);
}
int bind(int socket, const struct sockaddr *address, socklen_t address_len) {
    printf("Intercepted bind\n");
    return libc_bind(socket, address, address_len);
}
int connect(int socket, const struct sockaddr *address, socklen_t address_len) {
    printf("Intercepted connect\n");
    return libc_connect(socket, address, address_len);
}
int getsockopt(int socket, int level, int option_name, void *option_value, socklen_t *option_len) {
    printf("Intercepted getsockopt\n");
    return libc_getsockopt(socket, level, option_name, option_value, option_len);
}
int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len) {
    printf("Intercepted setsocketopt\n");
    return libc_setsockopt(socket, level, option_name, option_value, option_len);
}
int listen(int socket, int backlog) {
    printf("Intercepted listen\n");
    return libc_listen(socket, backlog);
}
ssize_t send(int socket, const void *message, size_t length, int flags) {
    printf("Intercepted send\n");
    return libc_send(socket, message, length, flags);
}
ssize_t recv(int socket, void *buffer, size_t length, int flags) {
    printf("Intercepted recv\n");
    return libc_recv(socket, buffer, length, flags);
}
int     shutdown(int socket, int how) {
    printf("Intercepted shutdown\n");
    return libc_shutdown(socket, how);
}
