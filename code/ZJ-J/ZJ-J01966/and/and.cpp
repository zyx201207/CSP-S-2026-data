#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n, m;
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == 1) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, a[i]);
        return cout << ans, 0;
    }
    if (m == n) {
        int ans = a[1];
        for (int i = 1; i <= n; i++)
            ans &= a[i];
        return cout << ans, 0;
    }
    if (m == 2) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans = max(ans, a[i] & a[j]);
        return cout << ans, 0;
    }
    if (n <= 20) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans = max(ans, a[i] & a[j]);
    }
    sort(a.begin() + 1, a.end());
    cout << a[n - m + 1];
    return 0;
}