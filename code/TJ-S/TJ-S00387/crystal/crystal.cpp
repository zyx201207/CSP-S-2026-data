#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    for (int r = 1, len = 1, cost = 0; r <= n; r++, len++) {
        while (cost > m) cost -= a[r - 1] - a[r - len--];
        ans = max(ans, len);
        if(r < n) cost += (a[r] - a[r - 1]) * len;
    }
    cout << ans;

    return 0;
}