#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rsrt(x) sort(rALL(x))
#define rev(x) reverse(ALL(x))
#define szsz(x) (int)((x).size())
#define lb(v,x) (int)(lower_bound(ALL(v),x)-(v).begin())
#define ub(v,x) (int)(uppwe_bound(ALL(v),x)-(v).begin())
#define popc(x) __builtin_popcount(x)
#define lowbit(x) ((x)&(-(x)))
using LL = long long;
using DD = double; // long double
using ULL = unsigned long long;
using UI = unsigned int;
using PII = pair<int, int>;
using i128 = __int128_t;

const int MAXN = 2e6 + 3;

int n;
LL d, a[MAXN];
int rr[MAXN];
int dp[MAXN][6];
// 1, 11, 21, 2, 31

void work(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) rr[i] = upper_bound(a+1, a+1+n, a[i]+d)-a-1;
  for(int i = 1; i <= n; i++){
    for(int o = 0; o < 6; o++) dp[i][o] = 0;
  }
  for(int i = n; i >= 1; i--){
    if(rr[i] == i) continue;
    // 1
    int cof = 0, ed = 1, la = 1;
    dp[i][0] = dp[rr[i]][rr[i] == i + 1 ? 0 : 1];
    // 11
    if(i > 1){
      cof = rr[i-1] - max(i, rr[i-2]);
      if(rr[i-1] == rr[i]){
        if(rr[i-2] == rr[i]) dp[i][1] = cof;
        else dp[i][1] = cof + dp[rr[i]][3];
      }else{
        if(rr[i-1] < rr[i]-1){
          dp[i][1] = cof + dp[rr[i]][1];
        }else{
          if(rr[i-2] == rr[i]-1){
            dp[i][1] = cof + dp[rr[i]][4];
          }else{
            dp[i][1] = cof + dp[rr[i]][2];
          }
        }
      }
    }
    // 21
    if(i > 1){
      cof = 0;
      if(rr[i-1] == rr[i]){
      }else{
        if(rr[i-1] < rr[i]-1){
          dp[i][2] = dp[rr[i]][1];
        }else{
          dp[i][2] = dp[rr[i]][4];
        }
      }
    }
    // 2
    cof = rr[i] - max(i, rr[i-1]);
    if(rr[i-1] == rr[i]){
      dp[i][3] = cof;
    }else{
      dp[i][3] = cof + dp[rr[i]][3];
    }
    // 31
    if(i > 1){
      cof = 0;
      if(rr[i-1] == rr[i]){
      }else{
        if(rr[i-1] < rr[i]-1){
          dp[i][4] = dp[rr[i]][1];
        }else{
          dp[i][4] = dp[rr[i]][4];
        }
      }
    }
  }
  LL ANS = 0;
  for(int i = 1; i <= n; i++) ANS += dp[i][0];
  cout << ANS << "\n";
}
/*
jikule孩子，浪费 1h
*/
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int T = 1;
  int cid;
  cin >> cid >> T;
  while(T--) work();
  return 0;
}