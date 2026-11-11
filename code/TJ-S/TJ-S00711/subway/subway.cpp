#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>
using namespace std;
#define MAXN 500510
#define pii pair<int,int>
vector<pii>g[MAXN];//g[u]:{v,w}
int c,n,m,d,q;
int dis[MAXN];bool vis[MAXN];
int tdis[500][500];
int dijkstra(int s,int t){
	for(int i=0;i<=n+m;i++)dis[i]=INT_MAX,vis[i]=0;
	priority_queue<pii>pq;//{dis,u}
	pq.push({0,s});dis[s]=0;
	while(!pq.empty()){
		pii now=pq.top();pq.pop();
		int u=now.second,d=now.first;
		if(vis[u])continue;
		//vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			pii te=g[u][i];
			int v=te.first,w=te.second;
			if(dis[v]>d+w){
				dis[v]=d+w;
				pq.push({dis[v],v});
			}
		}
	}
	return dis[t];
}
int dijkstra2(int s,int t){
	for(int i=0;i<=n+m;i++)tdis[s][i]=INT_MAX,vis[i]=0;
	priority_queue<pii>pq;//{dis,u}
	pq.push({0,s});tdis[s][s]=0;
	while(!pq.empty()){
		pii now=pq.top();pq.pop();
		int u=now.second,d=now.first;
		if(vis[u])continue;
		//vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			pii te=g[u][i];
			int v=te.first,w=te.second;
			if(tdis[s][v]>d+w){
				tdis[s][v]=d+w;
				pq.push({tdis[s][v],v});
			}
		}
	}
	return tdis[s][t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	// 第i个地铁站：g[n+i]；第i个线路：g[i] 
	if(c<=6){
		int w[m];
		for(int i=1;i<=m;i++)cin >> w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin >> k;
			for(int j=0;j<k;j++){
				int v,w;
				cin >> v >> w;
				g[i].push_back({n+v,w});
				g[n+v].push_back({i,w});
			}
		}
		while(q--){
			int x,y;
			cin >> x >> y;
			cout << dijkstra(n+x,n+y)+w[x]+w[y] << endl;
		}
	}else if(c<=11){
		int w[m];
		for(int i=1;i<=m;i++)cin >> w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin >> k;
			if(k==1){cin >> k >> k;continue;}
			int v1,v2,w1,w2;
			cin >> v1 >> w1 >> v2 >> w2;
			g[v1].push_back({v2,w1+w2});
			g[v2].push_back({v1,w1+w2});
		}
		while(q--){
			int x,y;
			cin >> x >> y;
			if(tdis[x][y]==0)dijkstra(x,y);
			cout << tdis[x][y]+w[x]+w[y] << endl;
		}
	}
}
