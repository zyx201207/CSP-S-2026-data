#include <bits/stdc++.h>
using namespace std;
#define int long long
using info = pair<int, int>;

int calc(int n, vector<int> a, int d) {

  if (n == 1) return 0;
  a.push_back(-5e18);
  reverse(a.begin(), a.end());
  a.push_back(-5e18);
  reverse(a.begin(), a.end());

  vector<int> fa(n + 2, -1);
  for (int i = 1, j = 1; i <= n; i++) {
    while (j < n && a[j + 1] - a[i] <= d) j++;
    fa[i] = j;
  }
  vector<int> far(n + 2, -1);
  for (int i = n, j = n; i; i--) {
    while (j > 1 && a[i] - a[j - 1] <= d) j--;
    far[i] = j;
  }

  //for (int i = 1; i <= n; i++) cerr << fa[i] << " \n"[i == n];
  // for (int i = 1; i <= n; i++) cerr << far[i] << " \n"[i == n];

  vector<int> sizl(n + 1, 1), sizr(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j > 0; j--)
      if (fa[j] != i) break;
      else sizl[i] += sizl[j];
  }
  for (int i = n; i; i--) {
    for (int j = i + 1; j <= n; j++) 
      if (far[j] != i) break;
      else sizr[i] += sizr[j];
  }


  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + sizr[i];

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (fa[fa[i]] == -1) continue;
    int l = fa[i], r = fa[fa[i] - 1];
    if (fa[i] >= i + 2) l = fa[fa[i] - 2]; 
    res += sizl[i] * (pre[r] - pre[l]);
  }
  return res;
}

void solve1(int n, int d) {
  vector<vector<int>> g(n + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<info> dp(n + 1, {1e18, 1e18});
    auto add = [&](info x, info y) {
      if (x.first != y.first) return min(x, y);
      else return make_pair(x.first, x.second + y.second);
    };
    dp[i] = {1, 1};
    for (int j = i; j <= n; j++)
      for (int k = j + 1; k <= n; k++) if (a[k] - a[j] <= d){
        auto cur = dp[j]; cur.first++;
        dp[k] = add(dp[k], cur);
      }
    for (int j = 1; j <= n; j++)
      if (dp[j].second == 2) ans++;
  }
  cout << ans << endl;
}


void solve() {
  //cerr << "-------------" << endl;
  int n, d; cin >> n >> d;
  if (n <= 300) return solve1(n, d);
  vector<vector<int>> g(n + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j < n && a[j + 1] - a[j] <= d) j++;
    vector<int> cur(a.begin() + i, a.begin() + j + 1);
    ans += calc(cur.size(), cur, d);
    i = j;
  } 
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout); 
  int c, T; cin >> c >> T; while (T--) solve();
  return 0;
}
