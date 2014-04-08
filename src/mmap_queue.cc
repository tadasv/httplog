#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "mmap_queue.hh"


MMQueue::MMQueue()
{
    fd_ = open("/tmp/test",
               O_CREAT | O_NOATIME | O_RDWR,
               S_IRUSR | S_IWUSR);

    data_size_ = 4096100000;
    if (ftruncate(fd_, data_size_) != 0) {
        perror("fruntcate");
        exit(-1);
    }
    data_ = mmap(NULL, data_size_, PROT_READ | PROT_WRITE, MAP_SHARED, fd_, 0);
    printf("map: %p\n", data_);
}


MMQueue::~MMQueue()
{
    munmap(data_, data_size_);
    close(fd_);
}


void MMQueue::Write(void *data, int size)
{
}
