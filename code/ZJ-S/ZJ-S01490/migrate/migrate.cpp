#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
using p64 = std::pair<i64, i64>;
const i32 inf32 = 1e9;
const i64 inf64 = 2e18;
void solve(i32 _);
signed main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
  freopen("migrate.err", "w", stderr);
	int c, T = 1;
	std::cin >> c >> T;
	while (T--) solve(c);
}
void solve(i32 _) {
  std::cerr << "testcase" << endl;
	i32 n;
	i64 d;
	std::cin >> n >> d;
  std::vector<i64> a(n + 2, 0), diff(n + 2, 0);
  for (i32 i = 1; i <= n; i++) std::cin >> a[i];
  std::vector<i32> ts(n + 2, 0), nor(n + 2, 0);
  // if and only if w_0 + w_1 > d, w_1 + w_2 <= d, w_2 + w_3 <= d, w_1 + w_2 + w_3 > d, w_3 + w_4 > d
  auto check = [&](i32 st, i32 ed) -> i32 {
    if (ed - st != 3) return 0;
    if (not (a[st + 2] - a[st] <= d and a[ed] - a[ed - 2] <= d and a[ed] - a[st] > d)) return 0;
    if (st != 1 and a[st + 1] - a[st - 1] <= d and ed != n and a[ed + 1] - a[ed - 1] <= d) return -1;
    if (st == 1 or a[st + 1] - a[st - 1] <= d) return -2;
    if (ed != n and a[ed + 1] - a[ed - 1] <= d) return 2;
    return 1;
  }; 
  if (n <= 3) return std::cout << 0 << endl, void();
  for (i32 i = 1; i <= n; i++) ts[i] = check(i, std::min(i + 3, n));
  for (i32 i = 1; i <= n; i++) std::cerr << ts[i] << " ";
  for (i32 i = 1; i <= n - 2; i++) {
    if (a[i + 1] - a[i] <= d and a[i + 2] - a[i] > d) nor[i] = 1;
  }
  i64 ans = 0;
  for (i32 i = 1; i <= n; i++) {
    i32 l = 1, r = 1;
    if (ts[i] == 0) continue;
    if (ts[i] == 1) {
      while (l > 1 and nor[l - 1]) --l;
      while (r < n and nor[r + 1]) ++r;
    }
    if (ts[i] == -2) {
      while (r < n and nor[r + 1]) ++r;
    }
    if (ts[i] == 2) {
      while (l > 1 and nor[l - 1]) --l;
    }
    ans += (i64)l * r;
  }
  std::cout << ans << endl;
}

// nihaoya, woyaowandanle.
// i can't solve this ez problem,,,