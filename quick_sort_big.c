#define MAX 20

extern int compare(char *a, char *b);

extern void print(char *a[], int n);

void swap(char *k[], int a, int b) {
    char *tmp = k[a];
    k[a] = k[b];
    k[b] = tmp;
}

//
void quick(char *k[], int s, int t) {
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
            } while (compare(k[i], k[s]) <= 0 && i < t);
            //循环从右往左进行
            //循环终止的两种情况，1是遇到一个元素比基准元素小，2是达到最小位置
            do {
                j--;
            } while (compare(k[j], k[s]) >= 0 && j > s);

            if (i < j) {
                //变为指针的位置交换
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

void quicksort(char *k[], int n) {
    quick(k, 0, n - 1);
}

#include <stdio.h>

int main() {
    char arr[MAX][102];
    char *a[MAX];
    int i, n;

    printf("Enter total elements (n <= %d) : ", MAX);
    scanf("%d", &n);
    n = n < MAX ? n : MAX;

    printf("Enter %d Elements : ", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        a[i] = arr[i];
    }

    printf("\nARRAY  : ");
    print(a, n);

    quicksort(a, n);

    printf("\nSORTED : ");
    print(a, n);
    printf("\n");

    return 0;
}

