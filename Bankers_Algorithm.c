#include <stdio.h>

int main() {
    int np, nr;

    printf("Enter number of processes: ");
    scanf("%d",&np);

    printf("Enter number of resources: ");
    scanf("%d",&nr);

    int allocation[np][nr];
    int maximum[np][nr];
    int need[np][nr];
    int available[nr];

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<np;i++)
        for(int j=0;j<nr;j++)
            scanf("%d",&allocation[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(int i=0;i<np;i++)
        for(int j=0;j<nr;j++)
            scanf("%d",&maximum[i][j]);

    printf("Enter Available Resources:\n");
    for(int i=0;i<nr;i++)
        scanf("%d",&available[i]);

    for(int i=0;i<np;i++)
        for(int j=0;j<nr;j++)
            need[i][j] = maximum[i][j] - allocation[i][j];

    int finished[np], safeSequence[np];

    for(int i=0;i<np;i++)
        finished[i] = 0;

    int count = 0;

    while(count < np){
        int processFound = 0;

        for(int i=0;i<np;i++){
            if(finished[i] == 0){
                int canRun = 1;

                for(int j=0;j<nr;j++){
                    if(need[i][j] > available[j]){
                        canRun = 0;
                        break;
                    }
                }

                if(canRun == 1){
                    for(int j=0;j<nr;j++)
                        available[j] += allocation[i][j];

                    safeSequence[count] = i;
                    count++;
                    finished[i] = 1;
                    processFound = 1;
                }
            }
        }

        if(processFound == 0){
            printf("System is NOT in safe state\n");
            return 0;
        }
    }

    printf("System is in safe state\nSafe sequence: ");
    for(int i=0;i<np;i++)
        printf("P%d ", safeSequence[i]);

    return 0;
}
