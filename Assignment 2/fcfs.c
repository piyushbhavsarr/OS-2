#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, sum = 0;
    printf("Enter the number of disk queues: ");
    scanf("%d", &n);
    int queues[n];

    printf("Enter the disk queues: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &queues[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("The disk queue traversal order is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", queues[i]);
        int diff = head - queues[i];
        if (diff < 0) {
            diff = -diff;
        }
        sum += diff;
        head = queues[i];
    }

    printf("\nTotal head movements: %d\n", sum);

    return 0;
}
