#include <stdio.h>

int mutex = 1;
int full = 0;
int empty;
int buffer[100];
int in = 0, out = 0;
int item;

void producer()
{
    if(empty == 0)
    {
        printf("Buffer is Full\n");
        return;
    }

    printf("Enter item: ");
    scanf("%d",&item);

    mutex = 0;

    buffer[in] = item;
    in = (in + 1) % empty;

    printf("Item %d inserted\n",item);

    mutex = 1;
    full++;
    empty--;
}

void consumer()
{
    if(full == 0)
    {
        printf("Buffer is Empty\n");
        return;
    }

    mutex = 0;

    item = buffer[out];
    out = (out + 1) % empty;

    printf("Item %d consumed\n",item);

    mutex = 1;
    full--;
    empty++;
}

int main()
{
    int choice;

    printf("Enter buffer size: ");
    scanf("%d",&empty);

    while(1)
    {
        printf("\n1 Producer\n2 Consumer\n3 Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
