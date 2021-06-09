void swap(int *a, int *b)                                            /*swap function to swap 2 numbers */

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
    scanf("%d",&n);
    int AT[n],BT[n],PR[n],CT[n],WT[n],TAT[n],RBT[n];
    printf("Enter the AT,BT and Priority of Process\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\t",i);
        scanf("%d%d%d",&AT[i],&BT[i],&PR[i]);
    }
    float avgWT = 0.0;
    float avgTAT = 0.0;
    for(int i=0;i<n;i++)                                            /*Bubble Sort  to  sort the  inputs */
    {
        for(int j=0;j<n-1-i;j++)
        {
            if((AT+j)>(AT+j+1))                                     /*left is greater than right in the array, then swap*/
            {
                swap((AT+j),(AT+j+1));
                swap((BT+j),(BT+j+1));
                swap((PR+j),(PR+j+1));
            }
        }
    }
    int flag[n];
    for(int i=0;i<n;i++)
    {
        flag[i]=0;                                                   /*flag array and initializing all the elements to 0 first*/
    }
    int current_time=AT[0],min,k;
    for(int j=0;j<n;j++)
    {
        min=100;
        k=0;
        for(int i=0;i<n;i++)
        {
            if(flag[i]==0)                                          /* if  flag value is 0  it means that the process is not completed*/
            {
                if(AT[i]<=time)
                {
                    if(PR[i]<min)
                    {
                        min=PR[i];
                        k=i;
                    }
                }
            }
        }
        CT[k]=BT[k]+time;
        time=time+BT[k];
        flag[k]=1;
        WT[k]=CT[k]-(BT[k]+AT[k]);
        TAT[k]=CT[k]-AT[k];
        avgTAT += TAT[k];
        avgWT += WT[k];
    }

    avgWT = avgWT/n;
    avgTAT = avgTAT/n;

    printf("\n\t\tAT\tBT\tPR\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],PR[i],WT[i],TAT[i]);
    printf("\nAverage Waiting Time is %f Units\n",avgWT);
    printf("Average Turn Around Time is %f Units",avgTAT);
}
