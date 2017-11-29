/*************************************************************************
	> File Name: pthrd_crt.c
	> Author: 
	> Mail: 
    > Main:循环创建多个线程，并打印线程ID
	> Created Time: 2017年09月02日 星期六 22时45分13秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<sched.h>

void *pthrd_fun(void *arg)
{
    while(1);
}
int main()
{
    pthread_t tid;
    int ret;
    int i = 0;
    
    //修改线程的调度策略与优先级
    struct sched_param param;
    param.sched_priority = 99;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_attr_setschedpolicy(&attr,SCHED_FIFO);
    pthread_attr_setschedparam(&attr,&param);

    for(i = 0;i<=50;i++)
    {
        ret = pthread_create(&tid,&attr,pthrd_fun,NULL);
    }
    if(ret != 0)
    {
        fprintf(stderr,"pthread create error: %s\n",strerror(ret));
        exit(1);
    }

    while(1);

    return 0;
}
