//*************************************************************************
//	> File Name: hello.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月09日 星期日 11时55分10秒
//************************************************************************
#include<linux/init.h>
#include<linux/module.h>

static int __init hello_init(void)
{
        printk(KERN_ALERT "Hello world!\n");
        return 0;

}

static void __exit hello_exit(void)
{
        printk(KERN_ALERT "Goodbye,cruel world!");

}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("LZD");
