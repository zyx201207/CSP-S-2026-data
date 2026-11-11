#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("crystal.in", "r", stdin),
  freopen("crystal.out", "w", stdout);
  int n, m; cin >> n >> m;
  vector<int> a(n + 1), pre(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  auto check = [&](int l, int r) {
    int len = r - l + 1;
    int cur = pre[r] - pre[l - 1];
    return cur + m >= len * a[r];
  };
  int ans = 0;
  for (int l = 1, r = 1; r <= n; r++) {
    while (!check(l, r)) l++;
    ans = max(ans, r - l + 1);
  }
  cout << ans << endl;
  return 0;
}