#include <bits/stdc++.h>
#define int long long

using namespace std;

constexpr int N = 5e5 + 10;
int a[N], pre[N];
int n, m; 

bool check(int x) {
    for (int i = 1; i + x - 1 <= n; i++) {
        int tot = x * a[i + x - 1] - (pre[i + x - 1] - pre[i - 1]);
        if (tot <= m) return true;
    }
    return false;
}

signed main() {
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    int l = 0, r = n, ans = 0; 
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    } 

    cout << ans << '\n';

    return 0;   
}