
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


int main(void){
    printf("Enter kernel system \n");
    
    long t=set_param(1,-2);
    long expect=set_param(2,6);
    long s=set_param(3,1000);
    struct d_params *params=malloc(sizeof(struct d_params));
    long d=get_param(NULL);
    long f=get_param(params);
    printf("First call expected 22 \n");
    printf("Get %ld\n",t);
    printf("Expeected 0 Take %ld\n",s);
    printf("Expected 22 Take= %ld",expect);
    printf(" Expected 22 Take %ld\n",d);
    printf("Expected 0 Take %ld\n",f);
    printf("END");
    return 0;
}