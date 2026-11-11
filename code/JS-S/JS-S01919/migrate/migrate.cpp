#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000005;
int a[N], n, f[N], sf[N], sum[N];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            sf[i] = 0;
            for (int i = 1; i <= n; i++)
                sum[i] = 0;
            sum[0] = 1;
            int now = 0, x = i;
            for (int j = i + 1; j <= n; j++)
            {
                while (a[j] - a[x] > d)
                {
                    sum[sf[x]] -= f[x];
                    while (sum[now] == 0)
                        now++;
                    x++;
                }
                f[j] = sum[now];
                sf[j] = now + 1;
                sum[now + 1] += f[j];
                if (f[j] == 2)
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}