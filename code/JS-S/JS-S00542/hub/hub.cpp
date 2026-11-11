#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 1e6 + 5;

int n, k;
vector<int> e[N];

int cnt, dfn[N], siz[N], fa[N];
void dfs1(int u, int f) {
  dfn[u] = ++cnt, siz[u] = 1, fa[u] = f;
  for (int v : e[u]) if (v != f) dfs1(v, u), siz[u] += siz[v];
}

int rt, d, ql, qr, d1[N], d2[N], d3[N];
void dfs2(int u, int f) {
  for (int v : e[u]) if (v != f && v != rt) {
    dfs2(v, u);
    if (d1[v] + 1 > d1[u]) d2[u] = d1[u], d1[u] = d1[v] + 1;
    else if (d1[v] + 1 > d2[u]) d2[u] = d1[v] + 1;
  }
}
void dfs3(int u, int f) {
  for (int v : e[u]) if (v != f && v != rt) {
    if (d1[u] == d1[v] + 1) d3[v] = max(d3[u], d2[u]) + 1;
    else d3[v] = max(d3[u], d1[u]) + 1;
    dfs3(v, u);
  }
}

int a[N];
void upd(int l, int r, int x, int tp) {
  if (l > r) return ;
  if (tp == 1) {
    if (r < ql) upd(l, r, x, 0);
    else if (l > qr) upd(l, r, x, 0);
    else {
      if (l < ql) upd(l, ql - 1, x, 0);
      if (qr < r) upd(qr + 1, r, x, 0);
    }
  }
  else a[l] += x, a[r + 1] -= x;
}
void dfs4(int u, int f, int tp) {
  upd(dfn[u], dfn[u], 1, tp);
  for (int v : e[u]) if (v != f && v != rt) {
    if (d3[v] >= d) upd(dfn[v], dfn[v] + siz[v] - 1, 1, tp);
    if (d1[v] >= d) upd(1, n, 1, tp), upd(dfn[v], dfn[v] + siz[v] - 1, -1, tp);
    dfs4(v, u, tp);
  }
}
int solve() {
  ql = dfn[rt], qr = dfn[rt] + siz[rt] - 1;
  F(i, 1, n + 1) a[i] = 0;
  F(i, 1, n) d1[i] = d2[i] = 0, d3[i] = -1;
  dfs2(rt, fa[rt]), dfs3(rt, fa[rt]);
  dfs2(1, 0), dfs3(1, 0);
  dfs4(1, 0, 1), dfs4(rt, fa[rt], 0);
  F(i, 1, n + 1) a[i] += a[i - 1];
  int x = n, y = n, z = n;
  // cout << rt << " " << d << "\n";
  // F(i, 1, n) cout << a[i] << " "; cout << "\n";
  F(i, ql, qr) x = min(x, a[i]);
  F(i, 1, ql - 1) y = min(y, a[i]);
  F(i, qr + 1, n) y = min(y, a[i]);  
  return x + y;
}

bool chk() {
  int res = n;
  F(i, 2, n) rt = i, res = min(res, solve());
  F(i, 1, n + 1) a[i] = 0;
  F(i, 1, n) d1[i] = d2[i] = 0, d3[i] = -1;
  rt = 0;
  dfs2(1, 0), dfs3(1, 0);
  dfs4(1, 0, 0);
  F(i, 1, n + 1) a[i] += a[i - 1];
  F(i, 1, n) res = min(res, a[i]);
  return res <= k;
}

void mian() {
  cin >> n >> k;
  F(i, 1, n - 1) {
    int u, v; cin >> u >> v;
    e[u].push_back(v), e[v].push_back(u);
  }
  cnt = 0, dfs1(1, 0);

  int l = 0, r = n, mid, ans = n;
  while (l <= r) {
    mid = l + r >> 1;
    if (d = mid, chk()) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  cout << ans << "\n";

  F(i, 1, n) e[i].clear();
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int cid, _; cin >> cid >> _; while (_--) mian();
  return 0;
}