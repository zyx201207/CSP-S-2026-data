#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[305];
struct DP{
	int v,cnt;
}dp[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		memset(dp,0x3f,sizeof dp);
		for(int i=1;i<=n;i++){
			dp[i][i].v=0;
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					dp[i][j].v=1;
					dp[i][j].cnt=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					if(dp[i][k].v>=0x3f3f3f3f||dp[k][j].v>=0x3f3f3f3f)continue;
					if(dp[i][j].v>dp[i][k].v+dp[k][j].v){
						dp[i][j].v=dp[i][k].v+dp[k][j].v;
						dp[i][j].cnt=dp[i][k].cnt*dp[k][j].cnt;
//						cout<<dp[i][k].cnt<<'*'<<dp[k][j].cnt<<'\n';
					} else if(dp[i][j].v==dp[i][k].v+dp[k][j].v){
//						cout<<dp[i][j].cnt<<'+'<<dp[i][k].cnt<<'*'<<dp[k][j].cnt<<'\n';
						dp[i][j].cnt+=dp[i][k].cnt*dp[k][j].cnt;
						
					}
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][j].cnt==2)res++;
//				cout<<i<<' '<<j<<' '<<dp[i][j].v<<'\n';
			}
		}
		cout<<res/2<<'\n';
	}
	return 0;
}