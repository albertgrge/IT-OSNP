#include <stdio.h>
#include <limits.h>


void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i]; 

    int t = 0; 
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; 

                if (rem_bt[i] > quantum) {
                    
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i]; 
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break; 
    }
}


void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i]; 
}


void findAverageTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    
    findWaitingTime(processes, n, bt, wt, quantum);

   
    findTurnaroundTime(processes, n, bt, wt, tat);

    
    printf("Process Burst Time Waiting Time Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d %d %d %d\n", processes[i], bt[i], wt[i], tat[i]);
    }


    float average_wt = (float)total_wt / n;
    float average_tat = (float)total_tat / n;
    printf("Average Waiting Time: %.2f\n", average_wt);
    printf("Average Turnaround Time: %.2f\n", average_tat);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n];
    int quantum;

    
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1; 
    }

    printf("Enter the arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("arival time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1;
        }	 
   
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

   
    findAverageTime(processes, n, bt, quantum);

    return 0;
}

