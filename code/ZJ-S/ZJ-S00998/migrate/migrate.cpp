#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],dp[5005][5005],dis[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dp,0x3f,sizeof(dp));
		memset(dis,0,sizeof(dis));
		memset(a,0,sizeof(a));
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			cout<<n-3<<endl;
			continue;
		}
		for(int i = 1;i<=n;i++){
			for(int j = i;j<=n;j++){
				if(a[j]-a[i]<=d)dp[i][j]=1;
			}
		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					if(dp[i][j]>dp[i][k]+dp[k][j]){
						dp[i][j] = dp[i][k]+dp[k][j];
					}
				}
			}
		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					if(dp[i][j]==dp[i][k]+dp[k][j]){
						dis[i][j]++;
					}
				}
			}
		}
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i;j<=n;j++){
				if(dis[i][j]==2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
