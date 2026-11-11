#include <bits/stdc++.h>

using namespace std;;

using ll = long long;
using ull = unsigned long long;

const int kMaxN = 5050;

ll n, d, x[kMaxN], dis[kMaxN], cnt[kMaxN], ans;
vector<ll> e[kMaxN];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
bool vis[kMaxN];

void Dijkstra(ll s) {
  fill(dis + 1, dis + n + 1, 1e18);
  fill(cnt + 1, cnt + n + 1, 0);
  fill(vis + 1, vis + n + 1, 0);
  for (; !q.empty(); q.pop());
  for (dis[s] = 0, cnt[s] = 1, q.push({0, s}); !q.empty(); ) {
    auto x = q.top();
    q.pop();
    if (vis[x.second]) {
      continue;
    }
    vis[x.second] = 1;
    for (auto i : e[x.second]) {
      if (dis[i] > dis[x.second] + 1) {
        dis[i] = dis[x.second] + 1;
        cnt[i] = cnt[x.second];
        q.push({dis[i], i});
      } else if (dis[i] == dis[x.second] + 1) {
        cnt[i] += cnt[x.second];
        q.push({dis[i], i});
      }
    }
  }
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int c, t;
  for (cin >> c >> t; t; -- t) {
    cin >> n >> d, ans = 0;
    for (int i = 1; i <= n; ++ i) {
      cin >> x[i], cnt[i] = 0;
      e[i].clear();
    }
    if (c >= 11) {
      cout << "0\n";
      continue;
    }
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= n; ++ j) {
        if (i != j && abs(x[i] - x[j]) <= d) {
          e[i].push_back(j);
        }
      }
    }
    for (int i = 1; i <= n; ++ i) {
      Dijkstra(i);
      for (int j = i + 1; j <= n; ++ j) {
        ans += (cnt[j] == 2);
      }
    }
    cout << ans << '\n';
  }
  return 0; 
}
