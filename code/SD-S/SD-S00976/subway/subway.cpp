#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int M=5e5+5,V=5e5+500+5,E=1e6+5,Q=1e5+5;
int C,n,m,d,q;
int wei[M];
struct Edge{
	int v,w,nxt;
}edge[E];
int head[V],cnt=0;
void addedge(int u,int v,int w){
	edge[++cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
struct Question{
	int S,T;
	ll ans;
}req[Q];
ll dis[V];
bool vis[V];
priority_queue<pair<ll,int> >que;
void dijkstra(int St){
	fill(dis+1,dis+m+n+1,inf);
	fill(vis+1,vis+m+n+1,false);
	que.emplace(0,St);
	while(!que.empty()){
		pair<ll,int>top=que.top();
		que.pop();
		int u=top.second;
		ll x=-top.first;
		if(vis[u])continue;
		vis[u]=true;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].v,w=edge[i].w;
			if(dis[v]>x+w){
				dis[v]=x+w;
				que.emplace(-x-w,v);
			}
		}
	}
	for(ll i=1;i<=q;++i)
		req[i].ans=min(req[i].ans,dis[req[i].S]+dis[req[i].T]);
}
namespace BFS{
queue<int>que;
void bfs(int St){
	fill(dis+1,dis+m+n+1,inf);
	fill(vis+1,vis+m+n+1,false);
	vis[St]=true;
	dis[St]=0;
	que.push(St);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].v,w=edge[i].w;
			if(!vis[v]){
				vis[v]=true;
				dis[v]=dis[u]+w;
				que.push(v);
			}
		}
	}
	for(ll i=1;i<=q;++i)
		req[i].ans=min(req[i].ans,dis[req[i].S]+dis[req[i].T]);
}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>wei[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			addedge(x,m+i,y);
			addedge(m+i,x,y);
		}
	}
	for(int i=1;i<=q;++i){
		cin>>req[i].S>>req[i].T;
		req[i].ans=inf;
	}
	if(12<=C&&C<=19){
		for(int i=1;i<=n;++i)BFS::bfs(m+i);
	}else if(22<=C){
		srand(time(0));
		for(int i=1;i<=20;++i){
			int u=rand()%n+1;
			dijkstra(m+u);
		}
	}else
		for(int i=1;i<=n;++i)dijkstra(m+i);
	for(int i=1;i<=q;++i)
		cout<<req[i].ans+wei[req[i].S]+wei[req[i].T]<<'\n';
	return 0;
}

