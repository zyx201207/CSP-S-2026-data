#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1000;
#define int long long
int n,m,c,t;
int a[N],dp[N][N],u[N][N];
int ans=0;
void init(){
	for (int i=1;i<=n;i++){
		a[i]=0;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			dp[i][j]=0;
			u[i][j]=0;
		}
	}
	ans=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		init();
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int j=n;j>=1;j--){
			for (int i=j-1;i>=1;i--){
				if ((a[i+1]-a[i])>m) break;
				if ((a[j]-a[i])<=m){
					dp[i][j]=1;
					u[i][j]=1;
					continue;
				}
				for (int k=i+1;k<j;k++){
					if ((a[k]-a[i])>m || dp[k][j]==0) break;	
					dp[i][j]=dp[k][j]+1;
				}
				for (int k=i+1;k<j;k++){
					if ((a[k]-a[i])>m || dp[k][j]==0) break;
					if (dp[i][j]==dp[k][j]+1) u[i][j]+=u[k][j];
				}
				if (u[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
