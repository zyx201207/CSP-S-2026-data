#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
const int MAXN = 1e6 * 2 + 10;
ll a[MAXN],b[MAXN];
bool f[MAXN];
ll ans = 0;
void dfs(ll des)
{
    if(des == m)
    {
        ll h = b[0];
        for(int i = 1;i < m;i++)
        {
            h = h & b[i];
        }
        ans = max(ans,h);
        return ;
    }
    for(int i = des;i < n;i++)
    {
        if(!f[i])
        {
            b[des] = a[i];
            f[i] = true;
            dfs(des + 1);
            f[i] = false;
        }
    }
    return ;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    fill(f,f + MAXN,false);
    for(int i = 0;i < n;i++)
    {
        scanf("%lld", &a[i]);
    }
    dfs(0);
    printf("%lld", ans);
}
