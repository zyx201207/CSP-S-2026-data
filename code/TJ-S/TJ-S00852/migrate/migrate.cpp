#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,t,v[500005];
long long dp[1005][1005],a[1005][1005],cnt[1005][1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		if(n<=1000){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j)a[i][j]=INT_MAX;
				}
			}
			for(int i=1;i<=n;i++){
				scanf("%d",&v[i]);
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(v[j]-v[i]<=d){
						a[i][j]=1;
						a[j][i]=1;
					}else{
						break;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j)dp[i][j]=INT_MAX;
					if(a[i][j]){
						dp[i][j]=a[i][j];
						cnt[i][j]=1;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(i==j||i==k||j==k)continue;
						if(dp[i][j]==dp[i][k]+dp[k][j]){
							cnt[i][j]++;
						}else if(dp[i][j]>dp[i][k]+dp[k][j]){
							dp[i][j]=dp[i][k]+dp[k][j];
							cnt[i][j]=1;
						}
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp[i][j]!=INT_MAX&&cnt[i][j]==2){
						
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
