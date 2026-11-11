#include<bits/stdc++.h>

using namespace std;

int n, maxn = 1;
long long m, a[500010], d[500010];

bool tp = 1;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);

    long long c = a[2] - a[1];
    for(int i = 3; i <= n; ++i)
    {
        if(a[i]- a[i-1] != c)
        {
            tp = 0;
            break;
        }
    }
    if(tp)
    {
        for(int i = 1; i < n; ++i)
        {
            long long sum = (1 + i) * i / 2;
            if(c * sum <= m)  maxn++;
        }
        printf("%d", maxn);
        return 0;
    }

    for(int i = 1; i < n; ++i)
    {
        d[i] = a[i+1] - a[i];
    }
    for(int i = 1; i < n; ++i)
    {
        long long ans = 0;
        if(i + maxn - 1 >= n)  break;
        for(int len = 1; len <= n - i; ++len)
        {
            ans += d[i + len -1] * len;
            if(ans > m)
            {
                maxn = max(maxn, len);
                break;
            }
        }
    }
    printf("%d", maxn);


    return 0;
}
