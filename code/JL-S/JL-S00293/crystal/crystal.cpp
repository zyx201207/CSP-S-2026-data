#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL 
const int maxn = 5e5 + 10;
int n; LL m;
inline int lowbit(int x) { return x & -x; }
int ans;
LL a[maxn], s[maxn]; 
signed main() {
  freopen("crystal.in", "r", stdin); 
  freopen("crystal.out", "w", stdout); 
  ios :: sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++ i) cin >> a[i]; 
  sort(a + 1,  a + 1 + n); 
  for(int i = 1; i <= n; ++ i) s[i] = s[i - 1] + a[i];
  for(int i = 1; i <= n; ++ i) {
    int l = 1, r = i;
    while(l < r) {
      int mid = l + r >> 1;
      int k = i - mid + 1;
      if(1LL * k * a[i] - (s[i] - s[mid - 1]) <= m) r = mid;
      else l = mid + 1;
    }
    ans = max(ans, i - l + 1); 
  }
  cout << ans << '\n';
  return 0; 
}