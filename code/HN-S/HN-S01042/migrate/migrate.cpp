#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5005],dp[5005][5005],cnt[5005][5005],ans;
signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(dp,0x3f3f3f3f3f3f3f3f,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;a[k]+d>=a[j];k--){
					if(dp[i][k]+1<dp[i][j]){
						cnt[i][j]=1;
						dp[i][j]=dp[i][k]+1;
						continue;
					}
					if(dp[i][k]+1==dp[i][j]){
						cnt[i][j]++;
						continue;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
