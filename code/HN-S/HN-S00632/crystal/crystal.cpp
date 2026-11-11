#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void FileIO (string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e5 + 10;

int n, ans;
ll a[N], m, now;

signed main () {
  ios::sync_with_stdio(0), cin.tie(0);
  FileIO("crystal");
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    now += (i - j) * (a[i] - a[i - 1]);
    for (; j < i && now > m; j++) now -= a[i] - a[j];
    ans = max(ans, i - j + 1);
  }
  cout << ans;
  return 0;
}
