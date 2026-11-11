#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+100;
int n;
int m,a[MAXN];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin >> n >> m;
  int ans=0,nd=0;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
  }
  sort(a+1,a+n+1);
  for (int i=1,j=1; i<=n; i++) {
    nd+=(i-j)*(a[i]-a[i-1]);
    while (nd>m) {
      nd-=a[i]-a[j];
      j++;
    }
   // cout << i << " " << j << " " << nd << "\n"; 
    ans=max(ans,i-j+1);
  }
	cout << ans;
	return 0;
}
