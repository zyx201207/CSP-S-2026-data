#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e6 + 5;

long long X[MAX], f[MAX], g[MAX];
int lgt[MAX];

int c, t, n;
long long d, ans = 0;

bool chk(int x, int j){
  if(x <= 0){return 0;};
  return (lgt[x] == j);
}

int mn[MAX];

void solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> X[i]; 
    mn[i] = i;
  }
  for(int i = n - 1, j = n; i >= 1; i--){
    while(X[j] - X[i] > d) --j;
    mn[lgt[i]] = min(mn[lgt[i]], i);
  }
  for(int i = 1, nx; i <= n; i++){
    ++f[i];
    nx = lgt[i];
    if(lgt[nx]){
      if(chk(nx - 1, lgt[nx])){
        if(!chk(nx - 2, lgt[nx])) g[lgt[nx]] += f[i];
      }else{
        f[nx] += f[i], g[nx] += g[i];
      }
    }
    ans += g[i];
    if(mn[i] < i - 1 && lgt[mn[i]+1] > i ){
      ans += f[mn[i]+1] - 1;
    }
  }
  cout << ans << '\n';
  for(int i = 1; i <= n; i++) f[i] = g[i] = 0;  
}

int main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> c >> t;
  while(t--){
    solve();
  }
  return 0;
}