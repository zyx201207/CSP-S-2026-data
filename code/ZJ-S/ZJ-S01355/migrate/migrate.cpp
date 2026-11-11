#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 1;

inline int read()
{
    int res = 0, f = 1, c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') res = res * 10 + (c - '0'), c = getchar();
    return res * f;
}

int pt_numb, T, n, d, a[N];

inline void work()
{
    int res = 0;
    n = read(), d = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 2; i + 1 < n; ++i)
    {
        int rgt = upper_bound(a + 1, a + 1 + n, a[i] + d) - upper_bound(a + 1, a + 1 + n, a[i - 1] + d);
        int lft = lower_bound(a + 1, a + 1 + n, a[i + 2] - d) - lower_bound(a + 1, a + 1 + n, a[i + 1] - d);
        res += max(0ll, lft) * max(0ll, rgt);
    }
    printf("%lld\n", res);
}

signed main()
{
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);

    pt_numb = read();
    T = read();
    while (T --) work();

    return 0;
}