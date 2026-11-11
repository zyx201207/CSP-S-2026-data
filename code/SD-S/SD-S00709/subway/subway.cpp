#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
const int INF=1e18;
int c,n,m,d,q;
int val[M],k[N];
vector<pair<int,int> > e[M+N];
int dis[N+M];
bool vis[N+M];
void dijkstra(int s){
	for(int i=1;i<=n+m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	dis[s]=0;
	pq.push({dis[s],s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first,w=e[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			e[i+m].push_back({a,t});
			e[a].push_back({i+m,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		int ans=val[x]+dis[y]+val[y];
		cout<<ans<<"\n";
	}
	return 0;
}
