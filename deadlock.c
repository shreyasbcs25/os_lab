#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m];
    int avail[m], finish[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++) {
        int flag = 0;

        for(j = 0; j < m; j++) {
            if(alloc[i][j] != 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    int count = 0;

    while(count < n) {

        int found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(request[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1) {

                    printf("\nP%d is completed", i);

                    printf("\nAvailable before execution: ");
                    for(k = 0; k < m; k++)
                        printf("%d ", avail[k]);

                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    printf("\nAvailable after execution: ");
                    for(k = 0; k < m; k++)
                        printf("%d ", avail[k]);

                    printf("\n");

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;

        count++;
    }
    int deadlock = 0;

    printf("\nProcesses in Deadlock:\n");

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }
    if(deadlock == 0)
        printf("No Deadlock");
    return 0;
}
