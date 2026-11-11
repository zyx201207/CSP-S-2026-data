#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kN = 5e5 + 5;

ll m, a[kN], sum[kN];
int n;

int main () {
  freopen ("crystal.in", "r", stdin);
  freopen ("crystal.out", "w", stdout);
  cin.tie (0)->sync_with_stdio (0);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort (a + 1, a + 1 + n);
  
  int ans = 0;
  for (int i = 1, lt = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i];
    ll tmp = i - lt + 1;
    for (; tmp * a[i] - sum[i] + sum[i - tmp] > m; ++lt, --tmp) {}
    ans = max (ans, i - lt + 1);
  }

  cout << ans;
  return 0;
}