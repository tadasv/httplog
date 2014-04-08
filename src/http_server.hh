#ifndef INCLUDE_GUARD_AA330A97_4F27_4542_A6EC_B8E67B66D18F
#define INCLUDE_GUARD_AA330A97_4F27_4542_A6EC_B8E67B66D18F

class HttpServer {
    public:
        HttpServer();
        ~HttpServer();
        void Init(struct event_base *loop, int port, int backlog);
        void Start();
        void Stop();

    protected:
        struct evhttp *httpd_;
        struct event_base *loop_;
        int socket_;
        int backlog_;
        int port_;
};

#endif /* end of include guard */
