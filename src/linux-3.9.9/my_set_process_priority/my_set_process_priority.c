#include <linux/sched.h>

asmlinkage int my_set_process_priority(int x) {
    if (!(x >= 101 && x <= 139)) {
        return 0;
    }

    struct task_struct *p = current;
    
    printk("\norignal:\n");
    printk("pid: %d\n", p->pid);
    printk("x: %d\n", x);
    printk("p->my_fixed_priority: %d\n", p->my_fixed_priority);
    printk("p->static_prio: %d\n", p->static_prio);

    p->my_fixed_priority = x;
    
    printk("\nafter:\n");
    printk("p->my_fixed_priority: %d\n", p->my_fixed_priority);
    
    return 1;
}
