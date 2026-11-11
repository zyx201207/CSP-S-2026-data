#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 5e5 + 5;

int n, k, a[kMaxN], s[kMaxN], ans;

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = i + 1;
    for (; l + 1 < r;) {
      int m = l + r >> 1;
      ((i - m + 1) * a[i] - s[i] + s[m - 1] <= k) ? (r = m) : (l = m);
    }
    ans = max(ans, i - r + 1);
  }
  cout << ans;
  return 0;
}