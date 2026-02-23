#include<stdio.h>

int main(){
    int n, tq;
    printf("Enter No of Processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], RT[n], WT[n], TAT[n], CT[n];
    int total_WT = 0, total_TAT = 0;

    for(int i=0;i<n;i++){
        printf("Enter Arrival Time of process %d: ",i+1);
        scanf("%d",&AT[i]);
        printf("Enter Burst Time of process %d: ",i+1);
        scanf("%d",&BT[i]);
        RT[i] = BT[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int completed = 0, time = 0;

    while(completed < n){
        int done_flag = 1;

        for(int i=0;i<n;i++){
            if(RT[i] > 0 && AT[i] <= time){
                done_flag = 0;

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

                    total_WT += WT[i];
                    total_TAT += TAT[i];
                }
            }
        }

        if(done_flag == 1){
            time++;
        }
    }

    printf("\nProcess  AT  BT  WT  TAT\n");
    for(int i=0;i<n;i++){
        printf("%d        %d   %d   %d   %d\n",
               i+1,AT[i],BT[i],WT[i],TAT[i]);
    }

    printf("Avg WT = %.2f\n",(float)total_WT/n);
    printf("Avg TAT = %.2f",(float)total_TAT/n);

    return 0;
}
