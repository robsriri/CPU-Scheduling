#include <stdio.h>
void main()
{
    int n;
    printf("No of Process  :  ");
    scanf("%d", &n);
    int AT[n], BT[n], CT[n], WT[n], TAT[n];
    printf("Enter the AT & BT of Process\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t", i);
        scanf("%d%d", &AT[i], &BT[i]);
    }
    float AvgWT = 0.0;
    float AvgTAT = 0.0;

    int flag[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = 0;                                               /*initializing all the values in the array, flag ,to 0 */
    }

    int current_time = AT[0], min, k;
    for (int j = 0; j < n; j++)
    {
        min = 100;
        k = 0;
        for (int i = 0; i < n; i++)
        {
            if (flag[i] == 0)                                    /* i.e. if the process is not completed*/
            {
                if (AT[i] <= current_time)
                {
                    if (BT[i] < min)
                    {
                        min = BT[i];
                        k = i;
                    }
                }
            }
        }
        CT[k] = min + current_time;
        current_time = current_time + min;
        flag[k] = 1;                                               /*update the value of flag array at k th index to 1 which shows that it is completed*/
        WT[k] = CT[k] - (BT[k] + AT[k]);
        TAT[k] = CT[k] - AT[k];
        AvgTAT += TAT[k];
        AvgWT += WT[k];
    }

    AvgWT = AvgWT / n;
    AvgTAT = AvgTAT / n;

    printf("\nAT BT WT TAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  %d  %d  %d\n", AT[i], BT[i], WT[i], TAT[i]);
    }
    printf("\nAverage WT : %f Units\n", AvgWT);
    printf("Average TAT : %f Units", AvgTAT);
}
