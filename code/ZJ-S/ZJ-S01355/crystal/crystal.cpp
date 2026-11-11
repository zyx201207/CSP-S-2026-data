#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

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

int n, m, a[N], ans = 1;

signed main()
{
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);

    n = read(), m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1, j = 1, cur = 0; i <= n; ++i)
    {
        cur += (i - j) * (a[i] - a[i - 1]);
        while (cur > m && j < i) cur -= a[i] - a[j], ++ j;
        ans = max(ans, i - j + 1); 
    }
    printf("%lld\n", ans);

    return 0;
}