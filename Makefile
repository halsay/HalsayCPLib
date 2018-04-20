TOPDIR =$(shell pwd)
CXX = g++
CXXFLAGS+= -std=c++11 -Wall -g

CXXFLAGS += -I$(TOPDIR)/include

objs_list += src/test.o
objs_list += src/hcplibrary/os.o
objs_list += src/hcplibrary/dir.o

EXES = demo

all: $(EXES)

$(EXES) : $(objs_list)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	
clean: 
	$(RM) $(EXES)
	$(RM) $(objs_list)

