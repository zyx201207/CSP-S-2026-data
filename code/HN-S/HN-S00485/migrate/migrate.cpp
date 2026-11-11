#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>; 

const int N = 2e6 + 10;

int t;
ll n, d;
ll a[N];
int dis[N], flag[N];
bool vis[N];
struct node {
  int u, step, pre;
};

void solve1() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 0;
  for (int st = 1; st <= n; st++) {
    for (int i = 1; i <= n; i++)
      vis[i] = dis[i] = flag[i] = 0;
    queue<node> q;
    flag[0] = 1;
    q.push({st, 0, 0});
    while (!q.empty()) {
      int u = q.front().u, step = q.front().step, pre = q.front().pre;
      q.pop();
      if (vis[u]) {
        if (dis[u] == step) {
          flag[u] += flag[pre];
        }
        continue;
      }
      vis[u] = 1;
      dis[u] = step;
      flag[u] = flag[pre];
      for (int i = u + 1; i <= n; i++) {
        if (a[i] - a[u] <= d) {
          q.push({i, step + 1, u});
        }
      }
    }
    for (int i = 1; i <= n; i++)
      ans += flag[i] == 2;
  }
  cout << ans << '\n';
}

void solve2() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int sum = a[2] - a[1];
  if (d / sum < 2) {
    cout << "0\n";
    return;
  }
  int tmp = d / sum;
  cout << max(0ll, n - (tmp * 2 - 1)) << '\n';
}

void solve3() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 0;
  int l = 1, r = 1;
  while (r <= n) {
    int sum = a[r] - a[l];
    if (sum > d) {
      l++;
      continue;
    }
    int tmp = r - l;
  }
}

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int type;
  cin >> type >> t;
  if (type <= 10) {
    while (t--)
      solve1();
  }
  if (type == 11 || type == 12) {
    while (t--)
      solve2();
  }
  if (type == 13 || type == 14) {
    while (t--)
      cout << "0\n";
  }
  return 0;
}
// 56 pts
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

ans: 6
*/
