#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
int n;
ll m;
const int mxn = 5e5 + 3;
ll a[mxn], sum[mxn];
int far(int i) {
  int l = 1, r = i, ans = i;
  while (l <= r) {
    int md = (r + l) / 2;
    ll cost = a[i] * (i - md + 1) - (sum[i] - sum[md - 1]);
    // cout << i << ',' << md << '=' << cost << '\n';
    if (cost <= m)
      r = md - 1, ans = md;
    else
      l = md + 1;
  }
  return ans;
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  int ans = -1;
  for (int i = 1; i <= n; i++) ans = max(ans, i - far(i) + 1);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  solve();
}