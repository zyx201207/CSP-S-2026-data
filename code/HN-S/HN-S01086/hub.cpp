#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int> ;

const int inf = 1e9;
template <typename T>
bool Chkmax(T &x, T y) { return (x < y) ? (x = y, 1) : 0; }
template <typename T>
bool Chkmin(T &x, T y) { return (x > y) ? (x = y, 1) : 0; }

const int kN = 1e6 + 5;
int n, k, c, d;
int fa[kN];
int diam[kN];
int dep[kN], dis[kN];
bool ind[kN];
vector<int> g[kN], sub[kN];

void Clear() {
  c = 0;
  for(int i = 0; i <= n + 1; i++) {
    fa[i] = diam[i] = ind[i] = dis[i] = 0;
    g[i].clear();
    sub[i].clear();
  }
}

void DFS(int x, int fa, int dep, int &d, int &p) {
  ::fa[x] = fa;
  if(dep >= d) d = dep, p = x;
  for(int to : g[x]) {
    if(to != fa) DFS(to, x, dep + 1, d, p);
  }
}

pii Diam() {
  int x, y, d = -1;
  DFS(1, 0, 0, d, x);
  DFS(x, 0, 0, d, y);
  return make_pair(x, y);
}

void DFS2(int x, int fa, vector<int> &vec) {
  dep[x] = (fa ? dep[fa] + 1 : 0);
  vec.push_back(x);
  for(int to : g[x]) {
    if((to == fa) || ind[to]) continue;
    DFS2(to, x, vec);
    Chkmax(dis[x], dis[to] + 1);
  }
}

int pre[kN], suf[kN];

struct DS {
  list<pii> li;
  DS() { }
  void Ins(int x, int v) {
    while(li.size() && (li.front().second > v)) li.pop_front();
    li.emplace_back(x, v);
  }
  void Del(int x) {
    if(li.size() && (li.back().first == x)) li.pop_back();
  }
  int Query() { return li.size() ? li.back().second : inf; }
} ds[kN];

struct DS2 {
  int buc[kN], cur, low;
  void Clear() {
    low = 0;
    for(int i = 0; i <= n + 2; i++) buc[i] = 0;
  }
  void Ins(int x) { if(x < cur) buc[x]++, low++; }
  void Del(int x) { if(x < cur) buc[x]--, low--; }
  void DecV() { low -= buc[--cur]; }
} ds2;

bool Case1() {
  for(int i = d + 1; i <= c - d; i++) {
    int cnt = 1;
    for(int x : sub[i]) {
      if(x != diam[i]) cnt += (dis[x] >= d);
    }
    pre[i] = suf[i] = cnt;
  }
  for(int i = d + 1; i <= c - d; i++) pre[i] += pre[i - 1];
  for(int i = c - d; i >= d + 1; i--) suf[i] += suf[i + 1];
  int l = c - d, r = c - d, mn = r;

  auto Ins = [&](int i) {
    if(i >= r) return ;
    int pos = i - d + dis[diam[i]];
    int val = i + d - dis[diam[i]];
    if(pos <= d) return ;
    if(pos > l) ds2.Del(ds[pos].Query());
    ds[pos].Ins(i, val);
    if(pos > l) ds2.Ins(ds[pos].Query());
  } ;
  auto Del = [&](int i) {
    int pos = i - d + dis[diam[i]];
    int val = i + d - dis[diam[i]];
    if(pos <= d) return ;
    if(pos > l) ds2.Del(ds[pos].Query());
    ds[pos].Del(i);
    if(pos > l) ds2.Ins(ds[pos].Query());
  } ;

  ds2.cur = r;
  for(; l >= d + 1; l--) {
    if(l < c - d) {
      ds2.Ins(ds[l + 1].Query());
      Ins(l + 1);
    }
    while(ds2.low) Del(r - 1), ds2.DecV(), r--;
    if(pre[l] + suf[r] <= k) return 1;
  }
  return 0;
}

int out[kN], mx[kN], se[kN], from[kN], cnt[kN];

void DFS3(int x, int fa) {
  if(dep[x] > d) mx[x] = 0, from[x] = x;
  cnt[x] = (fa && (dis[x] >= d));
  for(int to : g[x]) {
    if((to == fa) || ind[to]) continue;
    DFS3(to, x);
    cnt[x] += cnt[to];
    if(mx[to] < 0) continue;
    int val = mx[to] + 1;
    if(mx[x] < val) {
      se[x] = mx[x], mx[x] = val, from[x] = to;
    } else Chkmax(se[x], val);
  }
}

void DFS4(int x, int fa, int &mn) {
  if(out[x] <= d) Chkmin(mn, max(cnt[x], 1));
  for(int to : g[x]) {
    if((to == fa) || ind[to]) continue;
    Chkmax(out[to], out[x] + 1);
    Chkmax(out[to], ((from[x] == to) ? se[x] : mx[x]) + 1);
    DFS4(to, x, mn);
  }
}

bool Case2() {
  int f[2] = {0, 0};
  for(int i = d + 1; i <= c - d; i++) {
    int x = diam[i];
    for(int to : g[x]) {
      if(ind[to]) continue;
      int mn = inf;
      DFS3(to, x);
      DFS4(to, x, mn);
      int num = cnt[to];
      tie(f[0], f[1]) = 
        make_pair(f[0] + num, min(f[0] + mn, f[1] + num));
      if(min(f[0], f[1]) + c - 2 * d > k) return 0;
    }
  }
  return min(f[0], f[1]) + c - 2 * d <= k;
}

bool Check(int d) {
  ::d = d;
  ds2.Clear();
  for(int i = 0; i <= n + 1; i++) {
    ds[i] = DS();
    pre[i] = suf[i] = from[i] = cnt[i] = 0;
    out[i] = mx[i] = se[i] = -inf;
  }
  return Case1() || Case2();
}

void Solve() {
  cin >> n >> k;
  Clear();
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if(k == n) return void(cout << "0\n");
  auto [x, y] = Diam();
  for(int i = y; i != fa[x]; i = fa[i]) {
    diam[++c] = i;
    ind[i] = 1;
  }
  for(int i = 1; i <= c; i++) DFS2(diam[i], 0, sub[i]);
  int l = -1, r = (c + 1) / 2;
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    Check(mid) ? (r = mid) : (l = mid);
  }
  cout << r << "\n";
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  int sid, t;
  cin >> sid >> t;
  while(t--) Solve();
  return 0;
}