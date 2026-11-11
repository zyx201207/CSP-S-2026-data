#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], ans;

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0)->ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, j = 0, s = 0; i <= n; i++) {
    s += a[i];
    for (; j < i && a[i] * (i - j) - s > m; j++) {
      s -= a[j + 1];
    }
    ans = max(ans, i - j);
  }
  cout << ans;
  return 0;
}
// g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined