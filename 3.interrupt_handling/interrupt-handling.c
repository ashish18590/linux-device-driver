#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>


static int irq_line = 129, my_device_id, irq_counter = 0;


static irqreturn_t my_interrupt_handler(int irq, void *dev_id) {
	pr_info("Got Interrupt on wifi network card : %d \n", ++irq_counter);
	return IRQ_HANDLED;
}



static int __init helloworld_init(void)
{
	int ret;
	pr_info("Info : helloworld driver init function\n");
	ret = request_irq(irq_line, my_interrupt_handler, IRQF_SHARED, "ashish-interrupt-handler", &my_device_id);
	pr_info("Request_irq return value : %d \n", ret);
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

