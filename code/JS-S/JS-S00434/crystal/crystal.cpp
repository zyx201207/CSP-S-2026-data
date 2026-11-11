#include <bits/stdc++.h>
using namespace std;

#define int long long
int a[500050], sum[500050];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            if ((a[j] - a[i] > m)) {sum[j] = -1; break;}
            sum[j] += ((a[j] - a[i] >= 0 && sum[j] != -1) ? (a[j] - a[i]) : 0);
        }
    for (int i = n; i >= 1; i--)
    {
        int now = sum[i];
        if (now <= m && now != -1)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
