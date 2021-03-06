#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

extern struct bus_type my_bus_type;

struct device my_dev = {
     .init_name = "my_dev",
     .bus = &my_bus_type,	
};

static int __init my_device_init(void)
{
	int ret;
     ret = device_register(&my_dev);
     return ret;
     
}


static void __exit my_device_exit(void)
{
	device_unregister(&my_dev);
}

module_init(my_device_init);
module_exit(my_device_exit);
