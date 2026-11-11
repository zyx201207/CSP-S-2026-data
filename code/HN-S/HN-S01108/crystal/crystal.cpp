/*
CSP_S = max (CSP_S, 300);
bu yao chu (strings) a a a a a a a a a a.
bu yao chu (math) a a a a a a a a a a a.
bu dui a yun tang ji zi pao de bu shi hen kuai ma.
5e8 0.8s zhe me kuai hai you ren pen???
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 3;

int n, ans;
ll m, a[N], sum;

int main () {
  freopen ("crystal.in", "r", stdin);
  freopen ("crystal.out", "w", stdout);
  ios :: sync_with_stdio (0), cin.tie (0);
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> a[i++]) {
  }
  sort (a + 1, a + n + 1);
  for (int i = 1, j = 1; i <= n; ++i) {
    sum += 1ll * (i - j) * (a[i] - a[i - 1]);
    for (; j < i && sum > m; ++j) {
      sum -= a[i] - a[j];
    }
    ans = max (ans, i - j + 1);
  }
  cout << ans;
  return 0;
}

/*
by _Leehom_

uid : 994729
*/
