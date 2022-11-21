#include<stdio.h>
#include <string.h>

#define MAX 20
#define BASE 10

extern void print(char *a[], int n);

// 取字符串的倒数第i位字符，索引从1开始，并将字符串转换为数字
int charAtReversely(char *str, int i) {
    int n = strlen(str);
    if (i > n) {
        return 0;
    }
    //如果遇到负号，直接返回0
    if (str[n - i] == '-') {
        return 0;
    }
    return str[n - i] - 48;
}

void radixsort(char *a[], int n) {
    int i, j;
    char *b[MAX];
    // m表示所有字符串长度的最大值
    int m = strlen(a[0]);
    for (i = 1; i < n; ++i) {
        if (strlen(a[i]) > m) {
            m = strlen(a[i]);
        }
    }
    for (i = 1; i <= m; i++) {
        int bucket[BASE] = {0};
        for (j = 0; j < n; j++) {
            bucket[charAtReversely(a[j], i)]++;
        }
        // 将bucket每位进行累加
        for (j = 1; j < BASE; j++) {
            bucket[j] += bucket[j - 1];
        }
        // 将字符串放到b中去，循环结束时，第i位是排好序的
        for (j = n - 1; j >= 0; j--) {
            b[--bucket[charAtReversely(a[j], i)]] = a[j];
        }
        // 重新初始化，准备开始下一轮排序
        for (j = 0; j < n; j++) {
            a[j] = b[j];
        }
    }
}

int main() {
    char arr[MAX][102];
    char *a[MAX];
    //表示所有正数
    char *positive[MAX];
    //表示所有负数
    char *negative[MAX];
    int i, n, positiveNum = 0, negativeNum = 0;

    printf("输入元素的总个数 (n <= %d) : ", MAX);
    scanf("%d", &n);
    n = n < MAX ? n : MAX;

    printf("输入 %d 元素 : \n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        a[i] = arr[i];
        if (a[i][0] == '-') {
            negative[negativeNum++] = a[i];
        } else {
            positive[positiveNum++] = a[i];
        }
    }


//    printf("\n排序前  : \n");
//    print(a, n);

    radixsort(positive, positiveNum);
    // 负数比较的时候由于没有考虑开头的负号，比较的结果需要翻转过来才是正确的
    radixsort(negative, negativeNum);
    int j = 0;
    for (i = negativeNum - 1; i >= 0; i--) {
        a[j++] = negative[i];
    }
    for (i = 0; i < positiveNum; i++) {
        a[j++] = positive[i];
    }

    printf("\n-------------");
    printf("\n排序后 : \n");
    print(a, n);
    printf("\n");

    return 0;
}

