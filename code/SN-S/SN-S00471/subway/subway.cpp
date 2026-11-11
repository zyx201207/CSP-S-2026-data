//SN-S00471 田牧可 西安交通大学附属中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const int M=5e5+10;
const ll inf=1e18;
ll c,n,m,d,q,w[N],dist[N+M];
bool vis[N+M];
struct edge{
	ll to,val;
};
vector<edge> vec[N+M];
void dijkstra(int root){
	for(int i=1;i<=n+m;i++) dist[i]=inf;
	memset(vis,0,sizeof(vis));
	dist[root]=0;
	priority_queue<pair<ll,ll> > q;
	q.push(make_pair(0,root));
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue ;
		vis[x]=1;
		for(auto i:vec[x]){
			int y=i.to,w=i.val;
			if(dist[y]>dist[x]+w){
				dist[y]=dist[x]+w;
				q.push(make_pair(-dist[y],y));
			}
		}
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		if(k==1) continue ;
		int node=m+i;
		for(int j=1;j<=k;j++){
			int u,v;cin>>u>>v;
			vec[u].push_back((edge){node,v});
			vec[node].push_back((edge){u,v});
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		dijkstra(x);
		cout<<dist[y]+w[x]+w[y]<<"\n";
	}
}
ll f[N][N];
void solve2(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) f[i][j]=0;
			else f[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		if(k==1) continue ;
		int u,v,w1,w2;cin>>u>>w1>>v>>w2;
		f[u][v]=f[v][u]=w1+w2;
		//vec[u].push_back((edge){v,w1+w2});
		//vec[v].push_back((edge){u,w1+w2});
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c>=1&&c<=6) solve1();
	if(c>=7&&c<=11) solve2();
	return 0;
}
