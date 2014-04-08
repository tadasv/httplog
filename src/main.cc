#include <stdlib.h>
#include <event2/event.h>

#include "http_server.hh"
#include "mmap_queue.hh"


int main(int argc, const char *argv[])
{
    struct event_base *loop = event_base_new();

    if (!loop) {
        perror("event_base_new");
        exit(-1);
    }

    auto *queue = new MMQueue();
    delete queue;

    auto server = HttpServer();
    server.Init(loop, 8888, 0xffff);
    server.Start();

    event_base_free(loop);

    return 0;
}
