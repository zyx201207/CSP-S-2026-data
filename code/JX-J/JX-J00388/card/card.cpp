#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[500010], vis[500010], ans[300010];
bool vis1[500010];
signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (m == 1)
    {
        cout << n << endl;
        return 0;
    }
    /*
    if (m == 2)
    {
        for (int i = n - 1; i >= 1; --i)
    }*/
    if (n <= 500)
    {
        for (int i = 1; i <= n; ++i)
        {
            memset(vis, 0, sizeof(vis));
            memset(vis1, 0, sizeof(vis1));
            for (int j = i; j <= n; ++j)
            {
                if (vis[a[j]] && !vis1[vis[j]])
                {
                    for (int k = vis[a[j]]; k < j; ++k) vis1[k] = true, vis[a[k]] = 0;
              //      cout << vis[a[j]] << " " << j << endl;
                }
                vis[a[j]] = j;
            }
          //  cout << endl;
            for (int j = i; j <= n; ++j)
            {
                if (!vis1[j]) ++ans[a[j]];
            }
        }
        for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

