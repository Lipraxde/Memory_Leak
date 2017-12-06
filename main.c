#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
 
void *test(void *p)
{
    assert(pthread_detach(pthread_self())==0);
    free(p);			// 再thread裡面free會漸漸使記憶體用量變大
    p = 0;
    pthread_exit(NULL);
}
 
int main(int argc, char *argv[])
{
    pthread_t tid;
    void *p = NULL;
 
    for(int i=0;i<10;i++)
    {
        p = malloc(8*1024*1024);
        assert(p!=NULL);
        // printf("Pointer p = %p\n", p);	// print出來的記憶體位置有重複，應該是free成功
        assert(pthread_create(&tid, NULL, test, p)==0);
        p = 0;
        // assert(pthread_join(tid, NULL)==0);	// 等thread結束後再free就不會吃記憶體
        // free(p);
        // sleep(1);
        // printf("\n===========================\n");
        // malloc_stats();
    }
 
    // sleep(1);
    // printf("\n===========================\n");
    // malloc_stats();
    printf("Finish.\n");
    return 0;
}
