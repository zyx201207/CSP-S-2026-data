#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e6 + 5;

int tid, T, n, d, a[kMaxN], R[kMaxN], c[kMaxN];

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> tid >> T; T--;) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      int p = upper_bound(a + 1, a + n + 1, a[i] + d) - a;
      R[i] = p - 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = R[i];
      int lst = i;
      fill(c + i, c + n + 1, 0);
      for (int j = i; j <= x; j++) c[j] = 1;
      for (; x <= n && R[x] != x; x = R[x]) {
        if (c[x] == 1) {
          if (lst + 1 == x) {
            fill(c + x + 1, c + R[x] + 1, 1);
          } else if (c[x - 1] > 1) {
            fill(c + x + 1, c + R[x - 1] + 1, 3);
            fill(c + R[x - 1] + 1, c + R[x] + 1, 1);
          } else {
            int p = (lst + 2 == x ? x : R[x - 2]);
            fill(c + x + 1, c + p + 1, 3);
            fill(c + p + 1, c + R[x - 1] + 1, 2);
            fill(c + R[x - 1] + 1, c + R[x] + 1, 1);
          }
        } else if (c[x] == 2) {
          int p = (lst + 1 == x ? x : R[x - 1]);
          fill(c + x + 1, c + p + 1, 3);
          fill(c + p + 1, c + R[x] + 1, 2);
        } else {
          break;
        }
        lst = x;
      }
      for (int j = i; j <= n; j++) ans += (c[j] == 2);
    }
    cout << ans << '\n';
  }
}