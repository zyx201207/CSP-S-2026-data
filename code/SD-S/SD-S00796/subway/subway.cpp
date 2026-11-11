#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
const int maxn=510,maxm=5e5+10;
const ll inf=LLONG_MAX;
vector<vector<ll> > dis;
int cost[maxm];
struct edge { int v,w; };
struct node {
	int u; ll w;
	friend bool operator > (const node &a,const node &b) {
		return a.w>b.w;
	}
};
vector<edge> g[maxn+maxm];
int c,n,m,d,q;
void dijkstra(int s) {
	for(int i=1;i<=n+m;i++) dis[s][i]=inf;
	dis[s][m+s]=0;
	priority_queue<node,vector<node>,greater<node> > q;
	q.push(node{m+s,dis[s][m+s]});
	while(q.size()) {
		int u=q.top().u;
		q.pop();
		for(edge ed:g[u]) {
			int v=ed.v,w=ed.w;
			if(dis[s][v]>dis[s][u]+w) {
				dis[s][v]=dis[s][u]+w;
				q.push(node{v,dis[s][v]});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	dis.resize(n+10);
	for(int i=1;i<=n;i++) dis[i].resize(n+m+10);
	for(int i=1;i<=m;i++) cost[i]=read();
	for(int i=1;i<=n;i++) {
		int k=read();
		while(k--) {
			int u=m+i,v=read(),w=read();
			g[u].emplace_back(edge{v,w});
			g[v].emplace_back(edge{u,w});
		}
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	while(q--) {
		int x=read(),y=read();
		ll ans=inf;
		for(int i=1;i<=n;i++) {
			if(dis[i][x]<inf&&dis[i][y]<inf)
				ans=min(ans,dis[i][x]+dis[i][y]);
		}
		ans+=cost[x]+cost[y];
		printf("%lld\n",ans);
	}
	return 0;
}
