#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000005;
ll a[N], ans = -1e9, n, m;
bool vis[N];

void dfs(long long u, long long s, long long step)
{
    if(step == m)
    {
        ans = max(ans, s);
        return;
    }

    vis[u] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(i, s & a[i], step + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    ll m = -1e9;


    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }
    if(n > 200005)
    {
        cout << m;
        return 0;
    }
    memset(vis, 0, sizeof vis);

    for(int i = 1; i <= n; i++)
    {
        dfs(i, a[i], 1);
    }

    cout << ans;
    return 0;
}
