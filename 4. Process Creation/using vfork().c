#include <stdio.h>
#include <unistd.h>

int main()
{
    int a = 5,b = 10,pid;
    printf("Before fork a=%d, b=%d\n",a,b);
    pid = fork();
    if(pid == 1)
    {
        a++;
        b++;
        printf("In child, a=%d, b=%d\n",a,b);
    }
    else
    {
        sleep(1);
        a--;
        b--;
        printf("In parent, a=%d, b=%d\n",a,b);
    }
    return 0;
}

