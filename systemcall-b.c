#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
	struct stat filestat;
	if(stat("file.txt",&filestat)==1)
	{
		perror("error in stat");
		return 1;
	}
	printf("Filesize : %11d",(long long)filestat.st_size);
	
	DIR *dir;
	struct dirent *entry;
	if((dir=opendir("."))==NULL)
	{
		perror("Error in opendir");
		return 1;
	}
	while((entry = readdir(dir))!=NULL)
	{
		printf("%s\n", entry->d_name);
	}
	closedir(dir);
	return 0;
}

