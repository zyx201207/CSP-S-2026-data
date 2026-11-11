#include <bits/stdc++.h>
using namespace std;
int n;
long long d;
long long x[2000005];
long long cnt = 0;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, i1;
    bool f1 = 0, f2 = 1;
    scanf("%d %d", &c, &t);
    while (t--)
    {
        f1 = 0, f2 = 1;
        scanf("%d %lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        for (int i = 2; i < n; i++)
        {
            if (x[i] - x[1] <= d && x[n] - x[i] <= d)
                f1 = 1, i1 = i;
            if (f2 && x[i + 1] - x[i] != x[i] - x[i - 1])
                f2 = 0;
        }
        long long dif = x[2] - x[1], v1;
        if (d < (dif << 1))
        {
            printf("0\n");
            continue;
        }
        v1 = d + (d / dif - 1) * dif;
        printf("%lld\n", (x[n] - (x[1] + v1) + dif) / dif);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}