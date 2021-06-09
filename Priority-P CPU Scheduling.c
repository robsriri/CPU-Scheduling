void swap(int *a, int *b)                                    /*swap function to swap two numbers*/
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void main()
{
    int n;
    printf("No of Process  :  ");
    scanf("%d", &n);
    int AT[n], BT[n], PR[n], CT[n], WT[n], TAT[n], RBT[n];
    printf("Enter the AT,BT and Priority of Process\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t", i);
        scanf("%d%d%d", &AT[i], &BT[i], &PR[i]);
    }

    float avgWT = 0.0;
    float avgTAT = 0.0;


    for (int i = 0; i < n; i++)                        /*Bubble Sort  to  sort the  inputs */
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*(AT + j) > *(AT + j + 1))            /*left is greater than right in the array, then swap*/
            {
                swap((AT + j), (AT + j + 1));
                swap((BT + j), (BT + j + 1));
                swap((PR + j), (PR + j + 1));
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        RBT[i] = BT[i];
        sum += BT[i];
    }

    int current_time = AT[0], min, k;                /* current time is set to the process that first comes in ready queue - by using sorted AT array*/
    for (int i = 0; i < sum; i++)
    {
        min = 100;
        k = 0;
        for (int j = 0; j < n; j++)
        for (int j = 0; j < n; j++)                  /*j is used to access the elements of the  RBT array*/
        {
            if (RBT[j] != 0)
            {
                if (AT[j] <= current_time)
                {
                    if (PR[j] < min)                 /*checking if the priority of the newly arrived process is  higher than the priority of the running process or not*/
                    {
                        min = PR[j];
                        k = j;
                    }
                }
            }
        }
        RBT[k] = RBT[k] - 1;                         /*updating the remaining burst time*/
        current_time = current_time + 1;             /*increasing the current time by 1 unit. Checking 1 unit wise*/
        CT[k] = current_time;
    }

    for (int i = 0; i < n; i++)
    {
        WT[i] = CT[i] - AT[i] - BT[i];
        TAT[i] = CT[i] - AT[i];
        avgTAT += TAT[i];
        avgWT += WT[i];
    }

    avgWT = avgWT / n;
    avgTAT = avgTAT / n;

    printf("\n\t\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], PR[i], WT[i], TAT[i]);
    }
    printf("\nAverage Waiting Time is %f Units\n", avgWT);
    printf("Average Turn Around Time is %f Units", avgTAT);
}
