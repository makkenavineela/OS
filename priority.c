#include<stdio.h>
#define size 10
struct process{
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
    int pt;
    int done;
};
void Priority(struct process p[],int n);
void main()
{
    printf("enter no of process:");
    int n;
    scanf("%d",&n);
    struct process p[size];
    for(int i=0;i<n;i++){
        printf("enter arrival time:");
        scanf("%d",&p[i].at);
        printf("enter burst time");
        scanf("%d",&p[i].bt);
        printf("enter prority:");
        scanf("%d",&p[i].pt);
        p[i].done = 0;
    }
    Priority(p,n);

}
void Priority(struct process p[],int n){
    int completed=0;
    int t=0;
    float t_taat=0;
    float t_wt=0;
    while(completed<n){
        int idx=-1;
        int hig_pri=9999;
        for(int i=0;i<n;i++)
        {
            if((p[i].at<=t)&&(p[i].done==0)){

               if(p[i].pt<=hig_pri){
                    hig_pri=p[i].pt;
                    idx=i;
               }
               else if((p[i].pt==hig_pri)&&(p[i].at<p[idx].at)){
                    idx=i;

               }

            }
        }
        if(idx!=-1){
            p[idx].wt=t-p[idx].at;
            p[idx].ct=t+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;

            t_wt+=p[idx].wt;
            t_taat+=p[idx].tat;

            p[idx].done=1;

            completed++;
            t=p[idx].ct;
        }
        else{
            t++;
        }
    }
    printf("\nID\tAT\tBT\tPT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].at, p[i].bt, p[i].pt, p[i].ct,p[i].wt, p[i].tat);
    }
    printf("\nAverage Waiting Time: %.2f\n", t_wt / n);
    printf("Average Turnaround Time: %.2f\n", t_taat / n);

};
