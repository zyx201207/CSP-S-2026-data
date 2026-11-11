#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, a[N], cnt[N], s[N];
void dfs(int x, int sum)
{
    if (sum < s[x])
    {
        s[x] = sum;
        cnt[x] = 1;
    }
    else if (sum == s[x])
        cnt[x]++;
    else 
        return;
    for (int i = x + 1; i <= n; i++)
    {
        if (a[i] - a[x] > d)
            return;
        dfs(i, sum + 1);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            memset(cnt, 0, sizeof 0);
            memset(s, 0x3f, sizeof s);
            dfs(i, 0);
            for (int j = i; j <= n; j++)
                if (cnt[j] == 2)
                    ans++;
        }
        cout << ans << "\n";
    }
}