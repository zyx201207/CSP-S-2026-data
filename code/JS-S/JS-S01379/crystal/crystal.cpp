#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], n, m;
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 1, l = 1, r = 2, sum = 0;
    while (r <= n)
    {
        sum += (a[r] - a[r - 1]) * (r - l);
        while (sum > m)
        {
            sum -= a[r] - a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans;
    return 0;
}