#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=1e6+10;
typedef pair<int,int> P;
int c,n,m,d,Q;
struct node{
	int v,w;
};vector<node> G[N+M];
int x[M],k[N];
int dis[N][N];
priority_queue<P,vector<P>,greater<P> > q;
void Dij(int st){
	dis[st][st]=0;q.push({0,st});
	while(!q.empty()){
		int u=q.top().second,d=q.top().first;
		q.pop();
		if(dis[st][u]<d) continue;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v,w=G[u][i].w;
			for(int j=0;j<G[v].size();j++){
				int vv=G[v][j].v,ww=G[v][j].w;
				if(dis[st][vv]>dis[st][u]+w+ww) dis[st][vv]=dis[st][u]+w+ww,q.push({dis[st][vv],vv});
			}
		}
	}
}
signed main(){ 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dis[i][j]=1e18L;
	for(int i=1;i<=m;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			G[a+n].push_back({i,t});
			G[i].push_back({a+n,t});
		}
	}for(int i=1;i<=n;i++) Dij(i);
	while(Q--){
		int st,ed;cin>>st>>ed;
		int ans=1e18L;
		for(int i=0;i<G[st+n].size();i++){
			int u=G[st+n][i].v,d=G[st+n][i].w;
			for(int j=0;j<G[ed+n].size();j++){
				int v=G[ed+n][j].v,w=G[ed+n][j].w;
				ans=min(ans,dis[u][v]+d+w);
			}
		}cout<<ans+x[st]+x[ed]<<"\n";
	}
	return 0;
} 
