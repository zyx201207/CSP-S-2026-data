#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,Q,vis[N*2],w[N];
vector<pair<int,int> > g[N];
long long dis[N*2][N*2];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<> > q;
void D(int s){
	for(int i=1;i<=m*2;i++){
		vis[i]=0;
		dis[s][i]=0x3f3f3f3f3f3f3f3f;
	}
	dis[s][s]=0;
	while(!q.empty()) q.pop();
	q.push({dis[s][s],s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto h:g[u]){
			int v=h.first,w=h.second;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k,v,W;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>v>>W;
			g[i+m].push_back({v,W});
			g[v].push_back({i+m,W});
		}
	}
	for(int i=1;i<=m;i++) D(i);
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}