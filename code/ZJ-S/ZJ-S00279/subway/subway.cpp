#include<bits/stdc++.h>
using namespace std;
int const N=1e3+5;
int c,n,m,d,q,len;
long long v[N],w[N][N],a[N];
bool vis[N];
long long dist[N][N];
vector<pair<int,long long>> G[N];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> que;
void dijkstra(int s){
	for(int i=1;i<=m;i++) dist[s][i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	que.push({0,s});dist[s][s]=0;
	while(que.size()){
		int u=que.top().second;que.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto e:G[u]){
			int v=e.first;long long W=e.second;
			if(dist[s][v]>dist[s][u]+W){
				dist[s][v]=dist[s][u]+W;
				que.push({dist[s][v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++) cin>>v[j]>>w[i][j];
		for(int j=1;j<=len;j++){
			for(int k=j+1;k<=len;k++){
				G[v[j]].push_back({v[k],w[i][j]+w[i][k]});
				G[v[k]].push_back({v[j],w[i][j]+w[i][k]});
			}
		}
	}
	for(int i=1;i<=m;i++) dijkstra(i);
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		cout<<dist[u][v]+a[u]+a[v]<<'\n';
	}
	return 0;
}
