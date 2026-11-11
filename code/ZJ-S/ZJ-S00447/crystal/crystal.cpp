#include <bits/stdc++.h>
#define int long long
#define elif else if
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());

    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];

    int i = 1, j = 2, ans = 1;
    while (j <= n) {
        while (i <= j && (a[j] - a[j - 1]) * (j - i + 1) - (a[j] - a[i - 1]) > m)
            i++;
        while (j <= n && (a[j] - a[j - 1]) * (j - i + 1) - (a[j] - a[i - 1]) <= m)
            j++;
        ans = max(ans, j - i);
    }
    
    cout << ans << '\n';

    return 0;
}
