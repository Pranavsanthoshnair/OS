#include <stdio.h>

int main() {
    int numberOfProcesses, numberOfResources;

    printf("Enter number of processes: ");
    scanf("%d",&numberOfProcesses);

    printf("Enter number of resources: ");
    scanf("%d",&numberOfResources);

    int allocation[numberOfProcesses][numberOfResources];
    int maximum[numberOfProcesses][numberOfResources];
    int need[numberOfProcesses][numberOfResources];
    int available[numberOfResources];

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<numberOfProcesses;i++)
        for(int j=0;j<numberOfResources;j++)
            scanf("%d",&allocation[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(int i=0;i<numberOfProcesses;i++)
        for(int j=0;j<numberOfResources;j++)
            scanf("%d",&maximum[i][j]);

    printf("Enter Available Resources:\n");
    for(int i=0;i<numberOfResources;i++)
        scanf("%d",&available[i]);

    for(int i=0;i<numberOfProcesses;i++)
        for(int j=0;j<numberOfResources;j++)
            need[i][j]=maximum[i][j]-allocation[i][j];

    int finished[numberOfProcesses],safeSequence[numberOfProcesses];

    for(int i=0;i<numberOfProcesses;i++)
        finished[i]=0;

    int count=0;

    while(count<numberOfProcesses){
        int processFound=0;

        for(int i=0;i<numberOfProcesses;i++){
            if(finished[i]==0){
                int canRun=1;

                for(int j=0;j<numberOfResources;j++){
                    if(need[i][j]>available[j]){
                        canRun=0;
                        break;
                    }
                }

                if(canRun==1){
                    for(int j=0;j<numberOfResources;j++)
                        available[j]+=allocation[i][j];

                    safeSequence[count]=i;
                    count++;
                    finished[i]=1;
                    processFound=1;
                }
            }
        }

        if(processFound==0){
            printf("System is NOT in safe state\n");
            return 0;
        }
    }

    printf("System is in safe state\nSafe sequence: ");
    for(int i=0;i<numberOfProcesses;i++)
        printf("P%d ",safeSequence[i]);

    return 0;
}
