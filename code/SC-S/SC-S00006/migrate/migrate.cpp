#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int dp[5005][5005],f[5005][5005],a[5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;a[j]-a[k]<=d&&k>=i;k--){
					if(k==j-1){
						dp[i][j]=dp[i][k]+1;
						f[i][j]=f[i][k];
					}else{
						int t=dp[i][j];
						dp[i][j]=min(dp[i][j],dp[i][k]+1);
						if(t==dp[i][j]){
							f[i][j]+=max(1LL,f[i][k]);
						}else{
							f[i][j]=0;
						}
					}
				}
				if(dp[i][j]==0){
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j]==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}