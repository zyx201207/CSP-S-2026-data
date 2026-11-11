#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v,w;
	bool operator<(const node &y)const{
		return w > y.w;
	}
};
struct node2{
	int v,w;
};
int c,n,m,d,q;
int a[505],dist[500555];
vector<node2>e[500555];
bool vis[500555];
void dijkstra(int s){
	priority_queue<node>q;
	for(int i = 1;i <= n+m;i++){
		dist[i]=9999999999999;
		vis[i]=0;
	}
	dist[s]=0;
	q.push({s,0});
	while(q.size()){
		int u=q.top().v;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i = 0;i < e[u].size();i++){
			int v=e[u][i].v;
			int w=e[u][i].w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({v,dist[u]+w});
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			int v,w;
			cin>>v>>w;
			e[i+m].push_back({v,w});
			e[v].push_back({i+m,w});
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dist[y]+a[y]+a[x]<<"\n";
	}
	return 0;
}
