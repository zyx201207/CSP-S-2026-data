#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5 + 9;
int n, k, a[N], s[N];
signed main() {
#ifndef LOCAL
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 1, r = i;
    while (l < r) {
      int m = (l + r + 1) >> 1;
      if (a[i] * m - (s[i] - s[i - m]) <= k) l = m;
      else r = m - 1;
    }
    // cerr << l << '\n';
    ans = max(ans, l);
  }
  cout << ans;
}