TOP=  .
include ${TOP}/Makefile.config
  
PROG= freeutox

CFLAGS = $(shell pkg-config --cflags freetype2 x11 xft openal dbus-1)
CFLAGS += -g -pthread -std=gnu99
LDFLAGS = $(shell pkg-config --libs freetype2 x11 xft openal dbus-1)
LDFLAGS += -lX11 -lXft -lXrender -ltoxcore -ltoxav -ltoxdns -lopenal -pthread -lresolv -ldl -lm -lfontconfig -lv4lconvert -lvpx -lXext

DESTDIR=/usr/local

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: config-ok ${PROG}

config-ok:
	@if [ "${CONFIGURE_OK}" != "yes" ]; then \
	    echo "Please run ./configure first"; \
	    exit 1; \
	fi

install: ${PROG}
	mkdir -pv $(DESTDIR)/bin
	install -m 0755 ${PROG} $(DESTDIR)/bin

main.o: xlib/main.c xlib/keysym2ucs.c

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ${PROG} *.o

.PHONY: all clean

include ${TOP}/mk/build.prog.mk
