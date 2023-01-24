
#include <linux/kernel.h>
#include <asm/current.h>
#include <asm-generic/errno-base.h>
#include <linux/sched.h>	
asmlinkage long  sys_set_task_params(int deadline,int estimated_run){
	struct task_struct * p;

	 deadline=deadline*1000;

    if(deadline<0){
        printk("Christos Fysarakis AM: 4068 , The deadline time is less than 0\n");
        return EINVAL;
    }
    if(estimated_run<0){
         printk("Christos Fysarakis AM: 4068 , The estimated_run  time is less than 0\n");
        return EINVAL;

    }
    if(estimated_run>deadline){
         printk("Christos Fysarakis AM: 4068 , The estimated_run  time is bigger than deadline\n");
         return EINVAL;
    }
	
	p=current;
	p->deadline=deadline/1000;
	
	p->estimated_runtime=estimated_run;
	printk(" Christos Fysarakis AM: 4068: The inserted values are : %d sec, %d ms. SUCCESS ",p->deadline,p->estimated_runtime);
    return 0;
    

 }
