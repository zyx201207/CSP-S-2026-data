#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, a[500005], c[500005], ans, tot, ton[500005], cost;
map<int, int> mp;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (mp[a[i]] == 0) mp[a[i]] = ++tot;
        ton[tot]++;
        ans = max(ans, ton[tot]);
    }
    sort(a + 1, a + n + 1);
    for (int l = 1, r = 1;r <= n;)
    {
        while (r < n && cost + (a[r+1] - a[r]) * (r - l + 1) <= m)//
        {
            cost += (a[r+1] - a[r]) * (r - l + 1);
            r++;
        }
        ans = max(ans, r - l + 1);
        if (r < n)
        {
            cost += (a[r+1] - a[r]) * (r - l + 1);
            r++;
        }
        while (l <= r && cost > m)
        {
            cost -= a[r] - a[l];
            l++;
        }
        if (r == n && cost <= m)
        {
            ans = max(ans, r - l + 1);
            break;
        }
    }
    cout << ans;
    return 0;
}
