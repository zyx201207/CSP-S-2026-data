#include <bits/stdc++.h>
#define int long long

using I128 = __int128;

const int kMaxN = 5e5 + 25;

int n, m, ans;
I128 s[kMaxN], a[kMaxN];

signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  std::cin >> n >> m;
  for (int i = 1, x; i <= n; i++) {
    std::cin >> x, a[i] = x;
  }
  std::sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  int l = 1, r = 0;
  for (; r < n;) {
    for (; r < n && a[r + 1] * (r + 1 - l + 1) - (s[r + 1] - s[l - 1]) <= m; r++) {
    }
    ans = std::max(ans, r - l + 1);
    l++;
  }
  std::cout << ans;
  return 0;
}
