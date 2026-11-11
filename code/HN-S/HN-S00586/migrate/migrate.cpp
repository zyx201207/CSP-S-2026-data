#include <bits/stdc++.h>
// #define MEMORY
using namespace std;
using LL = long long;
bool Mbe;

const int N = 2e6 + 5, Inf = 1e9;
LL tid, t, n, k, a[N], rt[N][22], fl[N];
vector<int> d[N];

int Dis(int x, int y) {
  if (x == y) return 0;
  int d = 0;
  for (int i = 21; ~i; i--) {
    rt[x][i] && rt[x][i] < y && (d += (1 << i), x = rt[x][i]);
  }
  return rt[x][0] >= y ? d + 1 : Inf;
}

bool Med;
int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
#ifdef MEMORY
  cerr << abs(&Mbe - &Med) / 1048576.0 << "\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> tid >> t; t; t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], fl[i] = 0;
    for (int i = 1; i <= n; i++) {
      rt[i][0] = upper_bound(a + 1, a + n + 1, a[i] + k) - a - 1;
    }
    for (int j = 1; j < 22; j++) {
      for (int i = 1; i <= n; i++) {
        rt[i][j] = rt[rt[i][j - 1]][j - 1];
      }
    }
    for (int i = 1; i <= n; i++) {
      d[i].clear();
      for (int j = i;; j = rt[j][0]) {
        d[i].push_back(j);
        if (rt[j][0] == j) break;
      }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
      for (LL j = i + 1; j <= n; j++) {
        LL d1 = Dis(i, j), cnt = 0;
        if (d1 == 1 || d1 > n) continue;
        for (int k = i; k < j; k++) {
          int p = Dis(i, k);
          if (d[i][p] >= j) break;
          if ((cnt += (k != d[i][p] && min(j, rt[k][0]) == min(j, rt[d[i][p]][0]))) > 1) break;
        }
        ans += (cnt == 1);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
// zrr & xyz 99