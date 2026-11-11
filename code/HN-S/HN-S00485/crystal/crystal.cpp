#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

ll n, m;
ll a[N];

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans = 0;
  ll last = -1e18, id = 0, num = 0;
  for (int l = 1, r = 1; r <= n; r++) {
    if (a[r] == a[r + 1])
      continue;
    if (last != -1e18)
      num += (a[r] - last) * (id - l + 1);
    last = a[r], id = r;
    while (num > m) {
      num -= a[r] - a[l];
      l++;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans;
  return 0;
}
// 100pts
