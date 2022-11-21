void swap(int k[], int a, int b) {
    int tmp = k[a];
    k[a] = k[b];
    k[b] = tmp;
}

//
void quick(int k[], int s, int t) {
    int i, j;

    if (s < t) {
        i = s;
        j = t + 1;

        while (1) {
            //k[s]是基准元素
            //找到一个位置，左边的元素都比基准元素小，右边的元素都比基准元素大
            //循环从左往后进行
            //循环终止的两个情况，1是遇到一个元素比基准元素大，2是达到最大位置
            do {
                i++;
            } while (k[i] <= k[s] && i < t);
            //循环从右往左进行
            //循环终止的两种情况，1是遇到一个元素比基准元素小，2是达到最小位置
            do {
                j--;
            } while (k[j] >= k[s] && j > s);

            if (i < j) {
                swap(k, i, j);
            } else {
                break;
            }
        }
        swap(k, s, j);
        quick(k, s, j - 1);
        quick(k, j + 1, t);
    }
}

void quicksort(int k[], int n) {
    quick(k, 0, n - 1);
}

#include <stdio.h>

int main() {
//    int arr[] = {5, 4, 3, 2, 1};
//    int n = 11;
//    int arr[] = {3, 10, 8, 100, 20, 6, 5, 11000, 23, 84, 829};
    int n = 2;
    int arr[] = {1234,10};
    quicksort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

