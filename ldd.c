// #include <linux/init.h>
// #include <linux/module.h>
// #include <linux/proc_fs.h>

// MODULE_LICENSE("GPL");					// * Important since it provides you access to other drivers with different licenses * 
// MODULE_AUTHOR("Aditya Patil");				// Optional 
// MODULE_DESCRIPTION("My first linux kernel driver");	// Optional

#include "ldd.h"

// Detect writing in the proc file 
static ssize_t driver_proc_write(struct file* file_pointer, const char __user *user_buffer, size_t count, loff_t* offset) {
	printk("Write Operation Detected\n");

	char* kernel_buffer;

	kernel_buffer = kmalloc(count + 1, GFP_KERNEL);

	if (!kernel_buffer) {
		printk("Memory allocation for character buffer failed!");
		return -ENOMEM;
	}

	if (copy_from_user(kernel_buffer, user_buffer, count)) {
		kfree(kernel_buffer);
		return -EFAULT;
	}

	kernel_buffer[count] = '\0';

	printk(KERN_INFO "Content: %s\n", kernel_buffer);

	kfree(kernel_buffer);

	return count;
}

// Detect reading in the proc file 
static ssize_t driver_proc_read(struct file* file_pointer, char *user_space_buffer, size_t count, loff_t* offset) {
	printk("Read Operation Detected\n");
	return 0;
}

// Create a directory enrty in proc 
static struct proc_dir_entry *driver_proc_create;

// proc operations in the driver 
struct proc_ops driver_proc_ops = {
	.proc_read = driver_proc_read,
	.proc_write = driver_proc_write,
};

// Init Driver function
static int __init driver_init(void) {
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

// Exit Driver function
static void __exit driver_exit(void) {
	printk("Driver Exit function execution has been started\n");

	proc_remove(driver_proc_create);

	printk("Exiting the driver, bye bye\n");
}

module_init(driver_init);	// Macro, not a function (constructor)
module_exit(driver_exit);	// Macro, not a function (destructor)
