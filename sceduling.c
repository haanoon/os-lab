#include<stdio.h>
#include<string.h>

struct process
{
	char name[10];
	int at,tt,ct,bt,wt,status,left,pr;
}p[20],temp;

struct done
{
	char name[10];
	int st,ct;
}d[20];

void fcfs()
{
	int i,j,n,idle=0,c;
	
	printf("Enter Number of Processes\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter Details of Process %d\n",i+1);
		printf("Enter process name:");
		scanf("%s",&p[i].name);
		printf("\nEnter process arrival time:");
		scanf("%d",&p[i].at);
		printf("\nEnter process burst time:");
		scanf("%d",&p[i].bt);
	}	
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	for(i=0,j=0,c=0;j<n;)
	{
		if(p[j].at<=i && p[j].status=0)
		{
			if(idle=1)
			{
				d[c].ct=i;
				c++;
				idle=0;
			}
			strcpy(d[c].name,p[j].name);
			d[c].st=i;
			d[c].ct=i+d[c].bt;
			p[j].wt=d[c].st-p[j].at;
			p[j].tt=p[j].wt+p[j].bt;
			i=d[c].ct;
			p[j].status=1;
			j++;
			c++;
		}
		else if(idle=1)
		{
			strcpy(d[c].name,p[j].name);
			d[c].st=i;
			i++;
			idle=;
		}
		else if 
			i++;
	}
}

void sjf()
{
	int i,j,c,idle,min,n,ls;
	printf("Enter Number of Processes\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter Details of Process %d\n",i+1);
		printf("Enter process name:");
		scanf("%s",&p[i].name);
		printf("\nEnter process arrival time:");
		scanf("%d",&p[i].at);
		printf("\nEnter process burst time:");
		scanf("%d",&p[i].bt);
	}
	for(i=0,j=0,c=0,idle=0;ls<n;)
	{
		for(j=0,fnd=0;j<n;j++)
		{
			if(fnd==0)
			{
				min=j;
				fnd=1;
			}
			else if(fnd!=0 && p[min].bt>p[j].bt)
			{
				min=j;
			}
		}
		if(idle==0 && fnd==0)
		{
			strcpy(d[num].name,"Idle");
			d[num].st=i;
			i++;
			idle=1;
		}
		else if(fnd==1)
		{
			if(idle==1)
			{
				d[num].ct=i;
				num++;
				idle=0;
			}
			strcpy(d[num].name,p[min].name)
			p[min].status=1;
			d[num].st=i;
			d[num].ct=d[num].st+d[num].bt;
			i=d[num].ct;
			p[min].ct=d[num].ct;
			p[min].tt=p[min].ct-p[min].at;
			p[min].wt=p[min].tt-p[min].bt;
			num++;ls++;
		}
		else
			i++;
	}		
}


void priority()
{
	int i,j,n,ls,min,idle,num,fnd;
	
	printf("Enter Number of Processes\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter Details of Process %d\n",i+1);
		printf("Enter process name:");
		scanf("%s",&p[i].name);
		printf("\nEnter process arrival time:");
		scanf("%d",&p[i].at);
		printf("\nEnter process burst time:");
		scanf("%d",&p[i].bt);
		printf("\nEnter Process Priority");
		scanf("%d",&p[i].pr);
		p[i].status=0;
	}
	for(i=0,num=0,ls=0,idle=0;ls<n;)
	{
		for(j=0;fnd=0;j<n;j++)
		{
			if(p[j].at<=i && p[j].status=0)
			{
				if(fnd=0)
				{
					min=j;
					fnd=1;
				}
				else if(p[min].pr>p[j].pr || (p[min].bt>p[j].bt && p[min].pr==p[j].pr))
				{
					min=j;
				}
				
			}
			if(fnd == 0 && idle == 0)
			{
				strcpy(d[num].name,"Idle");
				d[num].st = i;
				i++;
				idle=1;
			}
			else if(fnd == 1)
			{
				if(idle==1)
				{
					d[num].ct=i;
					num++;
					idle=0;
				}
				strcpy(d[num].name,p[min].name);
				p[min].status=1;
				p[min].status =1;
	      			d[num].st = i;
	      			d[num].ct = i + p[min].bt;
	      			i = d[num].ct;
	      			p[min].ct = d[num].ct;
	      			p[min].tt = p[min].ct - p[min].at;
	      			p[min].wt = p[min].tt - p[min].bt;
	      			num++;
	      			ls++;
			}
			else
				i++;
		}
	}
}

int q[100],front=-1,rear=-1;

void enqueue(int j)
{
	if(front == -1)
		front++;
	rear++;
	q[rear]=j;	
}

int dequeue()
{
	int item;
	item = q[front];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front++;
	return item;
}

void roundrobin()
{
	int i,j,n,ls,min,idle=0,num,t,k;
	
	printf("Enter Number of Processes\n");
	scanf("%d",&n);
	printf("\nEnter Time Quantum");
	scanf("%d",&t);
	for(i=0;i<n;i++)
	{
		printf("Enter Details of Process %d\n",i+1);
		printf("Enter process name:");
		scanf("%s",&p[i].name);
		printf("\nEnter process arrival time:");
		scanf("%d",&p[i].at);
		printf("\nEnter process burst time:");
		scanf("%d",&p[i].bt);
		p[i].left=p[i].bt;
		p[i].status = 0;
	}
	
	for(i=0,ls=0,num=0;ls<n;)
	{
		for(j=0;j<n;j++)
		{
	 		if(p[j].status==0&&p[j].at<=i)
			{
				enqueue(j);
				p[j].status=1;
			}
		}
		
		if(idle==0 && front ==-1)
		{
			strcpy(d[num].name,"Idle");
			d[num].st=i;
			idle=1;
			i++;
		}
		else if(front != -1)
		{
			k=dequeue();
			d[num].st=i;
			strcpy(d[num].name,p[k].name);
			if(p[k].left<t)
			{
				d[num].ct=i+t;
				p[k].ct=d[num].ct;
				i=d[num].ct;
				p[k].tt=i-p[k].at;
				p[k].wt=p[k].tt-p[k].bt;
				p[k].status = 2;
				ls++;
				num++;
			}
			else if(p[k].left>t)
			{
				d[num].ct=i+t;
				i=d[num].ct;
				p[k].left = p[k].left-t;
				num++;
				for(j=0;j<n;j++)
				{
					if(p[j].status==0 && p[j].at<=i)
					{
						enqueue(j);
						p[j].status=1;
					}
				}
				enqueue(k);
			}
			
		}
		else
			i++;
	}
}
		
	
	
