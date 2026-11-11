#include <bits/stdc++.h>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e3 + 5;

int ord[kMaxN], dep[kMaxN], n, c, t, rval, k;
int cnt[kMaxN], ans[kMaxN][kMaxN], cc[kMaxN], op, len;
vector<int> g[kMaxN];

void GetVal(int u, int fa) {
  dep[u] = 0;
  for (int i = dep[u]; i >= 0; i--) {
    ans[u][i] = 0;
  }
  for (int i : g[u]) {
    if (i != fa) {
      GetVal(i, u);
      dep[u] = max(dep[u], dep[i] + 1);
      for (int j = 0; j <= dep[u] + 1; j++) {
        ans[u][j] += ans[i][j] + (dep[i] >= j);
      }
    }
  }
  dep[u] && (cnt[dep[u]] += op, cc[dep[u]]++);
}

bool Cmp(Pii x, Pii y) {
  return x.second > y.second;
}

void Dfs(int u, int fa) {
  int x = 0, f = 0;
  for (int i = 1; i <= len; i++){ 
    f = max(f, min(i + ord[i], len - i + ord[i] + 1));
  }
  for (int i = f; i <= n; i++) {
    (i > dep[u] + 1) && (ans[u][i] = 0);
    (ans[u][i] + cnt[i] <= k - 2) && (rval = min(rval, i));
  }
  vector<Pii> v;
  for (int i : g[u]) {
    if (i != fa) {
      v.push_back({i, dep[i]});
    }
  }
  sort(v.begin(), v.end(), Cmp);
  for (int i : g[u]) {
    if (i != fa) {
      if (v.size() == 1) {
        ord[++len] = 0;
      } else {
        ord[++len] = (v[0].first == i ? v[1].second : v[0].second) + 1;
      }
      Dfs(i, u);
      len--;
    }
  }
}

void Work(int u, int v) {
  for (int i = n; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  // if (u == 1 && v == 3) {
  //   cout << cnt[2] << " ???\n";
  // }
  Dfs(v, u);
  len = 0;
  for( int i = 0; i <= n; i++) {
    cnt[i] -= cnt[i + 1];
  }
}

void Calc() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  rval = n + 1;
  for (int i = 1; i <= n; i++) {
    for (int to : g[i]) {
      op = 1;
      for (int j = 0; j <= n; j++) {
        cc[j] = 0;
      }
      GetVal(to, i);
      dep[i] = max(dep[i], dep[to] + 1);
    }
    for (int to : g[i]) {
      op = -1;
      GetVal(to, i);
      Work(i, to);
      op = 1;
      for (int j = 0; j <= n; j++) {
        cc[j] = 0;
      }
      GetVal(to, i);
    }
    for (int to : g[i]){
      op = -1;
      GetVal(to, i);
    }
    if (k == 1) {
      rval = min(rval, dep[i]);
    }
  }
  cout << rval << "\n";
}

void Init() {
  for (int i = 0; i <= n + 1; i++) {
    g[i].clear();
    cnt[i] = ord[i] = 0;
    for (int j = 0; j <= n + 1; j++) {
      ans[i][j] = 0;
    }
  }
}

int main() {
  freopen("hub2.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> c >> t; t; t--) {
    Calc();
    Init();
  }
  return 0;
}
// g++ hub.cpp -o hub -std=c++14 -O2 -Wall && ./hub