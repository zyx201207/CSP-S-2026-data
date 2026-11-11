#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int c,n,m,d,Q;
struct e{
	int u,v;
	long long w;
};
vector<e> G[N];
long long w[N];
int a[N][N];
long long t[N][N];
int k[N];
int cnt[N];
long long dis[N];
bool vis[N];
long long Dijkstra(int s,int e){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<pair<long long,int> > q;
	q.push({-dis[s],s});
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v,w=G[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
	return dis[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		cnt[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		cnt[a[i][1]]++;
		for(int j=1;j<=k[i];j++){
			int u=a[i][j],v=a[i][j]+m*cnt[a[i][j]];
			G[u].push_back({u,v,t[i][j]});
			G[v].push_back({v,u,t[i][j]});
			if(j!=k[i]){
				u=v,v=a[i][j+1]+m*(++cnt[a[i][j+1]]);
				G[u].push_back({u,v,0});
				G[v].push_back({v,u,0});
			}
		}
	}
	while(Q--){
		int u,v;
		cin>>u>>v;
		cout<<Dijkstra(u,v)+w[u]+w[v]<<"\n";
	}
	return 0;
}

