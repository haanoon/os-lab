#include<stdio.h>
#include<sys/types.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t q;
	printf("before fork\n");
	q = fork();
	if(q==0)
	{
		printf("iam a child process having id %d",getpid());
		printf("my parent id is %d ",getppid());
		sleep(5);
		printf("Before\n");
		execl("/bin/ls","ls","-a",NULL);
		printf("After\n");
	}
	else
	{
		wait(NULL);
		printf("my child id is %d",q);
		printf("iam a parent having id %d",getpid());
	}
	printf("Common\n");
	
}
