#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define pii pair<int,int>
#define ft first
#define sd second
#define db double
const int INF=1e18,N=2e4+5;
int head[N],tot;
struct E {
	int next,to,w;
} e[N<<1];
void add(int u,int v,int w) {
	e[++tot]= {head[u],v,w};
	head[u]=tot;
}
int c,n,m,d,Q;
int val[N],idx;
struct node{
	int dis,id;
	const bool operator<(const node& x)const{
		return x.dis<dis;
	}
};
priority_queue<node>q;
int dis[N];
bool vis[N];
void dij(int s){
	fill(dis+1,dis+idx+1,INF);
	dis[s]=0;
	fill(vis+1,vis+idx+1,0);
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	AC;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1; i<=m; i++)cin>>val[i];
	idx=m;
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		int pre=0;
		for(int i=1; i<=k; i++) {
			int t,w;
			cin>>t>>w;
			int u=++idx;
			add(u,t,w);
			add(t,u,w);
			if(pre) {
				add(pre,u,0);
				add(u,pre,0);
			}
			pre=u;
		}
	}
	while(Q--) {
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<val[u]+dis[v]+val[v]<<'\n';
	}
	return 0;
}


