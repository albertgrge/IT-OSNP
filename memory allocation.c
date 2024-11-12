#include <stdio.h>
#define MAX 10

int main() {
    int blocksize[MAX], processsize[MAX];
    int allocation[MAX];
    int blocksizecopy[MAX];
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocksize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processsize[i]);
    }

    for (int i = 0; i < m; i++)
        blocksizecopy[i] = blocksize[i];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocksizecopy[j] >= processsize[i]) {
                allocation[i] = j;
                blocksizecopy[j] -= processsize[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT ALLOCATION:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processsize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not allocated\n");
    }

    
    for (int i = 0; i < m; i++)
        blocksizecopy[i] = blocksize[i];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestidx = -1;
        for (int j = 0; j < m; j++) {
            if (blocksizecopy[j] >= processsize[i]) {
                if (bestidx == -1 || blocksizecopy[j] < blocksizecopy[bestidx]) {
                    bestidx = j;
                }
            }
        }
        if (bestidx != -1) {
            allocation[i] = bestidx;
            blocksizecopy[bestidx] -= processsize[i];
        }
    }

    printf("\nBEST FIT ALLOCATION:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processsize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not allocated\n");
    }

   
    for (int i = 0; i < m; i++)
        blocksizecopy[i] = blocksize[i];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstidx = -1;
        for (int j = 0; j < m; j++) {
            if (blocksizecopy[j] >= processsize[i]) {
                if (worstidx == -1 || blocksizecopy[j] > blocksizecopy[worstidx]) {
                    worstidx = j;
                }
            }
        }

        if (worstidx != -1) {
            allocation[i] = worstidx;
            blocksizecopy[worstidx] -= processsize[i];
        }
    }

    printf("\nWORST FIT ALLOCATION:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processsize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not allocated\n");
    }

    return 0;
}

