#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N], n, m, sum[N];

bool check(int x)
{
    for (int i = x;i <= n;i++)
        if(sum[i - 1] - sum[i - x] >= a[i] * (x - 1) - m) return 1;
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;i++) sum[i] = a[i] + sum[i - 1];
    int ans = 0, l = 0, r = n;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
//15:05 pass
