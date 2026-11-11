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

const int MAXN = 5e5 + 3;

int n, m, d, Q;
LL gaoxiao[MAXN];
LL dis[503][503];
vector<PII> to[MAXN];

inline void ckmin(LL& x, LL y){ x = min(x, y); }

void work(){
  int cid;
  cin >> cid >> n >> m >> d >> Q;
  for(int i = 1; i <= m; i++){
    cin >> gaoxiao[i];
  }
  for(int i = 1, len, x, y; i <= n; i++){
    cin >> len;
    while(len--){
      cin >> x >> y;
      to[x].push_back({i, y});
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) dis[i][j] = 1e18;
    dis[i][i] = 0;
  }
  for(int i = 1; i <= m; i++){
    for(PII e1 : to[i]){
      for(PII e2 : to[i]) if(e1 != e2){
        ckmin(dis[e1.first][e2.first], e1.second + e2.second);
        ckmin(dis[e2.first][e1.first], e1.second + e2.second);
      }
    }
  }
  for(int h = 1; h <= n; h++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dis[i][j] = min(dis[i][j], dis[i][h] + dis[h][j]);
      }
    }
  }
  while(Q--){
    int x, y;
    cin >> x >> y;
    LL ANS = 1e18;
    for(PII e1 : to[x]){
      for(PII e2 : to[y]){
        ANS = min(ANS, e1.second + e2.second + dis[e1.first][e2.first]);
      }
    }
    cout << gaoxiao[x] + gaoxiao[y] + ANS << "\n";
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  int T = 1;
  while(T--) work();
  return 0;
}