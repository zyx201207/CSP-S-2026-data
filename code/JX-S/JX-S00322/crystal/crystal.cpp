#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], sum, ans;
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a+1, a+n+1);
    for (int l = 1, r = 1; l <= n; l++)
    {
        sum -= a[r]-a[l];
        while (r<l || r<n&&sum<=m)
        {
            r++;
            sum += (r-l)*(a[r]-a[r-1]);
        }
        ans = max(ans, r-l);
    }
    cout << ans;
    return 0;
}
