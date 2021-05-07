/*  start.c - Illustration of multi filed modules
 */

#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/module.h>	/* Specifically, a module */

int init_module(void)
{
	printk("Hello, world - this is the kernel speaking\n");
	return 0;
}

MODULE_LICENSE("GPL");

// CC=gcc
// MODCFLAGS := -O -Wall -DMODULE -D__KERNEL__
//
// hello.o:     hello2_start.o hello2_stop.o
//    ld -m elf_i386 -r -o hello2.o hello2_start.o hello2_stop.o
//
// start.o: hello2_start.c
//    ${CC} ${MODCFLAGS} -c hello2_start.c
//
// stop.o: hello2_stop.c
//    ${CC} ${MODCFLAGS} -c hello2_stop.c
