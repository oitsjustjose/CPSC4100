SHEDSKIN_LIBDIR=/Library/Python/2.7/site-packages/shedskin/lib
CC=g++
CCFLAGS=-O2 -Wno-deprecated $(CPPFLAGS) -I. -I${SHEDSKIN_LIBDIR} -I/usr/local/include
LFLAGS=-lgc -lpcre $(LDFLAGS) -L/usr/local/lib

CPPFILES=/Users/jose/Documents/GitHub/CPSC4100/c++/group_proj.cpp \
	${SHEDSKIN_LIBDIR}/sys.cpp \
	${SHEDSKIN_LIBDIR}/stat.cpp \
	${SHEDSKIN_LIBDIR}/re.cpp \
	${SHEDSKIN_LIBDIR}/os/path.cpp \
	${SHEDSKIN_LIBDIR}/os/__init__.cpp \
	${SHEDSKIN_LIBDIR}/builtin.cpp

HPPFILES=/Users/jose/Documents/GitHub/CPSC4100/c++/group_proj.hpp \
	${SHEDSKIN_LIBDIR}/sys.hpp \
	${SHEDSKIN_LIBDIR}/stat.hpp \
	${SHEDSKIN_LIBDIR}/re.hpp \
	${SHEDSKIN_LIBDIR}/os/path.hpp \
	${SHEDSKIN_LIBDIR}/os/__init__.hpp \
	${SHEDSKIN_LIBDIR}/builtin.hpp

all:	group_proj

group_proj:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o group_proj

group_proj_prof:	$(CPPFILES) $(HPPFILES)
	$(CC) -pg -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o group_proj_prof

group_proj_debug:	$(CPPFILES) $(HPPFILES)
	$(CC) -g -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o group_proj_debug

clean:
	rm -f group_proj group_proj_prof group_proj_debug

.PHONY: all clean

