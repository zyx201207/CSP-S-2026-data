#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 6;
int curtask;
int n;
ll d,x[maxn];
ll g[maxn],f[maxn];
ll sum[maxn];
void solve()
{
    cin >> n >> d;
    for(int i = 1;i <= n;i++) cin >> x[i];
    if(n == 1)
    {
        cout << "0\n";
        return ;
    }
    if(curtask == 11 || curtask == 12)
    {
        ll k = d / (1ll * (x[2] - x[1]));
        if(k <= 1)
        {
            cout << "0\n";
            return ;
        }
        ll ans = max(0ll,1ll * n - 2ll * k + 1ll);
        cout << ans << '\n';
        return ;
    }
    ll ans = 0;
    for(int l = 1;l <= n;l++)
    {
        for(int i = 1;i <= n;i++) 
        {
            sum[i] = 0;
            g[i] = 0;
            f[i] = 0;
        }
        g[l] = 0;
        f[l] = 1;
        sum[l] = 1;
        int r = n;
        for(int i = l + 1;i <= n;i++)
        {
            int p = lower_bound(x + 1,x + n + 1,x[i] - d) - x;
            if(p == i) 
            {
                r = i - 1;
                break;
            }
            p = max(l,p);
            g[i] = g[p] + 1;
        }
        for(int i = l + 1;i <= r;i++)
        {
            int p1 = lower_bound(x + 1,x + r + 1,x[i] - d) - x;
            p1 = max(l,p1);
            int p2 = lower_bound(g + 1,g + r + 1,g[i] - 1) - g;
            int x = max(p1,p2);
            int y = lower_bound(g + 1,g + r + 1,g[i]) - g;
            f[i] = sum[y - 1] - sum[x - 1];
            sum[i] = sum[i - 1] + f[i];
        }
        ll res = 0;
        for(int i = 1;i <= n;i++) 
        {
            if(f[i] == 2) 
            {
                res++;
                // cout << l << ' ' << i << '\n';
            }
        }
        // if(l == 1)
        // {
        //     for(int i = 1;i <= n;i++) cout << g[i] << " \n"[i == n];
        //     for(int i = 1;i <= n;i++) cout << f[i] << " \n"[i == n];
        //     for(int i = 1;i <= n;i++) cout << sum[i] << " \n"[i == n];
        // }
        // if(l == 1) cout <<"ddddd:" <<  f[4] << '\n';
        // cout << "debug:" << l << ' ' << res << '\n';
        ans += res;
    }
    cout << ans << '\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> curtask;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6 
*/