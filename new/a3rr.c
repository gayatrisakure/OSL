#include<stdio.h>

int main(){
    int i,j,n, time=0, at[10], bt[10], temp[10], wt=0, tat=0, x, quant;
    float atat, awt;

    printf("Enter total no of process : ");
    scanf("%d", &n);
    x = n;

    for (int i=0; i<n; i++){
        printf("Enter details for %d process : \n", i+1);
        printf("AT : \t");
        scanf("%d", &at[i]);
        printf("BT : \t");
        scanf("%d", &bt[i]);

        temp[i] = bt[i];
    }

    printf("Enter time quantum : ");
    scanf("%d", &quant);

    for(time=0, i=0; x!=0; ){

        if(temp[i] <= quant && temp[i]>0){
            time = time + temp[i];
            temp[i]=0;
            x--;

            wt = wt + time - at[i] - bt[i];
            tat = tat + time - at[i];
        }
        else if (temp[i] > 0){
            temp[i] = temp[i] - quant;
            time = time + quant;
        }

        if(i==n-1){
            i=0;
        }
        else if (at[i+1] <= time){
            i++;
        }
        else{
            i=0;
        }

    }

    awt = wt/n;
    atat = tat/n;

    printf("Avg wt is : %lf ", awt);
    printf("Avg tat is : %lf ", atat);

    return 0;
}