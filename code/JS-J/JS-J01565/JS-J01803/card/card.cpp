#include <bits/stdc++.h>
using namespace std;

int n, m;

int a[500005], b[500005];

int ans[300005];

bool vis[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof vis);
        memset(b, 0, sizeof b);
        int pos = 1;
        for (int j = i; j <= n; j++)
        {
            int num = a[j];
            for (int k = 1; k <= pos; k++)
            {
                if (b[k] == num)
                {
                    pos = k;
                    break;
                }
            }
            b[++pos] = num;
        }
        for (int j = 1; j <= pos; j++) vis[b[j]] = true;
        for (int j = 1; j <= m; j++) if (vis[j]) ans[j]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
