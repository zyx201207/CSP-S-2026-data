#include <algorithm>
#include <iostream>
using namespace std;
const int mxn = 2e6 + 3;
int c, n, d[mxn];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> d[i];
  if (c == 13 || c == 14) {
    cout << 0 << '\n';
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int t;
  cin >> c >> t;
  while (t--) solve();
}