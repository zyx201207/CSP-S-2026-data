#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using i64 = long long;
const int N = 2e6 + 5;

int n, r[N], l[N], f[N], g[N], s[N], t[N]; i64 d, a[N], ans;

void mian() {
  cin >> n >> d, ans = 0;
  F(i, 1, n) cin >> a[i];
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j < n && a[j + 1] - a[i] <= d) ++j;
    r[i] = j;
  }
  for (int i = n, j = n; i >= 1; --i) {
    while (j > 1 && a[i] - a[j - 1] <= d) --j;
    l[i] = j;
  }

  F(i, 1, n) f[i] = g[i] = s[i] = t[i] = 0;
  F(i, 1, n) if (i < r[i]) ++f[r[i]], ++s[r[i]];
  F(i, 1, n) if (l[i] < i) ++g[l[i]], ++t[l[i]];
  F(i, 1, n)
    if (l[i] < i && r[l[i]] == i)
      f[i] += f[l[i]];
  dF(i, n, 1)
    if (i < r[i] && l[r[i]] == i)
      g[i] += g[r[i]];

  F(i, 1, n - 1) if (r[i] > i + 1 && l[i + 1] < i) {
    ans += 1ll * s[i + 1] * t[i];
    if (r[i] == r[i + 1] && l[r[i]] == i)
      ans += 1ll * s[i + 1] * g[r[i]];
    if (l[i] == l[i + 1] && r[l[i + 1]] == i + 1)
      ans += 1ll * f[l[i]] * t[i];
    if (r[i] == r[i + 1] && l[i] == l[i + 1] && l[r[i]] == i && r[l[i + 1]] == i + 1)
      ans += 1ll * f[l[i]] * g[r[i]];
  }

  cout << ans << "\n";
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int cid, _; cin >> cid >> _; while (_--) mian();
  return 0;
}