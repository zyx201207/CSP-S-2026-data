#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 9;

int n;

LL m, a[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1;i <= n;++ i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    int ans = 0;
    LL sum = 0;
    for (int i = 1, j = 1;i <= n;++ i)
    {
        sum += (i - j) * (a[i] - a[i - 1]);
        while (sum > m)
            sum -= a[i] - a[j], ++ j;
        ans = max(ans, i - j + 1);
    }
    printf("%d\n", ans);

    return 0;
}