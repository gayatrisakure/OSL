#include<stdio.h>
#include<stdlib.h>

int main(){
    int p,c, count=0, i, j, aloc[5][3], max[5][3], need[5][3],safe[5], available[3], done[5], temonate=0;

    printf("Enter no of process and resources : ");
    scanf("%d %d", &p, &c);
    printf("Enter allocation mat : \n");
    for (int i=0; i<p; i++){
        for (int j=0; j<c; j++){
            scanf("%d", &aloc[i][j]);
        }
    }

    printf("Enter max mat : \n");
    for (int i=0; i<p; i++){
        for (int j=0; j<c; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("enter available resources : \n");
    for (int i=0; i<c; i++){
        scanf("%d", &available[i]);
    }

    printf("Need mat is : \n");
    for (int i=0; i<p; i++){
        for (int j=0; j<c; j++){
            need[i][j] = max[i][j]-aloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    printf("Enter res no who req res : \n");
    int n;
    scanf("%d", &n);

    int req[c];
    printf("Enter req : \n");
    for (int i=0; i<c; i++){
        int a;
        scanf("%d", &a);
        req[i]=a;
    }

    int flag = 0;
    for (int i=0; i<c; i++){
        if (req[i] > available[i]){
            flag = 1;
        }
    }
    if(flag == 1){
        printf("Req denied\n");
        return 0;
    }

    int flag1 = 0;
    for (int i=0; i<c; i++){
        if (req[i] > need[n][i]){
            flag1 = 1;
        }
    }
    if(flag1 == 1){
        printf("Req denied\n");
        return 0;
    }

    for (int i=0; i<c; i++){
        available[i] = available[i] - req[i];
        need[n][i] -= req[i];
        aloc[n][i] += req[i];
    }

    for (int i=0; i<p; i++){
        done[i]=0;
    }

    int proceed = 1;

    while(proceed){
        proceed = 0;

        for (i=0; i<p; i++){
            if (done[i]==0){
                for (j=0; j<c; j++){
                    if (need[i][j] > available[j]){
                        break;
                    }
                }
                if (j==c){
                    safe[count]=i;
                    done[i]=1;

                    for (j=0; j<c; j++){
                        available[j] += aloc[i][j];
                    }
                    count++;
                    proceed = 1;
                }
            }
        }

    }

    int cnt = 0;
    for (int i=0; i<p; i++){
        if (done[i]==1){
            cnt++;
        }
    }


    if (cnt == p){
        printf("\nReq accepted");

        printf("\nAvailable res after completion : \n");

        for (int i=0; i<c; i++){
            printf("%d\t", available[i]);
        }

        printf("Safe seq : \n");
        for (i=0; i<p; i++){
            printf("p[%d]\t", safe[i]);
        }


    }
    else{
        printf("Req denied");

    }

    return 0;


}