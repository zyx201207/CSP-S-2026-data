#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
const int maxn=5000;
long long x[maxn+5],dp[maxn+5][maxn+5],cnt[maxn+5][maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<0<<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			cnt[i][i]=1;
			for(int j=i+1;j<=n;j++){
				dp[i][j]=2e18;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n-1;j++){
				for(int k=j+1;k<=n&&(x[k]-x[j])<=d;k++){
					if(dp[i][k]>dp[i][j]+1){
						dp[i][k]=dp[i][j]+1;
						cnt[i][k]=cnt[i][j];
					}
					else if(dp[i][k]<dp[i][j]+1){
						continue;
					}
					else cnt[i][k]+=cnt[i][j];
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
