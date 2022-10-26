/**
 * @file memory_order.c
 * @author wangguibao(wang_guibao@163.com)
 * @date 2020/09/08 17:03:18
 * @brief A demo showing that unrelated instructions can be reordered, causing surprising results
 * 
 * Run the program with below command:
 * for i in `seq 0 10000`; do ./memory_order; done | grep 'r1 = 0, r2 = 0'     
 *
 * This is no C++, of course
 **/

#include <stdio.h>
#include <pthread.h>

int x = 0;
int y = 0;

int r1 = 0;
int r2 = 0;

void* thread1(void *arg)
{
    x = 1;
    r1 = y;
}

void* thread2(void *arg)
{
    y = 1;
    r2 = x;
}

int main()
{
    pthread_t th1;
    pthread_t th2;


    int ret = pthread_create(&th1, NULL, thread1, NULL);
    if (ret != 0) {
        printf("pthread_create th1 fail\n");
        return -1;
    }

    ret = pthread_create(&th2, NULL, thread2, NULL);
    if (ret != 0) {
        printf("pthread_create th2 fail\n");
        return -1;
    }

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("r1 = %d, r2 = %d\n", r1, r2);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
