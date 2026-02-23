#include<stdio.h>

int main(){
    int n;
    printf("Enter No of Processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], WT[n], TAT[n], CT[n], done[n];
    int total_WT = 0, total_TAT = 0;

    for(int i=0;i<n;i++){
        printf("Enter Arrival Time of process %d: ",i+1);
        scanf("%d",&AT[i]);
        printf("Enter Burst Time of process %d: ",i+1);
        scanf("%d",&BT[i]);
        done[i] = 0;
    }

    int completed = 0, time = 0;

    while(completed < n){
        int min_index = -1;
        int min_BT = 9999;

        for(int i=0;i<n;i++){
            if(AT[i] <= time && done[i] == 0){
                if(BT[i] < min_BT){
                    min_BT = BT[i];
                    min_index = i;
                }
            }
        }

        if(min_index == -1){
            time++;
        }
        else{
            WT[min_index] = time - AT[min_index];
            time += BT[min_index];
            CT[min_index] = time;
            TAT[min_index] = CT[min_index] - AT[min_index];

            done[min_index] = 1;
            completed++;

            total_WT += WT[min_index];
            total_TAT += TAT[min_index];
        }
    }

    printf("\nProcess  AT  BT  WT  TAT\n");
    for(int i=0;i<n;i++){
        printf("%d        %d   %d   %d   %d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);
    }

    printf("Avg WT = %.2f\n",(float)total_WT/n);
    printf("Avg TAT = %.2f",(float)total_TAT/n);

    return 0;
}
