#include <stdio.h>
int main()
{
int arriving_time[10],burst_time[10],temp[10];
int i,smallest,count=0,time,limit;
double waittime=0,turnaroundtime=0,end;
float avg_waiting_time,avg_turnaround_time;
printf("Enter total number of process:\t");
scanf("%d",&limit);
printf("Enter the details for %d process:",limit);
for(i=0;i<limit;i++)
{
printf("\nEnter arrival time:\t");
scanf("%d",&arriving_time[i]);
printf("Enter burst time:\t");
scanf("%d",&burst_time[i]);
temp[i]=burst_time[i];
}
burst_time[9]=9999;
for(time=0;count!=limit;time++)
{
smallest=9;
for(i=0;i<limit;i++)
{
if(arriving_time[i]<=time&&burst_time[i]<burst_time[smallest]&&burst_time[i]>0)
{
smallest=i;
}
}
burst_time[smallest]--;
if(burst_time[smallest]==0)
{
count++;
end=time+1;
waittime=waittime+end-arriving_time[smallest]-temp[smallest];
turnaroundtime=turnaroundtime+end-arriving_time[smallest];
}
}
avg_waiting_time=waittime/limit;
avg_turnaround_time=turnaroundtime/limit;
printf("\n\nAverage waiting time:\t%f\n",avg_waiting_time);
printf("\n\nAverage turnaround time:\t%f\n",avg_turnaround_time);
return 0;
}



