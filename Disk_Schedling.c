#include <stdio.h>
#include <stdlib.h>

int n, head, req[100], dir;

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void SSTF() {
    int visited[100] = {0};
    int total = 0, i, j, pos, min, dist;

    pos = head;
    printf("\nSeek Sequence: %d", pos);

    for(i = 0; i < n; i++) {
        min = 9999;
        int index = -1;

        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                dist = abs(pos - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total += min;
        pos = req[index];
        printf(" -> %d", pos);
    }

    printf("\nTotal Seek Time = %d\n", total);
}

void LOOK() {
    int total = 0, i;
    int left[100], right[100];
    int l = 0, r = 0;
    int pos = head;

    for(i = 0; i < n; i++) {
        if(req[i] < head)
            left[l++] = req[i];
        else
            right[r++] = req[i];
    }

    sort(left, l);
    sort(right, r);

    printf("\nSeek Sequence: %d", pos);

    if(dir == 2) {
        for(i = 0; i < r; i++) {
            total += abs(pos - right[i]);
            pos = right[i];
            printf(" -> %d", pos);
        }
        for(i = l - 1; i >= 0; i--) {
            total += abs(pos - left[i]);
            pos = left[i];
            printf(" -> %d", pos);
        }
    } else {
        for(i = l - 1; i >= 0; i--) {
            total += abs(pos - left[i]);
            pos = left[i];
            printf(" -> %d", pos);
        }
        for(i = 0; i < r; i++) {
            total += abs(pos - right[i]);
            pos = right[i];
            printf(" -> %d", pos);
        }
    }

    printf("\nTotal Seek Time = %d\n", total);
}

void CSCAN() {
    int total = 0, i;
    int left[100], right[100];
    int l = 0, r = 0;
    int disk_size = 200;
    int pos = head;

    for(i = 0; i < n; i++) {
        if(req[i] < head)
            left[l++] = req[i];
        else
            right[r++] = req[i];
    }

    sort(left, l);
    sort(right, r);

    printf("\nSeek Sequence: %d", pos);

    if(dir == 2) {
        for(i = 0; i < r; i++) {
            total += abs(pos - right[i]);
            pos = right[i];
            printf(" -> %d", pos);
        }

        total += abs(pos - (disk_size - 1));
        pos = disk_size - 1;

        total += abs(pos - 0);
        pos = 0;
        printf(" -> %d", pos);

        for(i = 0; i < l; i++) {
            total += abs(pos - left[i]);
            pos = left[i];
            printf(" -> %d", pos);
        }
    } else {
        for(i = l - 1; i >= 0; i--) {
            total += abs(pos - left[i]);
            pos = left[i];
            printf(" -> %d", pos);
        }

        total += abs(pos - 0);
        pos = 0;

        total += abs(pos - (disk_size - 1));
        pos = disk_size - 1;
        printf(" -> %d", pos);

        for(i = r - 1; i >= 0; i--) {
            total += abs(pos - right[i]);
            pos = right[i];
            printf(" -> %d", pos);
        }
    }

    printf("\nTotal Seek Time = %d\n", total);
}

int main() {
    int choice, i;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 = Left, 2 = Right): ");
    scanf("%d", &dir);

    while(1) {
        printf("\n--- Disk Scheduling ---\n");
        printf("1. SSTF\n2. LOOK\n3. C-SCAN\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: SSTF(); break;
            case 2: LOOK(); break;
            case 3: CSCAN(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
