#include<stdio.h>

int main(){

    int n, tq;

    printf("Enter No of Processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], RT[n];
    int WT[n], TAT[n], CT[n];

    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst Time: ");
        scanf("%d",&BT[i]);
        RT[i] = BT[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d",&tq);

    int time = 0, completed = 0;

    while(completed < n){

        int executed = 0;

        for(int i=0;i<n;i++){

            if(AT[i] <= time && RT[i] > 0){

                executed = 1;

                if(RT[i] > tq){
                    time += tq;
                    RT[i] -= tq;
                }
                else{
                    time += RT[i];
                    CT[i] = time;
                    RT[i] = 0;
                    completed++;

                    TAT[i] = CT[i] - AT[i];
                    WT[i] = TAT[i] - BT[i];
                }
            }
        }

        if(executed == 0)
            time++;
    }

    float totalWT = 0, totalTAT = 0;

    printf("\nProcess AT BT WT TAT\n");

    for(int i=0;i<n;i++){
        printf("%d      %d  %d  %d  %d\n",
               i+1, AT[i], BT[i], WT[i], TAT[i]);

        totalWT += WT[i];
        totalTAT += TAT[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT/n);
    printf("Average Turnaround Time = %.2f\n", totalTAT/n);

    return 0;
}
