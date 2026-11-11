#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=6e5+10,M=550;
int c,n,m,d,q;
bool vis[N];
int dis[M][M],w[N],a[N],t[N];
int dist[N];
vector<pii> e[N];
vector<pii> fa[N];
void dij(int s) {
	for(int i=1; i<=n+m; i++)
		vis[i]=0,dist[i]=0x3f3f3f3f;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	dist[s]=0;
	q.push({0,s});
	while(q.size()) {
		pii t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0; i<e[u].size(); i++) {
			int v=e[u][i].second,w=e[u][i].first;
			if(dist[v]>dist[u]+w) {
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)scanf("%lld",&w[i]);
	for(int l=1; l<=n; l++) {
		int k;
		scanf("%lld",&k);
		for(int j=1; j<=k; j++) {
			scanf("%lld%lld",&a[j],&t[j]);
			fa[a[j]].push_back({l,t[j]});
			e[a[j]].push_back({t[j],m+l});
			e[m+l].push_back({t[j],a[j]});
		}
	}
	for(int i=1; i<=n; i++) {
		dij(i+m);
		for(int j=1; j<=n; j++)
			dis[i][j]=dist[j+m];
	}
	while(q--) {
		int u,v;
		scanf("%lld%lld",&u,&v);
		int ans=1e9+10;
		for(int i=0; i<fa[u].size(); i++) {
			for(int j=0; j<fa[v].size(); j++) {
				int x=fa[u][i].first,y=fa[v][j].first;
				ans=min(ans,dis[x][y]+fa[u][i].second+fa[v][j].second);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
