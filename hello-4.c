/*  hello-4.c - Demonstrates module documentation.
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#define DRIVER_AUTHOR "Peiter Jay Salzman <p@dirac.org>"
#define DRIVER_DESC   "A sample driver"

int init_hello_3(void);
void cleanup_hello_3(void);

static int init_hello_4(void)
{
	printk(KERN_ALERT "Hello, world 4\n");
	return 0;
}

static void cleanup_hello_4(void)
{
	printk(KERN_ALERT "Goodbye, world 4\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

/*  You can use strings, like this:
 */
MODULE_LICENSE("GPL");		// Get rid of taint message by declaring code as GPL.

/*  Or with defines, like this:
 */
MODULE_AUTHOR(DRIVER_AUTHOR);	// Who wrote this module?
MODULE_DESCRIPTION(DRIVER_DESC);	// What does this module do?

/*  This module uses /dev/testdevice.  The MODULE_SUPPORTED_DEVICE macro might be used in
 *  the future to help automatic configuration of modules, but is currently unused other
 *  than for documentation purposes.
 */
MODULE_SUPPORTED_DEVICE("testdevice");
