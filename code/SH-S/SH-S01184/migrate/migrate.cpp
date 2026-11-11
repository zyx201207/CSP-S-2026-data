#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,sum[2000020],vis[2000020],a[2000020],cha[2000020],dp[2000020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	memset(dp,1,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<t;i++){
		int ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			cha[j]=a[j]-a[j-1];
			if(j>=2){
				sum[j]=cha[j]+sum[i-1];
			}
		}
		cha[1]=0;
		memset(vis,0,sizeof(vis));
		for(int j=2;j<=n;j++){
			for(int k=1;j-k>=1;k++){
				if(a[i]-a[j-k]<=d){
					int t=min(dp[j],dp[j-k]+1);
					if(t<dp[j]){
						vis[j]=0;
						dp[j]=t;
					}
					if(t==dp[j]){
						vis[j]++;
					}
				}
				else break;
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j]==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
