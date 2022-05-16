// First Come First Serve - Non Preemptive
#include<stdio.h>
struct process
{
    int WT,TT,BT,CT;
};

struct process a[10];
int main()
{
    int n,i,burst=0,cmpl_T;
    float Avg_WT,Avg_TT,Total=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("Enter Burst time of the process\nBT\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i].BT);
    
    // Logic for calculating Waiting time
    for(i=0;i<n;i++)
    {
        if(i==0)
            a[i].WT=0;
        else
            a[i].WT=burst;
        burst+=a[i].BT;
        Total+=a[i].WT;
    }
    Avg_WT=Total/n;
    
    // Logic for calculating Turn around  time
    cmpl_T=0;
    Total=0;
    for(int i=0;i<n;i++)
    {
        cmpl_T+=a[i].BT;
        a[i].CT=cmpl_T;
        a[i].TT=a[i].CT;
        Total+=a[i].TT;
    }
    Avg_TT=Total/n;
    
    // printing of outputs
    
    printf("Process ,  Burst_time   Compl_time ,  TurnA_time ,  Waiting_time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i].BT,a[i].CT,a[i].TT,a[i].WT);
    }
    printf("Average waiting time is : %.3f\n",Avg_WT);
    printf("Average turn around time is : %.3f\n",Avg_TT);
    return 0;
}

