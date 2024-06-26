#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");					// * Important since it provides you access to other drivers with different licenses * 
MODULE_AUTHOR("Aditya Patil");				// Optional 
MODULE_DESCRIPTION("My first linux kernel driver");	// Optional

static struct proc_dir_entry *driver_proc_create;
struct proc_ops driver_proc_ops = {

};

static int driver_init(void) {
	printk("Started Driver Initialization\n");

	// driver_proc_create is a pointer by defination
	driver_proc_create = proc_create("aditya", 0, NULL, &driver_proc_ops);  
	
	printk("Executed the driver_proc_create function\n");

	// Error handling  
	if (driver_proc_create == NULL) {
		printk("Driver failed! Unable to create /proc file: EXITING\n");
		return -1; 
	}

	printk("Successfully created /proc file!\n");
	return 0;
}

static void driver_exit(void) {
	printk("Driver Exit function execution has been started\n");

	proc_remove(driver_proc_create);

	printk("Exiting the driver, bye bye\n");
}

module_init(driver_init);	// Macro, not a function (constructor)
module_exit(driver_exit);	// Macro, not a function (destructor)
