#include <stdio.h>

#define MAX 20

extern int compare(char *a, char *b);

extern void print(char *a[], int n);

void swap(char *k[], int a, int b) {
    char *tmp = k[a];
    k[a] = k[b];
    k[b] = tmp;
}

//希尔排序的基本思想，
void shellsort(char *k[], int n) {
    int i, j, flag, gap = n;
    while (gap > 1) {
        gap = gap / 2;
        do {
            flag = 0;
            for (i = 0; i < n - gap; i++) {
                j = i + gap;
                if (compare(k[i], k[j]) > 0) {
                    swap(k, i, j);
                    flag = 1;
                }
            }
        } while (flag != 0);
    }
}

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

    shellsort(a, n);

    printf("\nSORTED : ");
    print(a, n);
    printf("\n");

    return 0;
}