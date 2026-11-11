#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##END = (r); i <= i##END; ++ i)
#define dwn(i, l, r) for (int i = (l), i##END = (r); i >= i##END; -- i)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std; typedef long long i64;

namespace Hub{
  const int N = 1e6 + 5;
  vector<int> G[N];
  int n, k, vis[N], fa[N], dis[N];
  int get(int x){ return x == fa[x] ? x : fa[x] = get(fa[x]); }
  void Dfs(int x, int fa, int st, int p){
    if (vis[x]){
      dis[st] = min(dis[st], p);
      return ;
    }
    for (int y : G[x]) if (y != fa)
      Dfs(y, x, st, p + 1);
  }
  void main(int idx){
    cin >> n >> k;
    if (idx <= 20){
      vector<pair<int, int> > ed;
      int ans = 1e9;
      rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        ed.push_back({x, y});
      }
      rep(st, 1, (1 << n) - 1){
        if (__builtin_popcount(st) != k) continue;
        rep(i, 1, n) G[i].clear(), fa[i] = i, vis[i] = 0;
        rep(i, 1, n) dis[i] = 1e9;
        for (auto [u, v] : ed){
          if ((st >> u - 1 & 1) && (st >> v - 1 & 1))
            fa[get(u)] = get(v);
        }
        vector<int> num;
        rep(i, 1, n) if (st >> i - 1 & 1)
          num.push_back(get(i)), vis[i] = 1;
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        if (num.size() > 2) continue;
        for (auto [u, v] : ed){
          G[u].push_back(v);
          G[v].push_back(u);
        }
        rep(i, 1, n) Dfs(i, 0, i, 0);
        int sum = -1e9;
        rep(i, 1, n) sum = max(sum, dis[i]);
        ans = min(ans, sum);
        // cout << st << ' ' << sum << '\n';
      }
      cout << ans << '\n';
      return ;
    }
  }
}

int main(){
  File("hub");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int id, T; cin >> id >> T;
  while (T --) Hub::main(id);
  return 0;
}
/*
写游记。uid = 486677
欸等一下我暴力没打完，不写了。
我怎么这么菜。
T1 -> Xterfusion.cpp
x x xxx
*/