#include <bits/stdc++.h>
// #define MEMORY
using namespace std;
using LL = long long;
bool Mbe;

const int N = 5e5 + 5;
LL n, m, a[N], sum[N];

bool Med;
int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
#ifdef MEMORY
  cerr << abs(&Mbe - &Med) / 1048576.0 << "\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  partial_sum(a + 1, a + n + 1, sum + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = i + 1;
    for (int o; l + 1 < r;) {
      o = l + r >> 1;
      a[i] * (i - o + 1) - (sum[i] - sum[o - 1]) <= m ? r = o : l = o;
    }
    ans = max(ans, i - r + 1);
  }
  cout << ans;
  return 0;
}
// zrr love xyz