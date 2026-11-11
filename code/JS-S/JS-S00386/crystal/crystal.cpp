#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n;
ll m, ans;
ll a[N], cha[N], dp[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (n <= 5000)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i + 1] == a[i]) continue;
            for (int j = 1; j < i; j++)
            {
                cha[j] = a[i] - a[j];
                // cout << cha[j] << ' ';
            }
            // cout << '\n';
            sort(cha + 1, cha + i);
            ll cnt = 0, x = 1;
            for (int j = i - 1; j >= 1; j--)
            {
                if (cnt + cha[j] <= m)
                {
                    cnt += cha[j];
                    x++;
                }
            }
            // cout << x << ' ';
            ans = max(x, ans);
        }
        cout << ans;
    }
    else
    {
        if (a[2] - a[1] == a[3] - a[2])
        {
            ll x = a[2] - a[1];
            for (int i = 2; i <= n; i++)
            {
                ll cnt = x * (i - 1) * i / 2;
                if (cnt > m)
                {
                    cout << i - 1;
                    return 0;
                }
            }
        }
    }
    return 0;
}
