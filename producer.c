#include<stdio.h>
#include<stdlib.h>

#define MAX_ 5
int buffer[MAX_];
int in=0,out=0;

void print()
{
  if(in==out)
    printf("Buffer Empty\n");
  int t=out;
  while(t!=in)
  {
    printf("%d\t",buffer[t]);
    t=(t+1)%MAX_;
  } 
  printf("\n");
}
void producer(int x)
{
  if((in+1)%MAX_ == out)
    printf("Buffer full");
  else
  {
    buffer[in]=x;
    in = (in+1)%MAX_;
  }
  print();
}
void consumer()
{
  if(in == out)
	{
		printf("Buffer Empty\n");
		return;
	}
	else
	{
		printf("Consumed Value is %d\n",buffer[out]);
		out = (out+1)%MAX_;
		print();
	}
}
void main()
{
	int ch,n;
	do
	{
		printf("1.Produce\n2.Consume\n3.Print\n4.Exit\nEnter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The value\n");
				scanf("%d",&n);
				producer(n);
				break;
			case 2:
				consumer();
				break;
			case 3:
				print();
				break;
			case 4:
				break;	
			default:
				printf("Wrong Choice");			
		}
	}while(ch!=4);
}

