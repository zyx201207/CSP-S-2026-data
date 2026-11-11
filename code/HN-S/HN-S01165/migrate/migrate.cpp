#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int kN = 2e6 + 1;

int Tc, T, N;
LL d, PX[kN];

int lst[kN], nxt[kN], f[kN], g[kN], fl[kN], gl[kN];
LL Solve(LL *x, int n) {
  if (x[n] - x[1] <= d)  return 0;
  for (int i = 1; i <= n; i++) {
    lst[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
    nxt[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
    f[nxt[i]]++;
    if (nxt[lst[i]] == i)  fl[i] = f[lst[i]] + fl[lst[i]];
  }
  for (int i = n; i >= 1; i--) {
    g[lst[i]]++;
    if (lst[nxt[i]] == i)  gl[i] = gl[nxt[i]] + g[nxt[i]];
  }
  LL ret = 0;
  for (int m = 2; m < n - 1; m++) {
    if (nxt[m] == m + 1 && lst[m + 1] == m)  continue;

    int fm = f[m + 1] - (nxt[m] == m + 1), gm = g[m] - (lst[m + 1] == m);
    ret += 1ll * fm * gm;
    if (nxt[m] == nxt[m + 1])  ret += 1ll * fm * gl[m];
    if (lst[m] == lst[m + 1])  ret += 1ll * fl[m + 1] * gm;
    if (nxt[m] == nxt[m + 1] && lst[m] == lst[m + 1])  ret += 1ll * fl[m + 1] * gl[m];
  }
  for (int i = 1; i <= n; i++)  f[i] = g[i] = lst[i] = nxt[i] = fl[i] = gl[i] = 0;
  return ret;
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  for (cin >> Tc >> T; T--;) {
    cin >> N >> d;
    for (int i = 1; i <= N; i++)  cin >> PX[i];
    PX[N + 1] = 8e18;
    LL ans = 0;
    for (int i = 1, lst = 0; i <= N; i++)
      if (PX[i + 1] - PX[i] > d)  ans += Solve(PX + lst, i - lst), lst = i;
    cout << ans << '\n';
  }
  return 0;
}