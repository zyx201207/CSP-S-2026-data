#include <queue>
#include <iostream>
#include <algorithm>

using ll = long long;
const ll MAXN = 5e5+10;
ll a[MAXN];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    ll n,m;
    std::cin >> n >> m;
    for(ll i = 1;i<=n;i++)
        std::cin >> a[i];
    std::sort(a+1,a+n+1);

    int head = 1, tail = 2;
    ll cur = 0, ans = 1;
    for(ll i = 2;i<=n;i++)
    {
        tail = i;
        cur += (i-head) * (a[i]-a[i-1]);
        
        while(cur > m)
            cur -= (a[i]-a[head++]);
        
        ans = std::max(ans, ll(tail-head)+1);
    }

    std::cout << ans << std::endl;

    return 0;
}