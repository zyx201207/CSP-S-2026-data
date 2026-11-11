#include <bits/stdc++.h>

using namespace std;;

using ll = long long;
using ull = unsigned long long;

const int kMaxN = 1010;

ll n, k, d[kMaxN], dis[kMaxN][kMaxN], ans;
vector<ll> e[kMaxN];
set<ll> rem, hav;
bool vis[kMaxN], zrr[kMaxN];
queue<ll> q;

void Dfs(ll x, ll fa) {
  for (auto i : e[x]) {
    if (i != fa) {
      d[i] = d[x] + 1;
      Dfs(i, x);
    }
  }
}

void Bfs(ll s) {
  for (; !q.empty(); q.pop());
  for (q.push(s); !q.empty(); ) {
    ll x = q.front();
    q.pop();
    if (vis[x]) {
      continue;
    }
    vis[x] = 1;
    for (auto i : e[x]) {
      if (zrr[i] == 1) {
        q.push(i);
      } 
    }
  }
}

void F(ll stp) {
  if (stp == k + 1) {
    ll mx = 0, cnt = 0;
    fill(vis + 1, vis + n + 1, 0);
    for (auto i : hav) {
      if (!vis[i]) {
        Bfs(i);
        ++ cnt;
      }
    }
    if (cnt > 2) {
      return;
    }
    for (ll i = 1, mn; i <= n; ++ i) {
      mn = 1e18;
      for (auto j : hav) {
        mn = min(mn, dis[i][j]);
      }
      mx = max(mx, mn);
    }
    ans = min(ans, mx);
    return;
  }
  set<int> tmp;
  for (auto i : rem) {
    tmp.insert(i);
  }
  for (auto i : tmp) {
    rem.erase(rem.find(i));
    hav.insert(i);
    zrr[i] = 1;
    F(stp + 1);
    rem.insert(i);
    zrr[i] = 0;
    hav.erase(hav.find(i));
  }
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int c, t;
  for (cin >> c >> t; t; -- t) {
    cin >> n >> k, hav.clear(), rem.clear();
    for (int i = 1; i <= n; ++ i) {
      e[i].clear(), rem.insert(i), zrr[i] = 0;
    }
    for (ll i = 1, u, v; i < n; ++ i) {
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++ i) {
      fill(d + 1, d + n + 1, 0);
      Dfs(i, 0);
      for (int j = 1; j <= n; ++ j) {
        dis[i][j] = d[j];
      }
    }
    ans = 1e18;
    F(1);
    cout << ans << '\n';
  }
  return 0; 
}
