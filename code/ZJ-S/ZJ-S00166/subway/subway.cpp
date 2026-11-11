#include <bits/stdc++.h>
using namespace std;
struct Edge{
	long long to,cost;
};
struct Node{
	long long pos,dis;
	bool operator<(const Node &x)const{return x.dis<dis;}
};
long long c,n,m,d,q;
long long walk[500010],dist[1000010],vis[1000010],k[510];
vector<long long> a[510],b[510];
vector<Edge> edge[500010];
inline long long dijkstra(long long s,long long e){
	memset(dist,0x3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	q.push({s,0});
	dist[s]=0;
	while (!q.empty()){
		Node x=q.top();
		q.pop();
		long long u=x.pos,size=edge[u].size();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=0;i<size;++i){
			long long v=edge[u][i].to,w=edge[u][i].cost;
			if (dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({v,dist[v]});
			}
		}
	}
	return dist[e];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;++i) cin>>walk[i];
	long long a1,a2;
	long long num=m;
	for (int i=1;i<=n;++i){
		cin>>k[i];
		for (int j=1;j<=k[i];++j){
			cin>>a1>>a2;
			a[i].push_back(a1);
			b[i].push_back(a2);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=0;j<k[i];++j){
			edge[a[i][j]].push_back({++num,b[i][j]});
			edge[num].push_back({a[i][j],b[i][j]});
			if (j<k[i]-1){
				edge[num].push_back({num+1,0});
				edge[num+1].push_back({num,0});
			} 
		}
	}
	for (int i=1;i<=q;++i){
		cin>>a1>>a2;
		cout<<dijkstra(a1,a2)+walk[a1]+walk[a2]<<'\n';
	}
}
