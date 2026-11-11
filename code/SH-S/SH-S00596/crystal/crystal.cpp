#include <cstdio>
#include <algorithm>
using namespace std;
using lonit = long long;

constexpr int kMaxN = 500'010;

int n;
lonit m;
lonit ary[kMaxN], sum[kMaxN];

inline lonit cost(lonit x) { return ary[x] * x - sum[x]; }

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &ary[i]);
    }

    sort(ary + 1, ary + 1 + n);

    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + ary[i];
    }

    int ans = 0, l = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ary[i] != ary[i - 1])
            l = 0;
        ++l;
        ans = max(ans, l);
    }

    int f = 0, len;
    for (int k = 2; k <= n; ++k)
    {
        while (!((cost(k) - (cost(f) + f * (ary[k] - ary[f]))) <= m))
            ++f;
        len = k - f;
        ans = max(ans, len);
    }

    printf("%d", ans);

    return 0;
}