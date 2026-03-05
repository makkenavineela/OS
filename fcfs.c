#include<stdio.h>
struct node{
    int at;
    int wt;
    int bt;
    int tat;
    int ct;
};
#define max 10
void sort(struct node process[],int n);
void FCFS(struct node process[],int n);

int main(){
    struct node process[max];
    int n;
    printf("enter the number of procress:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nenter arrival time for process %d :",i);
        scanf("%d",&process[i].at);
        printf("\nenter brust time for process %d :",i);
        scanf("%d",&process[i].bt);
    }
    sort(process,n);
    FCFS(process,n);


}
void sort(struct node process[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(process[j].at > process[j+1].at){
                    struct node k=process[j];
                    process[j]=process[j+1];
                    process[j+1]=k;

            }
        }
    }
}
void FCFS(struct node process[],int n){
    int t=0;
    for(int i=0;i<n;i++){
        if(t<process[i].at){
            t=process[i].at;
        }
        process[i].wt=t-process[i].at;
        process[i].ct=t+process[i].bt;
        process[i].tat=process[i].ct-process[i].at;
        t = t + process[i].bt;
    }
    printf("\n%-5s%-5s%-5s%-5s%-5s%-5s\n", "PID", "AT", "BT", "CT", "WT", "TAT");
    for (int i = 0; i < n; i++)
    {
        printf("%-5d%-5d%-5d%-5d%-5d%-5d\n", i, process[i].at, process[i].bt, process[i].ct, process[i].wt, process[i].tat);
    }

    float awt = 0.0, atat = 0.0;

    for (int i = 0; i < n; i++)
    {
        awt += process[i].wt;
        atat += process[i].tat;
    }

    awt = awt / n;
    atat = atat / n;

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);
}
