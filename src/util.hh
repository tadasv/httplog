#ifndef INCLUDE_GUARD_CA922543_BA40_40D7_A70D_4B02B127437B
#define INCLUDE_GUARD_CA922543_BA40_40D7_A70D_4B02B127437B


#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <errno.h>


static inline int str_to_int(const char* str, int default_value) {
    const char* last_location;
    int value;

    if (!str || !*str) {
        return default_value;
    }

    // Make sure to reset errno, because strtol doesn't on no-error.
    errno = 0;
    value = strtol(str, (char**) &last_location, 10);
    return (errno == 0) ? value : default_value;
}

static inline double str_to_double(const char* str, double default_value) {
    const char* last_location;
    double value;

    if (!str || !*str) {
        return default_value;
    }

    // Make sure to reset errno, because strtod doesn't on no-error.
    errno = 0;
    value = strtod(str, (char**) &last_location);
    return (errno == 0 && !isnan(value) && str != last_location) ? value : default_value;
}

#endif /* end of include guard */
