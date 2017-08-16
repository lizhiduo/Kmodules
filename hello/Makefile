obj-m := hello.o

KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -f  *.mod.c *.mod.o *.o *.order *.symvers

distclean:
	rm -f *.ko *.mod.c *.mod.o *.o *.order *.symvers

