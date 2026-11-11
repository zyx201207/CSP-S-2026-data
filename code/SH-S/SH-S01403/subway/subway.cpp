#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 5;
typedef long long i64;
int c, n, m, d, q, w[maxm];
i64 dist[505], adj[505][505];
bool visited[505];
vector<pair<i64, int> > edges[505];
vector<pair<int, int> > route[505];
bool reach[505][505];
void dijkstra(int start){
	//init
	priority_queue<pair<int, int> > pq;
	for(int i = 1; i <= m; i++){
		dist[i] = 1e9;
		visited[i] = false;
	}
	pq.push({0, start});
	dist[start] = 0;
	while(!pq.empty()){
		auto d = -pq.top().first;
		auto from = pq.top().second;
		pq.pop();
		if(visited[from]) continue;
		visited[from] = true;
		for(auto x : edges[from]){
			if(dist[x.second] > d + x.first){
				dist[x.second] = d + x.first;
				pq.push({-dist[x.second], x.second});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	//			地铁线路，地铁站，max，q
	//口->厅 
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++) adj[i][j] = 9e18;
	}
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, b;
			cin >> a >> b;
			route[i].push_back({b, a}); 
			//厅->台
		}
		for(int station1 = 0; station1 < k - 1; station1++){
			for(int station2 = station1 + 1; station2 < k; station2++){
				i64 d = route[i][station1].first + route[i][station2].first;
				int s1 = route[i][station1].second;
				int s2 = route[i][station2].second;
				adj[s1][s2] = min(adj[s1][s2], d);
				adj[s2][s1] = min(adj[s2][s1], d); 
			}
		}
	}
	for(int i = 1; i < m; i++){
		for(int j = i + 1; j <= m; j++){
			if(adj[i][j] == 9e18) continue;
			reach[i][j] = reach[j][i] = true;
			edges[i].push_back({adj[i][j], j});
			edges[j].push_back({adj[i][j], i});
		}
	}
	/*
	for(int i = 1; i <= m; i++){
		cout << "metro" << i << endl;
		for(auto x : edges[i]) cout << x.first << " " << x.second << endl;
	}
	*/
	for(int i = 1; i <= q; i++){
		int s, t;
		cin >> s >> t;
		dijkstra(s);
		cout << dist[t] + w[s] + w[t] << endl;
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
