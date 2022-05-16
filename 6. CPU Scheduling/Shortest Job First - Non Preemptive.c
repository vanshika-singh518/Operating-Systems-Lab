#include<stdio.h>
struct process
{
    int WT,BT,TAT;
}a[10];


void main()
{
    int p[10],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&a[i].BT);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j].BT<a[pos].BT)
                pos=j;
        }
 
        temp=a[i].BT;
        a[i].BT=a[pos].BT;
        a[pos].BT=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    a[0].WT=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        a[i].WT=0;
        for(j=0;j<i;j++)
            a[i].WT+=a[j].BT;
 
        total+=a[i].WT;
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 
    printf("Id\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        a[i].TAT=a[i].BT+a[i].WT;     //calculate turnaround time
        total+=a[i].TAT;
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],a[i].BT,a[i].TAT,a[i].TAT,a[i].WT);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%.3f",avg_wt);
    printf("\nAverage Turnaround Time=%.3f\n",avg_tat);
}

