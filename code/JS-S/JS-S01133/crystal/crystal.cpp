#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 500010;

int n;
LL m, a[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);

    int res = 0, last = 1;
    LL c = 0;
    for (int i = 1; i <= n; i ++ )
    {
        c += (i - last) * (a[i] - a[i - 1]);
        while (c > m) c -= a[i] - a[last ++ ];
        res = max(res, i - last + 1);
    }
    printf("%d\n", res);

    return 0;
}
