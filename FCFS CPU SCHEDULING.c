#include<stdio.h>
void main()
{
    int n;
    printf("No of Process  :  ");
    scanf("%d",&n);
    int AT[n],BT[n],CT[n],WT[n],TAT[n];
    printf("Enter the AT & BT of Process\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\t",i);
        scanf("%d%d",&AT[i],&BT[i]);
    }
    float avgWT = 0.0;
    float avgTAT = 0.0;
    CT[0] = AT[0] + BT[0];
    TAT[0] = CT[0] - AT[0];
    WT[0] = TAT[0] - BT[0];
    for(int i=1; i<n; i++)
    {                                          /*if the arrival time of the newly arrived process is less than the completion time of the previous process*/
        if(CT[i-1]>AT[i])                     /*comparing the arrival time of the i th  process  with the completion time of previous , i-1 process*/
            CT[i] = CT[i-1] + BT[i];         /*directly add burst time to the completion time of previous process*/
        else
            CT[i] = AT[i] + BT[i];          /*otherwise add  the  burst time of the process to its arrival time and update completion time*/
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        avgTAT += TAT[i];
        avgWT += WT[i];
    }
    avgWT = avgWT/n;
    avgTAT = avgTAT/n;
    printf("\n   \tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("P[%d]\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],WT[i],TAT[i]);
    printf("\nAverage WT : %f Units\n",avgWT);
    printf("Average TAT : %f Units",avgTAT);
}
