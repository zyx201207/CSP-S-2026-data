#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int unsigned long long

const int N=509;
const int M=6e4+9;
int c,n,m,d,q;
struct edge{int v,w;};
vector<edge>g[M];
int mark[N][M],tot;
int a[M],t[M];
int dis[N*M];
bool vis[N*M];
struct node{int u,dis;};
bool operator<(node x,node y){return x.dis>y.dis;}
priority_queue<node>pq;
int ans[5009][5009];

int get(int node,int line){
	line+=2;
	if(mark[line][node])return mark[line][node];
	return mark[line][node]=++tot;
}

int dijkstra(int st,int ed){ // ¶¼ÊÇstation
	for(int i=1;i<=tot;i++)dis[i]=5e18,vis[i]=0;
	dis[st]=0;
	pq.push({st,0});
	while(!pq.empty()){
		int u=pq.top().u;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto ert:g[u]){
			int v=ert.v;
			int w=ert.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
	return dis[ed];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		int u=get(i,-2);
		int v=get(i,-1);
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			int u=get(a[j],-1);
			int v=get(a[j],i);
			g[u].pb({v,t[j]});
			g[v].pb({u,t[j]});
			if(j>1){
				int uu=get(a[j-1],i);
				int vv=get(a[j],i);
				g[uu].pb({vv,0});
				g[vv].pb({uu,0});
			}
		}
	}
	for(int i=1;i<=tot;i++)for(int j=1;j<=tot;j++)ans[i][j]=5e18;
	while(q--){
		int x,y;
		cin>>x>>y;
		int st=get(x,-2);
		int ed=get(y,-2);
		if(ans[st][ed]<5e18)cout<<ans[st][ed]<<'\n';
		else{
			cout<<dijkstra(st,ed)<<'\n';
			for(int i=1;i<=tot;i++)ans[st][i]=dis[i];
		}
	}
}
