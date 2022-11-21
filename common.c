#include "string.h"
#include "stdio.h"

void print(char *a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
}

int compare(char *a, char *b) {
    int alen = strlen(a);
    int blen = strlen(b);
    // 都为正，先比较长度，长度大的值大，长度一样的，进行字符串比较
    if (a[0] != '-' && b[0] != '-') {
        if (alen != blen) {
            return alen > blen ? 1 : -1;
        }
        return strcmp(a, b);
        // 都为负，先比较长度，长度小的值大，长度一样的，进行字符串比较，结果取反
    } else if (a[0] == '-' && b[0] == '-') {
        if (alen != blen) {
            return blen > alen ? 1 : -1;
        }
        return -strcmp(a, b);
        // 一正一负
    } else {
        if (a[0] == '-') {
            return -1;
        } else {
            return 1;
        }
    }
}


