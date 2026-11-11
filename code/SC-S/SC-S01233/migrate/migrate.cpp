#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,T;
int n,d,ans;
int x[2000017];
int dp[2501][2501];
int cnt[2501][2501];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) dp[i][j]=0x3f3f3f3f3f3f;
				else dp[i][j]=0;
				if(i!=j) cnt[i][j]=0;
				else cnt[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i;k--){
					if(x[j]-x[k]<=d){
						if(dp[i][j]>dp[i][k]+1){
							dp[i][j]=dp[i][k]+1;
							cnt[i][j]=cnt[i][k];
						}else if(dp[i][j]==dp[i][k]+1){
							cnt[i][j]+=cnt[i][k];
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				cout<<dp[i][j]<<' ';
//			}
//			cout<<'\n';
//			for(int j=i+1;j<=n;j++){
//				cout<<cnt[i][j]<<' ';
//			}
//			cout<<'\n';
//			cout<<'\n';
//		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/