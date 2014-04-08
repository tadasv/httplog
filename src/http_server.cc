#include <stdlib.h>
#include <fcntl.h>
#include <event2/event.h>
#include <event2/http.h>

#include "http_server.hh"
#include "handlers.h"


HttpServer::HttpServer()
{
}


HttpServer::~HttpServer()
{
}


void HttpServer::Init(struct event_base *loop, int port, int backlog)
{
    // prepare server socket
    backlog_ = backlog;
    port_ = port;
    loop_ = loop;

    httpd_ = evhttp_new(loop);
    if (!httpd_) {
        perror("evhttp_new");
        exit(-1);
    }

    evhttp_set_cb(httpd_, "/admin/shutdown", ShutdownHandler, this);
    evhttp_set_cb(httpd_, "/ping", PingHandler, this);
}


void HttpServer::Start()
{
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_ < 0) {
        perror("socket");
        exit(-1);
    }

    if (fcntl(socket_, F_SETFL, O_NONBLOCK)) {
        perror("fcntl");
        exit(-1);
    }

    int one = 1;
    if (setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one))) {
        perror("setsockopt");
        exit(-1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_);

    if (bind(socket_, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }

    listen(socket_, backlog_);

    if (evhttp_accept_socket(httpd_, socket_)) {
        perror("evhttp_accept_socket");
        exit(-1);
    }

    event_base_dispatch(loop_);
}


void HttpServer::Stop()
{
    event_base_loopexit(loop_, NULL);
    // TODO cleanup
}
