#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

void main()
{
	int fd1,wr,ln;
	char *myf1="myf1";
	char *myf2="myf2";
	mkfifo(myf1,0666);
	mkfifo(myf2,0666);
	char str1[100],str2[100];
	while(1)
	{
		fd1=open(myf1,O_RDONLY);
		read(fd1,str1,100);
		printf("User1:%s\n",str1);
		close(fd1);
		ln=0;
		wr=1;
		
		for(int i=0;str1[i]!='\0';i++)
		{
			if(str1[i]==' ')
				wr++;
			if(str1[i]=='.')
				ln++;
		}
		
		sprintf(str2,"words:%d sentences:%d",wr,ln);
		fd1=open(myf2,O_WRONLY);
		write(fd1,str2,100);
		close(fd1);
	}
}