#include<stdio.h>
int main(){
	int n;
	printf("Enter No:of Processes: ");
	scanf("%d",&n);
	int AT[n],BT[n],WT[n],TAT[n],CT[n];
	int total_WT = 0,total_TAT = 0;
	int temp;
	for(int i=0;i<n;i++){
		printf("Enter Arrival Time of process %d :",i+1);
		scanf("%d",&AT[i]); Password 
		printf("Enter Burst Time of process %d :",i+1);
		scanf("%d",&BT[i]);
	}
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-i-1;j++){
			if(AT[j]>AT[j+1]){
				temp = AT[j];
				AT[j]=AT[j+1];
				AT[j+1]=temp;
				temp = BT[j];
				BT[j]=BT[j+1];
				BT[j+1]=temp;
			}
		}
	}
	if(n<=0){
		printf("INVALID:");
		return 0;
	}
	WT[0]=0;
	int time = AT[0]+BT[0];
	CT[0]=time;
	for(int i = 1;i<n;i++){
		if(time<AT[i]){
			time = AT[i];
		}
		WT[i]=time-AT[i];
		time+=BT[i];
		CT[i]=time;
	}
	for(int i = 0;i<n;i++){
		TAT[i]=CT[i]-AT[i];.
	}
	printf("\n%-10s %-5s %-5s %-5s %-5s\n","Process", "AT", "BT", "WT", "TAt");
	for(int i =0;i<n;i++){
		printf("%-10d %-5d %-5d %-5d %-5d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);
		total_WT += WT[i];
		total_TAT += TAT[i];
	}
	printf("Avg WT = %.2f\n",(float)total_WT/n);
	printf("Avg TAT = %.2f",(float)total_TAT/n);
	return 0;
}
