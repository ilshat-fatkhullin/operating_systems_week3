#include <stdio.h>

void bubble_sort(int n, int *a)
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            if (a[j - 1] > a[j])
            {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
        }
}

int main()
{
    int n = 5;
    int input[] = {5, 3, 4, 2, 1};
    bubble_sort(n, input);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", input[i]);
    }
}