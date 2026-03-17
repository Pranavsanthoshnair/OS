#include<stdio.h>

void printFrames(int f[], int frames){
    for(int i=0;i<frames;i++){
        if(f[i]==-1) printf("-\t");
        else printf("%d\t",f[i]);
    }
}

void FIFO(int pages[], int n, int frames){
    int f[10], faults=0, pos=0;

    for(int i=0;i<frames;i++) f[i]=-1;

    printf("\nPage\t");
    for(int i=0;i<frames;i++) printf("F%d\t",i+1);
    printf("Status\n");

    for(int i=0;i<n;i++){
        int found=0;

        for(int j=0;j<frames;j++){
            if(f[j]==pages[i]){
                found=1;
                break;
            }
        }

        printf("%d\t",pages[i]);

        if(found){
            printFrames(f,frames);
            printf("H\n");
        } else {
            f[pos]=pages[i];
            pos=(pos+1)%frames;
            faults++;

            printFrames(f,frames);
            printf("M\n");
        }
    }

    printf("Total Page Faults = %d\n",faults);
}

void LRU(int pages[], int n, int frames){
    int f[10], time[10], faults=0, count=0;

    for(int i=0;i<frames;i++){
        f[i]=-1;
        time[i]=0;
    }

    printf("\nPage\t");
    for(int i=0;i<frames;i++) printf("F%d\t",i+1);
    printf("Status\n");

    for(int i=0;i<n;i++){
        int found=0;

        for(int j=0;j<frames;j++){
            if(f[j]==pages[i]){
                count++;
                time[j]=count;
                found=1;
                break;
            }
        }

        printf("%d\t",pages[i]);

        if(found){
            printFrames(f,frames);
            printf("H\n");
        } else {
            int min=time[0], pos=0;

            for(int j=1;j<frames;j++){
                if(time[j]<min){
                    min=time[j];
                    pos=j;
                }
            }

            f[pos]=pages[i];
            count++;
            time[pos]=count;
            faults++;

            printFrames(f,frames);
            printf("M\n");
        }
    }

    printf("Total Page Faults = %d\n",faults);
}

void OPTIMAL(int pages[], int n, int frames){
    int f[10], faults=0;

    for(int i=0;i<frames;i++) f[i]=-1;

    printf("\nPage\t");
    for(int i=0;i<frames;i++) printf("F%d\t",i+1);
    printf("Status\n");

    for(int i=0;i<n;i++){
        int found=0;

        for(int j=0;j<frames;j++){
            if(f[j]==pages[i]){
                found=1;
                break;
            }
        }

        printf("%d\t",pages[i]);

        if(found){
            printFrames(f,frames);
            printf("H\n");
        } else {
            int pos=-1, far=-1;

            for(int j=0;j<frames;j++){
                int next=-1;

                for(int k=i+1;k<n;k++){
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

            printFrames(f,frames);
            printf("M\n");
        }
    }

    printf("Total Page Faults = %d\n",faults);
}

int main(){
    int n, frames, choice;
    int pages[50];

    printf("Enter reference string length: ");
    scanf("%d",&n);

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    printf("Enter page reference string:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    while(1){
        printf("\n1. FIFO\n2. LRU\n3. Optimal\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: FIFO(pages,n,frames); break;
            case 2: LRU(pages,n,frames); break;
            case 3: OPTIMAL(pages,n,frames); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}