#include <cstring>

#include <math.h>
#include <time.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/keyvalq_struct.h>

#include "user_data.hh"
#include "util.hh"

// get utc timestamp in nanoseconds
static inline uint64_t get_current_time()
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    uint64_t timestamp = spec.tv_sec * 1.0e9 + spec.tv_nsec;
    return timestamp;
}


void PingHandler(struct evhttp_request *req, void *data)
{
    const struct evhttp_uri *parsed_uri = evhttp_request_get_evhttp_uri(req);

    struct UserData user_data;
    memset(&user_data, 0, sizeof(user_data));

    if (!parsed_uri) {
        evhttp_send_reply(req, 400, "Bad Request", NULL);
        return;
    }

    struct evkeyvalq parsed_query;
    memset(&parsed_query, 0, sizeof(parsed_query));

    const char *query = evhttp_uri_get_query(parsed_uri);
    if (evhttp_parse_query_str(query, &parsed_query) == 0) {
        struct evkeyval *query_arg;

        // TODO eventually we will point to a mmaped region
        UserData *ud_ptr = &user_data;
        ud_ptr->timestamp = get_current_time();

        for (query_arg = parsed_query.tqh_first; query_arg; query_arg = query_arg->next.tqe_next) {
            const char *key = query_arg->key;
            switch (key[0]) {
                case 'g':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->g = value;
                            break;
                    }
                    break;
                case 'c':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->c = value;
                            break;
                    }
                    break;
                case 'x':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->x = value;
                            break;
                    }
                    break;
                case 'v':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->v = value;
                            break;
                    }
                    break;
                case 'w':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->w = value;
                            break;
                    }
                    break;
                case 'o':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->o = value;
                            break;
                    }
                    break;
                case 'j':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->j = value;
                            break;
                    }
                    break;
                case 'E':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->E = value;
                            break;
                    }
                    break;
                case 'b':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->b = value;
                            break;
                    }
                    break;
                case 'n':
                    switch (key[1]) {
                        case '\0':
                            uint64_t value = str_to_int(query_arg->value, 0);
                            ud_ptr->n = value;
                            break;
                    }
                    break;
                default:
                    // TODO something else
                    break;
            }
        }

        //ud_ptr->Print();

        evhttp_clear_headers(&parsed_query);
    } else {
        fprintf(stderr, "failed to parse query\n");
    }

    evhttp_send_reply(req, 200, "OK", NULL);
}
