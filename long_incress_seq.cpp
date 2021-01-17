#include <stdio.h>


int lis(int * arr, int n) {
    
    int max_len = 0;
    for (int i = 0; i < n; i++) {

        int len = 1;
        int prev = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > prev) {
                len++;
                prev = arr[j];
            }
        }
        if (len > max_len) max_len = len;
    }

    return max_len;
}

int main2()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %dn",
        lis(arr, n));
    return 0;
}