#include <bits/stdc++.h>
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kMaxN = 2e5 + 5;

int T, n, k, u[kMaxN], v[kMaxN], fa[kMaxN];
bool vis[kMaxN];

int Find(int x) {
  return (fa[x] == x ? x : fa[x] = Find(fa[x]));
}

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  if(x != y) {
    fa[x] = y;
  }
}

void Dfs(int x, int fa = 0) {

}

int Get_ans() {
  cin >> n >> k;
  for(int i = 1; i < n; i++) {
    cin >> u[i] >> v[i];
    nbr[u[i]].push_back(v[i]), nbr[v[i]].push_back(u[i]);
  }
  for(int i = 1; i < (1 << n); i++) {
    int bit = __builtin_popcount(i);
    if(bit != k) {
      continue;
    }
    for(int j = 0; j < n; j++) {
      if(i & (1 << j)) {
        vis[j + 1] = 1;
      }
    }
    iota(fa + 1, fa + n + 1, 1);
    for(int i = 1; i < n; i++) {
      if(vis[u[i]] && vis[v[i]]) {
        Union(u[i], v[i]);
      }
    }
    
  }
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for(cin >> T >> T; T--; ) {
    cout << Get_ans() << '\n';
  }
  return 0;
}