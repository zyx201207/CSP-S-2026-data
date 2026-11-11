#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;

int n;
ll m, a[N];

int main() {
  assert(freopen("crystal.in", "r", stdin));
  assert(freopen("crystal.out", "w", stdout));
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 1;
  ll v = 0;
  for (int i = 2, j = 1; i <= n; ++i) {
    v += (a[i] - a[i - 1]) * (i - j);
    while (j < i && v > m) {
      v -= (a[i] - a[j]);
      ++j;
    }
    ans = max(ans, i - j + 1);
  }
  cout << ans;
  return 0;
}