#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], s[N];
deque<int> q;
bool check(int k) {
    q.clear(); int mx = 0, ans = 0;
    for (int i = 1;i <= n;i ++) {
        while (!q.empty() && i - q.back() >= k) q.pop_back();
        while (!q.empty() && a[q.front()] <= a[i]) q.pop_front();
        q.push_front(i); if (i < k) continue;  // mx = a[i] !!!
        mx = a[q.back()]; ans = mx * k - (s[i] - s[i - k]);
        if (ans <= m) return 1;
    } return 0;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;i ++) s[i] = s[i - 1] + a[i];
    int l = 1, r = n, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    } cout << ans << "\n";
}