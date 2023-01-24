
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/dparams.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/current.h>
#include <asm-generic/errno-base.h>


asmlinkage long sys_get_task_param(struct d_params * params)
{    
	

	if(params==NULL){
        printk("Christos Fysarakis AM 4068 NULL PARAMETER\n");
        return EINVAL;
    }
    
	struct task_struct * p;
		p=current;
	if(copy_to_user(&(params->deadline),&(p->deadline),sizeof(int))==0 && copy_to_user(&(params->estimated_runtime),&(p->estimated_runtime),sizeof(int))==0){   	
        printk("Christos Fysarakis AM 4068 The copied values is %d %d . SUCCESS\n ",params->deadline,params->estimated_runtime);
	return 0;

	}else{
	return EINVAL;
 	}



    
}   




