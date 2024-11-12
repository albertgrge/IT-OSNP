#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	printf("enter the number of processes: ");
	scanf("%d",&n);
	printf("enter the number of resource types: ");
	scanf("%d",&m);
	int alloc[n][m],max[n][m],avail[m],need[n][m],f[n],ans[n],ind=0;
	printf("enter the allocation matrix:\n ");
	for(i=0;i<n;i++)
	{
		printf("process%d:",i+1);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter the maximum matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("process%d:",i+1);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
		
	}
	printf("enter the rcousrce available :\n ");
	for(j=0;j<m;j++)
	{
		scanf("%d",&avail[j]);
	}
	for(k=0;k<n;k++)
	{
		f[k]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("\n the need matrix is:\n");
	for(i=0;i<n;i++)
	{
		printf("process%d:",i+1);
		for(j=0;j<m;j++)
		{
			printf("%d",need[i][j]);
		}
		printf("\n");
	}
	int y=0;
	for(k=0;k<m;k++)
	{
		for(j=i;i<m;i++)
		{
			if(f[i]==0)
			{	
				int flag=0;
				for(j=0;j<m;j++)
				{
					if(need[i][j]>avail[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					if(need[i][j]>avail[j])
					{
					flag=1;
					break;
					}
				}
				if(flag==0)
				{
					ans[ind++]=i;
					for(y=0;y<m;y++){
					avail[y]+=alloc[i][y];
				}
				f[i]=1;
				}
			}
		}
	}
	int flag=1;
	for(i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			flag=0;
			printf("\n the system is not in safe state.\n");
			break;
		}
	}
		if(flag==1)
	{
		printf("\n the system is in safe state.\n");
		for(i=0;i<n-1;i++)
		{
			printf("P%d->",ans[i]);
		}
		printf("P%d\n",ans[n-1]);
	}
}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
