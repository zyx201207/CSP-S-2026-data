#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=510,M=5e5+10,INF=1e17;
int c,n,m,d,Q,a[M],dp[N][N],dis[N],mp[N][N];
bool vis[N];
vector<pii> e[N],g[M];
void init(){
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) mp[i][j]=INF;
	for(int i=1;i<=m;i++){
		int sz=g[i].size();
		for(int x=0;x<sz;x++){
			for(int y=x+1;y<sz;y++){
				int u=g[i][x].first,v=g[i][y].first,w=g[i][x].second+g[i][y].second;
				mp[u][v]=min(mp[u][v],w),mp[v][u]=min(mp[v][u],w);
			}
		}
	}
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]!=INF) e[i].push_back({j,mp[i][j]});
		}
	}
	
}
void dij(int S){
	for(int i=0;i<=n;i++) vis[i]=0,dis[i]=INF;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[S]=0,q.push({0,S});
	while(!q.empty()){
		int u=q.top().second; q.pop();
		int sz=e[u].size();
		if(vis[u]) continue;	
		vis[u]=1;	
		for(int i=0;i<sz;i++){
			pii y=e[u][i];
			int v=y.first,w=y.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++) dp[S][i]=dis[i];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int k; scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,y; scanf("%lld %lld",&x,&y);
			g[x].push_back({i,y});
		}
	}
	init();
	for(int i=1;i<=n;i++) dij(i);
	while(Q--){
		int st,ed,ans=INF;
		scanf("%lld %lld",&st,&ed);
		int sz1=g[st].size(),sz2=g[ed].size();
		for(int i=0;i<sz1;i++){
			pii x=g[st][i];
			for(int j=0;j<sz2;j++){
				pii y=g[ed][j];
				ans=min(ans,dp[x.first][y.first]+x.second+y.second);
			}
		}
		printf("%lld\n",ans+a[st]+a[ed]);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
