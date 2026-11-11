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

int n;
LL m, a[MAXN], s[MAXN];

void work(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++){
    s[i] = s[i - 1] + a[i];
  }
  int ANS = 0;
  for(int i = 1; i <= n; i++){
    int l = 1, r = i;
    while(l < r){
      int mid = (l + r) >> 1;
      LL sum = s[i] - s[mid - 1];
      sum = a[i] * (i - mid + 1) - sum;
      if(sum <= m){
        r = mid;
      }else l = mid + 1;
    }
    ANS = max(ANS, i - l + 1);
  }
  cout << ANS << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  int T = 1;
  while(T--) work();
  return 0;
}