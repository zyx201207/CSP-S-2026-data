#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
const int INF=1e18;
int c,n,m,d,q,dist[N],vis[N],tot;
vector<pair<int,int> > adj[N];
void djstl(int s){
	for(int i=1;i<=tot;i++){
		dist[i]=INF;
		vis[i]=0;
	}
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:adj[u]){
			int v=i.first,w=i.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	tot=m;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		adj[i].push_back({++tot,w});
		adj[tot].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=0;
		for(int j=1;j<=k;j++){
			int f,w;
			cin>>f>>w;
			adj[f].push_back({++tot,w});
			adj[tot].push_back({f,w});
			if(j!=1){
				adj[tot].push_back({last,0});
				adj[last].push_back({tot,0});
			}
			last=tot;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		djstl(m+x);
		cout<<dist[y+m]<<'\n';
	}
	return 0;
}
