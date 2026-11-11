#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m, ans, a[N], d[N], sum[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) d[i] = a[n] - a[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + d[i];
    if (sum[n] <= m)
    {
        cout << n;
        return 0;
    }
    for (int l = 1, r = 1; r <= n; l++)
        while (r <= n && sum[r] - sum[l - 1] - d[r] * (r - l + 1) <= m)
            ans = max(ans, r - l + 1), r++;
    cout << ans;
}
