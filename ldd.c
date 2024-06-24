#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");					// * Important since it provides you access to other drivers with different licenses * 
MODULE_AUTHOR("Aditya Patil");				// Optional 
MODULE_DESCRIPTION("My first linux kernel driver");	// Optional

static int driver_init(void) {
	printk("Driver has been activated!\n");
	return 0;
}

static void driver_exit(void) {
	printk("Exiting Linux Kernel!\n");
}

module_init(driver_init);	// Macro, not a function (constructor)
module_exit(driver_exit);	// Macro, not a function (destructor)
