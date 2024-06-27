obj-m += ldd.o 
SHELL = /bin/bash

all: ldd.c ldd.h
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean: ldd.ko
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
