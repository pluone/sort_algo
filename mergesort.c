#include <stdio.h>
// x为待排序数组，z为辅助空间，s-u, u+1-v 是两个已经排好序的子数组,
// 归并这一步的目的就是将两个有序子数组，合并为一个整体有序的数组，结果存放到z中
void merge(int x[], int z[], int s, int u, int v)
{
    int i, j, q;
    i = s;
    j = u + 1;
    q = s;
    while (i <= u && j <= v)
    {
        if (x[i] < x[j])
        {
            z[q++] = x[i++];
        }
        else
        {
            z[q++] = x[j++];
        }
    }
    while (i <= u)
    {
        z[q++] = x[i++];
    }
    while (j <= v)
    {
        z[q++] = x[j++];
    }
}

// 需要进行多轮，t表示子数组的长度，2个子数组之间进行两两排序，排完后，继续往后移动
// 如果最后剩余的长度不够2个子数组的长度，进行特殊处理
void mpass(int x[], int y[], int n, int t)
{
    int i = 0;
    while (n - i + 1 >= 2 * t)
    {
        merge(x, y, i, i + t - 1, i + 2 * t - 1);
        i = i + 2 * t;
    }
    if (n - i + 1 > t)
    {
        merge(x, y, i, i + t - 1, n);
    }
    else
    {
        for (int j = i; j <= n; j++)
        {
            y[j] = x[j];
        }
    }
}

// 用t表示归并排序的子数组的长度，一开始让t=1，表示两个相邻的元素之间进行排序，
// 然后每次迭代t变为原来的2倍，相邻的有序子数组进行排序，直至t的长度不小于待排序数n
void mergesort(int x[], int y[], int n)
{
    int t = 1;
    while (t <= n)
    {
        mpass(x, y, n - 1, t);
        t = t * 2;
        if (t <= n)
        {
            mpass(y, x, n - 1, t);
        }
        t = t * 2;
    }
}

int main(int argc, char const *argv[])
{
    int n = 7;
    int x[] = {10, 8, 5, 4, 3, 2, 1};
    printf("before sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    int y[7] = {0};
    mergesort(x, y, n);

    printf("\nafter sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", y[i]);
    }
    return 0;
}
