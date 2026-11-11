#include <bits/stdc++.h>
using namespace std;

const int N = 12;
const long long inf = 1e7;
using ll = long long;

ll c, t, vis[N], p[N], kk, cnt, n, d[N], ans = inf, k;

vector <ll> a[N];

void init(ll n){
  for(int i = 0; i <= n; i++){
    vis[i] = 0;
    p[i] = 0;
    a[i].clear();
    d[i] = inf;
  }
  ans = inf;
  k = 0;
}

void dfs1(ll x, ll fa){
  if(vis[x] == 1 && vis[fa] == 0){
    k++;
    p[x] = k;
  }else if(p[fa] != 0){
    p[x] = p[fa];
  }
  for(auto it : a[x]){
    if(it != fa){
      dfs1(it, x);
    }
  }
}

ll dfs2(ll x, ll fa){
  if(vis[x]){
    return 0;
  }
  ll cnt = inf;
  for(auto it : a[x]){
    if(it != fa){
      cnt = min(cnt, dfs2(it, x) + 1);
    }
  }
  return d[x] = cnt;
}

ll check(){
  dfs1(1, 0);
  if(k <= 2){
    cnt = 0;
    for(int i = 1; i <= n; i++){
      cnt = max(dfs2(i, 0), cnt);
    }
    return cnt;
  }else{
    return inf;
  }
}

void dfs(ll x, ll o){
  if(x == n + 1){
    k = 0;
    for(int i = 0; i <= n; i++){
      p[i] = 0;
      d[i] = 0;
    }
    ans = min(ans, check());
    return;
  }
  if(o < kk){
    vis[x] = 1;
    d[x] = 0;
    dfs(x + 1, o + 1);
  }
  d[x] = inf;
  vis[x] = 0;
  dfs(x + 1, o);
}

void solve(){
  cin >> n >> kk;
  init(n);
  for(int i = 1; i < n; i++){
    ll u, v;
    cin >> u >> v;
    a[u].push_back(v), a[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << '\n';
}

int main(){
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> c >> t;
  while(t--){
    solve();
  }
}
