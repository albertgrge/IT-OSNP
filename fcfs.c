#include <stdio.h>
void findwaitingtime(int process[],int n,int bt[],int at[],int wt[])
{
    int serv_time[n];
    serv_time[0]=at[0];
    wt[0]=0;
    for(int i=1;i<n;i++){
        serv_time[i]=serv_time[i-1]+bt[i-1];
        wt[i]=serv_time[i]- at[i];
        if (wt[i]<0)
        {
            wt[i]=0;
        }
        

    }
}
void findturnaroundtime(int process[],int n,int bt[],int wt[],int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i]=bt[i] + wt[i];
    }
    
}
void findaverageTime(int process[],int n,int bt[],int at[]){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    findwaitingtime(process,n,bt,at,wt);
    findturnaroundtime(process,n,bt,wt,tat);
    printf("process   arrivaltime  bursttime  waitingtime   turnaroundtime");
    for (int i = 0; i < n; i++)
    {
        total_wt+=wt[i];
        total_tat+=tat[i];
        printf("\n %d         %d         %d         %d              %d\n",
        process[i],at[i],bt[i],wt[i],tat[i]);


    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average waiting time = %.2f\n", avg_wt);
    printf("Average turnaround time = %.2f\n", avg_tat);
}

int main() {
    int processes[20], burst_time[20], arriving_time[20], nop;
    printf("Enter the number of processes: ");
    scanf("%d", &nop);

    printf("Enter the process IDs: ");
    for (int i = 0; i < nop; i++) {
        scanf("%d", &processes[i]);
    }

    printf("Enter the arrival times: ");
    for (int i = 0; i < nop; i++) {
        scanf("%d", &arriving_time[i]);
    }
      printf("Enter the burst times: ");
    for (int i = 0; i < nop; i++) {
        scanf("%d", &burst_time[i]);
    }

    findaverageTime(processes, nop, burst_time, arriving_time);
    return 0;
}

