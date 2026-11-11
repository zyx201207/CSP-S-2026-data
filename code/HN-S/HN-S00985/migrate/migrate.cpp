#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool aa;
const ll kM = 2e6 + 5;
ll cc, q, n, d, x[kM], nt[kM], pr[kM], f[kM], g[kM];
bool bb;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin >> cc >> q;
  while(q--){
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
      cin >> x[i];
    }
    if(cc == 13 || cc == 14){
      ll p = 1;
      for(int i = 1; i <= n; i++){
        while(x[i] - x[p] > d) p++;
        pr[i] = p;
      }
      p = n;
      for(int i = n; i; i--){
        while(x[p] - x[i] > d) p--;
        nt[i] = p;
      }
      ll ans = 0;
      for(int i = 1; i <= n; i++){
        if(x[i] - x[1] <= d && x[n] - x[i] <= d){
          ans = (pr[i + 1] - 1) * (n - nt[i - 1]);
          break;
        }
      }
      cout << ans << "\n";
    }
    else{
      ll p = 1;
      for(int i = 1; i <= n; i++){
        while(x[i] - x[p] > d) p++;
        pr[i] = p;
      }
      ll ans = 0;
      for(int i = 1; i <= n; i++){
        f[i] = 0, g[i] = 1;
        for(int j = i + 1; j <= n; j++){
          f[j] = 1e18, g[j] = 0;
          for(int k = max(1ll * i, pr[j]); k < j; k++){
            f[j] = min(f[j], f[k] + 1);
          }
          for(int k = max(1ll * i, pr[j]); k < j; k++){
            if(f[j] == f[k] + 1){
              g[j] += g[k];
            }
          }
          if(g[j] == 2) ans++;
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}