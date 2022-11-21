#include <stdio.h>

//希尔排序的基本思想，
void shellsort(int k[], int n) {
    int i, j, flag, gap = n;
    int temp;
    while (gap > 1) {
        gap = gap / 2;
        do {
            flag = 0;
            for (i = 0; i < n - gap; i++) {
                j = i + gap;
                if (k[i] > k[j]) {
                    temp = k[i];
                    k[i] = k[j];
                    k[j] = temp;
                    flag = 1;
                }
            }
        } while (flag != 0);
    }
}

int main() {
    int n = 11;
    int arr[] = {3, 10, 8, 100, 20, 6, 5, 11000, 23, 84, 829};
    shellsort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}