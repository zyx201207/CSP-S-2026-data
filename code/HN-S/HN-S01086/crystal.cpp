#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
template <typename T>
bool Chkmax(T &x, T y) { return (x < y) ? (x = y, 1) : 0; }
template <typename T>
bool Chkmin(T &x, T y) { return (x > y) ? (x = y, 1) : 0; }

const int kN = 5e5 + 5;
int n; ll m;
ll a[kN], s[kN];

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

  auto Check = [&](int l, int r) {
    return (r - l + 1) * a[r] - (s[r] - s[l - 1]) <= m;
  } ;

  int ans = 0;
  for(int i = 1, j = 1; i <= n; i++) {
    while((j < n) && Check(i, j + 1)) j++;
    Chkmax(ans, j - i + 1);
  }
  cout << ans << "\n";
  return 0;
}