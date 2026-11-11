#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxn = 2e5 + 100;
constexpr int maxk = 33;

int a[maxn];
bool vis[maxn];

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    scanf("%lld%lld", &n, &m);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    
    int ans = 0;

    for(int k = 30; k >= 0; --k)
    {
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(vis[i]) continue;
            if((a[i] >> k) & 1)
            {
                ++cnt;
            }
        }
        if(cnt >= m)
        {
            ans += (1LL << k);
            for(int i = 1; i <= n; ++i)
            {
                if(vis[i]) continue;
                if(!((a[i] >> k) & 1))
                {
                    vis[i] = true;
                }
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}