#include<stdio.h>
#include<limits.h>

int main(){
    int n;
    printf("Enter No: of Processes: ");
    scanf("%d",&n);

    if(n <= 0){
        printf("INVALID");
        return 0;
    }

    int AT[n], BT[n], RT[n];
    int WT[n], TAT[n], CT[n];
    int total_WT = 0, total_TAT = 0;

    for(int i = 0; i < n; i++){
        printf("Enter Arrival Time of process %d: ", i+1);
        scanf("%d",&AT[i]);

        printf("Enter Burst Time of process %d: ", i+1);
        scanf("%d",&BT[i]);

        RT[i] = BT[i];   // Remaining Time initially equals Burst Time
    }

    int completed = 0, time = 0, min_index;
    int shortest;
    int finish_time;
    int found;

    while(completed != n){
        shortest = INT_MAX;
        found = 0;

        for(int i = 0; i < n; i++){
            if(AT[i] <= time && RT[i] > 0 && RT[i] < shortest){
                shortest = RT[i];
                min_index = i;
                found = 1;
            }
        }

        if(found == 0){
            time++;
            continue;
        }

        RT[min_index]--;

        if(RT[min_index] == 0){
            completed++;
            finish_time = time + 1;

            CT[min_index] = finish_time;
            WT[min_index] = finish_time - AT[min_index] - BT[min_index];

            if(WT[min_index] < 0)
                WT[min_index] = 0;
        }

        time++;
    }

    for(int i = 0; i < n; i++){
        TAT[i] = BT[i] + WT[i];
        total_WT += WT[i];
        total_TAT += TAT[i];
    }

    printf("\n%-10s %-5s %-5s %-5s %-5s\n","Process","AT","BT","WT","TAT");

    for(int i = 0; i < n; i++){
        printf("%-10d %-5d %-5d %-5d %-5d\n",
               i+1, AT[i], BT[i], WT[i], TAT[i]);
    }

    printf("Avg WT = %.2f\n",(float)total_WT/n);
    printf("Avg TAT = %.2f\n",(float)total_TAT/n);

    return 0;
}
