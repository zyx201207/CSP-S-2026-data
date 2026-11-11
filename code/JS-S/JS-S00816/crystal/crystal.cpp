#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
long long a[N];
long long pre[N];
int n, m;
bool check(int l, int r) {
    long long use = a[r] * (r - l + 1) -(pre[r] - pre[l-1]);
    return use <= m;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i ++) pre[i] = pre[i-1] + a[i];
    int ans = 1;
    for (int i = 1; i <= n; i ++) {
        // start
        int l = i, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) {
                ans = max(ans, mid-i+1);
                l = mid + 1;
            } else r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
crystal
start : 14:43
end : 15:16
*/
