#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int n, m;
int maxn, minn = INT_MAX;
int a[N];
int q[N];
bool check(int xx)
{
    // cout << "check(" << xx << ") : " << endl;
    int cnt = 0;
    int ans = INT_MAX;
    for (int i = 1; i <= xx; ++ i )
    {
        cnt += a[xx] - a[i];
    }
    // cout << "cnt = " << cnt << endl;
    ans = min(ans, cnt);
    // cout << "n = " << n << endl;
    // cout << "xx = " << xx << endl;
    // cout << "n - xx + 1 = " << n - xx + 1 << endl;
    for (int i = 2; i <= n - xx + 1; ++ i )
    {
        // cout << "i = " << i << endl;
        // [i, i + xx - 1]
        cnt -= a[i + xx - 2] - a[i - 1];
        // cout << "cnt -= " << a[i + xx - 2] - a[i - 1] << ", cnt = " << cnt << endl;
        cnt += (a[i + xx - 1] - a[i + xx - 2]) * xx;
        // cout << "cnt += " << (a[i + xx - 1] - a[i + xx - 2]) * xx << ", cnt = " << cnt << endl;
        // cout << "ans = " << ans;
        ans = min(ans, cnt);
        // cout << " -> " << ans << endl;
    }
    return ans <= m;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i )
    {
        scanf("%d", &a[i]);
    }
    sort (a + 1, a + n + 1);
    // for (int i = 1; i <= n; ++ i ) cout << "a[" << i << "] = " << a[i] << endl;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << r << endl;
    return 0;
}