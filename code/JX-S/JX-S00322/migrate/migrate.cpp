#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, a[2000006], nxt[2000006], v[2000006][5];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            int j = max(i, nxt[i-1]);
            while (j<n && a[j]-a[i]<=d) j++;
            nxt[i] = j-1;
        }
        for (int i1 = 1; i1 <= n; i1++)
        {
            for (int i2 = i1+1; i2 <= nxt[i1]; i2++)
            {
                v[i2][2]++;
                v[nxt[i2]+1][2]--;
                for (int i3 = i2+1; i3 <= nxt[i2]; i3++)
                {
                    v[i3][3]++;
                    v[nxt[i3]+1][3]--;
                }
            }
        }
        int ans = 0;
        for (int i = 2; i <= 3; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                v[j][i] += v[j-1][i];
                if (v[j][i] == 2) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
