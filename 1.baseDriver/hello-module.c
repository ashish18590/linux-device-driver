#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


static int __init helloworld_init(void)
{
	pr_info("Info : helloworld driver init function\n");
	return 0;
}

static void __exit helloworld_exit(void)
{
	pr_info("Info : helloworld driver exit function");
}


module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_AUTHOR("Ashish Dahiya <ashish18590@gmail.com>");
MODULE_LICENSE("GPL");

