#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e6 + 1;

ifstream fin("hub.in");
ofstream fout("hub.out");

bool v[kMaxN], f[kMaxN];
int c, t, n, k, ans, e[kMaxN], d[kMaxN];
vector<int> g[kMaxN];

void dfs(int x) {
  v[x] = 1;
  for (int i : g[x]) {
    if (!v[i] && f[i]) {
      dfs(i);
    }
  }
}

void bfs() {
  queue<int> q;
  fill(v + 1, v + n + 1, 0);
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    if (!v[e[i]]) {
      dfs(e[i]);
      cnt++;
    }
  }
  if (cnt > 2) {
    return;
  }
  fill(d + 1, d + n + 1, 0);
  for (int i = 1; i <= k; i++) {
    q.push(e[i]);
  }
  int dis = 0;
  for (; q.size(); q.pop()) {
    int x = q.front();
    dis = max(dis, d[x]);
    for (int i : g[x]) {
      if (!v[i]) {
        d[i] = d[x] + 1;
        v[i] = 1;
        q.push(i);
      }
    }
  }
  ans = min(ans, dis);
}

void get(int x, int k) {
  if (n - x + 1 < k) {
    return;
  }
  if (k == 0) {
    bfs();
    return;
  }
  for (int i = x; i <= n; i++) {
    e[k] = i, f[i] = 1;
    get(i + 1, k - 1);
    f[i] = 0;
  }
}

int main() {
  for (fin >> c >> t; t; t--) {
    fin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
      fin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (13 <= c && c <= 14) {
      fout << ((n + 1) / 2 - k + 3) / 4 + 1 << '\n';
    } else {
      ans = 1e9;
      get(1, k);
      fout << ans << '\n';
    }
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
  }
  return 0;
}
/*
100+100+48+30 遗憾离场
*/