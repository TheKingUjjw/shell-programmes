#include <stdio.h>
#include <stdlib.h>

typedef struct MemoryBlock
{
    int id;
    int size;
} MemoryBlock;

typedef struct MemoryManager
{
    MemoryBlock b;
    struct MemoryManager *llink, *rlink;
} MemoryManager;

MemoryBlock worst_fit(MemoryManager *m, int memory)
{
    MemoryBlock bl;
    if (m == NULL)
    {
        bl.id = -1;
        bl.size = -1;
    }
    else
    {
        MemoryManager *ptr =m,*ptr1, *ptr2, *p;
        MemoryBlock worst;
        worst.id = -1;
        worst.size = -1;
        while (ptr != NULL)
        {
            if (ptr->b.size >= memory && ptr->b.size > worst.size)
            {
                worst.id = ptr->b.id;
                worst.size = ptr->b.size;
            }
            ptr = ptr->rlink;
        }
        bl = worst;
        ptr = m;
        while (ptr != NULL)
        {
            if (ptr->b.id == worst.id)
            {
                ptr->b.size = 0;
                break;
            }
            ptr = ptr->rlink;
        }
    }
    return bl;
}
void deallocate(MemoryManager *m, MemoryBlock memory)
{
    MemoryManager *ptr = m;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }
    MemoryManager *n = malloc(sizeof(MemoryManager));
    n->b = memory;
    ptr->rlink = n;
    n->llink = ptr;
    n->rlink = NULL;
}

int main()
{
    MemoryManager *m = (MemoryManager *)malloc(sizeof(MemoryManager));
    int n, np;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter the size of the blocks: ");
    for (int i = 0; i < n; i++)
    {
        int memory;
        scanf("%d", &memory);
        MemoryBlock *block = (MemoryBlock *)malloc(sizeof(MemoryBlock));
        block->id = i + 1;
        block->size = memory;
        deallocate(m, *block);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    int process[np];
    printf("Enter the required memory for : \n");
    for (int i = 0; i < np; i++)
    {
        printf("P%d - ", i + 1);
        scanf("%d", &process[i]);
    }

    printf("\n\t\tWORST FIT ALLOCATION\n====================================================\n");
    printf("Process id    Process size\tBlock id    Block Size\n");
    for (int i = 0; i < np; i++)
    {
        MemoryBlock block;
        block = worst_fit(m, process[i]);
        printf("    %d\t\t%d\t\t", i + 1, process[i]);
        if (block.id == -1)
        {
            printf("    Nil\t\t-\n");
        }
        else
        {
            printf("    %d\t\t%d\n", block.id, block.size);
        }
    }
    return 0;
}
