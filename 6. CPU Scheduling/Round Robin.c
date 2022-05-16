#include<stdio.h>
struct process
{
    int id,AT,BT,CT,WT,TAT;
}a[10];

// declaration of the ready queue
int queue[100],front=-1,rear=-1;

// function for insert the element into queue
void insert(int n)
{
    if(front==-1)
     front=0;
    rear=rear+1;
    queue[rear]=n;
}

// function for delete the element from queue
int delete()
{
    int n;
    n=queue[front];
    front=front+1;
    return n;
}
int main()
{
    int n,TQ,p,TIME=0;
    int temp[10],exist[10]={0};
    float total_wt=0,total_tat=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process: ");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of the process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].AT,&a[i].BT);
        a[i].id=i;
        temp[i]=a[i].BT;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&TQ);
    // logic for round robin scheduling
    
    // insert first process into ready queue
    insert(0);
    exist[0]=1;
    // until ready queue is empty
    while(front<=rear)
    {
        p=delete();
        if(a[p].BT>=TQ)
        {
            a[p].BT=a[p].BT-TQ;
            TIME=TIME+TQ;
        }
        else
        {
            TIME=TIME+a[p].BT;
            a[p].BT=0;
        }
        
        //if process is not exist in the ready queue even a single 
        // time then insert it if it arrive at time 'TIME'
        for(int i=0;i<n;i++)
        {
            if(exist[i]==0 && a[i].AT<=TIME)
            {
                insert(i);
                exist[i]=1;
            }
        }
        // if process is completed
        if(a[p].BT==0)
        {
            a[p].CT = TIME;
            a[p].TAT=TIME-a[p].AT;
            a[p].WT=a[p].TAT-temp[p];
            total_tat=total_tat+a[p].TAT;
            total_wt=total_wt+a[p].WT;
        }
        else
        {
            insert(p);
        }
    }
    
    Avg_TAT=total_tat/n;
    Avg_WT=total_wt/n;
    
    // printing of the answer
    printf("PId\tBT\tAT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,temp[i],a[i].AT,a[i].CT,a[i].TAT,a[i].WT);
    printf("Average waiting time of the processes is : %.3f\n",Avg_WT);
    printf("Average turn around time of the processes is : %.3f\n",Avg_TAT);
    return 0;
}
