#include <bits/stdc++.h>
using namespace std;
template <typename T> void ckmn(T& x, T y) { (y < x) && (x = y); }
template <typename T> void ckmx(T& x, T y) { (y > x) && (x = y); }
using ll = long long;
const int N = 2e6, inf = 0x3f3f3f3f;
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
  nxt[0] = -inf;
  for (int i = 1, p; i <= n; i++) {
    p = nxt[i]; if (p == i) continue ;
    int L, R;
    L = max(i + 1, nxt[i - 1] + 1), R = nxt[i];
    ans += (R - L + 1) * f[i][1];
    if (i >= 2) {
      R = L - 1;
      L = max(i + 1, nxt[i - 2] + 1);
      ans += (R - L + 1) * f[i][0];
    }
    if (nxt[p] != p && nxt[i - 1] < p - 1 && nxt[p] == nxt[p - 1]) {
      f[nxt[p]][1] += 1 + f[i][0];
      L = max(nxt[p - 2] + 1, p + 1), R = nxt[p];
      ans += (R - L + 1) * (1 + f[p][0]); // *
    } else {
      f[nxt[i]][0] += f[i][0] + 1;
      f[nxt[i]][1] += f[i][1];
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