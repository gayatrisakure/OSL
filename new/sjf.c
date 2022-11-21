#include<stdio.h>
#include<stdlib.h>
int main(){
    int at[10], bt[10], temp[10];
    int limit, c=0, s, wt, tat;
    printf("Enter no of processes : \n");
    scanf("%d", &limit);
    printf("details : \n");

    for (int i=0; i<limit; i++){
        printf("\nAT : ");
        scanf("%d", at[i]);
        printf("\nBT : ");
        scanf("%d", bt[i]);

        temp[i] = bt[i];

    }

    bt[9]=9999;
    for (int t=0; c!=limit; t++){
        s = 9;
        for(int i=0; i<limit; i++){
            if (at[i]<=t && bt[i]<bt[s] && bt>0){
                s = i;
            }
            
        }
        bt[s]--;
        if (bt[s]==0){
            c++;
            int end = t+1;
            wt = wt + end - at[s] - temp[s];
            tat = tat + end - at[s];
        }
    }

    float awt = wt/limit;
    float atat = tat/limit;

    printf("\nAvg wt : %lf\n", awt);
    printf("\nAvg bt : %lf\n", atat);

    return 0;
}