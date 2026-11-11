#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+2;
const int M=5e5+2;
const int inf=0x3f3f3f3f3f3f3f3f3f3f;
int c,n,m,d,T;
int test;
int W[M],dis[M+N];
bool vis[M+N];
struct edge{int to,nxt,val;}E[M<<1];
int head[M+N],tot;
void add(int u,int v,int w){
	E[++tot].to=v;
	E[tot].val=w;
	E[tot].nxt=head[u];
	head[u]=tot;
}
struct node{
	int id,val;
	bool operator<(const node &p)
		const{return val>p.val;}
};
priority_queue<node>q;
void Dijkstra(int u){
	while(!q.empty()) q.pop();
	for(int i=1;i<=m*2;i++) dis[i]=inf;
	for(int i=1;i<=m*2;i++) vis[i]=false;
	dis[u]=0;q.push((node){u,0});
	while(!q.empty()){
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=E[i].nxt){
			int v=E[i].to,w=E[i].val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;cin>>v>>w;
			add(m+i,v,w);
			add(v,m+i,w);
		}
	}
	int lst=0;
	while(T--){
		int u,v;cin>>u>>v;
		if(lst!=u) Dijkstra(u);
		cout<<dis[v]+W[u]+W[v]<<"\n";
		lst=u;
	}
	return 0;
}

