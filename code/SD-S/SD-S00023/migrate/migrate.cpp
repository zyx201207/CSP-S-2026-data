# include <iostream>
# include <algorithm>
# define int long long
const int N = 2e6 + 5, M = 305;
int c, t, l[N], r[N], st[M][M];
int n, d, x[N], p[15];
void solvea () {
  std::cin >> n >> d;
  for (int i = 1; i <= n; i ++) {
    std::cin >> x[i];
  }
  if (n == 1) {
    std::cout << "0\n"; return;
  }
  int D = x[n] - x[n - 1];
  if (D * 2 > d) {
    std::cout << "0\n"; return;
  } else if (D * 2 <= d && d < D * 3) {
    std::cout << std::max (0ll, n - 3) << '\n';
    return;
  } else {
    std::cout << std::max (0ll, n - (2 * (d / D) - 1)) << '\n'; return;
  }
  // 1 3 5 7 9 11 13 15
  // d = 4
  // 1,7
}
void solvel () {
  std::cin >> n >> d; int res = 0;
  for (int i = 1; i <= n; i ++) std::cin >> x[i];
  if (n == 1) {
    std::cout << "0\n"; return;
  }
  for (int i = 1; i <= n; i ++) {
    for (int j = i + 2; j <= n; j ++) {
      int md = 9e18, mdcnt = 0;
      for (int mask = 0; mask <= ((1 << (j - i - 1)) - 1); mask ++) {
        int lab = i, ddd = 0; bool ok = 1;
        for (int b = j - i - 2; b >= 0; b --) {
          int bb = mask & (1 << b);
          if (!bb) continue;
          int dis = x[j - b - 1] - x[lab];
          if (dis > d) {
            ok = 0; break;
          }
          lab = j - b - 1, ddd ++;
        }
        if (x[j] - x[lab] > d) ok = 0;
        else ddd ++;
        if (ok == 1) {
          if (ddd == md) mdcnt ++;
          else if (ddd < md) mdcnt = 1, md = ddd;
        }
      }
      if (mdcnt == 2) res ++;
    }
  }
  std::cout << res << '\n';
}
void solvef () {
  std::cin >> n >> d; int res = 0;
  for (int i = 1; i <= n; i ++) std::cin >> x[i];
  if (n == 1) {
    std::cout << "0\n"; return;
  }
  for (int i = 1; i <= n; i ++) {
    l[i] = std::lower_bound (x + 1, x + n + 1, x[i] - d) - x;
    r[i] = std::upper_bound (x + 1, x + n + 1, x[i] + d) - x - 1;
  }
  for (int i = 1; i <= n; i ++) {
    int ll = std::lower_bound (l + 1, l + n + 1, r[i] - 1) - x;
    int rr = std::upper_bound (l + 1, l + n + 1, r[i] - 1) - x - 1;
    res += rr - ll + 1;
  }
  std::cout << res << '\n';
}
void solve36 () {
  std::cin >> n >> d; int res = 0;
  for (int i = 1; i <= n; i ++)
    std::cin >> x[i];
  if (n == 1) {
    std::cout << "0\n"; return;
  }
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
      st[i][j] = 9e18;
  for (int i = 1; i <= n; i ++) {
//    int ri = std::upper_bound (x + 1, x + n + 1, x[i] + d) - x - 1;
    st[i][i] = 0;
    if (x[i + 1] - x[i] <= d)
      st[i][i + 1] = 1;
  }
  for (int len = 2; len <= n; len ++) {
    for (int i = 1; i + len - 1 <= n; i ++) {
      int j = i + len - 1;
      for (int k = i + 1; k < j; k ++) {
        if (st[i][k] == 9e18 || st[k][j] == 9e18)
          continue;
        st[i][j] = std::min (st[i][k] + st[k][j], st[i][j]);
      }
      if (i - j <= d) st[i][j] = 1;
//      std::cout << i << ' ' << j << ' ' << st[i][j] << '\n';
    }
  }
//  for (int i = 1; i <= n; i ++) {
//    for (int j = i + 1; j <= n; j ++) {
//      
//    }
//  }
  for (int len = 2; len <= n; len ++) {
    for (int i = 1; i + len - 1 <= n; i ++) {
      int j = i + len - 1, la = 0;
      for (int k = i + 1; k < j; k ++) {
        if (st[i][k] == 9e18 || st[k][j] == 9e18)
          continue;
        if (st[i][j] == st[i][k] + st[k][j])
          la ++;
      }
      if (la == 2) res ++;
    }
  }
//  for (int i = 1; i <= n; i ++)
//    for (int j = i + 1; j <= n; j ++)
//      if (dp[i][j] == 2) res ++;
  std::cout << res << '\n';
  // 1 3 5 7 9 11 13
}
signed main () {
  freopen ("migrate.in", "r", stdin);
  freopen ("migrate.out", "w", stdout);
	std::cin.tie (0) -> sync_with_stdio (false);
	std::cin >> c >> t;
	if (c == 1 || c == 2) { // 8pts
	  while (t --) solvel ();
	  return 0;
  }
	if (c == 11 || c == 12) { // 8pts
	  while (t --) solvea ();
	  return 0;
  }
  // 8pts
  while (t --) solvef ();
  return 0;
  // n <= 300:
  // 如果 (u,k) 方案为 1, (k,v) 方案为 2，那么 (u,v) 符合条件
  // 区间dp 
	return 0;
}
