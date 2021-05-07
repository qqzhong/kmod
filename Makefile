# /data/church/kernel/msm-5.4/scripts/Lindent
MAKE := make
NAME := hello-6
obj-m := $(NAME).o

#$(NAME)-y := start.o stop.o

all :
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

.PHONY : clean
clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
#	rm -f $(NAME).o
#	rm -f *.o
#	rm -f $(NAME).ko
#	rm -f $(NAME).mod
#	rm -f $(NAME).mod.c
#	rm -f $(NAME).mod.o
#	rm -f Module.symvers
#	rm -f modules.order
	rm -fr *~

