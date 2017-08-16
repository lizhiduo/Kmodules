// Created Time:    2017-08-15 16:03:35
// Modified Time:   2017-08-16 10:36:50

#include <linux/module.h>
  
static int  __init  hello_init(void)
{  
    printk(KERN_INFO " Hello World enter\n");  
    return 0;  
}
  
static void  __exit  hello_exit(void) 
{  
    printk(KERN_INFO " Hello World exit\n ");  
}  
  
module_init(hello_init);  
module_exit(hello_exit);


MODULE_LICENSE("Dual BSD/GPL");     /*模块许可证明，描述内核模块的许可权限,必须*/ 
MODULE_DESCRIPTION("A simple Hello World Module"); /*模块说明，可选*/
MODULE_AUTHOR("lzd");

