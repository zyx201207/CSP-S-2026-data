#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void FileIO (string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e6 + 10;

int TestCase, TestID, n, dis[N], cnt[N], pre[N];
ll d, x[N], ans;

void Solve () {
  cin >> n >> d, ans = 0;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) {
    int now = i;
    for (int j = 22; j >= 0; j--)
      if (now > (1 << j) && x[i] - x[now - (1 << j)] <= d)
        now -= (1 << j);
    pre[i] = now;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dis[j] = cnt[j] = 0;
    cnt[i] = 1;
    for (int j = i + 1; j <= n; j++) {
      int p = max(pre[j], i);
      if (p == j) break;
      dis[j] = dis[p] + 1, cnt[j] = cnt[p];
      if (p + 1 < j && dis[p + 1] + 1 == dis[j]) cnt[j] += cnt[p + 1];
      if (p + 2 < j && dis[p + 2] + 1 == dis[j]) cnt[j] += cnt[p + 2];
      cnt[j] = min(cnt[j], 3);
      if (cnt[j] == 2) ans++;
    }
  }
  cout << ans;
}

signed main () {
  ios::sync_with_stdio(0), cin.tie(0);
  FileIO("migrate");
  for (cin >> TestID >> TestCase; TestCase--; Solve(), cout << '\n') {}
  return 0;
}
