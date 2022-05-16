#include <stdio.h>
#include <unistd.h>

int main()
{
    int n, i, even_sum = 0, odd_sum=0, pid;
    printf("Enter value of n: ");
    scanf("%d",&n);
    pid = fork();
    if(pid == 0)
    {
        //child process
        for(i=1; i<=n; i++)
            odd_sum += 2*i-1;
        printf("Sum of n odd natural numbers: %d\n",odd_sum);
    }
    else
    {
        //parent process
        sleep(1);
        for(i=1; i<=n; i++)
            even_sum += 2*i;
        printf("Sum of n even natural numbers: %d",even_sum);
    }
    return 0;
}
