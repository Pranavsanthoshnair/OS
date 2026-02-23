#include<stdio.h>

int main(){
    int n;
    printf("Enter No of Processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], WT[n], TAT[n], CT[n], PR[n], done[n];
    int total_WT = 0, total_TAT = 0;

    for(int i=0;i<n;i++){
        printf("Enter Arrival Time of process %d: ",i+1);
        scanf("%d",&AT[i]);
        printf("Enter Burst Time of process %d: ",i+1);
        scanf("%d",&BT[i]);
        printf("Enter Priority of process %d: ",i+1);
        scanf("%d",&PR[i]);
        done[i] = 0;
    }

    int completed = 0, time = 0;

    while(completed < n){
        int highest = -1;
        int min_priority = 9999;

        for(int i=0;i<n;i++){
            if(AT[i] <= time && done[i] == 0){
                if(PR[i] < min_priority){
                    min_priority = PR[i];
                    highest = i;
                }
            }
        }

        if(highest == -1){
            time++;
        }
        else{
            WT[highest] = time - AT[highest];
            time += BT[highest];
            CT[highest] = time;
            TAT[highest] = CT[highest] - AT[highest];

            done[highest] = 1;
            completed++;

            total_WT += WT[highest];
            total_TAT += TAT[highest];
        }
    }

    printf("\nProcess  AT  BT  PR  WT  TAT\n");
    for(int i=0;i<n;i++){
        printf("%d        %d   %d   %d   %d   %d\n",
               i+1,AT[i],BT[i],PR[i],WT[i],TAT[i]);
    }

    printf("Avg WT = %.2f\n",(float)total_WT/n);
    printf("Avg TAT = %.2f",(float)total_TAT/n);

    return 0;
}
