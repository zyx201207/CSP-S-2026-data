#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5 + 5;
int a[N],s[N],n,m;
signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1;i <= n;i++){
    cin >> a[i];
  }
  sort(a + 1,a + n + 1);
  int ans = 0;
  for (int i = 1;i <= n;i++){
    s[i] = s[i - 1] + a[i];
    int l = 1,r = i;
    while (l <= r){
      int mid = (l + r) >> 1;
      (a[i] * mid - (s[i] - s[i - mid]) <= m)?l = mid + 1:r = mid - 1;
    }
    ans = max(ans,r);
  }
  cout << ans;
}
// great ccf ,you will bring us hope 
// great ccf,you will stronger  
// great ccf,you will save lifes 
// great ccf,you will save the earth
// great ccf,you will greater than everything 
// if you make me ak 
// do clean olympicd 
