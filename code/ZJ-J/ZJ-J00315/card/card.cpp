#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxn = 5e5 + 100;

int a[maxn];
int dp[maxn];

constexpr int maxm = 3e5 + 100;
int lst[maxm];

int ans[maxm];

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    
    int n, m;
    scanf("%lld%lld", &n, &m);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    for(int i = 1; i <= n; ++i)
    {
        lst[a[i]] = max(lst[a[i]], i);
    }

    for(int i = 1; i <= n; ++i)
    {
        ++dp[lst[a[i]]];
    }

    for(int i = 1; i < n; ++i)
    {
        int nxtpos = lst[a[i+1]];
        dp[nxtpos] += dp[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        ans[a[i]] += dp[i];
    }
    
    for(int i = 1; i <= m; ++i)
    {
        printf("%lld ", ans[i]);
    }

    return 0;
}