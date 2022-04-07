#include <stdio.h>
unsigned long long cnt = 0;
void tower(int n, int i, int j)
{
    int m;
    if (i == 0) {
        m = j == 1 ? 2 : 1;
    } else if (i == 1) {
        m = j == 0 ? 2 : 0;
    } else if (i == 2) {
        m = j == 0 ? 1 : 0;
    }

    if (n == 1) {
        printf("Move disk %d from %c to %c\n", 1, i + 'A', j + 'A');
        ++cnt;
    } else {
        tower(n-1, i, m);
        printf("Move disk %d from %c to %c\n", n, i + 'A', j + 'A');
        tower(n-1, m, j);
    }
}

int main()
{
    int n;
    printf("½Ð¿é¤J½L¼Æ:%d\n");
    scanf("%d", &n);
    tower(n, 0, 2);
    printf("%llu\n", cnt);
}
