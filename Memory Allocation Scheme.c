#include <stdio.h>
#include <stdlib.h>
main()
{
    int i, j, flag, x, y, min, alloc[100], k = 0, index, bestIdx, size1[100], size2[100];
    int size[6] = {300, 600, 350, 200, 750, 125};
    int process[5] = {115, 500, 358, 200, 375};
    for (i = 0; i < 6; i++)
    {
        size1[i] = size[i];
        size2[i] = size[i];
    }
    printf("-------------------------------------First Fit Allocation-------------------------------------\n\n");
    for (j = 0; j < 5; j++)
    {
        flag = 0;
        for (i = 0; i < 6; i++)
        {
            if (size[i] >= process[j])
            {
                flag = 1;
                x = size[i];
                size[i] = size[i] - process[j];
                y = size[i];
                break;
            }
        }
        if (flag == 1)
        {
            printf("Process of size %d is allocated in the memory block of %d and new hole is created of size %d\n", process[j], x, y);
        }
        else
            printf("Process of size %d is not allocated because sufficient contiguous memory hole is not available to load the process.\n", process[j]);
    }
    printf("\n-------------------------------------Best Fit Allocation-------------------------------------\n\n");
    for (j = 0; j < 5; j++)
    {
        index = -1;
        for (i = 0; i < 6; i++)
        {
            if (size1[i] >= process[j])
            {
                if (index == -1)
                    index = i;
                else if (size1[index] > size1[i])
                    index = i;
            }
        }
        if (index != -1)
        {
            x = size1[index];
            size1[index] -= process[j];
            y = size1[index];
            printf("Process of size %d is allocated in the memory block of %d and new hole is created of size %d\n", process[j], x, y);
        }
        else
            printf("Process of size %d is not allocated because sufficient contiguous memory hole is not available to load the process.\n", process[j]);
    }
    printf("\n-------------------------------------For worst fit allocation-------------------------------------\n\n");
    for (j = 0; j < 5; j++)
    {
        index = -1;
        for (i = 0; i < 6; i++)
        {
            if (size2[i] >= process[j])
            {
                if (index == -1)
                    index = i;
                else if (size2[index] < size2[i])
                    index = i;
            }
        }
        if (index != -1)
        {
            x = size2[index];
            size2[index] -= process[j];
            y = size2[index];
            printf("Process of size %d is allocated in the memory block of %d and new hole is created of size %d\n", process[j], x, y);
        }
        else
            printf("Process of size %d is not allocated because sufficient contiguous memory hole is not available to load the process.\n", process[j]);
    }
}
