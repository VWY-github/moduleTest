
USE_MODULES=YES

CPP=g++-13
CPPFLAGS+=-std=c++23

CPPFLAGS+= -fmodules-ts -DUSE_MODULES -DMODULE_IF=export

INCS+=-I../classA
INCS+=-I../classB
INCS+=-I../classC
INCS+=-I../classD

HEADER_CLASSES+=../classA/Foo.h
HEADER_CLASSES+=../classB/Accumulator.h
HEADER_CLASSES+=../classC/MovingAverage.h
HEADER_CLASSES+=../classD/StringUtils.h


all: utilModule.o

utilModule.o:  utilModule.cpp $(HEADER_CLASSES)
	$(CPP) $(INCS) $(CPPFLAGS) -o $@ -c $<

clean:
	- @ rm -rf gcm.cache

distclean: clean
	- @ rm -f utilModule.o
