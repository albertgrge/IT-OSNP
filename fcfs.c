#include <stdio.h>
void findWaitingTime(int processes[],int n,int bt[],int wt[],int at[])
{
wt[0]=0;
for(int i=1;i<n;i++)
  wt[i]=bt[i-1]+wt[i-1];
  for(int i=1;i<n;i++)
  {
  wt[i]-=at[i];
  }
  }
  void findTurnAroundtime(int processes[],int n,int bt[],int wt[],int tat[])
  {
  for(int i=0;i<n;i++)
  tat[i]=bt[i]+wt[i];
  }
  void findAveragetime(int processes[],int n,int bt[],int arriving_time[])
 {
  int wt[n],tat[n],total_wt=0,total_tat=0;
  findWaitingTime(processes,n,bt,wt,arriving_time);
  findTurnAroundtime(processes,n,bt,wt,tat);
  printf("Process    Arrivingtime   Bursttime    Waitingtime   Turnroundtime\n");
  for(int i=0;i<n;i++)
  {
  total_wt=total_wt+wt[i];
  total_tat=total_tat+tat[i];
  printf("     %d",processes[i]);
  printf("         %d",arriving_time[i]);
  printf("            %d",bt[i]);
  printf("              %d",wt[i]);
  printf("                 %d\n",tat[i]);
  }
  float s=(float)total_wt/(float)n;
  float t=(float)total_tat/(float)n;
  printf("Average wating time=%f",s);
  printf("\n");
  printf("Average turnaround time=%f",t);
  }
  int main()
  {
  int processes[20],burst_time[20], arriving_time[20], nop;
  printf("Enter the number of process:");
  scanf("%d",&nop);
  printf("Enter the %d process",nop);
  for(int i=0;i<nop;i++)
  {
  scanf("%d",&processes[i]);
  }
  printf("Enter %d Arriving time:",nop);
  for(int i=0;i<nop;i++)
  {
  scanf("%d",&arriving_time[i]);
  }
  printf("Enter %d burst time:",nop);
  for(int i=0;i<nop;i++)
  {
  scanf("%d",&burst_time[i]);
  }
  findAveragetime(processes,nop,burst_time,arriving_time);
  return 0;
  }
  
  
  
                                                                                                                                                                                              

