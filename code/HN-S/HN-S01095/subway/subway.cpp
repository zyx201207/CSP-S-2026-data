#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5, M = 505;

struct E {
  int d, t;
};

int c, n, m, d, q, w[N];
ll f[M][M];
vector<E> e[N];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->ios::sync_with_stdio(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int j = 1, x, y; j <= k; j++) {
      cin >> x >> y;
      e[x].push_back({i, y});
    }
  }
  fill(f[0], f[n + 1], 1e18);
  for (int i = 1; i <= m; i++) {
    for (E j : e[i]) {
      for (E k : e[i]) {
        f[j.d][k.d] = f[k.d][j.d] = min(f[j.d][k.d], (ll)(j.t + k.t));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        f[j][k] = min(f[j][i] + f[i][k], f[j][k]);
      }
    }
  }
  for (int x, y; q--;) {
    cin >> x >> y;
    ll r = 1e18;
    for (E i : e[x]) {
      for (E j : e[y]) {
        r = min(r, f[i.d][j.d] + i.t + j.t);
      }
    }
    cout << r + w[x] + w[y] << '\n';
  }
  return 0;
}
// g++ subway.cpp -o subway -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined