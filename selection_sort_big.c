#include "string.h"
#include <stdio.h>

#define MAX 20

void print(char *a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\t", a[i]);
    }
}

int compare(char *a, char *b) {
    int alen = strlen(a);
    int blen = strlen(b);
    // 如果是一个正数与一个负数进行比较
    if (a[0] != '-' && b[0] != '-') {
        // 都为正，先比较长度，长度大的值大，长度一样的，进行字符串比较
        if (alen != blen) {
            return alen > blen ? 1 : -1;
        }
        return strcmp(a, b);
    } else if (a[0] == '-' && b[0] == '-') {
        // 都为负，先比较长度，长度小的值大，长度一样的，进行字符串比较，结果取反
        if (alen != blen) {
            return blen > alen ? 1 : -1;
        }
        return -strcmp(a, b);
    } else {
        // 一正一负
        if (a[0] == '-') {
            return -1;
        } else {
            return 1;
        }
    }
}

void selection_sort(char *a[], int len) {
    int i, j, min;
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (compare(a[j], a[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            char *tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
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

    selection_sort(a, n);

    printf("\nSORTED : ");
    print(a, n);
    printf("\n");

    return 0;
}