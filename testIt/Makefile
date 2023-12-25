

CPP=g++-13
CPPFLAGS+=-std=c++23

MODULE_DIR=../utilModule
MODULE_NAME=utilModule
MY_MODULE=$(MODULE_DIR)/$(MODULE_NAME).o

MODULE_MAPPER_FILE=utilModuleMapper

CPPFLAGS+= -fmodules-ts -DUSE_MODULES=YES -DMODULE_IF=export
CPPFLAGS+= -fmodule-mapper=$(MODULE_MAPPER_FILE)

all: makeMapperFile testIt


########################################
# need  a module mapping file
# using relative path to compiled module
# these absolute paths work also:
#	A) echo $(MODULE_NAME) `readlink -f $(MODULE_DIR)/gcm.cache/$(MODULE_NAME).gcm` > $(MODULE_MAPPER_FILE)
#	B) $(shell printf "%s %s\n" ${MODULE_NAME} "`readlink -f ${MODULE_DIR}/gcm.cache/${MODULE_NAME}.gcm`" > ${MODULE_MAPPER_FILE})
########################################
.PHONY: makeMapperFile
makeMapperFile:
	- @ rm -f $(MODULE_MAPPER_FILE)
	@ echo $(MODULE_NAME) $(MODULE_DIR)/gcm.cache/$(MODULE_NAME).gcm > $(MODULE_MAPPER_FILE)

testIt: testIt.cpp
	$(CPP) $(CPPFLAGS) -o $@ $< $(MY_MODULE)

run: testIt
	./$<

distclean:
	- @ rm -f testIt
	- @ rm -f $(MODULE_MAPPER_FILE)
