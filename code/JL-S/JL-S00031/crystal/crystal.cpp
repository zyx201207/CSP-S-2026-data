#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        while (l <= r) {
            long long cnt = r - l + 1;
            long long cost = a[r] * cnt - (pre[r] - pre[l - 1]);
            if (cost <= m) break;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
