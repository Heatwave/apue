#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%1lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void *
thr_fn(void *arg)
{
    int i = 3;
    while (i--)
    {
        printids("new thread: ");
        printf("func thr_fn\n");
        sleep(1);
    }
    printf("thread exit!\n");
    return ((void *)0);
}

int main()
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
        printf("error!\n");
        //err_exit(err, "can't create thread");
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
        printf("error!\n");
        //err_exit(err, "can't create thread");
    printids("main thread:");
    sleep(5);
    printids("main thread:");
    printf("exit!\n");
    exit(0);
}

