#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], nxt[500005], z[300005], cnt[300005];
signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        nxt[i] = z[a[i]];
        z[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cnt[a[j]]++;
            while (nxt[j]) j = nxt[j];
        }
    }
    for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
    return 0;
}
