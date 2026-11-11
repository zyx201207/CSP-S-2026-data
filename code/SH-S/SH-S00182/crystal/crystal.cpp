#include <stdio.h>
#include <algorithm>
int n;
long long m;
long long a[500001];
long long sum[500001];
bool ok(int x)
{
    for (int i = 1; i + x - 1 <= n; ++i)
    {
        const int l = i, r = i + x - 1;
        if (a[r] * x - (sum[r] - sum[l - 1]) <= m)
            return true;
    }
    return false;
}
int main(void) {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (ok(mid))
            l = mid + 1;
        else
            r = mid;
    }
    printf("%d\n", l - (!ok(l)));
    return 0;
}
