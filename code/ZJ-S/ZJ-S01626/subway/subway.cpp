#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10;
int C,n,m,d,q;
ll w[M];
int h[M<<1],cnt=1;
struct Edge{
	int to,nxt;
	ll val;
}e[M<<2];
void add(int u,int v,ll c){
	e[++cnt]={v,h[u],c},h[u]=cnt;
}
struct point{
	int pt;
	ll val;
};
vector<point> g[M];
ll dis[N][N],f[M+N];
bool vis[N+M];
void dijkstra(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	memset(f,0x3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	f[s]=0;q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			ll c=e[i].val;
			if(f[v]>f[u]+c){
				f[v]=f[u]+c;
				q.push({f[v],v});
			}
		}
	}
}
void bfs(int s){
	queue<int> q;
	memset(f,0x3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	f[s]=0;q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(vis[v]) continue;
			f[v]=f[u]+e[i].val;
			vis[v]=1;
			q.push(v);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;ll t;
			cin>>a>>t;
			g[a].push_back({i,t});
			add(i,a+n,t);add(a+n,i,t);
		}
	}
	if(16<=C && C<=19){
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				dis[i][j]=f[j];
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++){
				dis[i][j]=f[j];
			}
		}	
	}
	while(q--){
		ll ans=1e18;
		int x,y;cin>>x>>y;
		for(int i=0;i<(int)g[x].size();i++){
			for(int j=0;j<(int)g[y].size();j++){
				int u=g[x][i].pt,v=g[y][j].pt;
				ll cu=g[x][i].val,cv=g[y][j].val;
				ans=min(ans,w[x]+w[y]+cu+cv+dis[u][v]);
				//cout<<u<<" "<<v<<" "<<dis[u][v]<<" "<<cu<<" "<<cv<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}