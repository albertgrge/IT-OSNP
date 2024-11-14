#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20];
    int i, k, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter the Burst Time & Priority of Process %d: ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sorting processes based on priority using bubble sort
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swapping priority, burst time, and process ID
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    // Initialize waiting time and turnaround time for the first process
    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = tat[0];

    // Calculate waiting time and turnaround time for each process
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display process details
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    // Display average waiting time and turnaround time
    printf("\nAverage Waiting Time is --- %.2f", wtavg / n);
    printf("\nAverage Turnaround Time is --- %.2f", tatavg / n);

    return 0;
}
