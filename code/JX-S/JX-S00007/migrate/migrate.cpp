#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define I return
#define love 0
#define Sasuke ;
#define forever ;
#define int long long
const int N = 305;
int c,t,n,d;
int a[N],ma[N][N],dis[N][N],cnt[N][N];
signed main() {
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  ios
  cin >> c >> t;
  while(t--) {
	  cin >> n >> d;
	  memset(ma,0,sizeof(ma));
	  memset(dis,0x3f,sizeof(dis));
	    memset(cnt,0,sizeof(cnt));
	  for(int i = 1; i <= n; i++) cin >> a[i];
	  for(int i = 1; i <= n; i++) 
		  for(int j = i + 1; j <= n; j++) if(abs(a[i] - a[j]) <= d) dis[i][j] = 1; 
	  for(int k = 1; k <= n; k++) {
		  for(int i = 1; i < k; i++) {
			  for(int j = k + 1; j <= n; j ++) {
					   int val = dis[i][k] + dis[k][j];	
				 //  cout << i << " " << k << " " << j << " " << val << '\n';
					   if(val < dis[i][j]){
						   dis[i][j] = val, cnt[i][j] = 1;
					   } 
					   else if(val == dis[i][j]) {
						   cnt[i][j]++;
					   }		 
			  }
		  }
	  }
	  long long ans = 0;
	  for(int i =1;i <= n; i++) {
		  for(int j = i + 1; j <= n; j++){
			  if(cnt[i][j] == 2) ans++;
		  } 
	  }
	  cout << ans << '\n';
  } 
  I love Sasuke forever 
}
