#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int MAXN = 505;
const int MAXM = 5e5+10;
struct Edge{
	int v,w;
};
int c,n,m,d,q;
vector<bool> vis(MAXM); 
vector<int> w(MAXM),dis(MAXM);
vector<Edge> adj[MAXM];
void dijkstra(int s){
	for (int i=1;i<=m;i++){
		dis[i] = 0x3f3f3f3f3f3f;
		vis[i] = false;
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,s});
	dis[s] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (const auto& to : adj[u]){
			int v = to.v;
			int w = to.w;
			if (dis[v]>dis[u]+w){
				dis[v] = dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		vector<pii> a(k+1);
		for (int j=1;j<=k;j++){
			cin >> a[j].first >> a[j].second;
		}
		for (int j=1;j<k;j++){
			int u = a[j].first,w1 = a[j].second;
			int v = a[j+1].first,w2 = a[j+1].second;
			adj[u].push_back({v,w1+w2});
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y]+w[x]+w[y] << '\n';
	} 
	return 0; 
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
