#include<stdio.h>
#include<limits.h>

int main(){

    int n, choice, tq;

    printf("Enter No of Processes: ");
    scanf("%d",&n);

    if(n<=0){
        printf("INVALID INPUT");
        return 0;
    }

    int AT[n], BT[n], PR[n];

    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst Time: ");
        scanf("%d",&BT[i]);
        printf("Priority: ");
        scanf("%d",&PR[i]);
    }

    float minAvgWT = 99999;
    float bestAvgTAT = 0;
    int bestAlgo = 0;

    while(1){

        int WT[n], TAT[n], CT[n], RT[n], done[n];
        int totalWT=0,totalTAT=0;
        float avgWT=0,avgTAT=0;

        printf("\n1.FCFS\n2.SJF\n3.Priority\n4.Round Robin\n5.Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        if(choice==5)
            break;

        switch(choice){

        case 1:{
            int time=0;
            for(int i=0;i<n;i++){
                if(time<AT[i])
                    time=AT[i];
                WT[i]=time-AT[i];
                time+=BT[i];
                CT[i]=time;
                TAT[i]=CT[i]-AT[i];
                totalWT+=WT[i];
                totalTAT+=TAT[i];
            }
            break;
        }

        case 2:{
            for(int i=0;i<n;i++)
                done[i]=0;

            int completed=0,time=0;

            while(completed<n){
                int min_index=-1,minBT=INT_MAX;
                for(int i=0;i<n;i++){
                    if(AT[i]<=time && !done[i] && BT[i]<minBT){
                        minBT=BT[i];
                        min_index=i;
                    }
                }
                if(min_index==-1){
                    time++;
                }else{
                    WT[min_index]=time-AT[min_index];
                    time+=BT[min_index];
                    CT[min_index]=time;
                    TAT[min_index]=CT[min_index]-AT[min_index];
                    done[min_index]=1;
                    completed++;
                    totalWT+=WT[min_index];
                    totalTAT+=TAT[min_index];
                }
            }
            break;
        }

        case 3:{
            for(int i=0;i<n;i++)
                done[i]=0;

            int completed=0,time=0;

            while(completed<n){
                int high=-1,minP=INT_MAX;
                for(int i=0;i<n;i++){
                    if(AT[i]<=time && !done[i] && PR[i]<minP){
                        minP=PR[i];
                        high=i;
                    }
                }
                if(high==-1){
                    time++;
                }else{
                    WT[high]=time-AT[high];
                    time+=BT[high];
                    CT[high]=time;
                    TAT[high]=CT[high]-AT[high];
                    done[high]=1;
                    completed++;
                    totalWT+=WT[high];
                    totalTAT+=TAT[high];
                }
            }
            break;
        }

        case 4:{
            printf("Enter Time Quantum: ");
            scanf("%d",&tq);

            for(int i=0;i<n;i++)
                RT[i]=BT[i];

            int completed=0,time=0;

            while(completed<n){
                int flag=0;
                for(int i=0;i<n;i++){
                    if(RT[i]>0 && AT[i]<=time){
                        flag=1;
                        if(RT[i]>tq){
                            time+=tq;
                            RT[i]-=tq;
                        }else{
                            time+=RT[i];
                            CT[i]=time;
                            TAT[i]=CT[i]-AT[i];
                            WT[i]=TAT[i]-BT[i];
                            totalWT+=WT[i];
                            totalTAT+=TAT[i];
                            RT[i]=0;
                            completed++;
                        }
                    }
                }
                if(flag==0)
                    time++;
            }
            break;
        }

        default:
            printf("Invalid Choice\n");
            continue;
        }

        avgWT=(float)totalWT/n;
        avgTAT=(float)totalTAT/n;

        printf("\nProcess AT BT WT TAT\n");
        for(int i=0;i<n;i++)
            printf("%d      %d  %d  %d  %d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);

        printf("\nAverage Waiting Time = %.2f\n",avgWT);
        printf("Average Turnaround Time = %.2f\n",avgTAT);

        if(avgWT < minAvgWT){
            minAvgWT = avgWT;
            bestAvgTAT = avgTAT;
            bestAlgo = choice;
        }
    }

    if(bestAlgo!=0){
        char *name;
        if(bestAlgo==1) name="FCFS";
        else if(bestAlgo==2) name="SJF";
        else if(bestAlgo==3) name="Priority";
        else name="Round Robin";

        printf("\n%s gives the minimum Average Waiting Time = %.2f and Average Turnaround Time = %.2f\n",
               name,minAvgWT,bestAvgTAT);
    }

    return 0;
}
