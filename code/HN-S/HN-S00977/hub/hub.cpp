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

const int MAXN = 1e6 + 3;

int n, k;
int lim;
PII fa[MAXN];

bool check(int _lim){
  if(k == n) return 1;
  lim = _lim;
  for(int i = 1; i <= n; i++){
    dep[i] = 1;
    for(PII e : eg[i]){
      
    }
  }
}

void work(){
  cin >> n >> k;
  for(int i = 1, U, V; i < n; i++){
    cin >> U >> V;
    eg[U].push_back({V, i}), eg[V].push_back({U, i});
  }
  int l = 0, r = n;
  while(l < r){
    int mid = (l + r) >> 1;
    if(check(mid)){
      r = mid;
    }else l = mid + 1;
  }
  cout << l << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int T = 1;
  int cid;
  cin >> cid >> T;
  while(T--) work();
  return 0;
}