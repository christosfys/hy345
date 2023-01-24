#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *print_Hello(void *ptr)
{
    printf("hello");
}
void *print_World(void *ptr)
{
    printf("world");
}
int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int rc, rc2;
    rc = pthread_create(&t1, NULL, print_Hello, NULL);
    if (rc)
    {
        printf("ERROR: return code from pthread_create() is %d\n",rc);
        exit(-1);
    }
    rc2 = pthread_create(&t2, NULL, print_World, NULL);
    if (rc2)
    {
        printf("ERROR: return code from pthread_create() is %d\n",rc);
        exit(-1);
    }
    pthread_join(t1, NULL); /*Wait for the thread to finish*/
    pthread_join(t2, NULL);
}