#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const int M=5e5+10;
const ll INF=1e18;
int c,n,m,d,Q;
ll W[M];
int h[N+M],tot;
struct Node{
	int to,nxt;
	ll w;
}e[2*M];
void Add(int u,int v,ll w){
	tot++;
//	cout<<tot<<'\n';
	e[tot].to=v,e[tot].nxt=h[u],e[tot].w=w;
	h[u]=tot;
}
struct Heapnode{
	ll w;
	int u;
	bool operator <(const Heapnode &x) const{
		return w>x.w;
	}
};
vector<Heapnode> a[M];
priority_queue<Heapnode> q;
int pre[N+M];
ll dis[N+M],ddis[N][N];
//bool vis[N+M];
void bfs(){
	memset(ddis,0x3f,sizeof(ddis));
	for(int i=1;i<=n;i++){
		pre[i]=i;
		ddis[i][i]=0;
		q.push((Heapnode){0,i});
	}
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!pre[v]){
				pre[v]=pre[u];
				dis[v]=dis[u]+e[i].w;
				q.push((Heapnode){dis[v],v});
			}else if(pre[v]!=pre[u]){
//				cout<<pre[u]<<' '<<pre[v]<<' '<<dis[u]+dis[v]+e[i].w<<'\n';
				ddis[pre[v]][pre[u]]=min(ddis[pre[v]][pre[u]],dis[v]+dis[u]+e[i].w);
				ddis[pre[u]][pre[v]]=min(ddis[pre[u]][pre[v]],dis[v]+dis[u]+e[i].w);
			} 
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ddis[i][j]=min(ddis[i][j],ddis[i][k]+ddis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++){
		int k,x;
		ll y;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[x].push_back((Heapnode){y,i});
			Add(i,n+x,y),Add(n+x,i,y);
		}
	}
	bfs();
	floyd();
	ll ans;
//	for(int i=1;i<=m;i++){
//		cout<<i<<'\n';
//		for(int j=0;j<a[i].size();j++) cout<<a[i][j].u<<' '<<a[i][j].w<<'\n';
//	}
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		ans=INF;
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				int u=a[x][j].u,v=a[y][k].u;
				ans=min(ans,ddis[u][v]+a[x][j].w+a[y][k].w);
			}
		}
		ans+=W[x]+W[y];
		cout<<ans<<'\n';
	}
	return 0;
}
//Flaming June.
