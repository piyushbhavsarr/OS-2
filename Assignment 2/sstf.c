#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 100

int main()
{
    int n, head, sum = 0;
    printf("Enter the number of disk queues: ");
    scanf("%d", &n);
    int queues[MAX_QUEUES], visited[MAX_QUEUES];

    if (n > MAX_QUEUES) {
        printf("Error: number of disk queues exceeds maximum allowed value of %d.\n", MAX_QUEUES);
        return 1;
    }

    printf("Enter the disk queues: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &queues[i]);
        visited[i] = 0;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("The disk queue traversal order is: ");
    for(int i=0; i<n; i++)
    {
        int min_distance = 1000000;  // initialize to a large enough value
        int min_index = -1;
        for(int j=0; j<n; j++)
        {
            if(!visited[j])
            {
                int distance = abs(head - queues[j]);
                if(distance < min_distance)
                {
                    min_distance = distance;
                    min_index = j;
                }
            }
        }
        visited[min_index] = 1;
        printf("%d ", queues[min_index]);
        sum += min_distance;
        head = queues[min_index];
    }

    printf("\nTotal head movements: %d\n", sum);

    return 0;
}
