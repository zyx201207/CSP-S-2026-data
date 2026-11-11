#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],x,y,dist[500010];
bool vis[500010];
vector<int>station[510];
vector<pair<int,int>>g[510];
void Dijkstra(int x,int y){
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	dist[x]=0;
	vis[x]=1;
	priority_queue<int,vector<int>,greater<int>>q;
	q.push(x);
	while(q.size()){
		int u=q.top();q.pop();
		if(u==y){
			cout<<w[x]+dist[y]+w[y]<<'\n';
		}
		for(auto i:g[u]){
			int v=i.second,weight=i.first;
			if(vis[v]==0){
				vis[v]=1;
				dist[v]=dist[u];
				q.push(v);
			}else if(dist[u]+weight+g[u][v].first<dist[v]){
				dist[v]=dist[u]+weight+g[u][v].first;
				q.push(v);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back({t,a});
			station[t].push_back(i);
		}
	}
	while(q--){
		cin>>x>>y;
		Dijkstra(x,y);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
