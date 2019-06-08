#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


struct student {
	int rollno;
	char name[20];
	int marks;
};





static int __init helloworld_init(void)
{
	struct student stu1={10,"ashish",71},*stu1Ptr;
	pr_info("Info : container of  usecase init function\n");
	stu1Ptr=container_of(&stu1.marks,struct student,marks);
	pr_info("Info : Studnt Name : %s \n", stu1Ptr->name);
	pr_info("Info : Studnt rollno : %d \n", stu1Ptr->rollno);
	pr_info("Info : Studnt marks : %d \n", stu1Ptr->marks);
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

