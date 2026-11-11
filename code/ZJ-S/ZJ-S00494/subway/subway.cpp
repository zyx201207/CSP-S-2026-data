#include<bits/stdc++.h>
#define int long long
using namespace std;
long long dp[1501][1501];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	memset(dp,63,sizeof dp);
	int n,m,d,q;
	cin>>n>>n>>m>>d>>q;
	long long w[m+1];
	for(int i=1;i<=m;++i)cin>>w[i],dp[i][i]=0;
	for(int i=m+1;i<=m+n;++i){
		int k;
		cin>>k;
		for(int j=0;j<k;++j){
			int x,z;
			cin>>x>>z;
			dp[x][i]=dp[i][x]=z;
		}
		dp[i][i]=0;
	}
	const int t=n+m;
	for(int k=2;k<=t;++k){
		for(int i=1;i<=t;++i){
			for(int j=1;j<i;++j){	
				if(dp[i][k]+dp[k][j]<dp[i][j])dp[i][j]=dp[j][i]=dp[i][k]+dp[k][j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dp[x][y]+w[y]<<'\n';
	}
}