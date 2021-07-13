#include<stdio.h>

int minimum(int arr[], int n)
{
    int i, m = 0;
    for(i=0; i<n; i++)
    {
        if(arr[i] < arr[m])
            m = i;
    }
    return m;
}

int maximum(int arr[], int n)
{
    int i, m = 0;
    for(i=0; i<n; i++)
    {
        if(arr[i] > arr[m])
            m = i;
    }
    return m;
}

void FIFO(int str[], int nframes, int nref)
{
    int i, j, flag, last_in = -1, page_fault = 0, frames[nframes];
    for(i=0; i<nref; i++)
    {
        flag = 0;
        for(j=0; j<nframes; j++)
        {
            if(str[i]==frames[j])
                flag = 1;
        }
        if(flag == 0)
        {
            last_in = (last_in+1)%nframes;
            frames[last_in] = str[i];
            page_fault++;
        }
    }
    printf("Final Frames :\n");
    for(i=0; i<nframes; i++)
        printf("%d\t",frames[i]);

    printf("No of Page faults : %d\n",page_fault);
}

void LRU(int str[], int nframes, int nref)
{
    int i, frames[nframes], page_faults = 0, full = 0, age[nframes], j, flag, leastRecent;
    for(i=0; i<nref; i++)
    {
        if(full < nframes)
        {
            frames[full] = str[i];
            age[full] = i;
            full++;
            page_faults++;
        }
        else
        {
            flag = 0;
            for(j=0; j<nframes; j++)
            {
                if(str[i]==frames[j])
                    {
                        flag = 1;
                        age[j] = i;
                    }
            }
            if(flag == 0)
            {
                leastRecent = minimum(age, nframes);
                frames[leastRecent] = str[i];
                age[leastRecent] = i;
                page_faults++;
            }
        }
    }
    printf("Final Frames :\n");
    for(i=0; i<nframes; i++)
        printf("%d\t",frames[i]);
    printf("No of Page faults : %d\n",page_faults);
}

void Optimal(int str[], int nframes, int nref)
{
    int i, frames[nframes], page_faults = 0, full = 0, j, flag, freq[nframes], optimal, k;
    for(i=0; i<nref; i++)
    {
        if(full < nframes)
        {
            frames[full] = str[i];
            full++;
            page_faults++;
        }
        else
        {
            flag = 0;
            for(j=0; j<nframes; j++)
            {
                if(str[i]==frames[j])
                    {
                        flag = 1;
                    }
            }
            if(flag == 0)
            {
                for(j=0; j<nframes; j++)
                {
                    int f = 0;
                    for(k=i; k<nref; k++)
                    {
                        if(str[k] == frames[j])
                            {
                                freq[j] = k;
                                f = 1;
                                break;
                            }
                    }
                    if(f==0)
                        freq[j] = 100;
                }
                optimal = maximum(freq, nframes);
                frames[optimal] = str[i];
                page_faults++;
            }
        }
    }
    printf("Final Frames :\n");
    for(i=0; i<nframes; i++)
        printf("%d\t",frames[i]);

    printf("No of Page faults : %d\n",page_faults);
}

int main(void)
{
    int page[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int nref = 20;
    int nframes = 3;
    FIFO(page, nframes, nref);
    LRU(page, nframes, nref);
    Optimal(page, nframes, nref);
}
