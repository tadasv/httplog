httplog_CXXFLAGS = -I$(top_srcdir)/src
httplog_CFLAGS = -I$(top_srcdir)/src

bin_PROGRAMS = httplog

httplog_SOURCES = main.cc \
                  util.hh \
                  mmap_queue.hh \
                  mmap_queue.cc \
                  user_data.h \
                  http_server.hh \
                  http_server.cc \
                  handlers.h \
                  handler/shutdown.cc \
                  handler/ping.cc
