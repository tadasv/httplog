#include <event2/event.h>
#include <event2/http.h>

#include "http_server.hh"


void ShutdownHandler(struct evhttp_request *req, void *data)
{
    auto server = (HttpServer*)data;
    server->Stop();
}
