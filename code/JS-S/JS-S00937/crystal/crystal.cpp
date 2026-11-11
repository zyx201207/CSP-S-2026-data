#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int r = 1; r <= n; ++r)
    {
        int tot = r * a[r] - sum[r];
        if (tot <= m)
        {
            ans = max(ans, r);
            continue;
        }
        int L = 1, R = r;
        while (L < R)
        {
            int flag = 0;
            int mid = (L + R) / 2;
            int cur = (r - mid + 1) * a[r] - sum[r] + sum[mid - 1];
            flag = cur <= m;
            if (!flag)
                L = mid + 1;
            else
                R = mid;
        }
        ans = max(ans, r - L + 1);
    }
    cout << ans << "\n";

    return 0;
}