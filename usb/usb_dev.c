//*************************************************************************
//	> File Name: usb_dev.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月09日 星期日 11时27分28秒
//************************************************************************
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

static int dnw_probe(struct usb_interface *intf, const struct usb_device_id *id){

    struct usb_host_interface *interface;
    struct usb_endpoint_descriptor *endpoint;
    int i;
    
    printk("%s is runing...\n", __func__);
    /* 接口设置描述 */
    interface = intf->cur_altsetting;
     
        
    printk("num %d\n", interface->desc.bNumEndpoints);

    for(i=0;i<interface->desc.bNumEndpoints;i++)
    {
        endpoint = &interface->endpoint[i].desc;
        printk(" attr: %x \n", endpoint-> bmAttributes);   
    }

    return 0;
}

static void dnw_disconnect(struct usb_interface *intf)
{
    printk("%s is runing...\n", __func__);
//    usb_deregister_dev(intf,&dnw_class);

}

static struct usb_device_id dnw_id_table [] = {
        { USB_DEVICE(0x2717, 0xff48)  },
        {  }

};

struct usb_driver dnw_driver = {
    .name= "dnw",   /* 驱动名 */
    .probe= dnw_probe, /* 捕获函数 */
    .disconnect= dnw_disconnect, /* 卸载函数 */
    .id_table= dnw_id_table, /* 设备列表 */

};


static int __init dnw_init(void){
    printk("%s is runing...\n", __func__);
    usb_register(&dnw_driver);
    return 0;
}

void __exit dnw_exit(void){
    printk("%s is runing...\n", __func__);
    usb_deregister(&dnw_driver);
}

module_init(dnw_init);
module_exit(dnw_exit);
MODULE_LICENSE("GPL");

