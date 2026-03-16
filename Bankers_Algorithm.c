#include<stdio.h>

int main(){
    int np,nr;

    printf("Enter Number of Processes : ");
    scanf("%d",&np);

    printf("Enter Number of Resources: ");
    scanf("%d",&nr);

    int allocation[10][10];
    int maximum[10][10];
    int need[10][10];
    int available[10];

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("Enter Maximum Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&maximum[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(int i=0;i<nr;i++){
        scanf("%d",&available[i]);
    }

    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("\nNeed Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    int finished[np],safeSequence[np];

    for(int i=0;i<np;i++){
        finished[i]=0;
    }

    int count=0;

    while(count<np){
        int processFound=0;

        for(int i=0;i<np;i++){
            if(finished[i]==0){

                int canRun=1;

                for(int j=0;j<nr;j++){
                    if(need[i][j] > available[j]){
                        canRun=0;
                        break;
                    }
                }

                if(canRun==1){

                    for(int j=0;j<nr;j++){
                        available[j]+=allocation[i][j];
                    }

                    safeSequence[count]=i;
                    count++;
                    finished[i]=1;
                    processFound=1;
                }
            }
        }

        if(processFound==0){
            printf("\nSystem is NOT in safe state\n");
            return 0;
        }
    }

    printf("\nSystem is in safe state\n");
    printf("Safe sequence: ");

    for(int i=0;i<np;i++){
        printf("P%d ",safeSequence[i]);
    }

    printf("\n");

    return 0;
}
