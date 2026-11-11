// crystal
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

using ll = long long;

const int N = 5e5 + 3;

ll a[N];

int n, ans = 0;

ll m, k = 0;

int main () {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    for (; j < i && a[i] * (i - j) > m + k; j++)  k -= a[j];
    ans = max (ans, i - j + 1), k += a[i];
  }
  cout << ans;
  return 0;
}
