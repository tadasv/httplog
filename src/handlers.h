#ifndef INCLUDE_GUARD_6F84D1C8_11C5_488E_B060_1AFF0EE4741B
#define INCLUDE_GUARD_6F84D1C8_11C5_488E_B060_1AFF0EE4741B

struct evhttp_request;

void ShutdownHandler(struct evhttp_request *req, void *data);
void PingHandler(struct evhttp_request *req, void *data);


#endif /* end of include guard */
