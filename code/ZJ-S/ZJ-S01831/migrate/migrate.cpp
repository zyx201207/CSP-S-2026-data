#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;
constexpr ll inf = 4e18;
constexpr int N = 2e6 + 5;

int sub_id, T;

int n;
ll d;
ll a[N];
int pre[N];

ll f[N], g[N];

void solve_main() {
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 1, j = 1; i <= n; ++i) {
    while (a[i] - a[j] > d) ++j;
    pre[i] = j;
  }

  if (sub_id <= 10) {
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      f[i] = 0, g[i] = 1;
      for (int j = i + 1; j <= n; ++j) {
        if (pre[j] == j) break;
        int pr = max(pre[j], i);

        f[j] = f[pr] + 1, g[j] = g[pr];

        for (int k = pr + 1; k <= j - 1; ++k) {
          if (f[k] == f[pr]) {
            g[j] += g[k];
          } else {
            break;
          }
          if (g[j] >= 3) break;
        }
        if (g[j] == 2) ++ans;
      }
    }
    cout << ans << '\n';
    return;
  }

  if (sub_id <= 12) {
    ll dt = a[2] - a[1];
    ll k = d / dt;
    if (k > n || k <= 1) {
      cout << 0 << '\n';
      return;
    }
    int real_k = k;
    cout << max(0, n - 2 * real_k + 1) << '\n';
    return;
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = 0, g[i] = 1;
    for (int j = i + 1; j <= min(i + 50, n); ++j) {
      if (pre[j] == j) break;
      int pr = max(pre[j], i);

      f[j] = f[pr] + 1, g[j] = g[pr];

      for (int k = pr + 1; k <= j - 1; ++k) {
        if (f[k] == f[pr]) {
          g[j] += g[k];
        } else {
          break;
        }
        if (g[j] >= 3) break;
      }
      if (g[j] == 2) ++ans;
    }
  }
  cout << ans << '\n';
}

int main() {
  assert(freopen("migrate.in", "r", stdin));
  assert(freopen("migrate.out", "w", stdout));
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> sub_id >> T;
  while (T--) {
    solve_main();
  }
  return 0;
}