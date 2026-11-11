#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int dian[500010];
int ddist[510][510];
struct edge{
	int to,w;
};
vector<edge>g[500010];
int dist[510];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
void dj(int u){
	memset(dist,0x3f,sizeof(dist));
	dist[u]=0;
	pq.push({0,u});
	while(!pq.empty()){
		int d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(d>dist[u])continue;
		for(auto e:g[u]){
			int v=e.to;
			int w=e.w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>dian[i];
	}
	for(int i=1;i<=n;i++){
		int k;//2
		cin>>k;int a[3],w[3];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>w[j];
			if(j>=2){
				g[a[j-1]].push_back({a[j],w[j-1]+w[j]});
				g[a[j]].push_back({a[j-1],w[j-1]+w[j]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		dj(i);
		for(int j=1;j<=m;j++){
			ddist[i][j]=dist[j];
			ddist[j][i]=dist[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=dian[x]+dian[y];
		cout<<ans+ddist[x][y]<<"\n";
	}
	return 0;
}
