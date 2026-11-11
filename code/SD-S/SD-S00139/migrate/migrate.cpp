#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int cnt[5005][5005];
int x[2000005];
int ans;
int n,d;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=0;
				dp[i][j]=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int dd=abs(x[i]-x[j]);
				if(dd<dp[i][j]){
					dp[i][j]=dd;
					cnt[i][j]++;
				}
			}
			dp[i][i]=0;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(i==j||j==k||i==k){
						continue;
					}
					if(dp[i][k]<=d&&dp[k][j]<=d&&dp[i][j]<=d){
						if(dp[i][k]+dp[k][j]<dp[i][j]){
							dp[i][j]=dp[i][k]+dp[k][j];
							cnt[i][j]=1;
						}
						else if(dp[i][k]+dp[k][j]==dp[i][j]){
							cnt[i][j]++;
						}						
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
