#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
//1~mµØÌú¿Ú m+1~2mÕ¾Ìü 2m+1~3mÕ¾Ì¨
struct Edge{
	LL v,w;
};
struct Path{
	LL u,d;
	bool operator < (const Path b)const{
		return b.d<d;
	}
};
LL c,n,m,d,q,w[N],k[N],a[N],t[N],dis[N];
vector<Edge> g[N];
bool vis[N];
LL ans=1e18;
void dfs(LL st,LL d){
	if(vis[st]){
		ans=min(ans,d);
	}
	for(Edge e:g[st]){
		vis[st]=true;
		dfs(e.v,e.w+d);
		vis[e.v]=true;
	}
	vis[st]=true;
}
void dijkstra(LL st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[st]=0;
	priority_queue<Path> pq;
	pq.push({st,0});
	while(!pq.empty()){
		int u=pq.top().u;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(Edge e:g[u])if(!vis[e.v]){
			int v=e.v,w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i].push_back({i+m+1,w[i]});
		g[i+m+1].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			g[m+i+1].push_back({2*m+i+2,t[j]}); 
			g[2*m+2+i].push_back({m+i+1,t[j]}); 
		}
		for(int j=1;j<k[i];j++){
			g[2*m+a[j]+2].push_back({2*m+a[j+1]+2,0});
			g[2*m+a[j+1]+2].push_back({2*m+a[j]+2,0});
		}
	}
	for(int i=1;i<=q;i++){
		LL x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
