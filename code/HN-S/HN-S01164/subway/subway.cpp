#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
long long dis[500005];
vector<pair<int,int>>g[500005];
int dij(int start,int end){
	for(int i=1;i<=m+n;i++){
		dis[i]=1e16;
	}
	priority_queue<pair<int,int>>q;
	dis[start]=0;
	q.push({0,start});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			if(dis[v]>dis[u]+g[u][i].second){
				dis[v]=dis[u]+g[u][i].second;
				q.push({-dis[v],v});
			}
		}
	} 
	return dis[end];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		dij(u,v);
		cout<<dis[v]+w[u]+w[v]<<"\n";
	}
	return 0;
} 
