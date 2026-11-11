#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;

int c, T, n, k, a[N], d[N], vis[N], f[N], mx[N], rt, zrr, px, py, lc, ans;
vector<int> v[N];

int find(int x){
 return f[x] == x ? x : f[x] = find(f[x]);
}

void dfsk(int x, int fa, int d){ mx[x] = 0;
  for(int i : v[x]) if(i != fa) dfsk(i, x, d + 1), mx[x] = max(mx[x], mx[i] + 1);
  ans = min(ans, max(d, mx[x]));
}

void dfs2(int x, int fa){
  d[x] = d[fa] + 1, mx[x] = x, f[x] = fa;
  for(int i : v[x]){
    if(i != fa){
      dfs2(i, x);
      if(d[mx[x]] + d[mx[i]] - 2 * d[x] > zrr) zrr = d[mx[x]] + d[mx[i]] - 2 * d[x], px = mx[x], py = mx[i], lc = x;
      if(d[mx[x]] < d[mx[i]] + 1) mx[x] = mx[i];
    }
  }
}

int maxd(int x, int y){ fill(d + 1, d + 1 + n, -1);
  queue<int> q; q.push(x), q.push(y), d[x] = d[y] = 0;
  for(int j = 1; j <= n; j++) if(a[j]) q.push(j), d[j] = 0;
  while(!q.empty()){ int x = q.front(); q.pop();
    for(int i : v[x]) if(d[i] == -1) d[i] = d[x] + 1, q.push(i);
  }
  return *max_element(d + 1, d + 1 + n);
}

void solve(){
  cin >> n >> k;
  ans = 1e18;
  for(int i = 1; i <= n; i++) v[i].clear();
  for(int i = 1, x, y; i < n; i++){
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
  }
  if(k == 1){
    rt = 0, zrr = 1e18, dfsk(1, 0, 0);
    cout << ans << '\n';
    return ;
  }
  for(int i = 0; i < (1 << n); i++){
    int sum = 0;
    for(int j = 0; j < n; j++) a[j + 1] = (i >> j & 1), sum += a[j + 1], vis[j + 1] = 0, f[j + 1] = j + 1, d[j + 1] = -1;
    if(sum != k) continue;
    for(int j = 1; j <= n; j++) for(int l : v[j]) if(a[j] && a[l]) f[find(j)] = find(l);
    int op = 0;
    for(int j = 1; j <= n; j++) if(a[j] && f[j] == j) op++;
    if(op > 2) continue; queue<int> q;
    for(int j = 1; j <= n; j++) if(a[j]) q.push(j), d[j] = 0;
    while(!q.empty()){ int x = q.front(); q.pop();
      for(int i : v[x]) if(d[i] == -1) d[i] = d[x] + 1, q.push(i);
    }
    ans = min(ans, (*max_element(d + 1, d + 1 + n)));
  }
  cout << ans << '\n';
}

signed main(){
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> c >> T;
  while(T--) solve();
  return 0;
}
