//migrate
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+5;
int c,t;
int n,d,a[N];
int mp[N][N],ans;
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	/**/
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j] = abs(a[i]-a[j])<=d;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(mp[i][j]) continue;
				int cnt=0;
				for(int k=i+1;k<j;k++){
					cnt+= mp[i][k]&&mp[k][j];
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		
		cout << ans <<'\n';
	}
	return 0;
	
} 
/*

2

  |   |
1 2 4 8 9
3 2 0
*/
