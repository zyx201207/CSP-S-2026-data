/*
CSP_S = max (CSP_S, 300);
bu yao chu (strings) a a a a a a a a a a.
bu yao chu (math) a a a a a a a a a a a.
bu dui a yun tang ji zi pao de bu shi hen kuai ma.
5e8 0.8s zhe me kuai hai you ren pen???

1 1
6 4
-3 0 1 2 3 4
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 3, LOG = 20;

int Test, n, f[N], g[N], jump[2][LOG][N];
ll m, a[N], pre[N], dp[N][N], dis[N][N];

void Solve () {
  cin >> n >> m, a[n + 1] = 0;
  for (int i = 1; i <= n; cin >> a[i++]) {
  }
  if (m == 1) {
    cout << 0 << '\n';
    return ;
  }
  for (int i = 1, beg = 1; i <= n; ++i) {
    while (beg < n && a[i] + m >= a[beg + 1]) {
      ++beg;
    }
    jump[0][0][i] = beg, g[i] = 1;
  }
  for (int i = n, beg = n; i; --i) {
    while (beg > 1 && a[beg - 1] >= a[i] - m) {
      --beg;
    }
    jump[1][0][i] = beg, f[i] = 1;
  }
  ll ans = 0;
  for (int i = 1; i < LOG; ++i) {
    for (int j = 1; j <= n; ++j) {
      jump[0][i][j] = jump[0][i - 1][jump[0][i - 1][j]];
      jump[1][i][j] = jump[1][i - 1][jump[1][i - 1][j]];
    }
  }
  for (int i = 1; i < LOG - 1; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (jump[0][i + 1][j] == jump[0][i][j]) {
        jump[0][i][j] = 0;
      }
      if (jump[1][i + 1][j] == jump[1][i][j]) {
        jump[1][i][j] = 0;
      }
    }
  }
  pre[1] = 1;
//  cerr << "puck" << endl;
  for (int i = 2; i <= n; ++i) {
    if (jump[1][0][jump[1][0][i] + 1]) {
      f[i] += pre[jump[1][0][jump[1][0][i] + 1] - 1];
    }
    if (jump[1][0][jump[1][0][i]]) {
      f[i] -= pre[jump[1][0][jump[1][0][i]] - 1];
    }
    pre[i] = pre[i - 1] + f[i];
  }
  pre[n] = 1, pre[n + 1] = 0;
//  cerr << "puck" << endl;
  for (int i = n - 1; i; --i) {
    if (jump[0][0][jump[0][0][i] - 1]) {
      g[i] += pre[jump[0][0][jump[0][0][i] - 1] + 1];
    }
    if (jump[0][0][jump[0][0][i]]) {
      g[i] -= pre[jump[0][0][jump[0][0][i]] + 1];
    }
//    cout << i << " " << jump[0][0][jump[0][0][i] - 1] + 1 << " " << jump[0][0][jump[0][0][i]] + 1 << '\n';
    pre[i] = pre[i + 1] + g[i];
  }
//  cerr << "puck" << endl;
  for (int p = 1; p <= n; ++p) {
    if (jump[0][0][p] >= p + 2) {
      int x = jump[0][0][p], y = jump[0][0][p] - 1, z = jump[0][0][p] - 2;
      for (int i = LOG - 1; ~i; --i) {
        int u = jump[0][i][x], v = jump[0][i][y], w = jump[0][i][z];
        if (u && v && w && (u != v || v != w)) {
          x = u, y = v, z = w;
        }
      }
      int X = x, Y = y, Z = z;
      x = jump[0][0][p], y = jump[0][0][p] - 1, z = jump[0][0][p] - 2;
      for (int i = LOG - 1; ~i; --i) {
        int u = jump[0][i][x], v = jump[0][i][y], w = jump[0][i][z];
        if (u && v && w && u != v && v != w) {
          x = u, y = v, z = w;
        }
      }
//      cout << p << " " << X << " " << Y << " " << Z << " " << x << " " << y << " " << z << '\n';
      if (x && y && z && X && Y && Z) {
        ans += max (0ll, 1ll * f[p] * (pre[x + 1] - pre[Y + 1]));
//        cout << p << " " << X << " " << x << " " << f[p] << " " << ans << '\n';
      }
    }
  }/*
  fill (dp[1] + 1, dp[n] + n + 1, 0);
  for (int p = 1; p <= n; ++p) {
//    cerr << p << endl;
    dp[p][p] = 1;
    for (int q = p; q ^ 1; q = jump[1][0][q]) {
      for (int i = q; i >= jump[1][0][q]; --i) {
        dis[p][i] = dis[p][q] + 1;
//        cerr << i << endl;
        for (int j = q; jump[0][0][q] && j <= min (p, jump[0][0][q]); ++j) {
          cout << p << " " << i << " " << j << '\n';
          if (dis[p][i] == dis[p][j] + 1 && a[j] - a[i] <= m) {
            dp[p][i] += dp[p][j];
          }
        }
      }
    }
//    cerr << p << endl;
    for (int q = p; q ^ n; q = jump[0][0][q]) {
      for (int i = q; i <= jump[0][0][q]; ++i) {
        dis[p][i] = dis[p][q] + 1;
        for (int j = q; jump[1][0][q] && j >= max (p, jump[1][0][q]); --j) {
          if (dis[p][i] == dis[p][j] + 1 && a[i] - a[j] <= m) {
            dp[p][i] += dp[p][j];
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      cout << dis[i][j] << " " << dp[i][j] << '\n';
      ans += dp[i][j] == 2;
    }
  }*/
  cout << ans << '\n';
}

int main () {
  freopen ("migrate.in", "r", stdin);
  freopen ("migrate.out", "w", stdout);
  ios :: sync_with_stdio (0), cin.tie (0);
  for (cin >> Test >> Test; Test--; Solve ()) {
  }
  return 0;
}

/*
by _Leehom_

uid : 994729
*/
