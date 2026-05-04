#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], at[20], ct[20], temp;
    int i, j, pos;
    float twt = 0.0, ttat = 0.0, awt, att;
    int current_time = 0, completed = 0;
    int visited[20] = {0};

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    while (completed < n) {
        int min_bt = 9999;
        pos = -1;

        // Find process with minimum burst time among arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && visited[i] == 0) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    pos = i;
                }
            }
        }

        // If no process has arrived, increment time
        if (pos == -1) {
            current_time++;
        } else {
            wt[pos] = current_time - at[pos];
            current_time += bt[pos];
            ct[pos] = current_time;
            tat[pos] = ct[pos] - at[pos];
            visited[pos] = 1;
            completed++;
        }
    }

    // Calculate averages
    for (i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }

    awt = twt / n;
    att = ttat / n;

    // Output Table
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", att);

    return 0;
}
