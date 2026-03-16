#include<stdio.h>

int main()
{
    int n,frames;
    int pages[50];

    printf("Enter reference string length: ");
    scanf("%d",&n);

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    printf("Enter page reference string:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    int f[10],i,j,k,faults;

    /* FIFO */
    faults=0;
    for(i=0;i<frames;i++)
        f[i]=-1;

    int pos=0;

    for(i=0;i<n;i++){
        int found=0;

        for(j=0;j<frames;j++){
            if(f[j]==pages[i]){
                found=1;
                break;
            }
        }

        if(found==0){
            f[pos]=pages[i];
            pos=(pos+1)%frames;
            faults++;
        }
    }

    printf("FIFO Page Faults = %d\n",faults);

    /* LRU */
    int time[10];
    int count=0;
    faults=0;

    for(i=0;i<frames;i++){
        f[i]=-1;
        time[i]=0;
    }

    for(i=0;i<n;i++){
        int found=0;

        for(j=0;j<frames;j++){
            if(f[j]==pages[i]){
                count++;
                time[j]=count;
                found=1;
                break;
            }
        }

        if(found==0){
            int min=time[0];
            pos=0;

            for(j=1;j<frames;j++){
                if(time[j]<min){
                    min=time[j];
                    pos=j;
                }
            }

            f[pos]=pages[i];
            count++;
            time[pos]=count;
            faults++;
        }
    }

    printf("LRU Page Faults = %d\n",faults);

    /* Optimal */
    faults=0;

    for(i=0;i<frames;i++)
        f[i]=-1;

    for(i=0;i<n;i++){
        int found=0;

        for(j=0;j<frames;j++){
            if(f[j]==pages[i]){
                found=1;
                break;
            }
        }

        if(found==0){
            int far=-1;
            pos=-1;

            for(j=0;j<frames;j++){
                int next=-1;

                for(k=i+1;k<n;k++){
                    if(f[j]==pages[k]){
                        next=k;
                        break;
                    }
                }

                if(next==-1){
                    pos=j;
                    break;
                }

                if(next>far){
                    far=next;
                    pos=j;
                }
            }

            f[pos]=pages[i];
            faults++;
        }
    }

    printf("Optimal Page Faults = %d\n",faults);

    return 0;
}
