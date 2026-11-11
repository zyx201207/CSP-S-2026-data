#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define int long long
#define pb emplace_back
#define rep(i,j,k) for(int i=(j);i<=(int)(k);++i)
const int N=505,M=5e5+5,inf=1e18;
int C,n,m,d,q,w[M],dp[N][N];
vector<pair<int,int>>g[M];
inline void OIer_WiFi(){
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i) dp[i][i]=0;
	for(int i=1;i<=m;++i) scanf("%lld",w+i);
	for(int i=1,k;i<=n;++i){
		scanf("%lld",&k);
		for(int a,t;k--;)
			scanf("%lld%lld",&a,&t),g[a].pb(i,t);
	}
	rep(i,1,m) rep(j,0,g[i].size()-1){
		rep(k,j+1,g[i].size()-1){
			int u=g[i][j].X,v=g[i][k].X,w=g[i][j].Y+g[i][k].Y;
			dp[u][v]=min(dp[u][v],w),dp[v][u]=min(dp[v][u],w);
		}
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n)
		dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	
	for(int st,ed;q--;){
		scanf("%lld%lld",&st,&ed);
		int res=inf;
		rep(i,0,g[st].size()-1) rep(j,0,g[ed].size()-1)
			res=min(res,dp[g[st][i].X][g[ed][j].X]+g[st][i].Y+g[ed][j].Y);
		res+=w[st]+w[ed];
		printf("%lld\n",res);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	OIer_WiFi(); return 0;
}
// 14:56 AC max=962ms