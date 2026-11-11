#include <bits/stdc++.h>

using i64 = long long;

int c, t;
void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1;  i<= n -1 ; i ++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  std::cout << t << std::endl;
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w",stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  std::cin >> c >> t;
  while(t--) solve();
  
  return 0;
}