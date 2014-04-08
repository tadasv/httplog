#ifndef INCLUDE_GUARD_97E9D564_074C_49AA_B03A_DEB90EC71C06
#define INCLUDE_GUARD_97E9D564_074C_49AA_B03A_DEB90EC71C06

#include <cstdint>

// Without NULL terminator
#define UD_U_SIZE 32
#define UD_T_SIZE 32


struct UserData {
    uint64_t timestamp; // timestamp in utc
    uint64_t g; // account id
    uint64_t c; // time on page in minutes
    uint64_t x; // scroll position top
    uint64_t v; // scroll window height
    uint64_t w; // window height
    uint64_t o; // page width
    uint64_t j; // decay in seconds
    uint64_t E; // engaged seconds on a page
    uint64_t b; // page load time
    uint8_t n; // new user
    unsigned char u[UD_U_SIZE]; // user id
    unsigned char t[UD_T_SIZE]; // page session
    uint64_t data_size;
    uint8_t data[];

    void Print() {
        printf("timestmap: %lu\n"
               "g: %lu\n"
               "c: %lu\n"
               "x: %lu\n"
               "v: %lu\n"
               "w: %lu\n"
               "o: %lu\n"
               "j: %lu\n"
               "E: %lu\n"
               "b: %lu\n"
               "n: %u\n",
        timestamp, g, c, x, v, w, o, j, E, b, n);
    }
};


#endif /* end of include guard */
