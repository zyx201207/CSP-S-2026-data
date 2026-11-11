#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2 * 1e6 + 10;
struct zfc
{
    ll a;
    char b;
}v[MAXN];
ll l = 1,r;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n;
    scanf("%lld", &n);
    r = n;
    for(ll i = 1;i <= n;i++)
    {
        scanf("%lld %c", &v[i].a, &v[i].b);
    }
    ll ans = 0;
    while(l < r)
    {
        if(v[l].a == v[r].a)
        {
            if(v[l].b != v[r].b)
                ans += v[l].a;
            l++,r--;
        }
        else
        {
            if(v[l].a > v[r].a)
            {
                if(v[l].b != v[r].b) ans += v[r].a;
                v[l].a -= v[r].a;
                r--;
            }
            else
            {
                if(v[l].b != v[r].b) ans += v[l].a;
                v[r].a -= v[l].a;
                l++;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
