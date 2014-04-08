#ifndef INCLUDE_GUARD_33395315_5832_403C_B8CA_42B31798A324
#define INCLUDE_GUARD_33395315_5832_403C_B8CA_42B31798A324

#include <stdint.h>

class MMQueue {
    public:
        MMQueue();
        ~MMQueue();

    private:
        uint64_t data_size_;
        void *data_;
        int fd_;
};

#endif /* end of include guard */
