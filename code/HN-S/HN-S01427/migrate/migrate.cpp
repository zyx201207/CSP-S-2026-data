#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 2e6 + 1, MAXN1 = 5e3 + 1;

int c, t, n, dp[MAXN1][MAXN1], cnt[MAXN1][MAXN1];
ll d, ans, x[MAXN];

vector<ll> vt;

inline void Solve1(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> x[i];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] = n + 1, cnt[i][j] = 0;
    }
  }
  ans = 0;
  for(int i = 1; i <= n; i++){
    dp[i][i] = 0;
    for(int j = i + 1; j <= n; j++){
      for(int k = i; k < j; k++){
        if(abs(x[j] - x[k]) <= d){
          int v = dp[i][k] + 1;
          if(v < dp[i][j]){
            dp[i][j] = v, cnt[i][j] = 1;
          }else if(v == dp[i][j]){
            cnt[i][j]++;
          }
        }
      }
      ans += (cnt[i][j] == 2);
    }
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin >> c >> t;
  while(t--){
    Solve1();
  }
  return 0;
}
