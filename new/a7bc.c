#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/ipc.h>
int main()
{
	char str[100];
	int shmid=shmget(123,100,0666|IPC_CREAT);
	printf("SHMID:%d\n",shmid);
	void *shmaddr=shmat(shmid,NULL,0);
	printf("ATTACHED TO:%p\n",shmaddr);
	printf("ENter the Content\n");
	fgets(str,100,stdin);
	strcpy(shmaddr,str);
	printf("Content:%s",(char *)shmaddr);
	return 0;
}