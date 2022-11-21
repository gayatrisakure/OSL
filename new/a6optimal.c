#include<stdio.h>

int main(){

    int no_of_pages,no_of_frames,flag1=0,flag2=0,flag3=0,fault=0,max,pos;
    int ref_str[50],frames[15],temp[10];

    printf("Enter the number of pages: ");
    scanf("%d",&no_of_pages);

    printf("Enter the page number: ");
    for (int i = 0; i < no_of_pages; i++)
        scanf("%d",&ref_str[i]);       

    printf("Enter the number of frames: ");
    scanf("%d",&no_of_frames);

    for (int i = 0; i < no_of_frames; i++)
        frames[i]=-1;

    for (int i = 0; i < no_of_pages; i++)
    {
        flag1=flag2=0;
        for (int j = 0; j < no_of_frames; j++)
        {
            if (frames[j]==ref_str[i])      //page found
            {
                flag1=flag2=1;
                break;
            }            
        }

        if (flag1==0)
        {
            for (int j = 0; j < no_of_frames; j++)
            {
                if (frames[j]==-1)      //insert page if frame is empty
                {
                    fault++;
                    frames[j]=ref_str[i];
                    flag2=1;
                    break;
                }                
            }
        }

        if (flag2==0)
        {
            flag3=0;
            for (int j = 0; j < no_of_frames; j++)
            {
                temp[j]=-1;
                for (int k = i+1; k < no_of_pages; k++)     //check the future string for the page
                {
                    if (frames[j]==ref_str[k])
                    {
                        temp[j]=k;
                        break;
                    }                    
                }
            }
            for (int j = 0; j < no_of_frames; j++)
            {
                if (temp[j]==-1)
                {
                    pos=j;
                    flag3=1;
                    break;
                }
                
            }
            
        if (flag3==0)
        {
            max=temp[0];
            pos=0;

            for (int j = 1; j < no_of_frames; j++)
            {
                if (temp[j]>max)
                {
                    max=temp[j];
                    pos=j;
                }                        
            }                    
        }
            frames[pos]=ref_str[i];
            fault++;
        }
        printf("\n");

        for (int j = 0; j < no_of_frames; j++)
        {
            printf("%d\t",frames[j]);
        }
                            
    }
    printf("\n\nTotal Page Faults: %d",fault)  ;
    return 0;
    
}