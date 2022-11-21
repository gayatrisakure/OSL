#include<stdio.h>

int main(){

    int no_of_pages,no_of_frames,avail,fault=0,hit=0;
    int ref_str[50],frame[15];
    printf("Enter the number of pages: ");
    scanf("%d",&no_of_pages);

    printf("Enter the page number: ");
    for(int i = 0; i < no_of_pages; i++)
    {
        scanf("%d",&ref_str[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d",&no_of_frames);

    for (int i = 0; i < no_of_frames; i++)
    {
        frame[i]=-1;    //initialize all page frame to -
    }
    int j=0;    //initialize page frame pointer
    printf("\nReference string\tPage Frames \tHit/Fault\n");
    for (int i = 0; i < no_of_pages; i++)
    {
        printf("%d\t\t\t",ref_str[i]);
        avail=0;     //default value of flag=0
        for (int k = 0; k < no_of_frames; k++)        
            if (frame[k]==ref_str[i])   //input page is compared with the ref_str
            {
                avail=1;    //page found
                hit++;                //incre page fault counter                
                for(int k = 0; k < no_of_frames; k++)                
                    printf(" %d  ",frame[k]);    //print current state of frame                
                printf("\t H");        //page hit              
            }
            if (avail==0)   //page not found in the frame
            {
                frame[j]=ref_str[i];    //place page requested at jth location
                j=(j+1)%no_of_frames;   //update the value of j
                fault++;                //incre page fault counter
                for (int k = 0; k < no_of_frames; k++)
                    printf(" %d  ",frame[k]);     //print current state of frame                                           
                printf("\t F");
            }
            printf("\n");        

    }
printf("Page Fault is %d",fault);
printf("Page Fault is %d",hit);

return 0;
}