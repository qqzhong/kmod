/*  stop.c - Illustration of multi filed modules
 */

#if defined(CONFIG_MODVERSIONS) && ! defined(MODVERSIONS)
#include <linux/modversions.h>	/* Will be explained later */
#define MODVERSIONS
#endif
#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/module.h>	/* Specifically, a module  */

//In all the source files but one, add the line #define __NO_VERSION__.
// This is important because module.h normally includes the definition of kernel_version,
// a global variable with the kernel version the module is compiled for.
// If you need version.h, you need to include it yourself, because module.h won't do it for you with __NO_VERSION__.
#define __NO_VERSION__		/* It's not THE file of the kernel module */
#include <linux/version.h>	/* Not included by module.h because of  __NO_VERSION__ */

void cleanup_module()
{
	printk("<1>Short is the life of a kernel module\n");
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
