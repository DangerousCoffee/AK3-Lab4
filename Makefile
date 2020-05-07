KDIR ?= /lib/modules/`uname -r`/build

default: build

hello1.o hello2.o &:
	$(MAKE) -C $(KDIR) M=$$PWD obj-m=$@ CFLAGS_$@=-I$$PWD/inc

build: hello1.o hello2.o

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
