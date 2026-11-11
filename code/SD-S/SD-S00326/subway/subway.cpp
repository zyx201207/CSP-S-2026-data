#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXM=5e5+5;
const int MAXN=505;
const int MAXR=1005;
int yuanshen,n,m,d,q;
int w[MAXM],a[MAXM][MAXN],t[MAXM][MAXN];
int head[MAXR],tot,dis[MAXR*MAXN];
bool vis[MAXR*MAXN];
struct Edge{
	int to,next,w;
}e[(MAXR<<1)*MAXN];
struct Node{
	int v,w;
	inline bool operator < (const Node &b)const{
		return w>b.w;
	}
};
inline void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}
void dijkstra(int s){
	priority_queue<Node> q;
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	q.push((Node){s,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to,w=e[i].w;
			if(!vis[v]&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push((Node){v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>yuanshen>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		add(m*(i-1),m*(i-1)+1,w[i]);
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			add(m*(a[i][j]-1)+i+1,m*(a[i][j]-1)+1,t[i][j]);
		}
		for(int j=2;j<=k;j++){
			add(m*(a[i][j-1]-1)+i+1,m*(a[i][j]-1)+i+1,0);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dijkstra(m*(u-1));
		cout<<dis[m*(v-1)]<<"\n";
	}
	return 0;
}
