#include <bits/stdc++.h>
using namespace std;
template <typename T> void ckmn(T& x, T y) { (y < x) && (x = y); }
template <typename T> void ckmx(T& x, T y) { (y > x) && (x = y); }
using ll = long long;
const int N = 2e6;
int n, nxt[N + 5];
ll a[N + 5], d;
ll f[N + 5][2];
void cls() {
  for (int i = 1; i <= n; i++) a[i] = 0, nxt[i] = 0, f[i][0] = f[i][1] = 0;
  n = d = 0;
}
void solve() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    nxt[i] = max(nxt[i - 1], i);
    while (nxt[i] < n && a[nxt[i] + 1] - a[i] <= d) ++nxt[i];
    // cout << i << " ---> " << nxt[i] << '\n';
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    // f[i][0]++; // *
    if (nxt[i] == i) continue ;
    if (nxt[i - 1] < nxt[i]) {
      f[nxt[i]][0] += f[i][0] + 1;
      f[nxt[i]][1] += f[i][1];
    } else if (nxt[i - 2] < nxt[i] && nxt[i - 1] == nxt[i]) {
      f[nxt[i]][0] += 1;
      f[nxt[i]][1] += f[i][0];
    }
    if (i > 1) {
      ans += f[i][0] * (max(i, nxt[i - 1]) - max(i, nxt[i - 2]));
      // cerr << "+ " << i << ", " << f[i][0] * (max(i, nxt[i - 1]) - max(i, nxt[i - 2])) << '\n';
      // if (i == 2) {
      //   cerr << "??? : " << f[i][0] * (nxt[i - 1] - max(i, nxt[i - 2])) << '\n';
      //   cerr << "INFO : \n";
      //   cerr << f[i][0] << ' ' << nxt[i - 1] << ' ' << max(i - 1, nxt[i - 2]) << '\n';
      // }
      ans += f[i][1] * (nxt[i] - max(i, nxt[i - 1]));
      // cerr << "+ " << i << ", " << f[i][1] * (nxt[i] - nxt[i - 1]) << '\n';
    }
  }
  cout << ans << '\n';
  cls();
}
int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int c, t; cin >> c >> t; while (t--) solve();
  return 0;
} // g++ migrate.cpp -o migrate -std=c++14 -O2 -static -Wall -Wextra