#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 1e4 + 5, INF = 0x3f3f3f3f;
int c, n, m, d, q;
int w[N];
int dist[N];
struct Edge{
	int to, w;
};
vector<Edge> G[N];
struct Point{
	int u, dist;
	bool operator < (const Point p) const{
		return dist > p.dist;
	}
};
void dijkstra(int start){
	fill(dist,dist + N, INF);
	priority_queue<Point> pq;
	dist[start] = 0;
	pq.push({start, 0});
	while(!pq.empty()){
		int u = pq.top().u, d = pq.top().dist;
		pq.pop();
		if(d > dist[u]) continue;
		for(auto e : G[u]){
			int v = e.to, w = e.w;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({v,dist[v]});
			}
		}
	}
}
int a[N],t[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int j = 1; j <= n; j++){
		int k;
		cin >> k;
		for(int i = 1; i <= k; i++) cin >> a[i];
		for(int i = 1; i <= k; i++) cin >> t[i];
	while(q--){
		int x, y;
		cin >> x >> y;
	}
	return 0;
}








