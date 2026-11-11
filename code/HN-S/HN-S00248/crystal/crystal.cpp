#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kMaxN = 5e5 + 5;

int n, m, a[kMaxN], s[kMaxN];

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    int lt = 0, rt = i + 1;
    auto Check = [&](int x) -> bool {
      int val = s[i] - s[x - 1], goal = (i - x + 1) * a[i];
      return m >= goal - val;
    };
    for(int mid; rt - 1 > lt; ) {
      mid = lt + rt >> 1;
      Check(mid) ? rt = mid : lt = mid;
    }
    ans = max(ans, i - rt + 1);
  }
  cout << ans << endl;
  return 0;
}