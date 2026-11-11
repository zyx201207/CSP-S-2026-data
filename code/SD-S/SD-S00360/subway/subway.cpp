#include<bits/stdc++.h>
#define int long long
#define pll pair<long long,long long>
using namespace std;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q;
int w[N],k[N],a[M][N],t[M][N];
int x[N],y[N];
vector<pll> e[N];
//int dep[N],f[N][25];
//void dfs(int u,int fa){
//	dep[u]=dep[fa]+1;
//	f[u][0]=fa;
//	for(int i=1;i<=19;i++){
//		f[u][i]=f[f[u][i-1]][i-1];
//	}
//	for(auto v:e[u]){
//		
//		if(v==fa) continue;
//		dfs(v,u); 
//	}
//	return ;
//}
//int lca(int u,int v){
//	if(dep[u]<dep[v]) swap(u,v);
//	for(int i=19;i>=0;i--){
//		if(dep[f[u][i]]<=dep[v]){
//			u=f[u][i];
//		}
//	}
//	if(u==v) return u;
//	for(int i=19;i>=0;i--){
//		if(f[u][i]!=f[v][i]){
//			u=f[u][i];
//			v=f[v][i];
//		}
//	}
//	return f[u][0];
//}
bool vis[N],dist[N];
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dist[i]=1e18;
	}
	dist[s]=0;
	priority_queue<pll,vector<pll>,greater<pll> > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.second,w=i.first;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
			}
		}
	}
	return ;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>q>>d;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j>1){
				e[a[i][j]].push_back({a[i][j-1],t[i][j]});
				e[a[i][j-1]].push_back({a[i][j],t[i][j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		dijkstra(y[i]);
		cout<<dist[x[i]]+w[x[i]]+w[y[i]]<<"\n";
	}
//	if(d<=2){
//		
//	}
//	if(d<=2||n<=2){
//		for(int i=1;i<=q;i++){
//			int u=lca(x[i],y[i]);
//		}
//	}
	return 0;
}
//坏了百词斩忘打卡了 

