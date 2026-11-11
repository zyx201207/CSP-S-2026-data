#include <bits/stdc++.h>
using namespace std;
template <typename T> void ckmn(T& x, T y) { (y < x) && (x = y); }
template <typename T> void ckmx(T& x, T y) { (y > x) && (x = y); }
using ll = long long;
const int N = 5e5;
int n;
ll m, a[N + 5], pre[N + 5];
int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  int ans = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    while (j < i && (1ll * a[i] * (i - j + 1) - (pre[i] - pre[j - 1])) > m) ++j;
    ckmx(ans, i - j + 1);
  }
  cout << ans << '\n';
  return 0;
} // g++ crystal.cpp -o crystal -std=c++14 -O2 -static -Wall -Wextra