
obj-m := hello.o

KDIR := /usr/src/linux-headers-4.8.0-58-generic/

PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean



