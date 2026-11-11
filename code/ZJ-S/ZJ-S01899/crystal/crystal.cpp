#include <bits/stdc++.h>
using namespace std;

#define N 500007

#define int long long

int n, m, a[N], pre[N];

int check(int pos, int k)
{
    return k * a[pos] - (pre[pos] - pre[pos - k]) <= m;
}

int calc(int pos)
{
    int l = 1, r = pos, mid, ans = 1;
    while (l <= r)
    {
        mid = r - (r - l) / 2;
        if (check(pos, mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i];
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, calc(i));
    }
    cout << ans;
    return 0;
}
