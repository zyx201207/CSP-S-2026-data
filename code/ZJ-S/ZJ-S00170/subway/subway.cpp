#include<bits/stdc++.h>
using namespace std;
#define int long long
//You are more powerful than you think.
const int N=510;
const int M=500010;
int c,n,m,d,q;
int w[M];
struct edge{
	int to,wt;
};
vector<edge>g[M];
int dp[N][N];
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto lty:g[i]){
			for(auto yzl:g[i]){
				if(lty.to==yzl.to) continue;
				int u=lty.to;
				int v=yzl.to;
				int val=lty.wt+yzl.wt;
				dp[u][v]=dp[v][u]=min(dp[u][v],val);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int aa,tt;
			cin>>aa>>tt;
			g[aa].push_back({i,tt});
		}
	}
	solve();
	while(q--){
		int x,y;
		cin>>x>>y;
		int miku=LONG_LONG_MAX;
		for(auto lty:g[x]){
			for(auto yzl:g[y]){
				int u=lty.to;
				int v=yzl.to;
				miku=min(miku,dp[u][v]+lty.wt+yzl.wt);
			}
		}
		cout<<miku+w[x]+w[y]<<"\n";
	}
	return 0;
}