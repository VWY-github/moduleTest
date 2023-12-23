
USE_MODULES=YES

CPP=g++-13
CPPFLAGS+=-std=c++23

ifeq (YES,$(USE_MODULES))
CPPFLAGS+= -fmodules-ts -DUSE_MODULES -DMODULE_IF=export
else
CPPFLAGS+=-DMODULE_IF=
endif

INCS+=-I../classA
INCS+=-I../classB
INCS+=-I../classC
INCS+=-I../classD

HEADER_CLASSES+=../classA/Foo.h
HEADER_CLASSES+=../classB/Accumulator.h
HEADER_CLASSES+=../classC/MovingAverage.h
HEADER_CLASSES+=../classD/StringUtils.h


all: testIt

ifeq (YES,$(USE_MODULES))
testIt: testIt.cpp utilModule.o
	$(CPP) $(CPPFLAGS) -o $@ $^

utilModule.o:  utilModule.cpp $(HEADER_CLASSES)
	$(CPP) $(INCS) $(CPPFLAGS) -o $@ -c $<
else
testIt: testIt.cpp
	$(CPP) $(CPPFLAGS) $(INCS) -o $@ $^
endif

run: testIt
	./$<

clean:
	- @ rm -rf gcm.cache

distclean: clean
	- @ rm -f utilModule.o
	- @ rm -f testIt
