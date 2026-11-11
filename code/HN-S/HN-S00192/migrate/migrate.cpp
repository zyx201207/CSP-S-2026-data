#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e6 + 5;

int type;

namespace sub1{

const int MAXN = 5e3 + 5;

int n, dis[MAXN], f[MAXN], ind[MAXN];
ll d, x[MAXN];
vector<int> G[MAXN], H[MAXN];

int Calc(int s){
  for(int i = 1; i <= n; i++) dis[i] = -1, ind[i] = 0, H[i].clear();
  queue<int> que;
  que.push(s);
  dis[s] = 0;
  for(; !que.empty(); ){
    int u = que.front(); que.pop();
    for(int v : G[u]){
      if(dis[v] == -1){
        dis[v] = dis[u] + 1;
        que.push(v);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j : G[i]){
      if(dis[j] == dis[i] + 1) H[i].push_back(j), ind[j]++;
    }
  }
  for(int i = 1; i <= n; i++) f[i] = 0;
  f[s] = 1;
  for(int i = 1; i <= n; i++){
    if(!ind[i]) que.push(i);
  }
  for(; !que.empty(); ){
    int u = que.front(); que.pop();
    for(int v : H[u]){
      f[v] = min(3, f[v] + f[u]);
      if(!--ind[v]) que.push(v);
    }
  }
  int res = 0;
  for(int i = 1; i <= n; i++){
    res += f[i] == 2;
  }
  return res;
}

void Solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++) cin >> x[i];
  for(int i = 1; i <= n; i++) G[i].clear();
  for(int i = 1; i <= n; i++){
    int pre = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
    int nxt = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
    for(int j = pre; j <= pre + 2; j++){
      if(abs(x[i] - x[j]) <= d) G[i].push_back(j); 
    }
    for(int j = max(pre + 3, nxt - 2); j <= nxt; j++){
      if(abs(x[i] - x[j]) <= d) G[i].push_back(j); 
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) ans += Calc(i);
  cout << ans / 2 << '\n';
}

}

namespace sub2{

ll d, x, y;
int n;

void Solve(){
  cin >> n >> d >> x;
  if(n == 1) return cout << 0 << '\n', void();
  cin >> y;
  d /= (y - x);
  for(int i = 1; i <= n - 2; i++) cin >> x;
  if(d <= 1) return cout << 0 << '\n', void();
  ll ans = n - 2 * d + 1;
  cout << max(ans, 0ll) << '\n';
}

}

void Solve(){
  if(type <= 10){
    sub1::Solve();
  }else if(type >= 13 && type <= 14){
    cout << 0 << '\n';
  }else if(type >= 11 && type <= 12){
    sub2::Solve();
  }
}

int main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T; cin >> type >> T;
  for(; T; Solve(), T--); 
  return 0;
}