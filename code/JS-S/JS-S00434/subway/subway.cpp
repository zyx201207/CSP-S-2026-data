#include <bits/stdc++.h>
using namespace std;

#define int long long
int c, n, m, d, q;
int w[500050], a[500050], t[500050];
struct sta
{
    int dis1, dis2;
}
s[500050];

void solve(x, y)
{

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> s[i].dis1;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) cin >> a[i] >> t[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}
