#include <stdio.h>
#include <stdlib.h>

// Function to sort the request array in ascending order
void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to perform SCAN disk scheduling
void scan(int arr[], int head, int n, int direction)
{
    int i, j, pos, seek_time = 0, curr_pos = head;

    // Sort the request array in ascending order
    sort(arr, n);

    // Find the position of the head in the request array
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= head)
        {
            pos = i;
            break;
        }
    }

    // Move the head to the nearest end of the disk
    if (direction == 1)
    {
        for (i = pos; i < n; i++)
        {
            seek_time += abs(arr[i] - curr_pos);
            curr_pos = arr[i];
        }
        seek_time += abs(curr_pos - (n - 1));
        curr_pos = n - 1;
        for (i = pos - 1; i >= 0; i--)
        {
            seek_time += abs(arr[i] - curr_pos);
            curr_pos = arr[i];
        }
    }
    else if (direction == -1)
    {
        for (i = pos - 1; i >= 0; i--)
        {
            seek_time += abs(arr[i] - curr_pos);
            curr_pos = arr[i];
        }
        seek_time += abs(curr_pos - 0);
        curr_pos = 0;
        for (i = pos; i < n; i++)
        {
            seek_time += abs(arr[i] - curr_pos);
            curr_pos = arr[i];
        }
    }

    // Print the total seek time
    printf("Total seek time = %d\n", seek_time);
}

// Driver function
int main()
{
    int n, head, direction, i;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the direction (1 for right, -1 for left): ");
    scanf("%d", &direction);
    scan(arr, head, n, direction);
    return 0;
}
