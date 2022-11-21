#include<stdio.h>

int findLRU(int timer[],int no_frames){
    int min=timer[0],pos=0;

    for (int i = 1; i < no_frames; i++)
    {
        if (timer[i]<min)
        {
            min=timer[i];       //least recently used page
            pos=i;
        }        
    }
    return pos;
}

int main(){
    int no_of_frames, no_of_pages,flag1,flag2,counter=0,fault=0,pos;
    int ref_str[50],frames[15],timer[10];

    printf("Enter the number of pages: ");
    scanf("%d",&no_of_pages);
    
    printf("Enter the page numbers: ");
    for(int i=0;i<no_of_pages;i++)
        scanf("%d",&ref_str[i]);
    
    printf("Enter the number of frames: ");
    scanf("%d",&no_of_frames);

    for(int i=0;i<no_of_frames;i++){
        frames[i]=-1;
    }
    for(int i=0;i<no_of_pages;i++){
        flag1=flag2=0;
        for (int j = 0; j < no_of_frames; j++)
        {
            if (frames[j]==ref_str[i])
            {
                counter++;
                timer[j]=counter;
                flag1=flag2=1;
                break;
            }            
        }
        if (flag1==0)       //check if frames are empty and insert
        {
            for (int j = 0; j < no_of_frames; j++)
            {
                if (frames[j]==-1)
                {
                    counter++;
                    fault++;
                    frames[j]=ref_str[i];   //placing page in the frame
                    timer[j]=counter;       //timer storing counts
                    flag2=1;
                    break;
                }                
            }            
        }
        if (flag2==0)   //page fault but no free frame
        {
            pos=findLRU(timer,no_of_frames);
            counter++;
            fault++;
            frames[pos]=ref_str[i];
            timer[pos]=counter;
        }
        printf("\n");
        
        for (int j = 0; j < no_of_frames; j++)
        {
            printf("%d\t",frames[j]);
        }        
    }
    printf("\n\nTotal Page Faults= %d",fault);
    return 0;
}