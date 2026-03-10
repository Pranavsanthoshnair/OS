#include<stdio.h>
int size;
int mutex = 1;
int full = 0;
int empty;
int buffer[100];
int in = 0,out = 0;
int item;
void producer(){
	if(empty==0){
		printf("Buffer is Full\n");
		return;
	}
	printf("Enter Item: ");
	scanf("%d",&item);
	mutex = 0;
	buffer[in]=item;
	in = (in+1)%size;
	printf("Item %d inserted\n",item);
	mutex = 1;
	full ++;
	empty --;
	display();
}
void consumer(){
	if(full==0){
		printf("Buffer is Empty\n");
		return;
	}
	mutex = 0;
	item = buffer[out];
	out=(out+1)%size;
	printf("Item %d consumed\n",item);
	mutex = 1;
	full --;
	empty ++;
	display();
}
void display(){
	if(full==0){
		printf("Queue: Empty\n");
		return;
	}
	printf("Queue: ");
	int i = out;
	for(int count =0;count<full;count++){
		printf("%d ",buffer[i]);
		i=(i+1)%size;
	}
	printf("\n");
}
int main(){
	int choice;
	printf("Enter Buffer Size : ");
	scanf("%d",&size);
	empty=size;
	while(1){
		printf("\n1)Producer\n2)Consumer\n3)Exit\n");
		printf("Enter Choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				producer();
				break;
			case 2:
				consumer();
				break;
			case 3:
				return 0;
			default:
				printf("Invalid Choice\n");
		}
	}
}
