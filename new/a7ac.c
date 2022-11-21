#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

void main()
{
	int fd;
	char *myf1="myf1";
	char *myf2="myf2";
	mkfifo(myf1,0666);
	mkfifo(myf2,0666);
	char str1[100],str2[100];
	while(1)
	{
	fd=open(myf1,O_WRONLY);
	fgets(str1,100,stdin);
	write(fd,str1,100);
	close(fd);
	
	fd=open(myf2,O_RDONLY);
	read(fd,str2,100);
	printf("User 2:%s",str2);
	close(fd);
	}
}
	