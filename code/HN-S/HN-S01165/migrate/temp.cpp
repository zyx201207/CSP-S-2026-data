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

int lst[kN], nxt[kN];
int col[kN], hd[kN], tl[kN], num, cnt[kN];
LL f[kN];
LL Solve(LL *x, int n) {
  if (x[n] - x[1] <= d)  return 0;
  for (int i = 1; i <= n; i++) {
    lst[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
    nxt[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
    cnt[nxt[i]]++;
    if (nxt[lst[i]] == i)  col[i] = col[lst[i]], tl[col[i]] = i, assert(col[i] != 0);
    else  col[i] = ++num, hd[num] = tl[num] = i;
  }
  for (int c = 1; c <= num; c++) {
    int x = hd[c];
    if (x < n && col[x + 1] != col[x])
      f[x] = cnt[x + 1] + 
  }
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