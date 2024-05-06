#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
	char fi[100],fo[100],s[30];
	printf("Enter the input file name\n");
	scanf("%s",fi);
	printf("Enter the output file name\n");
	scanf("%s",fo);
	
	int p1,p2;
	p1 = open(fi,O_RDWR);
	if(p1!=-1)
	{
		read(p1,s,sizeof(s));
		printf("Data:%s",s);
		close(p1);
	}
	else
		printf("File not found");
	
	p2=open(fo,O_RDWR);
	if(p2!=-1)
	{
		write(p2,s,sizeof(s));
		printf("Data written");
		close(p2);
	}
	else
		printf("File not found");
}
