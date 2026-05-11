#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], finish[n], safe[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);


    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }


    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }


    printf("\nInitial Available Resources:\n");
    for(i = 0; i < m; i++) {
        printf("%d ", avail[i]);
    }
    printf("\n");


    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1) {

                    printf("\nP%d is executed", i);

                    printf("\nAvailable before execution: ");
                    for(k = 0; k < m; k++)
                        printf("%d ", avail[k]);

                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    printf("\nAvailable after execution: ");
                    for(k = 0; k < m; k++)
                        printf("%d ", avail[k]);

                    printf("\n");

                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n) {
        printf("\nSystem is in SAFE state\n");

        printf("Safe Sequence: ");
        for(i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    }
    else {
        printf("\nSystem is NOT in safe state");
    }

    return 0;
}
