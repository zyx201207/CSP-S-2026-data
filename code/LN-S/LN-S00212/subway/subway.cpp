#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c,n,m,d,q;
int dp[N][N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=n;++i)dp[i][i]=0;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=m+1;i<=m+n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int u,v;
			cin>>u>>v;
			dp[i][u]=min(dp[i][u],v);
			dp[u][i]=min(dp[u][i],v);
		}
	}
	for(int k=1;k<=m+n;++k){
		for(int i=1;i<=m+n;++i){
			for(int j=1;j<=m+n;++j){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dp[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}
