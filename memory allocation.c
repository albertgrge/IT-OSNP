#include <stdio.h>

// Bubble Sort function to sort memory blocks in ascending or descending order
void bubbleSort(int arr[], int n, int idx[], int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Swap the corresponding index
                int tempIdx = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = tempIdx;
            }
        }
    }
}

// First Fit Allocation
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

// Best Fit Allocation with Sorting
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    int sortedBlocks[m], index[m];
    for (int i = 0; i < m; i++) {
        sortedBlocks[i] = blockSize[i];
        index[i] = i;
    }

    // Sort blocks in ascending order for Best Fit
    bubbleSort(sortedBlocks, m, index, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sortedBlocks[j] >= processSize[i]) {
                allocation[i] = index[j];
                sortedBlocks[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nBest Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

// Worst Fit Allocation with Sorting
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    int sortedBlocks[m], index[m];
    for (int i = 0; i < m; i++) {
        sortedBlocks[i] = blockSize[i];
        index[i] = i;
    }

    // Sort blocks in descending order for Worst Fit
    bubbleSort(sortedBlocks, m, index, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sortedBlocks[j] >= processSize[i]) {
                allocation[i] = index[j];
                sortedBlocks[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nWorst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int blockSize[m], processSize[n];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Copy of blockSize array for each strategy
    int blockSizeFirstFit[m], blockSizeBestFit[m], blockSizeWorstFit[m];
    for (int i = 0; i < m; i++) {
        blockSizeFirstFit[i] = blockSize[i];
        blockSizeBestFit[i] = blockSize[i];
        blockSizeWorstFit[i] = blockSize[i];
    }

    firstFit(blockSizeFirstFit, m, processSize, n);
    bestFit(blockSizeBestFit, m, processSize, n);
    worstFit(blockSizeWorstFit, m, processSize, n);

    return 0;
}
