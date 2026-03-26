#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    int at, bt, pr, rt;
    int wt, tat;
} Process;



void calculateScheduling(Process p[], int n) {
    int time = 0, completed = 0;
    int min_pr, highest;

    while (completed != n) {
        highest = -1;
        min_pr = 9999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].pr < min_pr) {
                min_pr = p[i].pr;
                highest = i;
            }
        }
        if (highest == -1) {
            time++;
            continue;
        }
        p[highest].rt--;

        if (p[highest].rt == 0) {
            completed++;
            int finish_time = time + 1;

            p[highest].tat = finish_time - p[highest].at;
            p[highest].wt = p[highest].tat - p[highest].bt;

            if (p[highest].wt < 0) p[highest].wt = 0;
        }
        time++;
    }
}


int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[MAX];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter AT, BT, Priority for P%d: ", p[i].id);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].rt = p[i].bt;
    }


    calculateScheduling(p, n);

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);


    return 0;
}

