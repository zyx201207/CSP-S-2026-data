#include <bits/stdc++.h>
#define pir pair<int,int>
using namespace std;
const int N = 500,M = 2e5+10,D = 20+10;
int n, m, c, d, q, a[M];
long long w[M];
struct Node{
	int ind, type;
}; 
struct Edge{
	Node u;
	long long v;
	bool operator<(const Edge &other) const{
		return v > other.v;
	}
}; 
int sz[M];
vector <Edge> g[M][D];
long long dist[M][D];
bool vis[M][D];
void dijkstra(int s){
	priority_queue<Edge> pq;
	for (int i = 0;i <= d;i++){
		for (int j = 1;j <= m;j++){
			vis[j][i] = false;
			dist[j][i] = 1e18;
		}
	}
	Edge es;
	es.v = 0,es.u.ind = s,es.u.type = 0;
	pq.push(es);
	dist[s][0] = 0;
	
	while (pq.size()){
		Edge cur = pq.top();pq.pop();
		int ind = cur.u.ind, type = cur.u.type;
		if (vis[ind][type]) continue;
		vis[ind][type] = true;
		
		for (int i = 0;i < g[ind][type].size();i++){
			int x = g[ind][type][i].u.ind; 
			int y = g[ind][type][i].u.type;
			int v = g[ind][type][i].v;
			if (dist[x][y] > dist[ind][type]+v){
				dist[x][y] = dist[ind][type]+v;
				Edge e;
				e.u.ind = x;
				e.u.type = y;
				e.v = dist[x][y];
				pq.push(e);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		int k; cin >> k; 
		for (int j = 1;j <= k;j++){
			int ind,v;
			cin >> a[j] >> v;
			ind = a[j];
			sz[ind]++;int num = sz[ind];
			Edge e1,e2;
			e1.u.ind = ind;
			e1.u.type = 0;
			e1.v = v;
		
			e2.u.ind = ind;
			e2.u.type = num;
			e2.v = v;
			
			g[ind][num].push_back(e1);
			g[ind][0].push_back(e2);
			
			if (j > 1){
				int last_ind = a[j-1],last_num = sz[last_ind];
				Edge e3, e4;
				e3.u.ind = last_ind;
				e3.u.type = last_num;
				e3.v = 0;
				
				e4.u.ind = ind;
				e4.u.type = num;
				e4.v = 0;
				g[ind][num].push_back(e3);
				g[last_ind][last_num].push_back(e4);
			}
		}
	}
	for (int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		dijkstra(x);
		cout << dist[y][0]+w[x]+w[y] << '\n';
	}
	return 0;
}

